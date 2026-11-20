// writer::TableCell. See writer/Helpers.h for the shared includes.
#pragma once

#include "writer/Helpers.h"

namespace writer {

// ---------------------------------------------------------------------------
// Table cell.
// ---------------------------------------------------------------------------
class TableCell final : public IWriterTableCell
{
public:
    TableCell(const Reference<css::text::XTextDocument>& doc, const Reference<css::text::XTextTable>& table,
                  long columnIndex, long rowIndex);
    LO_COM_IUNKNOWN_AND_DISPATCH(IWriterTableCell)

    STDMETHODIMP get_Style(IWriterStyle** ppVal) override;
    STDMETHODIMP get_Range(IWriterRange** ppVal) override;
    STDMETHODIMP get_Text(BSTR* pVal) override;
    STDMETHODIMP put_Text(BSTR value) override;
    STDMETHODIMP get_Font(IWriterFont** ppVal) override;
    STDMETHODIMP get_VerticalAlignment(long* pVal) override;
    STDMETHODIMP put_VerticalAlignment(long value) override;
    STDMETHODIMP get_HorizontalAlignment(long* pVal) override;
    STDMETHODIMP put_HorizontalAlignment(long value) override;
    STDMETHODIMP get_Width(float* pVal) override;
    STDMETHODIMP put_Width(float value) override;
    STDMETHODIMP get_Height(float* pVal) override;
    STDMETHODIMP put_Height(float value) override;
    STDMETHODIMP get_RightPadding(float* pVal) override;
    STDMETHODIMP put_RightPadding(float value) override;
    STDMETHODIMP get_LeftPadding(float* pVal) override;
    STDMETHODIMP put_LeftPadding(float value) override;
    STDMETHODIMP get_TopPadding(float* pVal) override;
    STDMETHODIMP put_TopPadding(float value) override;
    STDMETHODIMP get_BottomPadding(float* pVal) override;
    STDMETHODIMP put_BottomPadding(float value) override;
    STDMETHODIMP GetActiveEndPageNumber(long* pVal) override;
    STDMETHODIMP ScrollIntoView(VARIANT_BOOL option) override;
    STDMETHODIMP GetFirstColLeftDistance(double* pVal) override;

    // Internal (TableCell.Style setter in the .NET version).
    void ApplyStyle(const OUString& styleName);

private:
    Reference<css::text::XTextDocument> m_doc;
    Reference<css::text::XTextTable> m_table;
    Reference<css::table::XCell> m_cell;
    Reference<css::text::XText> m_text;
    long m_columnIndex;
    long m_rowIndex;
};

} // namespace writer
