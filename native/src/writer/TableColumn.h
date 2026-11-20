// writer::TableColumn. See writer/Helpers.h for the shared includes.
#pragma once

#include "writer/Helpers.h"

namespace writer {

class TableColumn final : public IWriterTableColumn
{
public:
    TableColumn(const Reference<css::text::XTextDocument>& doc, const Reference<css::text::XTextTable>& table,
                    long columnIndex);
    LO_COM_IUNKNOWN_AND_DISPATCH(IWriterTableColumn)

    STDMETHODIMP get_CellCount(long* pVal) override;
    STDMETHODIMP GetCell(long index, IWriterTableCell** ppVal) override;

private:
    Reference<css::text::XTextDocument> m_doc;
    Reference<css::text::XTextTable> m_table;
    long m_columnIndex;
};

} // namespace writer
