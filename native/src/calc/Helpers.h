// Shared includes and helper functions for the calc classes (Calc).
#pragma once

#include "Common.h"
#include "Uno.h"
#include <com/sun/star/awt/Size.hpp>
#include <com/sun/star/beans/XPropertySetInfo.hpp>
#include <com/sun/star/container/XIndexAccess.hpp>
#include <com/sun/star/container/XNamed.hpp>
#include <com/sun/star/frame/XStorable.hpp>
#include <com/sun/star/sheet/XSpreadsheet.hpp>
#include <com/sun/star/sheet/XSpreadsheetDocument.hpp>
#include <com/sun/star/sheet/XSpreadsheets.hpp>
#include <com/sun/star/sheet/XUsedAreaCursor.hpp>
#include <com/sun/star/table/CellContentType.hpp>
#include <com/sun/star/table/XCell.hpp>
#include <com/sun/star/table/XCellRange.hpp>
#include <com/sun/star/table/XColumnRowRange.hpp>
#include <com/sun/star/text/XText.hpp>
#include <com/sun/star/util/XCloseable.hpp>
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

namespace calc {

// Shortest round-trip text for a double (similar to Convert.ToString(double) in .NET).
inline std::string DoubleToText(double v)
{
    char buf[64];
    for (int precision = 15; precision <= 17; ++precision)
    {
        std::snprintf(buf, sizeof(buf), "%.*g", precision, v);
        if (std::strtod(buf, nullptr) == v) break;
    }
    return buf;
}

} // namespace calc
