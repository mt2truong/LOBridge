// calc::App: implementation.
#include "calc/App.h"
#include "calc/Workbook.h"

namespace calc {

App::App()
{
    try
    {
        m_session = StartSession();
    }
    catch (const css::uno::Exception& ex) { lo_com::LogException(ex.Message); }
    catch (...) { lo_com::LogException(OUString::createFromAscii("StartSession: unknown C++ exception")); }
}

App::~App()
{
    if (!m_disposed) EndSession(m_session);
}

STDMETHODIMP App::Dispose()
{
    if (!m_disposed)
    {
        EndSession(m_session);
        m_disposed = true;
    }
    return S_OK;
}

STDMETHODIMP App::Open(BSTR filePath, VARIANT_BOOL readOnly, ICalcWorkbook** ppVal)
{
    if (!ppVal) return E_POINTER;
    *ppVal = nullptr;
    LO_COM_TRY
    if (!m_session.loader.is()) return E_FAIL;

    css::uno::Sequence<css::beans::PropertyValue> props = MakeProps({
        MakeProp("Hidden", css::uno::makeAny(true)),
        MakeProp("ReadOnly", css::uno::makeAny(FromVB(readOnly)))
    });
    Reference<css::lang::XComponent> component = m_session.loader->loadComponentFromURL(
        ToUrl(ToOUString(filePath)), OUString::createFromAscii("_blank"), 0, props);
    Reference<css::sheet::XSpreadsheetDocument> doc(component, UNO_QUERY);
    if (!doc.is()) return S_OK;
    return ReturnNew<ICalcWorkbook>(new Workbook(doc), ppVal);
    LO_COM_CATCH
}

} // namespace calc
