// writer::Shape: implementation.
#include "writer/Shape.h"
#include "writer/Font.h"
#include "writer/PageSetup.h"

namespace writer {

Shape::Shape(const Reference<css_text::XTextDocument>& doc, const Reference<css::drawing::XShape>& shape)
    : m_doc(doc), m_shape(shape)
{
}

STDMETHODIMP Shape::get_Width(float* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    *pVal = ToPoints((float)m_shape->getSize().Width);
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP Shape::put_Width(float value)
{
    LO_COM_TRY
    css::awt::Size size = m_shape->getSize();
    size.Width = (sal_Int32)Round(ToHundredMillMeter(value));
    m_shape->setSize(size);
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP Shape::get_Height(float* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    *pVal = ToPoints((float)m_shape->getSize().Height);
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP Shape::put_Height(float value)
{
    LO_COM_TRY
    css::awt::Size size = m_shape->getSize();
    size.Height = (sal_Int32)Round(ToHundredMillMeter(value));
    m_shape->setSize(size);
    return S_OK;
    LO_COM_CATCH
}

// The .NET version multiplied by 10000 here; kept for compatibility.
STDMETHODIMP Shape::get_LeftPosition(float* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    *pVal = ToPoints((float)m_shape->getPosition().X) * 10000.0f;
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP Shape::get_TopPosition(float* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    *pVal = ToPoints((float)m_shape->getPosition().Y) * 10000.0f;
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP Shape::get_ShapeType(BSTR* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    *pVal = ToBSTR(m_shape->getShapeType());
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP Shape::GetAlignment(long* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    *pVal = 0;
    Reference<css_text::XText> text(m_shape, UNO_QUERY);
    if (!text.is()) return S_OK;
    sal_Int16 adjust = GetProp<sal_Int16>(StartProps(text), "ParaAdjust");
    if (adjust == (sal_Int16)css::style::ParagraphAdjust_CENTER) *pVal = 1;
    else if (adjust == (sal_Int16)css::style::ParagraphAdjust_RIGHT) *pVal = 2;
    else if (adjust == (sal_Int16)css::style::ParagraphAdjust_BLOCK
          || adjust == (sal_Int16)css::style::ParagraphAdjust_STRETCH) *pVal = 3;
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP Shape::GetTextFont(IWriterFont** ppVal)
{
    if (!ppVal) return E_POINTER;
    LO_COM_TRY
    Reference<XPropertySet> ps(m_shape, UNO_QUERY);
    if (!ps.is())
    {
        *ppVal = nullptr;
        return S_OK;
    }
    return ReturnNew<IWriterFont>(new Font(ps), ppVal);
    LO_COM_CATCH
}

STDMETHODIMP Shape::CopyFrom(IWriterShape* src)
{
    if (!src) return E_POINTER;
    LO_COM_TRY
    Shape* srcShape = dynamic_cast<Shape*>(src);
    if (!srcShape) return E_INVALIDARG;

    float w = 0, h = 0;
    srcShape->get_Width(&w);
    srcShape->get_Height(&h);
    put_Width(w);
    put_Height(h);

    Reference<XPropertySet> from(srcShape->m_shape, UNO_QUERY);
    Reference<XPropertySet> to(m_shape, UNO_QUERY);
    css::uno::Sequence<css::beans::Property> props = from->getPropertySetInfo()->getProperties();
    for (sal_Int32 i = 0; i < props.getLength(); ++i)
    {
        try
        {
            to->setPropertyValue(props[i].Name, from->getPropertyValue(props[i].Name));
        }
        catch (const css::uno::Exception&)
        {
            // Some properties are read-only; skip them as the .NET version did.
        }
    }
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP Shape::get_Text(BSTR* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    Reference<css_text::XText> text(m_shape, UNO_QUERY);
    if (!text.is()) return E_FAIL;
    *pVal = ToBSTR(text->getString());
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP Shape::put_Text(BSTR value)
{
    LO_COM_TRY
    Reference<css_text::XText> text(m_shape, UNO_QUERY);
    if (!text.is()) return E_FAIL;
    text->setString(ToOUString(value));
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP Shape::get_PageSetup(IWriterPageSetup** ppVal)
{
    LO_COM_TRY
    OUString styleName = GetProp<OUString>(Reference<XPropertySet>(m_shape, UNO_QUERY), "PageStyleName");
    return ReturnNew<IWriterPageSetup>(new PageSetup(m_doc, styleName), ppVal);
    LO_COM_CATCH
}

} // namespace writer
