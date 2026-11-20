// UNO helpers shared by the Word and Excel implementations.
// Mirrors the static helpers of the .NET LibreOffice library (ToUrl, unit conversions, property access).
#pragma once

#include "Common.h"

#include <com/sun/star/uno/XComponentContext.hpp>
#include <com/sun/star/uno/Reference.hxx>
#include <com/sun/star/uno/Any.hxx>
#include <com/sun/star/uno/Sequence.hxx>
#include <com/sun/star/lang/XMultiComponentFactory.hpp>
#include <com/sun/star/lang/XComponent.hpp>
#include <com/sun/star/beans/XPropertySet.hpp>
#include <com/sun/star/beans/PropertyValue.hpp>
#include <com/sun/star/frame/XDesktop.hpp>
#include <com/sun/star/frame/XComponentLoader.hpp>
#include <com/sun/star/frame/Desktop.hpp>
#include <com/sun/star/util/XCloseable.hpp>
#include <com/sun/star/frame/XStorable.hpp>
#include <com/sun/star/container/XNameAccess.hpp>
#include <com/sun/star/container/XIndexAccess.hpp>
#include <com/sun/star/container/XEnumeration.hpp>
#include <com/sun/star/container/XEnumerationAccess.hpp>
#include <cppuhelper/bootstrap.hxx>

#include <cmath>
#include <initializer_list>
#include <string>

namespace css = ::com::sun::star;
using css::uno::Reference;
using css::uno::XInterface;
using css::uno::UNO_QUERY;
using css::uno::Any;
using css::beans::XPropertySet;
using rtl::OUString;

namespace lo_uno {

// Converts a Windows path into a file:/// URL the way the .NET helper did (ToUrl).
inline OUString ToUrl(const OUString& path)
{
    return OUString::createFromAscii("file:///") + path.replace(u'\\', u'/');
}

// Converts 1/100 mm to points and points to 1/100 mm (same formulas as HelperExtension.cs).
inline float ToPoints(float hmm) { return (float)(hmm / 100.0 * (72.0 / 25.4)); }
inline float ToHundredMillMeter(float pt) { return (float)(pt * 100.0 / (72.0 / 25.4)); }

// Swaps the red and blue channels of a 0xAARRGGBB value (LibreOffice stores BGR).
inline long SwapRedBlueBits(long src)
{
    unsigned int v = (unsigned int)src;
    v = (v & 0xFF000000u) | ((v & 0x00FF0000u) >> 16) | (v & 0x0000FF00u) | ((v & 0x000000FFu) << 16);
    return (long)v;
}

template <class T>
Reference<XPropertySet> PS(const Reference<T>& x)
{
    return Reference<XPropertySet>(x, UNO_QUERY);
}

// Converts between std::basic_string<sal_Unicode> and OUString (used for character-level edits).
inline std::basic_string<sal_Unicode> ToU16(const OUString& s) { return std::basic_string<sal_Unicode>(s.getStr(), (size_t)s.getLength()); }
inline OUString FromU16(const std::basic_string<sal_Unicode>& s) { return OUString(s.data(), (sal_Int32)s.size()); }

// Reads a property. Returns T() when the property does not exist.
template <class T>
T GetProp(const Reference<XPropertySet>& ps, const char* name)
{
    T value{};
    if (!ps.is()) return value;
    try
    {
        Any a = ps->getPropertyValue(OUString::createFromAscii(name));
        a >>= value;
    }
    catch (const css::uno::Exception&) {}
    return value;
}

// Writes a property. Exceptions are swallowed, as the .NET setters did.
template <class T>
void SetProp(const Reference<XPropertySet>& ps, const char* name, const T& value)
{
    if (!ps.is()) return;
    try
    {
        ps->setPropertyValue(OUString::createFromAscii(name), css::uno::makeAny(value));
    }
    catch (const css::uno::Exception&) {}
}

inline css::beans::PropertyValue MakeProp(const char* name, const Any& value)
{
    css::beans::PropertyValue p;
    p.Name = OUString::createFromAscii(name);
    p.Handle = -1;
    p.Value = value;
    p.State = css::beans::PropertyState_DIRECT_VALUE;
    return p;
}

// Builds a PropertyValue sequence from a braced list (Sequence has no initializer-list constructor).
inline css::uno::Sequence<css::beans::PropertyValue> MakeProps(std::initializer_list<css::beans::PropertyValue> list)
{
    css::uno::Sequence<css::beans::PropertyValue> s((sal_Int32)list.size());
    sal_Int32 i = 0;
    for (const auto& p : list) s[i++] = p;
    return s;
}

// Directory of the LibreOffice installation (contains soffice.exe, fundamental.ini, the UNO runtime).
std::wstring LibreOfficeProgramDir();

// One LibreOffice office process session (equivalent of the .NET App constructor/Dispose pair).
struct Session
{
    Reference<css::uno::XComponentContext> ctx;
    Reference<css::frame::XDesktop> desktop;
    Reference<css::frame::XComponentLoader> loader;
};

// Bootstraps the UNO runtime from the installed LibreOffice and creates the Desktop service.
Session StartSession();

// Terminates the desktop (closes the office process).
void EndSession(Session& session);

} // namespace lo_uno
