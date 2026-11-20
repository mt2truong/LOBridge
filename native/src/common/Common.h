// Shared COM plumbing: IUnknown/IDispatch boilerplate, BSTR helpers and error mapping.
#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <ole2.h>
#include <oleauto.h>
#include <string>
#include <vector>

// MIDL-generated interface declarations (run midl on LibreOffice.idl first).
#include "LOBridge.h"

#include <rtl/ustring.hxx>

// Module handle of this DLL, set in DllMain (Dll.cpp).
extern HINSTANCE g_hModule;

namespace lo_com {

// Writes a UNO exception message to stderr and the debugger output.
void LogException(const rtl::OUString& message);


// LIBID of the type library. Must match LOBridge.idl.
extern const CLSID kLibId;

// Loads the type library used for IDispatch (registered, or embedded in the module).
HRESULT LoadTypeInfoFor(REFIID iid, ITypeInfo** ppTypeInfo);

// Module path of this DLL (set in DllMain).
const std::wstring& ModulePath();

// Converts between BSTR and OUString.
rtl::OUString ToOUString(BSTR bstr);
BSTR ToBSTR(const rtl::OUString& s);
BSTR ToBSTR(const std::string& ascii);

inline VARIANT_BOOL ToVB(bool b) { return b ? VARIANT_TRUE : VARIANT_FALSE; }
inline bool FromVB(VARIANT_BOOL v) { return v != VARIANT_FALSE; }

// Returns a freshly created object (refcount 1) through an [out] pointer.
// Ownership of the creation reference is transferred to the caller.
template <class TIface, class TImpl>
HRESULT ReturnNew(TImpl* obj, TIface** out)
{
    if (!out)
    {
        if (obj) obj->Release();
        return E_POINTER;
    }
    *out = obj;
    return S_OK;
}

} // namespace lo_com

// Counts live COM objects so DllCanUnloadNow can refuse to unload the DLL while objects exist.
extern LONG g_objectCount;

namespace lo_com {
struct ModuleRef
{
    ModuleRef() { InterlockedIncrement(&g_objectCount); }
    ~ModuleRef() { InterlockedDecrement(&g_objectCount); }
    ModuleRef(const ModuleRef&) { InterlockedIncrement(&g_objectCount); }
    ModuleRef& operator=(const ModuleRef&) { return *this; }
};
} // namespace lo_com

// ---- IUnknown + IDispatch for a class implementing a dual interface -------------
// The vtable of the dual interface is used directly; IDispatch is forwarded to ITypeInfo
// obtained from the type library, so no hand-written dispatch table is needed.
#define LO_COM_IUNKNOWN_AND_DISPATCH(IFACE)                                                    \
    LONG m_ref = 1;                                                                            \
    lo_com::ModuleRef m_moduleRef;                                                             \
    STDMETHODIMP QueryInterface(REFIID riid, void** ppv) override                              \
    {                                                                                          \
        if (!ppv) return E_POINTER;                                                            \
        if (riid == IID_IUnknown || riid == IID_IDispatch || riid == __uuidof(IFACE))          \
        {                                                                                      \
            *ppv = static_cast<IFACE*>(this);                                                  \
            AddRef();                                                                          \
            return S_OK;                                                                       \
        }                                                                                      \
        *ppv = nullptr;                                                                        \
        return E_NOINTERFACE;                                                                  \
    }                                                                                          \
    STDMETHODIMP_(ULONG) AddRef() override { return (ULONG)InterlockedIncrement(&m_ref); }     \
    STDMETHODIMP_(ULONG) Release() override                                                    \
    {                                                                                          \
        LONG r = InterlockedDecrement(&m_ref);                                                 \
        if (r == 0) delete this;                                                               \
        return (ULONG)r;                                                                       \
    }                                                                                          \
    STDMETHODIMP GetTypeInfoCount(UINT* pctinfo) override                                      \
    {                                                                                          \
        if (!pctinfo) return E_POINTER;                                                        \
        *pctinfo = 1;                                                                          \
        return S_OK;                                                                           \
    }                                                                                          \
    STDMETHODIMP GetTypeInfo(UINT iTInfo, LCID, ITypeInfo** ppTInfo) override                 \
    {                                                                                          \
        if (!ppTInfo) return E_POINTER;                                                        \
        *ppTInfo = nullptr;                                                                    \
        if (iTInfo != 0) return DISP_E_BADINDEX;                                               \
        ITypeInfo* ti = nullptr;                                                               \
        HRESULT hr = lo_com::LoadTypeInfoFor(__uuidof(IFACE), &ti);                            \
        if (SUCCEEDED(hr)) *ppTInfo = ti;                                                      \
        return hr;                                                                             \
    }                                                                                          \
    STDMETHODIMP GetIDsOfNames(REFIID, LPOLESTR* rgszNames, UINT cNames, LCID,                 \
                               DISPID* rgDispId) override                                      \
    {                                                                                          \
        ITypeInfo* ti = nullptr;                                                               \
        HRESULT hr = lo_com::LoadTypeInfoFor(__uuidof(IFACE), &ti);                            \
        if (FAILED(hr)) return hr;                                                             \
        hr = ti->GetIDsOfNames(rgszNames, cNames, rgDispId);                                   \
        ti->Release();                                                                         \
        return hr;                                                                             \
    }                                                                                          \
    STDMETHODIMP Invoke(DISPID dispIdMember, REFIID, LCID, WORD wFlags, DISPPARAMS* pDispParams,\
                        VARIANT* pVarResult, EXCEPINFO* pExcepInfo, UINT* puArgErr) override   \
    {                                                                                          \
        ITypeInfo* ti = nullptr;                                                               \
        HRESULT hr = lo_com::LoadTypeInfoFor(__uuidof(IFACE), &ti);                            \
        if (FAILED(hr)) return hr;                                                             \
        hr = ti->Invoke(static_cast<IFACE*>(this), dispIdMember, wFlags, pDispParams,          \
                        pVarResult, pExcepInfo, puArgErr);                                     \
        ti->Release();                                                                         \
        return hr;                                                                             \
    }

// Wraps a body in UNO exception handling. Any UNO or C++ exception becomes E_FAIL.
#define LO_COM_TRY try {
#define LO_COM_CATCH                                                                           \
    }                                                                                          \
    catch (const ::com::sun::star::uno::Exception& lo_ex) { lo_com::LogException(lo_ex.Message); return E_FAIL; } \
    catch (...) { return E_FAIL; }
