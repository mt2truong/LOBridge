// writer::PageSetup: implementation.
#include "writer/PageSetup.h"

namespace writer {

PageSetup::PageSetup(const Reference<css_text::XTextDocument>& doc, const OUString& styleName)
{
    Reference<css::container::XNameAccess> families =
        Reference<css::style::XStyleFamiliesSupplier>(doc, UNO_QUERY)->getStyleFamilies();
    Reference<css::container::XNameAccess> pageStyles;
    families->getByName(Ascii("PageStyles")) >>= pageStyles;
    Reference<XPropertySet> style;
    pageStyles->getByName(styleName) >>= style;
    m_pageStyle = style;

    m_width = ToPoints((float)GetProp<sal_Int32>(m_pageStyle, "Width"));
    m_height = ToPoints((float)GetProp<sal_Int32>(m_pageStyle, "Height"));
    m_paperSize = PaperSizeByPoints(m_width, m_height);
}

STDMETHODIMP PageSetup::get_PaperSize(BSTR* pVal)
{
    if (!pVal) return E_POINTER;
    *pVal = ToBSTR(m_paperSize);
    return S_OK;
}

STDMETHODIMP PageSetup::get_PageWidth(float* pVal)
{
    if (!pVal) return E_POINTER;
    *pVal = m_width;
    return S_OK;
}

STDMETHODIMP PageSetup::get_PageHeight(float* pVal)
{
    if (!pVal) return E_POINTER;
    *pVal = m_height;
    return S_OK;
}

void PageSetup::SetPageSize(float widthPt, float heightPt)
{
    m_width = widthPt;
    SetProp<sal_Int32>(m_pageStyle, "Width", Round(ToHundredMillMeter(m_width)));
    m_height = heightPt;
    SetProp<sal_Int32>(m_pageStyle, "Height", Round(ToHundredMillMeter(m_height)));
}

void PageSetup::SetLandscape(bool landscape)
{
    SetProp<bool>(m_pageStyle, "IsLandscape", landscape);
}

#define LO_MARGIN_GET(FN, PROP)                                                        \
    STDMETHODIMP PageSetup::FN(float* pVal)                                        \
    {                                                                                  \
        if (!pVal) return E_POINTER;                                                   \
        *pVal = ToPoints((float)GetProp<sal_Int32>(m_pageStyle, PROP));                \
        return S_OK;                                                                   \
    }
#define LO_MARGIN_PUT(FN, PROP)                                                        \
    STDMETHODIMP PageSetup::FN(float value)                                        \
    {                                                                                  \
        SetProp<sal_Int32>(m_pageStyle, PROP, Round(ToHundredMillMeter(value)));       \
        return S_OK;                                                                   \
    }

LO_MARGIN_GET(get_LeftMargin, "LeftMargin")
LO_MARGIN_PUT(put_LeftMargin, "LeftMargin")
LO_MARGIN_GET(get_RightMargin, "RightMargin")
LO_MARGIN_PUT(put_RightMargin, "RightMargin")
LO_MARGIN_GET(get_TopMargin, "TopMargin")
LO_MARGIN_PUT(put_TopMargin, "TopMargin")
LO_MARGIN_GET(get_BottomMargin, "BottomMargin")
LO_MARGIN_PUT(put_BottomMargin, "BottomMargin")

} // namespace writer
