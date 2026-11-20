// calc::Worksheet. See calc/Helpers.h for the shared includes.
#pragma once

#include "calc/Helpers.h"

namespace calc {

// ---------------------------------------------------------------------------
// Worksheet.
// ---------------------------------------------------------------------------
class Worksheet final : public ICalcWorksheet
{
public:
    explicit Worksheet(const Reference<css::sheet::XSpreadsheet>& sheet);
    LO_COM_IUNKNOWN_AND_DISPATCH(ICalcWorksheet)

    STDMETHODIMP Dispose() override;
    STDMETHODIMP get_UsedRange(ICalcRange** ppVal) override;
    STDMETHODIMP get_Name(BSTR* pVal) override;

private:
    Reference<css::sheet::XSpreadsheet> m_sheet;
};

} // namespace calc
