// writer::TableRow. See writer/Helpers.h for the shared includes.
#pragma once

#include "writer/Helpers.h"

namespace writer {

// ---------------------------------------------------------------------------
// Table row / column.
// ---------------------------------------------------------------------------
class TableRow final : public IWriterTableRow
{
public:
    TableRow(const Reference<css::text::XTextDocument>& doc, const Reference<css::text::XTextTable>& table,
                 long rowIndex);
    LO_COM_IUNKNOWN_AND_DISPATCH(IWriterTableRow)

    STDMETHODIMP get_Range(IWriterRange** ppVal) override;
    STDMETHODIMP get_Height(float* pVal) override;
    STDMETHODIMP put_Height(float value) override;
    STDMETHODIMP get_HeightRule(RowHeightRule* pVal) override;
    STDMETHODIMP put_HeightRule(RowHeightRule value) override;
    STDMETHODIMP get_AllowSplit(VARIANT_BOOL* pVal) override;
    STDMETHODIMP put_AllowSplit(VARIANT_BOOL value) override;
    STDMETHODIMP get_CellCount(long* pVal) override;
    STDMETHODIMP GetCell(long index, IWriterTableCell** ppVal) override;
    STDMETHODIMP IsRepeatingRow(VARIANT_BOOL* pVal) override;
    STDMETHODIMP SetStyle(IWriterStyle* style) override;

    long m_rowIndex;

private:
    Reference<css::text::XTextDocument> m_doc;
    Reference<css::text::XTextTable> m_table;
};

} // namespace writer
