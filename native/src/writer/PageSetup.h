// writer::PageSetup. See writer/Helpers.h for the shared includes.
#pragma once

#include "writer/Helpers.h"

namespace writer {

class App;

// ---------------------------------------------------------------------------
// Page setup of a page style ("Standard", or the style of a range/shape).
// ---------------------------------------------------------------------------
class PageSetup final : public IWriterPageSetup
{
public:
    PageSetup(const Reference<css::text::XTextDocument>& doc, const OUString& styleName);
    LO_COM_IUNKNOWN_AND_DISPATCH(IWriterPageSetup)

    STDMETHODIMP get_PaperSize(BSTR* pVal) override;
    STDMETHODIMP get_PageWidth(float* pVal) override;
    STDMETHODIMP get_PageHeight(float* pVal) override;
    STDMETHODIMP get_LeftMargin(float* pVal) override;
    STDMETHODIMP put_LeftMargin(float value) override;
    STDMETHODIMP get_RightMargin(float* pVal) override;
    STDMETHODIMP put_RightMargin(float value) override;
    STDMETHODIMP get_TopMargin(float* pVal) override;
    STDMETHODIMP put_TopMargin(float value) override;
    STDMETHODIMP get_BottomMargin(float* pVal) override;
    STDMETHODIMP put_BottomMargin(float value) override;

    // Not part of the COM interface: used by App::NewDoc.
    void SetPageSize(float widthPt, float heightPt);
    void SetLandscape(bool landscape);

private:
    Reference<XPropertySet> m_pageStyle;
    float m_width = 0;   // points
    float m_height = 0;  // points
    OUString m_paperSize;
};

} // namespace writer
