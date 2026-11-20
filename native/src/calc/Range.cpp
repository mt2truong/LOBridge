// calc::Range: implementation.
#include "calc/Range.h"
#include "calc/Cell.h"

namespace calc {

Range::Range(const Reference<css::table::XCellRange>& range) : m_range(range) {}

STDMETHODIMP Range::Dispose()
{
    m_range.clear();
    return S_OK;
}

STDMETHODIMP Range::get_RowCount(long* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    *pVal = (long)Reference<css::table::XColumnRowRange>(m_range, UNO_QUERY)->getRows()->getCount();
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP Range::get_ColumnCount(long* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    *pVal = (long)Reference<css::table::XColumnRowRange>(m_range, UNO_QUERY)->getColumns()->getCount();
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP Range::GetCell(long rowIndex, long columnIndex, ICalcCell** ppVal)
{
    LO_COM_TRY
    Reference<css::table::XCell> cell = m_range->getCellByPosition((sal_Int32)columnIndex, (sal_Int32)rowIndex);
    return ReturnNew<ICalcCell>(new Cell(cell), ppVal);
    LO_COM_CATCH
}

} // namespace calc
