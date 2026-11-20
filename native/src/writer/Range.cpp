// writer::Range: implementation.
#include "writer/Range.h"
#include "writer/PageSetup.h"

namespace writer {

Range::Range(const Reference<css_text::XTextDocument>& doc, const Reference<css_text::XTextTable>& table,
                     const OUString& rangeName)
    : m_doc(doc)
{
    Reference<css::table::XCell> cell = table->getCellByName(rangeName);
    m_cellText = Reference<css_text::XText>(cell, UNO_QUERY);
    m_ps = StartProps(m_cellText);
}

STDMETHODIMP Range::get_PageSetup(IWriterPageSetup** ppVal)
{
    LO_COM_TRY
    OUString styleName = GetProp<OUString>(m_ps, "PageStyleName");
    return ReturnNew<IWriterPageSetup>(new PageSetup(m_doc, styleName), ppVal);
    LO_COM_CATCH
}

STDMETHODIMP Range::get_LineSpacingMode(long* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    css::style::LineSpacing ls = GetProp<css::style::LineSpacing>(m_ps, "ParaLineSpacing");
    *pVal = ls.Mode;
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP Range::put_LineSpacingMode(long value)
{
    LO_COM_TRY
    css::style::LineSpacing ls = GetProp<css::style::LineSpacing>(m_ps, "ParaLineSpacing");
    ls.Mode = (sal_Int16)value;
    SetProp<css::style::LineSpacing>(m_ps, "ParaLineSpacing", ls);
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP Range::get_LineSpacingHeight(float* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    css::style::LineSpacing ls = GetProp<css::style::LineSpacing>(m_ps, "ParaLineSpacing");
    if (ls.Mode == css::style::LineSpacingMode::PROP)
    {
        *pVal = (ls.Height == 100) ? 12.0f : (float)(ls.Height * 12 / 100);
    }
    else
    {
        *pVal = (float)ls.Height;
    }
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP Range::put_LineSpacingHeight(float value)
{
    LO_COM_TRY
    css::style::LineSpacing ls = GetProp<css::style::LineSpacing>(m_ps, "ParaLineSpacing");
    ls.Height = (sal_Int16)Round(value);
    SetProp<css::style::LineSpacing>(m_ps, "ParaLineSpacing", ls);
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP Range::get_Start(long* pVal)
{
    if (!pVal) return E_POINTER;
    *pVal = m_start;
    return S_OK;
}

STDMETHODIMP Range::put_Start(long value)
{
    m_start = value;
    return S_OK;
}

STDMETHODIMP Range::get_End(long* pVal)
{
    if (!pVal) return E_POINTER;
    *pVal = m_end;
    return S_OK;
}

STDMETHODIMP Range::put_End(long value)
{
    m_end = value;
    return S_OK;
}

STDMETHODIMP Range::get_SpaceBefore(float* pVal)
{
    if (!pVal) return E_POINTER;
    *pVal = ToPoints((float)GetProp<sal_Int32>(m_ps, "ParaTopMargin"));
    return S_OK;
}

STDMETHODIMP Range::put_SpaceBefore(float value)
{
    SetProp<sal_Int32>(m_ps, "ParaTopMargin", Round(ToHundredMillMeter(value)));
    return S_OK;
}

STDMETHODIMP Range::get_SpaceAfter(float* pVal)
{
    if (!pVal) return E_POINTER;
    *pVal = ToPoints((float)GetProp<sal_Int32>(m_ps, "ParaBottomMargin"));
    return S_OK;
}

STDMETHODIMP Range::put_SpaceAfter(float value)
{
    SetProp<sal_Int32>(m_ps, "ParaBottomMargin", Round(ToHundredMillMeter(value)));
    return S_OK;
}

STDMETHODIMP Range::get_KeepTogetherNextParagraph(VARIANT_BOOL* pVal)
{
    if (!pVal) return E_POINTER;
    *pVal = ToVB(GetProp<bool>(m_ps, "ParaKeepTogether"));
    return S_OK;
}

STDMETHODIMP Range::put_KeepTogetherNextParagraph(VARIANT_BOOL value)
{
    SetProp<bool>(m_ps, "ParaKeepTogether", FromVB(value));
    return S_OK;
}

// Not implemented in the .NET version either (it threw NotImplementedException).
STDMETHODIMP Range::GetRangeHeight(float* pVal)
{
    if (pVal) *pVal = 0;
    return E_NOTIMPL;
}

long Range::CellVerticalAlignment() const
{
    Reference<XPropertySet> cellProps(m_cellText, UNO_QUERY);
    sal_Int16 v = GetProp<sal_Int16>(cellProps, "VertOrient");
    switch (v)
    {
    case css_text::VertOrientation::CENTER:
    case css_text::VertOrientation::CHAR_CENTER:
    case css_text::VertOrientation::LINE_CENTER:
        return 1;
    case css_text::VertOrientation::BOTTOM:
    case css_text::VertOrientation::CHAR_BOTTOM:
    case css_text::VertOrientation::LINE_BOTTOM:
        return 2;
    default:
        return 0;
    }
}

void Range::SetCellVerticalAlignment(long value)
{
    sal_Int16 v = css_text::VertOrientation::TOP;
    if (value == 1) v = css_text::VertOrientation::CENTER;
    else if (value == 2) v = css_text::VertOrientation::BOTTOM;
    Reference<XPropertySet> cellProps(m_cellText, UNO_QUERY);
    SetProp<sal_Int16>(cellProps, "VertOrient", v);
}

STDMETHODIMP Range::GetVerticalPositionRelativeToPage(float* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    Reference<css_text::XTextViewCursor> viewCursor = Reference<css_text::XTextViewCursorSupplier>(
        m_doc->getCurrentController(), UNO_QUERY)->getViewCursor();

    // Vertical alignment must be TOP to get the right Y coordinate.
    long originalVA = CellVerticalAlignment();
    if (originalVA != 0) SetCellVerticalAlignment(0);

    viewCursor->gotoRange(Reference<css_text::XTextRange>(m_cellText, UNO_QUERY), false);
    css::awt::Point position = viewCursor->getPosition();
    sal_Int16 pageNumber = Reference<css_text::XPageCursor>(viewCursor, UNO_QUERY)->getPage();

    long pageHeightGap = (long)(pageNumber - 1) * GapPageHeight();
    float topCoordinate = ToPoints((float)(position.Y - pageHeightGap));

    // Page style of this range.
    OUString styleName = GetProp<OUString>(m_ps, "PageStyleName");
    Scoped<PageSetup, Reference<css_text::XTextDocument>, OUString> ps(m_doc, styleName);
    float topMargin = 0;
    ps->get_TopMargin(&topMargin);
    float pageHeight = 0;
    ps->get_PageHeight(&pageHeight);

    *pVal = topCoordinate + topMargin - (float)(pageNumber - 1) * pageHeight;

    if (originalVA != 0) SetCellVerticalAlignment(originalVA);
    return S_OK;
    LO_COM_CATCH
}

float Range::GetLineHeight() const
{
    try
    {
        float fontSize = GetProp<float>(m_ps, "CharHeight");
        css::style::LineSpacing ls = GetProp<css::style::LineSpacing>(m_ps, "ParaLineSpacing");
        return fontSize * (ls.Height / 100.0f);
    }
    catch (...)
    {
        return 12.0f;
    }
}

STDMETHODIMP Range::GetStaticLines(long* pVal)
{
    if (!pVal) return E_POINTER;
    *pVal = 1;
    OUString str = m_cellText->getString();
    if (str.isEmpty())
    {
        return S_OK;
    }

    // Estimated lines by counting newline characters (fallback, as in the .NET version).
    long estimate = 1;
    for (sal_Int32 i = 0; i < str.getLength(); ++i)
        if (str[i] == u'\n') ++estimate;

    try
    {
        Reference<css_text::XTextCursor> startCursor = m_cellText->createTextCursor();
        Reference<css_text::XTextCursor> endCursor = m_cellText->createTextCursor();
        startCursor->gotoStart(false);
        endCursor->gotoEnd(false);

        Reference<css_text::XTextViewCursor> viewCursor = Reference<css_text::XTextViewCursorSupplier>(
            m_doc->getCurrentController(), UNO_QUERY)->getViewCursor();

        viewCursor->gotoRange(Reference<css_text::XTextRange>(startCursor, UNO_QUERY), false);
        css::awt::Point startPos = viewCursor->getPosition();
        viewCursor->gotoRange(Reference<css_text::XTextRange>(endCursor, UNO_QUERY), false);
        css::awt::Point endPos = viewCursor->getPosition();

        float lineHeight = GetLineHeight();
        if (lineHeight > 0)
        {
            long verticalDiff = std::labs(endPos.Y - startPos.Y);
            long lines = (long)std::ceil(ToPoints((float)verticalDiff) / lineHeight);
            *pVal = std::max(lines, 1L);
            return S_OK;
        }
    }
    catch (...)
    {
        // Fall through to the estimate.
    }
    *pVal = estimate;
    return S_OK;
}

STDMETHODIMP Range::LinesToPoints(float value, float* pVal)
{
    if (!pVal) return E_POINTER;
    *pVal = value * 12;   // 1 line = 12 points
    return S_OK;
}

} // namespace writer
