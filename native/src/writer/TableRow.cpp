// writer::TableRow: implementation.
#include "writer/TableRow.h"
#include "writer/Range.h"
#include "writer/TableCell.h"

namespace writer {

TableRow::TableRow(const Reference<css_text::XTextDocument>& doc,
                           const Reference<css_text::XTextTable>& table, long rowIndex)
    : m_rowIndex(rowIndex), m_doc(doc), m_table(table)
{
}

STDMETHODIMP TableRow::get_Range(IWriterRange** ppVal)
{
    LO_COM_TRY
    long columns = m_table->getColumns()->getCount();
    Reference<css_text::XTextTableCursor> cursor =
        m_table->createCursorByCellName(Ascii("A") + OUString::number(m_rowIndex + 1));
    cursor->goRight((sal_Int16)(columns - 1), true);
    OUString rangeName = cursor->getRangeName();
    return ReturnNew<IWriterRange>(new Range(m_doc, m_table, rangeName), ppVal);
    LO_COM_CATCH
}

STDMETHODIMP TableRow::get_Height(float* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    *pVal = RowHeightPoints(m_table, m_rowIndex);
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP TableRow::put_Height(float value)
{
    LO_COM_TRY
    SetRowHeightPoints(m_table, m_rowIndex, value);
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP TableRow::get_HeightRule(RowHeightRule* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    *pVal = GetProp<bool>(RowProps(m_table, m_rowIndex), "IsAutoHeight") ? Auto : AtLeast;
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP TableRow::put_HeightRule(RowHeightRule value)
{
    LO_COM_TRY
    SetProp<bool>(RowProps(m_table, m_rowIndex), "IsAutoHeight", value == Auto);
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP TableRow::get_AllowSplit(VARIANT_BOOL* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    *pVal = ToVB(GetProp<bool>(RowProps(m_table, m_rowIndex), "IsSplitAllowed"));
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP TableRow::put_AllowSplit(VARIANT_BOOL value)
{
    LO_COM_TRY
    SetProp<bool>(RowProps(m_table, m_rowIndex), "IsSplitAllowed", FromVB(value));
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP TableRow::get_CellCount(long* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    *pVal = (long)m_table->getColumns()->getCount();
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP TableRow::GetCell(long index, IWriterTableCell** ppVal)
{
    LO_COM_TRY
    return ReturnNew<IWriterTableCell>(new TableCell(m_doc, m_table, index, m_rowIndex), ppVal);
    LO_COM_CATCH
}

STDMETHODIMP TableRow::IsRepeatingRow(VARIANT_BOOL* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    Reference<XPropertySet> table(m_table, UNO_QUERY);
    bool repeat = GetProp<bool>(table, "RepeatHeadline");
    long count = (long)GetProp<sal_Int32>(table, "HeaderRowCount");
    *pVal = ToVB(repeat && count > 0 && m_rowIndex < count);
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP TableRow::SetStyle(IWriterStyle* style)
{
    if (!style) return E_POINTER;
    LO_COM_TRY
    BSTR name = nullptr;
    HRESULT hr = style->get_Name(&name);
    if (FAILED(hr)) return hr;
    OUString styleName = ToOUString(name);
    SysFreeString(name);

    long cells = (long)m_table->getColumns()->getCount();
    for (long i = 0; i < cells; ++i)
    {
        Scoped<TableCell, Reference<css_text::XTextDocument>, Reference<css_text::XTextTable>, long, long> cell(
            m_doc, m_table, i, m_rowIndex);
        cell->ApplyStyle(styleName);
    }
    return S_OK;
    LO_COM_CATCH
}

} // namespace writer
