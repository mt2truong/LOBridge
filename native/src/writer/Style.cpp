// writer::Style: implementation.
#include "writer/Style.h"
#include "writer/Font.h"

namespace writer {

Style::Style(const Reference<XPropertySet>& style, const OUString& name)
    : m_style(style), m_name(name) {}

STDMETHODIMP Style::get_Name(BSTR* pVal)
{
    if (!pVal) return E_POINTER;
    *pVal = ToBSTR(m_name);
    return S_OK;
}

STDMETHODIMP Style::get_Font(IWriterFont** ppVal)
{
    return ReturnNew<IWriterFont>(new Font(m_style), ppVal);
}

} // namespace writer
