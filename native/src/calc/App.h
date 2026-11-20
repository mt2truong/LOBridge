// calc::App. See calc/Helpers.h for the shared includes.
#pragma once

#include "calc/Helpers.h"

namespace calc {

// ---------------------------------------------------------------------------
// Application.
// ---------------------------------------------------------------------------
class App final : public ICalcApp
{
public:
    App();
    LO_COM_IUNKNOWN_AND_DISPATCH(ICalcApp)

    STDMETHODIMP Dispose() override;
    STDMETHODIMP Open(BSTR filePath, VARIANT_BOOL readOnly, ICalcWorkbook** ppVal) override;

private:
    ~App();
    lo_uno::Session m_session;
    bool m_disposed = false;
};

} // namespace calc
