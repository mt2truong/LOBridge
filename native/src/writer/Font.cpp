// writer::Font: implementation.
#include "writer/Font.h"

namespace writer {

Font::Font(const Reference<XPropertySet>& ps) : m_font(ps)
{
    m_valid = m_font.is() && m_font->getPropertySetInfo().is()
              && m_font->getPropertySetInfo()->hasPropertyByName(Ascii("CharFontName"));
}

STDMETHODIMP Font::get_Name(BSTR* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    OUString v = m_valid ? GetProp<OUString>(m_font, "CharFontName") : OUString();
    *pVal = ToBSTR(v);
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP Font::get_Size(float* pVal)
{
    if (!pVal) return E_POINTER;
    *pVal = m_valid ? GetProp<float>(m_font, "CharHeight") : 0.0f;
    return S_OK;
}

STDMETHODIMP Font::put_Size(float value)
{
    if (m_valid) SetProp<float>(m_font, "CharHeight", value);
    return S_OK;
}

STDMETHODIMP Font::get_Bold(long* pVal)
{
    if (!pVal) return E_POINTER;
    *pVal = 0;
    if (!m_valid) return S_OK;
    float w = GetProp<float>(m_font, "CharWeight");
    *pVal = (w == css::awt::FontWeight::BOLD) ? 1 : 0;
    return S_OK;
}

STDMETHODIMP Font::get_Italic(long* pVal)
{
    if (!pVal) return E_POINTER;
    *pVal = 0;
    if (!m_valid) return S_OK;
    css::awt::FontSlant slant = GetProp<css::awt::FontSlant>(m_font, "CharPosture");
    *pVal = (slant == css::awt::FontSlant_ITALIC) ? 1 : 0;
    return S_OK;
}

STDMETHODIMP Font::get_Underline(long* pVal)
{
    if (!pVal) return E_POINTER;
    *pVal = m_valid ? (long)GetProp<sal_Int16>(m_font, "CharUnderline") : 0;
    return S_OK;
}

STDMETHODIMP Font::get_Color(long* pVal)
{
    if (!pVal) return E_POINTER;
    *pVal = 0;
    if (!m_valid) return S_OK;
    long color = (long)GetProp<sal_Int32>(m_font, "CharColor");
    if (color == -1)
        *pVal = (long)0xFF000000u;   // default colour, same as the .NET version
    else
        *pVal = SwapRedBlueBits(color);
    return S_OK;
}

STDMETHODIMP Font::get_Hidden(VARIANT_BOOL* pVal)
{
    if (!pVal) return E_POINTER;
    *pVal = VARIANT_FALSE;
    if (!m_valid) return S_OK;
    *pVal = ToVB(GetProp<bool>(m_font, "CharHidden"));
    return S_OK;
}

STDMETHODIMP Font::put_Hidden(VARIANT_BOOL value)
{
    if (m_valid) SetProp<bool>(m_font, "CharHidden", FromVB(value));
    return S_OK;
}

} // namespace writer
