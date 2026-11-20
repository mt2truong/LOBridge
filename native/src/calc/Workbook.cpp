// calc::Workbook: implementation.
#include "calc/Workbook.h"
#include "calc/Worksheet.h"

namespace calc {

Workbook::Workbook(const Reference<css::sheet::XSpreadsheetDocument>& doc) : m_doc(doc) {}

STDMETHODIMP Workbook::Dispose()
{
    return Close();
}

STDMETHODIMP Workbook::Close()
{
    if (!m_doc.is()) return S_OK;
    try
    {
        Reference<css::util::XCloseable> closeable(m_doc, UNO_QUERY);
        if (closeable.is()) closeable->close(false);
    }
    catch (const css::uno::Exception&) {}
    return S_OK;
}

STDMETHODIMP Workbook::Save()
{
    LO_COM_TRY
    Reference<css::frame::XStorable> storable(m_doc, UNO_QUERY);
    if (!storable->hasLocation()) return S_OK;
    storable->store();
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP Workbook::get_WorksheetCount(long* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    *pVal = (long)Reference<css::container::XIndexAccess>(m_doc->getSheets(), UNO_QUERY)->getCount();
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP Workbook::GetWorksheet(long index, ICalcWorksheet** ppVal)
{
    LO_COM_TRY
    Reference<css::sheet::XSpreadsheet> sheet;
    Reference<css::container::XIndexAccess>(m_doc->getSheets(), UNO_QUERY)->getByIndex((sal_Int32)index) >>= sheet;
    return ReturnNew<ICalcWorksheet>(new Worksheet(sheet), ppVal);
    LO_COM_CATCH
}

} // namespace calc
