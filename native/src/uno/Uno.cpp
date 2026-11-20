// Connects to a LibreOffice process from C++ (out-of-process UNO over a local socket).
#include "Uno.h"

#include <com/sun/star/bridge/XUnoUrlResolver.hpp>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

namespace lo_uno {

namespace {

// Private port and profile: never touches an office the user may already be running.
const wchar_t kHost[] = L"localhost";
const int kPort = 2083;

std::wstring ProfileUrl()
{
    wchar_t temp[MAX_PATH] = {};
    GetTempPathW(MAX_PATH, temp);
    std::wstring dir = std::wstring(temp) + L"LOBridge\\profile";
    CreateDirectoryW((std::wstring(temp) + L"LOBridge").c_str(), nullptr);
    CreateDirectoryW(dir.c_str(), nullptr);
    std::wstring url = L"file:///" + dir;
    for (auto& c : url) if (c == L'\\') c = L'/';
    return url;
}

// Starts soffice headless listening on the private socket. Returns false if the process cannot be created.
bool LaunchOffice(const std::wstring& prog)
{
    std::wstring cmd = L"\"" + prog + L"\\soffice.exe\" --headless --invisible --nologo --norestore --nodefault"
                       L" -env:UserInstallation=" + ProfileUrl() +
                       L" \"--accept=socket,host=" + kHost + L",port=" + std::to_wstring(kPort) + L";urp;StarOffice.ServiceManager\"";
    STARTUPINFOW si = { sizeof(si) };
    PROCESS_INFORMATION pi = {};
    std::vector<wchar_t> buf(cmd.begin(), cmd.end());
    buf.push_back(L'\0');
    if (!CreateProcessW(nullptr, buf.data(), nullptr, nullptr, FALSE,
                        DETACHED_PROCESS | CREATE_NO_WINDOW, nullptr, prog.c_str(), &si, &pi))
    {
        return false;
    }
    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);
    return true;
}

} // namespace


std::wstring LibreOfficeProgramDir()
{
    wchar_t buf[MAX_PATH * 4] = {};
    DWORD n = GetEnvironmentVariableW(L"LIBREOFFICE_PROGRAM", buf, (DWORD)(sizeof(buf) / sizeof(buf[0])));
    if (n > 0 && n < sizeof(buf) / sizeof(buf[0]))
    {
        return std::wstring(buf, n);
    }

    HKEY key = nullptr;
    if (RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\LibreOffice\\UNO\\InstallPath", 0, KEY_READ, &key) == ERROR_SUCCESS)
    {
        DWORD type = 0, size = sizeof(buf);
        if (RegQueryValueExW(key, nullptr, nullptr, &type, reinterpret_cast<LPBYTE>(buf), &size) == ERROR_SUCCESS
            && type == REG_SZ && size > 0)
        {
            RegCloseKey(key);
            std::wstring dir(buf);
            while (!dir.empty() && (dir.back() == L'\\' || dir.back() == L'/')) dir.pop_back();
            return dir;
        }
        RegCloseKey(key);
    }
    return L"C:\\Program Files\\LibreOffice\\program";
}

Reference<css::uno::XComponentContext> Bootstrap()
{
    std::wstring prog = LibreOfficeProgramDir();

    // The UNO runtime DLLs (sal3, cppu3, cppuhelper3MSC, ...) live in the program directory.
    // URE_BOOTSTRAP is left to the default lookup (fundamental.ini in the program directory).
    // Setting it to a vnd.sun.star.pathname: URL crashed the bootstrap, so it is not set here.
    SetDllDirectoryW(prog.c_str());
    if (GetEnvironmentVariableW(L"UNO_PATH", nullptr, 0) == 0)
    {
        SetEnvironmentVariableW(L"UNO_PATH", prog.c_str());
    }

    // Experiment: the 8.3 short path of fundamental.ini has no spaces, so the URL needs no encoding.
    wchar_t shortIni[MAX_PATH * 4] = {};
    std::wstring ini = prog + L"\\fundamental.ini";
    GetShortPathNameW(ini.c_str(), shortIni, (DWORD)(sizeof(shortIni) / sizeof(shortIni[0])));
    std::wstring value = std::wstring(L"vnd.sun.star.pathname:") + (shortIni[0] ? shortIni : ini.c_str());
    SetEnvironmentVariableW(L"URE_BOOTSTRAP", value.c_str());
    lo_com::LogException(OUString::createFromAscii("URE_BOOTSTRAP set"));
    return cppu::defaultBootstrap_InitialComponentContext();
}

Session StartSession()
{
    // The UNO socket connector needs Winsock initialised (once per process).
    static const bool winsock = [] { WSADATA wsa; return WSAStartup(MAKEWORD(2, 2), &wsa) == 0; }();
    (void)winsock;

    Session s;
    s.ctx = Bootstrap();
    // In-process Desktop creation crashes in this environment (see docs/TROUBLESHOOTING.md), so the office
    // runs out of process on a private socket.
    Reference<css::lang::XMultiComponentFactory> localSmgr = s.ctx->getServiceManager();
    Reference<XInterface> resolverObj =
        localSmgr->createInstanceWithContext(OUString::createFromAscii("com.sun.star.bridge.UnoUrlResolver"), s.ctx);
    Reference<css::bridge::XUnoUrlResolver> resolver(resolverObj, UNO_QUERY);
    if (!resolver.is()) return s;

    std::wstring urlW = std::wstring(L"uno:socket,host=") + kHost + L",port=" + std::to_wstring(kPort)
                        + L";urp;StarOffice.ComponentContext";
    OUString url(reinterpret_cast<const sal_Unicode*>(urlW.c_str()), (sal_Int32)urlW.size());

    // Connect to a running listener, or start one and wait for it (up to ~60 s).
    Reference<XInterface> remote;
    bool launched = false;
    for (int attempt = 0; attempt < 120 && !remote.is(); ++attempt)
    {
        try
        {
            remote = resolver->resolve(url);
        }
        catch (const css::uno::Exception& ex)
        {
            if (attempt == 0 || attempt == 119)
                lo_com::LogException(OUString::createFromAscii("resolve: ") + ex.Message);
            if (!launched)
            {
                launched = true;
                LaunchOffice(LibreOfficeProgramDir());
            }
            Sleep(500);
        }
    }
    if (!remote.is())
    {
        lo_com::LogException(OUString::createFromAscii("StartSession: could not connect to LibreOffice"));
        return s;
    }

    // Created through the service manager of the remote office.
    s.ctx = Reference<css::uno::XComponentContext>(remote, UNO_QUERY);
    Reference<css::lang::XMultiComponentFactory> smgr = s.ctx->getServiceManager();
    Reference<XInterface> desktopObj =
        smgr->createInstanceWithContext(OUString::createFromAscii("com.sun.star.frame.Desktop"), s.ctx);
    if (!desktopObj.is()) lo_com::LogException(OUString::createFromAscii("StartSession: Desktop service returned null"));
    // Known issue: this query on the remote object currently recurses (see docs/TROUBLESHOOTING.md).
    s.desktop = Reference<css::frame::XDesktop>(desktopObj, UNO_QUERY);
    s.loader = Reference<css::frame::XComponentLoader>(s.desktop, UNO_QUERY);
    return s;
}

void EndSession(Session& session)
{
    if (!session.desktop.is()) return;
    // The office may be shared with other sessions, so it is not terminated here; only the references are released.
    session.loader.clear();
    session.desktop.clear();
}

} // namespace lo_uno
