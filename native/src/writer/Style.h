// writer::Style. See writer/Helpers.h for the shared includes.
#pragma once

#include "writer/Helpers.h"

namespace writer {

// ---------------------------------------------------------------------------
// Style (paragraph/character/table/... style).
// ---------------------------------------------------------------------------
class Style final : public IWriterStyle
{
public:
    Style(const Reference<XPropertySet>& style, const OUString& name);
    LO_COM_IUNKNOWN_AND_DISPATCH(IWriterStyle)

    STDMETHODIMP get_Name(BSTR* pVal) override;
    STDMETHODIMP get_Font(IWriterFont** ppVal) override;

    Reference<XPropertySet> m_style;

private:
    OUString m_name;
};

} // namespace writer
