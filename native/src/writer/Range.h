// writer::Range. See writer/Helpers.h for the shared includes.
#pragma once

#include "writer/Helpers.h"

namespace writer {

// ---------------------------------------------------------------------------
// Range: a text range inside a table cell (identified by cell name). Port of Word/Range.cs.
// ---------------------------------------------------------------------------
class Range final : public IWriterRange
{
public:
    Range(const Reference<css::text::XTextDocument>& doc, const Reference<css::text::XTextTable>& table,
              const OUString& rangeName);
    LO_COM_IUNKNOWN_AND_DISPATCH(IWriterRange)

    STDMETHODIMP get_PageSetup(IWriterPageSetup** ppVal) override;
    STDMETHODIMP get_LineSpacingMode(long* pVal) override;
    STDMETHODIMP put_LineSpacingMode(long value) override;
    STDMETHODIMP get_LineSpacingHeight(float* pVal) override;
    STDMETHODIMP put_LineSpacingHeight(float value) override;
    STDMETHODIMP get_Start(long* pVal) override;
    STDMETHODIMP put_Start(long value) override;
    STDMETHODIMP get_End(long* pVal) override;
    STDMETHODIMP put_End(long value) override;
    STDMETHODIMP get_SpaceBefore(float* pVal) override;
    STDMETHODIMP put_SpaceBefore(float value) override;
    STDMETHODIMP get_SpaceAfter(float* pVal) override;
    STDMETHODIMP put_SpaceAfter(float value) override;
    STDMETHODIMP get_KeepTogetherNextParagraph(VARIANT_BOOL* pVal) override;
    STDMETHODIMP put_KeepTogetherNextParagraph(VARIANT_BOOL value) override;
    STDMETHODIMP GetRangeHeight(float* pVal) override;
    STDMETHODIMP GetVerticalPositionRelativeToPage(float* pVal) override;
    STDMETHODIMP GetStaticLines(long* pVal) override;
    STDMETHODIMP LinesToPoints(float value, float* pVal) override;

private:
    long CellVerticalAlignment() const;
    void SetCellVerticalAlignment(long value);
    float GetLineHeight() const;

    Reference<css::text::XTextDocument> m_doc;
    Reference<css::text::XText> m_cellText;
    Reference<XPropertySet> m_ps;
    long m_start = 0;
    long m_end = 0;
};

} // namespace writer
