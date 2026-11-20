// Minimal ZIP reader (stored and deflate entries) used to read Office Open XML packages (.docx).
// Replaces DocumentFormat.OpenXml for the two operations the library needs.
#pragma once

#include <rtl/ustring.hxx>
#include <string>

namespace lo_zip {

// Reads one entry of a zip file (e.g. "word/document.xml") into 'out'. Returns false when the file or entry is missing.
bool ReadEntry(const rtl::OUString& zipPath, const char* entryName, std::string& out);

// Finds the Target of the attached template referenced by <w:attachedTemplate r:id="..."/> in settings.xml.
// Returns an empty string when there is no attached template.
std::string FindAttachedTemplateTarget(const std::string& settingsXml, const std::string& relsXml);

} // namespace lo_zip
