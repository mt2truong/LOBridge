// writer::Shape. See writer/Helpers.h for the shared includes.
#pragma once

#include "writer/Helpers.h"

namespace writer {

// ---------------------------------------------------------------------------
// Shape (text frame / drawing shape).
// ---------------------------------------------------------------------------
class Shape final : public IWriterShape
{
public:
    Shape(const Reference<css::text::XTextDocument>& doc, const Reference<css::drawing::XShape>& shape);
    LO_COM_IUNKNOWN_AND_DISPATCH(IWriterShape)

    STDMETHODIMP get_Width(float* pVal) override;
    STDMETHODIMP put_Width(float value) override;
    STDMETHODIMP get_Height(float* pVal) override;
    STDMETHODIMP put_Height(float value) override;
    STDMETHODIMP get_LeftPosition(float* pVal) override;
    STDMETHODIMP get_TopPosition(float* pVal) override;
    STDMETHODIMP get_ShapeType(BSTR* pVal) override;
    STDMETHODIMP GetAlignment(long* pVal) override;
    STDMETHODIMP GetTextFont(IWriterFont** ppVal) override;
    STDMETHODIMP CopyFrom(IWriterShape* shape) override;
    STDMETHODIMP get_Text(BSTR* pVal) override;
    STDMETHODIMP put_Text(BSTR value) override;
    STDMETHODIMP get_PageSetup(IWriterPageSetup** ppVal) override;

    Reference<css::text::XTextDocument> m_doc;
    Reference<css::drawing::XShape> m_shape;
};

} // namespace writer
