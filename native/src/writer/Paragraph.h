// writer::Paragraph. See writer/Helpers.h for the shared includes.
#pragma once

#include "writer/Helpers.h"

namespace writer {

// ---------------------------------------------------------------------------
// Paragraph.
// ---------------------------------------------------------------------------
class Paragraph final : public IWriterParagraph
{
public:
    Paragraph(const Reference<css::text::XTextRange>& para);
    LO_COM_IUNKNOWN_AND_DISPATCH(IWriterParagraph)

    STDMETHODIMP get_Text(BSTR* pVal) override;
    STDMETHODIMP put_Text(BSTR value) override;
    STDMETHODIMP GetRawText(BSTR* pVal) override;
    STDMETHODIMP get_Font(IWriterFont** ppVal) override;

private:
    Reference<css::text::XTextRange> m_para;
};

} // namespace writer
