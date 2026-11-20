// Type library loading, module path and BSTR conversions.
#include "Common.h"

#include <cstdio>
#include <cwchar>

namespace lo_com {

// {6B1E2C7A-3F0D-4E8B-9A57-2D4C8F1B6E90} - keep in sync with LOBridge.idl
const CLSID kLibId = { 0x6B1E2C7A, 0x3F0D, 0x4E8B, { 0x9A, 0x57, 0x2D, 0x4C, 0x8F, 0x1B, 0x6E, 0x90 } };

const std::wstring& ModulePath()
{
    static std::wstring path;
    if (path.empty())
    {
        wchar_t buf[MAX_PATH * 4] = {};
        DWORD n = GetModuleFileNameW(g_hModule, buf, (DWORD)(sizeof(buf) / sizeof(buf[0])));
        path.assign(buf, n);
    }
    return path;
}

static ITypeLib* LoadLibraryTypeInfo()
{
    ITypeLib* tl = nullptr;
    // Prefer the registered library, fall back to the copy embedded in this DLL.
    if (FAILED(LoadRegTypeLib(kLibId, 1, 0, LOCALE_SYSTEM_DEFAULT, &tl)))
    {
        tl = nullptr;
        LoadTypeLibEx(ModulePath().c_str(), REGKIND_NONE, &tl);
    }
    return tl;
}

HRESULT LoadTypeInfoFor(REFIID iid, ITypeInfo** ppTypeInfo)
{
    if (!ppTypeInfo) return E_POINTER;
    *ppTypeInfo = nullptr;
    // Function-local static: initialised once, thread-safe since C++11.
    static ITypeLib* tl = LoadLibraryTypeInfo();
    if (!tl) return TYPE_E_CANTLOADLIBRARY;
    return tl->GetTypeInfoOfGuid(iid, ppTypeInfo);
}

void LogException(const rtl::OUString& message)
{
    std::wstring line = L"[LOBridge] " + std::wstring(message.getStr(), message.getStr() + message.getLength()) + L"\n";
    OutputDebugStringW(line.c_str());
    std::fputws(line.c_str(), stderr);
}

rtl::OUString ToOUString(BSTR bstr)
{
    if (!bstr) return rtl::OUString();
    return rtl::OUString(reinterpret_cast<const sal_Unicode*>(bstr), (sal_Int32)SysStringLen(bstr));
}

BSTR ToBSTR(const rtl::OUString& s)
{
    return SysAllocStringLen(reinterpret_cast<const OLECHAR*>(s.getStr()), (UINT)s.getLength());
}

BSTR ToBSTR(const std::string& ascii)
{
    rtl::OUString s = rtl::OUString::createFromAscii(ascii.c_str());
    return ToBSTR(s);
}

} // namespace lo_com
