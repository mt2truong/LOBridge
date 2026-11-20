// writer::Paragraph: implementation.
#include "writer/Paragraph.h"
#include "writer/Font.h"

namespace writer {

Paragraph::Paragraph(const Reference<css_text::XTextRange>& para) : m_para(para) {}

STDMETHODIMP Paragraph::get_Text(BSTR* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    *pVal = ToBSTR(m_para->getString());
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP Paragraph::put_Text(BSTR value)
{
    LO_COM_TRY
    m_para->setString(ToOUString(value));
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP Paragraph::GetRawText(BSTR* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    *pVal = ToBSTR(m_para->getString());
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP Paragraph::get_Font(IWriterFont** ppVal)
{
    return ReturnNew<IWriterFont>(new Font(PS(m_para)), ppVal);
}

} // namespace writer
