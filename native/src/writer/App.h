// writer::App. See writer/Helpers.h for the shared includes.
#pragma once

#include "writer/Helpers.h"

namespace writer {

// ---------------------------------------------------------------------------
// Application.
// ---------------------------------------------------------------------------
class App final : public IWriterApp
{
public:
    App();
    LO_COM_IUNKNOWN_AND_DISPATCH(IWriterApp)

    STDMETHODIMP Dispose() override;
    STDMETHODIMP NewDoc(VARIANT_BOOL landscape, float pageHeight, float pageWidth, IWriterDocument** ppDoc) override;
    STDMETHODIMP Open(BSTR filePath, VARIANT_BOOL readOnly, IWriterDocument** ppDoc) override;
    STDMETHODIMP get_ActiveDocument(IWriterDocument** ppDoc) override;

private:
    ~App();
    lo_uno::Session m_session;
    bool m_disposed = false;
    HRESULT OpenInternal(const OUString& url, bool readOnly, IWriterDocument** ppDoc);
};

} // namespace writer
