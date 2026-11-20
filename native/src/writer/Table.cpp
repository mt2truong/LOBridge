// writer::Table: implementation.
#include "writer/Table.h"
#include "writer/PageSetup.h"
#include "writer/Range.h"
#include "writer/TableCell.h"
#include "writer/TableRow.h"
#include "writer/TableColumn.h"

namespace writer {

Table::Table(const Reference<css_text::XTextDocument>& doc, const Reference<css_text::XTextTable>& table)
    : m_doc(doc), m_table(table), m_props(table, UNO_QUERY)
{
}

STDMETHODIMP Table::get_AllowAutoFit(VARIANT_BOOL* pVal)
{
    if (!pVal) return E_POINTER;
    *pVal = VARIANT_FALSE;   // LibreOffice has no auto-fit option
    return S_OK;
}

STDMETHODIMP Table::put_AllowAutoFit(VARIANT_BOOL)
{
    return S_OK;
}

STDMETHODIMP Table::get_RowCount(long* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    *pVal = (long)m_table->getRows()->getCount();
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP Table::get_ColumnCount(long* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    *pVal = (long)m_table->getColumns()->getCount();
    return S_OK;
    LO_COM_CATCH
}

#define LO_TABLE_PAD(GET, PUT, PROP)                                                   \
    STDMETHODIMP Table::GET(float* pVal)                                           \
    {                                                                                  \
        if (!pVal) return E_POINTER;                                                   \
        *pVal = ToPoints((float)GetProp<sal_Int32>(m_props, PROP));                    \
        return S_OK;                                                                   \
    }                                                                                  \
    STDMETHODIMP Table::PUT(float value)                                           \
    {                                                                                  \
        SetProp<sal_Int32>(m_props, PROP, Round(ToHundredMillMeter(value)));           \
        return S_OK;                                                                   \
    }

LO_TABLE_PAD(get_LeftPadding, put_LeftPadding, "LeftMargin")
LO_TABLE_PAD(get_TopPadding, put_TopPadding, "TopMargin")
LO_TABLE_PAD(get_BottomPadding, put_BottomPadding, "BottomMargin")
LO_TABLE_PAD(get_RightPadding, put_RightPadding, "RightMargin")

STDMETHODIMP Table::GetRow(long index, IWriterTableRow** ppVal)
{
    LO_COM_TRY
    return ReturnNew<IWriterTableRow>(new TableRow(m_doc, m_table, index), ppVal);
    LO_COM_CATCH
}

STDMETHODIMP Table::GetColumn(long index, IWriterTableColumn** ppVal)
{
    LO_COM_TRY
    return ReturnNew<IWriterTableColumn>(new TableColumn(m_doc, m_table, index), ppVal);
    LO_COM_CATCH
}

STDMETHODIMP Table::Normalize()
{
    LO_COM_TRY
    // Allow the table to split across pages/columns (otherwise it can jump to the next page).
    SetProp<bool>(m_props, "Split", true);

    long rows = (long)m_table->getRows()->getCount();
    long cols = (long)m_table->getColumns()->getCount();
    for (long i = 0; i < rows; ++i)
    {
        // Rows are only prevented from splitting (handled per row).
        SetProp<bool>(RowProps(m_table, i), "IsSplitAllowed", false);

        for (long j = 0; j < cols; ++j)
        {
            OUString cellName = CellNameAt(m_table, j, i);
            Scoped<Range, Reference<css_text::XTextDocument>, Reference<css_text::XTextTable>, OUString> r(
                m_doc, m_table, cellName);
            // PROP line spacing at 100% is the same as "Single" in Word.
            r->put_LineSpacingMode(0);
            r->put_LineSpacingHeight(100);
            r->put_SpaceAfter(0);
            r->put_SpaceBefore(0);
            r->put_KeepTogetherNextParagraph(VARIANT_FALSE);
        }
    }
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP Table::AddRow(IWriterTableRow* rowAfter, IWriterTableRow** ppVal)
{
    LO_COM_TRY
    TableRow* after = dynamic_cast<TableRow*>(rowAfter);
    if (!after) return E_INVALIDARG;
    long afterIndex = after->m_rowIndex;
    m_table->getRows()->insertByIndex((sal_Int32)(afterIndex + 1), 1);
    // Same as the .NET version: returns the row at rowAfter's index.
    return ReturnNew<IWriterTableRow>(new TableRow(m_doc, m_table, afterIndex), ppVal);
    LO_COM_CATCH
}

STDMETHODIMP Table::DeleteRow(IWriterTableRow* row)
{
    LO_COM_TRY
    TableRow* r = dynamic_cast<TableRow*>(row);
    if (!r) return E_INVALIDARG;
    m_table->getRows()->removeByIndex((sal_Int32)r->m_rowIndex, 1);
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP Table::SetTabStops(VARIANT_BOOL* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    *pVal = VARIANT_FALSE;
    if (m_table->getRows()->getCount() < 2 || m_table->getColumns()->getCount() < 1) return S_OK;

    // The tab stops are read from the text of the first content cell (row 1, column 0).
    Reference<css::table::XCell> c = Reference<css::table::XCellRange>(m_table, UNO_QUERY)->getCellByPosition(0, 1);
    Reference<XPropertySet> prop = StartProps(Reference<css_text::XText>(c, UNO_QUERY));

    css::uno::Sequence<css::style::TabStop> stops;
    prop->getPropertyValue(Ascii("ParaTabStops")) >>= stops;
    if (stops.getLength() == 0) return S_OK;

    // distance = left margin of the document ("Standard" page style) + width of the first content cell.
    Scoped<PageSetup, Reference<css_text::XTextDocument>, OUString> ps(m_doc, Ascii("Standard"));
    float distance = 0;
    ps->get_LeftMargin(&distance);
    Scoped<TableCell, Reference<css_text::XTextDocument>, Reference<css_text::XTextTable>, long, long> cell(
        m_doc, m_table, 0, 1);
    float cellWidth = 0;
    cell->get_Width(&cellWidth);
    distance += cellWidth;

    css::style::TabStop newStop = stops[0];
    newStop.Position = (sal_Int32)std::lround(distance);

    css::uno::Sequence<css::style::TabStop> out(stops.getLength() + 1);
    for (sal_Int32 i = 0; i < stops.getLength(); ++i) out[i] = stops[i];
    out[stops.getLength()] = newStop;
    prop->setPropertyValue(Ascii("ParaTabStops"), css::uno::makeAny(out));

    css::uno::Sequence<css::style::TabStop> reread;
    prop->getPropertyValue(Ascii("ParaTabStops")) >>= reread;
    *pVal = ToVB(reread.getLength() > 0);
    return S_OK;
    LO_COM_CATCH
}

} // namespace writer
