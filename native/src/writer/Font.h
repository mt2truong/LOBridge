// writer::Font. See writer/Helpers.h for the shared includes.
#pragma once

#include "writer/Helpers.h"

namespace writer {

// ---------------------------------------------------------------------------
// Font: wraps the character properties of any text range / style.
// ---------------------------------------------------------------------------
class Font final : public IWriterFont
{
public:
    Font(const Reference<XPropertySet>& ps);
    LO_COM_IUNKNOWN_AND_DISPATCH(IWriterFont)

    STDMETHODIMP get_Name(BSTR* pVal) override;
    STDMETHODIMP get_Size(float* pVal) override;
    STDMETHODIMP put_Size(float value) override;
    STDMETHODIMP get_Bold(long* pVal) override;
    STDMETHODIMP get_Italic(long* pVal) override;
    STDMETHODIMP get_Underline(long* pVal) override;
    STDMETHODIMP get_Color(long* pVal) override;
    STDMETHODIMP get_Hidden(VARIANT_BOOL* pVal) override;
    STDMETHODIMP put_Hidden(VARIANT_BOOL value) override;

private:
    Reference<XPropertySet> m_font;
    bool m_valid = false;
};

} // namespace writer
