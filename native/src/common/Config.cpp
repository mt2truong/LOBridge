// Reads GapPageHeight and SetZoomFitWidth from the appSettings of "<dll>.config" (same keys as the .NET helper).
#include "Config.h"
#include "Common.h"

#include <fstream>
#include <sstream>
#include <string>

namespace {

struct Settings
{
    int gapPageHeight = 501;
    bool setZoomFitWidth = true;

    Settings()
    {
        std::wstring path = lo_com::ModulePath() + L".config";
        std::ifstream f(path, std::ios::binary);
        if (!f) return;
        std::stringstream ss;
        ss << f.rdbuf();
        std::string xml = ss.str();

        std::string gap = Value(xml, "GapPageHeight");
        if (!gap.empty())
        {
            try { gapPageHeight = std::stoi(gap); } catch (...) {}
        }
        std::string zoom = Value(xml, "SetZoomFitWidth");
        if (zoom == "true" || zoom == "True" || zoom == "false" || zoom == "False")
        {
            setZoomFitWidth = (zoom == "true" || zoom == "True");
        }
    }

    // Finds <add key="name" value="..."/> and returns the value.
    static std::string Value(const std::string& xml, const std::string& key)
    {
        std::string k = "key=\"" + key + "\"";
        size_t pos = xml.find(k);
        if (pos == std::string::npos) return "";
        size_t end = xml.find('>', pos);
        size_t v = xml.find("value=\"", pos);
        if (v == std::string::npos || (end != std::string::npos && v > end)) return "";
        v += 7;
        size_t q = xml.find('"', v);
        if (q == std::string::npos) return "";
        return xml.substr(v, q - v);
    }
};

const Settings& Get()
{
    static Settings s;   // thread-safe initialisation
    return s;
}

} // namespace

int GapPageHeight() { return Get().gapPageHeight; }

bool SetZoomFitWidth() { return Get().setZoomFitWidth; }
