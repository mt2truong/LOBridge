// calc::Cell. See calc/Helpers.h for the shared includes.
#pragma once

#include "calc/Helpers.h"

namespace calc {

// ---------------------------------------------------------------------------
// Cell.
// ---------------------------------------------------------------------------
class Cell final : public ICalcCell
{
public:
    explicit Cell(const Reference<css::table::XCell>& cell);
    LO_COM_IUNKNOWN_AND_DISPATCH(ICalcCell)

    STDMETHODIMP Dispose() override;
    STDMETHODIMP get_RowIsHidden(VARIANT_BOOL* pVal) override;
    STDMETHODIMP get_RowHeight(float* pVal) override;
    STDMETHODIMP get_Color(long* pVal) override;
    STDMETHODIMP get_Text(BSTR* pVal) override;
    STDMETHODIMP get_Value(VARIANT* pVal) override;

private:
    Reference<css::table::XCell> m_cell;
};

} // namespace calc
