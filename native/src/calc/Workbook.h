// calc::Workbook. See calc/Helpers.h for the shared includes.
#pragma once

#include "calc/Helpers.h"

namespace calc {

// ---------------------------------------------------------------------------
// Workbook.
// ---------------------------------------------------------------------------
class Workbook final : public ICalcWorkbook
{
public:
    explicit Workbook(const Reference<css::sheet::XSpreadsheetDocument>& doc);
    LO_COM_IUNKNOWN_AND_DISPATCH(ICalcWorkbook)

    STDMETHODIMP Dispose() override;
    STDMETHODIMP Save() override;
    STDMETHODIMP Close() override;
    STDMETHODIMP get_WorksheetCount(long* pVal) override;
    STDMETHODIMP GetWorksheet(long index, ICalcWorksheet** ppVal) override;

private:
    Reference<css::sheet::XSpreadsheetDocument> m_doc;
};

} // namespace calc
