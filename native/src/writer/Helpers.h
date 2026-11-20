// Shared includes and helper functions for the writer classes (Writer).
#pragma once

#include "Common.h"
#include "Uno.h"
#include "Config.h"
#include "Zip.h"
#include <com/sun/star/awt/FontSlant.hpp>
#include <com/sun/star/awt/FontWeight.hpp>
#include <com/sun/star/awt/Point.hpp>
#include <com/sun/star/awt/Size.hpp>
#include <com/sun/star/beans/XPropertyAccess.hpp>
#include <com/sun/star/beans/XPropertySetInfo.hpp>
#include <com/sun/star/container/XEnumeration.hpp>
#include <com/sun/star/container/XEnumerationAccess.hpp>
#include <com/sun/star/container/XIndexAccess.hpp>
#include <com/sun/star/container/XNameAccess.hpp>
#include <com/sun/star/container/XNameContainer.hpp>
#include <com/sun/star/drawing/XDrawPage.hpp>
#include <com/sun/star/drawing/XDrawPageSupplier.hpp>
#include <com/sun/star/drawing/XShape.hpp>
#include <com/sun/star/frame/XStorable.hpp>
#include <com/sun/star/lang/XMultiServiceFactory.hpp>
#include <com/sun/star/style/BreakType.hpp>
#include <com/sun/star/style/LineSpacing.hpp>
#include <com/sun/star/style/LineSpacingMode.hpp>
#include <com/sun/star/style/ParagraphAdjust.hpp>
#include <com/sun/star/style/TabStop.hpp>
#include <com/sun/star/style/XStyle.hpp>
#include <com/sun/star/style/XStyleFamiliesSupplier.hpp>
#include <com/sun/star/table/XCell.hpp>
#include <com/sun/star/table/XCellRange.hpp>
#include <com/sun/star/table/XTableColumns.hpp>
#include <com/sun/star/table/XTableRows.hpp>
#include <com/sun/star/text/ControlCharacter.hpp>
#include <com/sun/star/text/TableColumnSeparator.hpp>
#include <com/sun/star/text/VertOrientation.hpp>
#include <com/sun/star/text/XPageCursor.hpp>
#include <com/sun/star/text/XText.hpp>
#include <com/sun/star/text/XTextContent.hpp>
#include <com/sun/star/text/XTextCursor.hpp>
#include <com/sun/star/text/XTextDocument.hpp>
#include <com/sun/star/text/XTextFrame.hpp>
#include <com/sun/star/text/XTextRange.hpp>
#include <com/sun/star/text/XTextTable.hpp>
#include <com/sun/star/text/XTextTableCursor.hpp>
#include <com/sun/star/text/XTextTablesSupplier.hpp>
#include <com/sun/star/text/XTextViewCursor.hpp>
#include <com/sun/star/text/XTextViewCursorSupplier.hpp>
#include <com/sun/star/view/DocumentZoomType.hpp>
#include <com/sun/star/view/XViewSettingsSupplier.hpp>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
#include <utility>
#include <vector>

using namespace lo_com;
using namespace lo_uno;
namespace css_text = css::text;

namespace writer {

// ---- small helpers ----------------------------------------------------------

inline long Round(float v) { return (long)std::lround(v); }

inline OUString Ascii(const char* s) { return OUString::createFromAscii(s); }

inline std::wstring ToLowerW(std::wstring s)
{
    for (auto& c : s) c = (wchar_t)towlower(c);
    return s;
}

// Extension without the dot, like Path.GetExtension(...).TrimStart('.').
inline std::wstring ExtensionOf(const std::wstring& path)
{
    size_t dot = path.find_last_of(L'.');
    size_t sep = path.find_last_of(L"\\/");
    if (dot == std::wstring::npos || (sep != std::wstring::npos && dot < sep)) return L"";
    return path.substr(dot + 1);
}

// Port of HelperExtension.GetPaperSizeByPoints.
inline OUString PaperSizeByPoints(float width, float height)
{
    struct Size { const char* name; int w; int h; };
    static const Size sizes[] = {
        { "A3", 842, 1191 }, { "A4", 595, 842 }, { "A5", 420, 595 }, { "Letter", 612, 791 },
        { "Legal", 612, 1009 }, { "Tabloid", 791, 1225 }, { "Ledger", 1225, 791 } };
    for (const auto& s : sizes)
        if (std::fabs(s.w - width) <= 1 && std::fabs(s.h - height) <= 1) return Ascii(s.name);
    for (const auto& s : sizes)
        if (std::fabs(s.h - width) <= 1 && std::fabs(s.w - height) <= 1) return Ascii(s.name);
    return Ascii("Custom");
}

// Reads the (font-) style name of the text at the start of a text object.
inline Reference<XPropertySet> StartProps(const Reference<css_text::XText>& text)
{
    return PS(text->getStart());
}

inline Reference<XPropertySet> RowProps(const Reference<css_text::XTextTable>& t, long index)
{
    Any a = t->getRows()->getByIndex((sal_Int32)index);
    Reference<XPropertySet> p;
    a >>= p;
    return p;
}

inline Reference<XPropertySet> ColumnProps(const Reference<css_text::XTextTable>& t, long index)
{
    Any a = t->getColumns()->getByIndex((sal_Int32)index);
    Reference<XPropertySet> p;
    a >>= p;
    return p;
}

// Row height in points, 9999999 for auto height (same as TableRow.Height in C#).
inline float RowHeightPoints(const Reference<css_text::XTextTable>& t, long index)
{
    Reference<XPropertySet> row = RowProps(t, index);
    if (GetProp<bool>(row, "IsAutoHeight")) return 9999999.0f;
    return ToPoints((float)GetProp<sal_Int32>(row, "Height"));
}

inline void SetRowHeightPoints(const Reference<css_text::XTextTable>& t, long index, float points)
{
    SetProp<sal_Int32>(RowProps(t, index), "Height", Round(ToHundredMillMeter(points)));
}

inline OUString CellNameAt(const Reference<css_text::XTextTable>& t, long column, long row)
{
    Reference<css::table::XCellRange> range(t, UNO_QUERY);
    Reference<css::table::XCell> cell = range->getCellByPosition((sal_Int32)column, (sal_Int32)row);
    return GetProp<OUString>(PS(cell), "CellName");
}

// Creates a COM object on the heap and releases it after use (helper for internal calls).
template <class T, class... Args>
class Scoped
{
public:
    explicit Scoped(Args... args) : m_obj(new T(args...)) {}
    ~Scoped() { m_obj->Release(); }
    T* operator->() const { return m_obj; }
    T* get() const { return m_obj; }
private:
    T* m_obj;
};

} // namespace writer
