// calc::Range. See calc/Helpers.h for the shared includes.
#pragma once

#include "calc/Helpers.h"

namespace calc {

// ---------------------------------------------------------------------------
// Range.
// ---------------------------------------------------------------------------
class Range final : public ICalcRange
{
public:
    explicit Range(const Reference<css::table::XCellRange>& range);
    LO_COM_IUNKNOWN_AND_DISPATCH(ICalcRange)

    STDMETHODIMP Dispose() override;
    STDMETHODIMP get_RowCount(long* pVal) override;
    STDMETHODIMP get_ColumnCount(long* pVal) override;
    STDMETHODIMP GetCell(long rowIndex, long columnIndex, ICalcCell** ppVal) override;

private:
    Reference<css::table::XCellRange> m_range;
};

} // namespace calc
