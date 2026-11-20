// writer::TableColumn: implementation.
#include "writer/TableColumn.h"
#include "writer/TableCell.h"

namespace writer {

TableColumn::TableColumn(const Reference<css_text::XTextDocument>& doc,
                                 const Reference<css_text::XTextTable>& table, long columnIndex)
    : m_doc(doc), m_table(table), m_columnIndex(columnIndex)
{
}

STDMETHODIMP TableColumn::get_CellCount(long* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    *pVal = (long)m_table->getRows()->getCount();
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP TableColumn::GetCell(long index, IWriterTableCell** ppVal)
{
    LO_COM_TRY
    return ReturnNew<IWriterTableCell>(new TableCell(m_doc, m_table, m_columnIndex, index), ppVal);
    LO_COM_CATCH
}

} // namespace writer
