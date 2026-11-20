// calc::Worksheet: implementation.
#include "calc/Worksheet.h"
#include "calc/Range.h"

namespace calc {

Worksheet::Worksheet(const Reference<css::sheet::XSpreadsheet>& sheet) : m_sheet(sheet) {}

STDMETHODIMP Worksheet::Dispose()
{
    m_sheet.clear();
    return S_OK;
}

STDMETHODIMP Worksheet::get_UsedRange(ICalcRange** ppVal)
{
    LO_COM_TRY
    Reference<css::sheet::XUsedAreaCursor> cursor(m_sheet->createCursor(), UNO_QUERY);
    cursor->gotoEndOfUsedArea(false);
    cursor->gotoStartOfUsedArea(true);
    Reference<css::table::XCellRange> used(cursor, UNO_QUERY);
    return ReturnNew<ICalcRange>(new Range(used), ppVal);
    LO_COM_CATCH
}

STDMETHODIMP Worksheet::get_Name(BSTR* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    *pVal = ToBSTR(Reference<css::container::XNamed>(m_sheet, UNO_QUERY)->getName());
    return S_OK;
    LO_COM_CATCH
}

} // namespace calc
