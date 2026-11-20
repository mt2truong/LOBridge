// calc::Cell: implementation.
#include "calc/Cell.h"

namespace calc {

Cell::Cell(const Reference<css::table::XCell>& cell) : m_cell(cell) {}

STDMETHODIMP Cell::Dispose()
{
    m_cell.clear();
    return S_OK;
}

STDMETHODIMP Cell::get_RowIsHidden(VARIANT_BOOL* pVal)
{
    if (!pVal) return E_POINTER;
    *pVal = VARIANT_FALSE;
    LO_COM_TRY
    // The row of this cell: hidden when it is not visible and has (almost) no height.
    Any rowAny = Reference<css::container::XIndexAccess>(
        Reference<css::table::XColumnRowRange>(m_cell, UNO_QUERY)->getRows(), UNO_QUERY)->getByIndex(0);
    Reference<css::table::XCellRange> row;
    rowAny >>= row;
    Reference<XPropertySet> props(row, UNO_QUERY);
    if (!props.is()) return S_OK;

    double height = (double)GetProp<sal_Int32>(props, "Height");
    if (props->getPropertySetInfo()->hasPropertyByName(OUString::createFromAscii("IsVisible")))
    {
        bool isVisible = GetProp<bool>(props, "IsVisible");
        *pVal = ToVB(!isVisible && height < 1.0);
    }
    else
    {
        // IsVisible is not supported: use the height only.
        *pVal = ToVB(height < 1.0);
    }
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP Cell::get_RowHeight(float* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    css::awt::Size size = GetProp<css::awt::Size>(PS(m_cell), "Size");
    *pVal = ToPoints((float)size.Height);   // height is in 1/100 mm
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP Cell::get_Color(long* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    long c = (long)GetProp<sal_Int32>(PS(m_cell), "CellBackColor");
    // Same channel extraction as System.Drawing.Color.FromArgb((c >> 16) & 0xff, (c >> 8) & 0xff, c & 0xff).
    unsigned int r = ((unsigned int)c >> 16) & 0xff;
    unsigned int g = ((unsigned int)c >> 8) & 0xff;
    unsigned int b = (unsigned int)c & 0xff;
    *pVal = (long)(0xFF000000u | (r << 16) | (g << 8) | b);   // ARGB, alpha 255
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP Cell::get_Text(BSTR* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    VARIANT v;
    VariantInit(&v);
    HRESULT hr = get_Value(&v);
    if (FAILED(hr)) return hr;
    OUString text;
    if (v.vt == VT_R8) text = OUString::createFromAscii(DoubleToText(v.dblVal).c_str());
    else if (v.vt == VT_BSTR) text = ToOUString(v.bstrVal);
    VariantClear(&v);
    *pVal = ToBSTR(text);
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP Cell::get_Value(VARIANT* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    VariantInit(pVal);
    css::table::CellContentType type = m_cell->getType();
    switch (type)
    {
    case css::table::CellContentType_VALUE:
        pVal->vt = VT_R8;
        pVal->dblVal = m_cell->getValue();
        break;
    case css::table::CellContentType_TEXT:
        // XText.getString(): getFormula() can return "'0001" instead of "0001".
        pVal->vt = VT_BSTR;
        pVal->bstrVal = ToBSTR(Reference<css::text::XText>(m_cell, UNO_QUERY)->getString());
        break;
    case css::table::CellContentType_FORMULA:
        pVal->vt = VT_BSTR;
        pVal->bstrVal = ToBSTR(m_cell->getFormula());
        break;
    default:
        pVal->vt = VT_EMPTY;
        break;
    }
    return S_OK;
    LO_COM_CATCH
}

} // namespace calc
