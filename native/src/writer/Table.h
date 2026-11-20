// writer::Table. See writer/Helpers.h for the shared includes.
#pragma once

#include "writer/Helpers.h"

namespace writer {

// ---------------------------------------------------------------------------
// Table.
// ---------------------------------------------------------------------------
class Table final : public IWriterTable
{
public:
    Table(const Reference<css::text::XTextDocument>& doc, const Reference<css::text::XTextTable>& table);
    LO_COM_IUNKNOWN_AND_DISPATCH(IWriterTable)

    STDMETHODIMP get_AllowAutoFit(VARIANT_BOOL* pVal) override;
    STDMETHODIMP put_AllowAutoFit(VARIANT_BOOL value) override;
    STDMETHODIMP get_RowCount(long* pVal) override;
    STDMETHODIMP get_ColumnCount(long* pVal) override;
    STDMETHODIMP get_LeftPadding(float* pVal) override;
    STDMETHODIMP put_LeftPadding(float value) override;
    STDMETHODIMP get_TopPadding(float* pVal) override;
    STDMETHODIMP put_TopPadding(float value) override;
    STDMETHODIMP get_BottomPadding(float* pVal) override;
    STDMETHODIMP put_BottomPadding(float value) override;
    STDMETHODIMP get_RightPadding(float* pVal) override;
    STDMETHODIMP put_RightPadding(float value) override;
    STDMETHODIMP GetRow(long index, IWriterTableRow** ppVal) override;
    STDMETHODIMP GetColumn(long index, IWriterTableColumn** ppVal) override;
    STDMETHODIMP Normalize() override;
    STDMETHODIMP AddRow(IWriterTableRow* rowAfter, IWriterTableRow** ppVal) override;
    STDMETHODIMP DeleteRow(IWriterTableRow* row) override;
    STDMETHODIMP SetTabStops(VARIANT_BOOL* pVal) override;

    Reference<css::text::XTextDocument> m_doc;
    Reference<css::text::XTextTable> m_table;
    Reference<XPropertySet> m_props;
};

} // namespace writer
