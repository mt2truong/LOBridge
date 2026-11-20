// In-process COM server entry points: class factory, self-registration and type library registration.
#include "Common.h"
#include "writer/App.h"
#include "calc/App.h"

#include <unknwn.h>
#include <olectl.h>

HINSTANCE g_hModule = nullptr;
LONG g_objectCount = 0;
static LONG g_lockCount = 0;

namespace {

const wchar_t kWordProgId[] = L"LOBridge.Writer.App";
const wchar_t kExcelProgId[] = L"LOBridge.Calc.App";

class ClassFactory final : public IClassFactory
{
public:
    explicit ClassFactory(bool word) : m_word(word) {}

    STDMETHODIMP QueryInterface(REFIID riid, void** ppv) override
    {
        if (!ppv) return E_POINTER;
        if (riid == IID_IUnknown || riid == IID_IClassFactory)
        {
            *ppv = static_cast<IClassFactory*>(this);
            AddRef();
            return S_OK;
        }
        *ppv = nullptr;
        return E_NOINTERFACE;
    }

    STDMETHODIMP_(ULONG) AddRef() override { return (ULONG)InterlockedIncrement(&m_ref); }
    STDMETHODIMP_(ULONG) Release() override
    {
        LONG r = InterlockedDecrement(&m_ref);
        if (r == 0) delete this;
        return (ULONG)r;
    }

    STDMETHODIMP CreateInstance(IUnknown* outer, REFIID riid, void** ppv) override
    {
        if (!ppv) return E_POINTER;
        *ppv = nullptr;
        if (outer) return CLASS_E_NOAGGREGATION;

        IUnknown* obj = nullptr;
        try
        {
            if (m_word)
                obj = static_cast<IWriterApp*>(new writer::App());
            else
                obj = static_cast<ICalcApp*>(new calc::App());
        }
        catch (...)
        {
            return E_OUTOFMEMORY;
        }
        // The object was created with refcount 1: query for the requested interface, then drop our reference.
        HRESULT hr = obj->QueryInterface(riid, ppv);
        obj->Release();
        return hr;
    }

    STDMETHODIMP LockServer(BOOL lock) override
    {
        if (lock) InterlockedIncrement(&g_lockCount);
        else InterlockedDecrement(&g_lockCount);
        return S_OK;
    }

private:
    LONG m_ref = 1;
    bool m_word;
};

// ---- registry helpers --------------------------------------------------------

LONG SetString(HKEY root, const std::wstring& subKey, const wchar_t* name, const std::wstring& value)
{
    HKEY key = nullptr;
    LONG rc = RegCreateKeyExW(root, subKey.c_str(), 0, nullptr, 0, KEY_WRITE, nullptr, &key, nullptr);
    if (rc != ERROR_SUCCESS) return rc;
    rc = RegSetValueExW(key, name, 0, REG_SZ, reinterpret_cast<const BYTE*>(value.c_str()),
                        (DWORD)((value.size() + 1) * sizeof(wchar_t)));
    RegCloseKey(key);
    return rc;
}

std::wstring GuidToString(REFCLSID clsid)
{
    wchar_t buf[64] = {};
    StringFromGUID2(clsid, buf, 64);
    return buf;
}

HRESULT RegisterClass(REFCLSID clsid, const wchar_t* progId, const wchar_t* description)
{
    std::wstring clsidText = GuidToString(clsid);
    std::wstring clsidKey = L"CLSID\\" + clsidText;
    LONG rc = SetString(HKEY_CLASSES_ROOT, clsidKey, nullptr, description);
    if (rc == ERROR_SUCCESS) rc = SetString(HKEY_CLASSES_ROOT, clsidKey + L"\\InprocServer32", nullptr, lo_com::ModulePath());
    if (rc == ERROR_SUCCESS) rc = SetString(HKEY_CLASSES_ROOT, clsidKey + L"\\InprocServer32", L"ThreadingModel", L"Both");
    if (rc == ERROR_SUCCESS) rc = SetString(HKEY_CLASSES_ROOT, clsidKey + L"\\ProgID", nullptr, progId);
    if (rc == ERROR_SUCCESS) rc = SetString(HKEY_CLASSES_ROOT, progId, nullptr, description);
    if (rc == ERROR_SUCCESS) rc = SetString(HKEY_CLASSES_ROOT, std::wstring(progId) + L"\\CLSID", nullptr, clsidText);
    return HRESULT_FROM_WIN32(rc);
}

void UnregisterClass(REFCLSID clsid, const wchar_t* progId)
{
    RegDeleteTreeW(HKEY_CLASSES_ROOT, (L"CLSID\\" + GuidToString(clsid)).c_str());
    RegDeleteTreeW(HKEY_CLASSES_ROOT, progId);
}

} // namespace

BOOL APIENTRY DllMain(HINSTANCE hInstance, DWORD reason, LPVOID)
{
    if (reason == DLL_PROCESS_ATTACH)
    {
        g_hModule = hInstance;
        DisableThreadLibraryCalls(hInstance);
    }
    return TRUE;
}

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    if (!ppv) return E_POINTER;
    *ppv = nullptr;
    bool word = rclsid == CLSID_WriterApp;
    bool excel = rclsid == CLSID_CalcApp;
    if (!word && !excel) return CLASS_E_CLASSNOTAVAILABLE;

    ClassFactory* factory = new ClassFactory(word);
    HRESULT hr = factory->QueryInterface(riid, ppv);
    factory->Release();
    return hr;
}

STDAPI DllCanUnloadNow()
{
    return (g_objectCount == 0 && g_lockCount == 0) ? S_OK : S_FALSE;
}

STDAPI DllRegisterServer()
{
    HRESULT hr = RegisterClass(CLSID_WriterApp, kWordProgId, L"LOBridge Writer COM");
    if (FAILED(hr)) return hr;
    hr = RegisterClass(CLSID_CalcApp, kExcelProgId, L"LOBridge Calc COM");
    if (FAILED(hr)) return hr;

    ITypeLib* typeLib = nullptr;
    hr = LoadTypeLibEx(lo_com::ModulePath().c_str(), REGKIND_NONE, &typeLib);
    if (FAILED(hr)) return hr;
    hr = RegisterTypeLib(typeLib, lo_com::ModulePath().c_str(), nullptr);
    typeLib->Release();
    return hr;
}

STDAPI DllUnregisterServer()
{
    UnregisterClass(CLSID_WriterApp, kWordProgId);
    UnregisterClass(CLSID_CalcApp, kExcelProgId);
    UnRegisterTypeLib(lo_com::kLibId, 1, 0, LOCALE_SYSTEM_DEFAULT, SYS_WIN64);
    return S_OK;
}
