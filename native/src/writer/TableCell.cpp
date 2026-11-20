// writer::TableCell: implementation.
#include "writer/TableCell.h"
#include "writer/Font.h"
#include "writer/PageSetup.h"
#include "writer/Style.h"
#include "writer/Range.h"

namespace writer {

TableCell::TableCell(const Reference<css_text::XTextDocument>& doc,
                             const Reference<css_text::XTextTable>& table, long columnIndex, long rowIndex)
    : m_doc(doc), m_table(table), m_columnIndex(columnIndex), m_rowIndex(rowIndex)
{
    Reference<css::table::XCellRange> range(table, UNO_QUERY);
    m_cell = range->getCellByPosition((sal_Int32)columnIndex, (sal_Int32)rowIndex);
    m_text = Reference<css_text::XText>(m_cell, UNO_QUERY);
}

STDMETHODIMP TableCell::get_Text(BSTR* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    // The .NET version appended "\r\a" (the end-of-cell mark of Word).
    *pVal = ToBSTR(m_text->getString() + OUString::createFromAscii("\r\a"));
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP TableCell::put_Text(BSTR value)
{
    LO_COM_TRY
    std::basic_string<sal_Unicode> s = ToU16(ToOUString(value));
    std::basic_string<sal_Unicode> out;
    for (size_t i = 0; i < s.size(); ++i)
    {
        if (s[i] == u'\r' && i + 1 < s.size() && s[i + 1] == u'\a') { ++i; continue; }
        out.push_back(s[i]);
    }
    m_text->setString(FromU16(out));
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP TableCell::get_Style(IWriterStyle** ppVal)
{
    LO_COM_TRY
    Reference<XPropertySet> textRange = PS(StartProps(m_text));
    OUString styleName = GetProp<OUString>(textRange, "CharStyleName");
    return ReturnNew<IWriterStyle>(new Style(textRange, styleName), ppVal);
    LO_COM_CATCH
}

STDMETHODIMP TableCell::get_Range(IWriterRange** ppVal)
{
    LO_COM_TRY
    OUString cellName = GetProp<OUString>(PS(m_cell), "CellName");
    return ReturnNew<IWriterRange>(new Range(m_doc, m_table, cellName), ppVal);
    LO_COM_CATCH
}

STDMETHODIMP TableCell::get_Font(IWriterFont** ppVal)
{
    LO_COM_TRY
    return ReturnNew<IWriterFont>(new Font(PS(StartProps(m_text))), ppVal);
    LO_COM_CATCH
}

STDMETHODIMP TableCell::get_VerticalAlignment(long* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    sal_Int16 v = GetProp<sal_Int16>(PS(m_cell), "VertOrient");
    switch (v)
    {
    case css_text::VertOrientation::CENTER:
    case css_text::VertOrientation::CHAR_CENTER:
    case css_text::VertOrientation::LINE_CENTER:
        *pVal = 1; break;
    case css_text::VertOrientation::BOTTOM:
    case css_text::VertOrientation::CHAR_BOTTOM:
    case css_text::VertOrientation::LINE_BOTTOM:
        *pVal = 2; break;
    default:
        *pVal = 0; break;
    }
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP TableCell::put_VerticalAlignment(long value)
{
    LO_COM_TRY
    sal_Int16 v = css_text::VertOrientation::TOP;
    if (value == 1) v = css_text::VertOrientation::CENTER;
    else if (value == 2) v = css_text::VertOrientation::BOTTOM;
    SetProp<sal_Int16>(PS(m_cell), "VertOrient", v);
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP TableCell::get_HorizontalAlignment(long* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    sal_Int16 adjust = GetProp<sal_Int16>(StartProps(m_text), "ParaAdjust");
    if (adjust == (sal_Int16)css::style::ParagraphAdjust_CENTER) *pVal = 1;
    else if (adjust == (sal_Int16)css::style::ParagraphAdjust_RIGHT) *pVal = 2;
    else if (adjust == (sal_Int16)css::style::ParagraphAdjust_STRETCH
          || adjust == (sal_Int16)css::style::ParagraphAdjust_BLOCK) *pVal = 3;
    else *pVal = 0;
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP TableCell::put_HorizontalAlignment(long value)
{
    LO_COM_TRY
    sal_Int16 adjust = (sal_Int16)css::style::ParagraphAdjust_LEFT;
    if (value == 1) adjust = (sal_Int16)css::style::ParagraphAdjust_CENTER;
    else if (value == 2) adjust = (sal_Int16)css::style::ParagraphAdjust_RIGHT;
    else if (value == 3) adjust = (sal_Int16)css::style::ParagraphAdjust_STRETCH;
    SetProp<sal_Int16>(StartProps(m_text), "ParaAdjust", adjust);
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP TableCell::get_Width(float* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    Reference<XPropertySet> table(m_table, UNO_QUERY);
    long width = (long)GetProp<sal_Int32>(table, "Width");
    long relativeWidth = (long)GetProp<sal_Int32>(table, "TableColumnRelativeSum");
    css::uno::Sequence<css_text::TableColumnSeparator> separators;
    table->getPropertyValue(Ascii("TableColumnSeparators")) >>= separators;

    long count = separators.getLength();
    long startPosition = m_columnIndex == 0 ? 0 : (long)separators[m_columnIndex - 1].Position;
    long endPosition = m_columnIndex == count ? relativeWidth : (long)separators[m_columnIndex].Position;
    if (relativeWidth == 0)
    {
        *pVal = 0;
        return S_OK;
    }
    long realWidth = width * (endPosition - startPosition) / relativeWidth;
    *pVal = ToPoints((float)realWidth);
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP TableCell::put_Width(float)
{
    // Not implemented in the .NET version.
    return S_OK;
}

STDMETHODIMP TableCell::get_Height(float* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    *pVal = RowHeightPoints(m_table, m_rowIndex);
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP TableCell::put_Height(float value)
{
    LO_COM_TRY
    SetRowHeightPoints(m_table, m_rowIndex, value);
    return S_OK;
    LO_COM_CATCH
}

#define LO_CELL_PAD(GET, PUT, PROP)                                                    \
    STDMETHODIMP TableCell::GET(float* pVal)                                       \
    {                                                                                  \
        if (!pVal) return E_POINTER;                                                   \
        *pVal = ToPoints((float)GetProp<sal_Int32>(PS(m_cell), PROP));                 \
        return S_OK;                                                                   \
    }                                                                                  \
    STDMETHODIMP TableCell::PUT(float value)                                       \
    {                                                                                  \
        SetProp<sal_Int32>(PS(m_cell), PROP, Round(ToHundredMillMeter(value)));        \
        return S_OK;                                                                   \
    }

LO_CELL_PAD(get_RightPadding, put_RightPadding, "RightBorderDistance")
LO_CELL_PAD(get_LeftPadding, put_LeftPadding, "LeftBorderDistance")
LO_CELL_PAD(get_TopPadding, put_TopPadding, "TopBorderDistance")
LO_CELL_PAD(get_BottomPadding, put_BottomPadding, "BottomBorderDistance")

STDMETHODIMP TableCell::GetActiveEndPageNumber(long* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    Reference<css_text::XTextViewCursor> viewCursor = Reference<css_text::XTextViewCursorSupplier>(
        m_doc->getCurrentController(), UNO_QUERY)->getViewCursor();
    viewCursor->gotoRange(Reference<css_text::XTextRange>(m_text, UNO_QUERY), false);
    *pVal = Reference<css_text::XPageCursor>(viewCursor, UNO_QUERY)->getPage();
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP TableCell::ScrollIntoView(VARIANT_BOOL)
{
    // Not implemented in the .NET version.
    return S_OK;
}

STDMETHODIMP TableCell::GetFirstColLeftDistance(double* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    long origAlign = 0;
    get_HorizontalAlignment(&origAlign);
    bool changed = false;
    if (origAlign != 0)
    {
        put_HorizontalAlignment(0);
        changed = true;
    }

    Reference<css_text::XTextViewCursor> viewCursor = Reference<css_text::XTextViewCursorSupplier>(
        m_doc->getCurrentController(), UNO_QUERY)->getViewCursor();
    Reference<css_text::XTextCursor> cellCursor = m_text->createTextCursor();
    cellCursor->gotoStart(false);
    viewCursor->gotoRange(Reference<css_text::XTextRange>(cellCursor, UNO_QUERY), false);
    float x = ToPoints((float)viewCursor->getPosition().X);

    // + the left margin of the page style of this cell's range.
    Reference<XPropertySet> rangeProps = StartProps(m_text);
    OUString styleName = GetProp<OUString>(rangeProps, "PageStyleName");
    Scoped<PageSetup, Reference<css_text::XTextDocument>, OUString> ps(m_doc, styleName);
    float leftMargin = 0;
    ps->get_LeftMargin(&leftMargin);

    *pVal = (double)(x + leftMargin);

    if (changed) put_HorizontalAlignment(origAlign);
    return S_OK;
    LO_COM_CATCH
}

// Internal: applies a paragraph/character style by name to the cell text (TableCell.Style setter in .NET).
void TableCell::ApplyStyle(const OUString& styleName)
{
    SetProp<OUString>(StartProps(m_text), "CharStyleName", styleName);
}

} // namespace writer
