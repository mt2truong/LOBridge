// ZIP reading and DEFLATE decoding (RFC 1951 / 1950-free raw deflate), written to avoid external dependencies.
#include "Zip.h"

#include <windows.h>
#include <cstdint>
#include <fstream>
#include <stdexcept>
#include <vector>

namespace lo_zip {
namespace {

uint16_t U16(const std::vector<unsigned char>& d, size_t p)
{
    if (p + 2 > d.size()) throw std::runtime_error("zip: truncated");
    return (uint16_t)(d[p] | (d[p + 1] << 8));
}

uint32_t U32(const std::vector<unsigned char>& d, size_t p)
{
    if (p + 4 > d.size()) throw std::runtime_error("zip: truncated");
    return (uint32_t)d[p] | ((uint32_t)d[p + 1] << 8) | ((uint32_t)d[p + 2] << 16) | ((uint32_t)d[p + 3] << 24);
}

// ---- DEFLATE ------------------------------------------------------------------

struct Bits
{
    const unsigned char* src;
    size_t size;
    size_t pos = 0;
    uint32_t buf = 0;
    int count = 0;

    uint32_t Get(int n)
    {
        while (count < n)
        {
            if (pos >= size) throw std::runtime_error("deflate: out of input");
            buf |= (uint32_t)src[pos++] << count;
            count += 8;
        }
        uint32_t v = buf & ((1u << n) - 1u);
        buf >>= n;
        count -= n;
        return v;
    }
};

struct Huffman
{
    uint16_t count[16];
    uint16_t symbol[320];
};

void Construct(Huffman& h, const uint16_t* length, int n)
{
    for (int i = 0; i < 16; ++i) h.count[i] = 0;
    for (int s = 0; s < n; ++s) h.count[length[s]]++;

    uint16_t offs[16];
    offs[1] = 0;
    for (int len = 1; len < 15; ++len) offs[len + 1] = offs[len] + h.count[len];
    for (int s = 0; s < n; ++s)
        if (length[s] != 0) h.symbol[offs[length[s]]++] = (uint16_t)s;
}

int Decode(Bits& in, const Huffman& h)
{
    int code = 0, first = 0, index = 0;
    for (int len = 1; len < 16; ++len)
    {
        code |= (int)in.Get(1);
        int count = h.count[len];
        if (code - count < first) return h.symbol[index + (code - first)];
        index += count;
        first += count;
        first <<= 1;
        code <<= 1;
    }
    throw std::runtime_error("deflate: bad code");
}

const uint16_t kLenBase[29] = { 3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 15, 17, 19, 23, 27, 31,
                                35, 43, 51, 59, 67, 83, 99, 115, 131, 163, 195, 227, 258 };
const uint16_t kLenExtra[29] = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2,
                                 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 0 };
const uint16_t kDistBase[30] = { 1, 2, 3, 4, 5, 7, 9, 13, 17, 25, 33, 49, 65, 97, 129, 193,
                                 257, 385, 513, 769, 1025, 1537, 2049, 3073, 4097, 6145,
                                 8193, 12289, 16385, 24577 };
const uint16_t kDistExtra[30] = { 0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6,
                                  7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13 };

void CodesBlock(Bits& in, std::string& out, const Huffman& lencode, const Huffman& distcode)
{
    for (;;)
    {
        int sym = Decode(in, lencode);
        if (sym < 256)
        {
            out.push_back((char)sym);
        }
        else if (sym == 256)
        {
            return;
        }
        else
        {
            sym -= 257;
            if (sym >= 29) throw std::runtime_error("deflate: bad length");
            size_t len = kLenBase[sym] + in.Get(kLenExtra[sym]);
            int dsym = Decode(in, distcode);
            if (dsym >= 30) throw std::runtime_error("deflate: bad distance");
            size_t dist = kDistBase[dsym] + in.Get(kDistExtra[dsym]);
            if (dist > out.size()) throw std::runtime_error("deflate: distance too far");
            size_t from = out.size() - dist;
            for (size_t i = 0; i < len; ++i) out.push_back(out[from + i]);
        }
    }
}

void Inflate(const unsigned char* data, size_t size, std::string& out)
{
    Bits in{ data, size };
    int last = 0;
    do
    {
        last = (int)in.Get(1);
        int type = (int)in.Get(2);
        if (type == 0)
        {
            // Stored block: discard the remaining bits of the current byte.
            in.buf = 0;
            in.count = 0;
            if (in.pos + 4 > in.size) throw std::runtime_error("deflate: truncated stored block");
            uint16_t len = (uint16_t)(in.src[in.pos] | (in.src[in.pos + 1] << 8));
            in.pos += 4;   // LEN and NLEN
            if (in.pos + len > in.size) throw std::runtime_error("deflate: truncated stored data");
            out.append(reinterpret_cast<const char*>(in.src + in.pos), len);
            in.pos += len;
        }
        else if (type == 1)
        {
            uint16_t lengths[320];
            int i = 0;
            for (; i < 144; ++i) lengths[i] = 8;
            for (; i < 256; ++i) lengths[i] = 9;
            for (; i < 280; ++i) lengths[i] = 7;
            for (; i < 288; ++i) lengths[i] = 8;
            Huffman lencode;
            Construct(lencode, lengths, 288);
            uint16_t dl[30];
            for (int k = 0; k < 30; ++k) dl[k] = 5;
            Huffman distcode;
            Construct(distcode, dl, 30);
            CodesBlock(in, out, lencode, distcode);
        }
        else if (type == 2)
        {
            static const uint8_t order[19] = { 16, 17, 18, 0, 8, 7, 9, 6, 10, 5, 11, 4, 12, 3, 13, 2, 14, 1, 15 };
            int nlen = (int)in.Get(5) + 257;
            int ndist = (int)in.Get(5) + 1;
            int ncode = (int)in.Get(4) + 4;

            uint16_t lengths[320] = {};
            for (int i = 0; i < ncode; ++i) lengths[order[i]] = (uint16_t)in.Get(3);
            Huffman lencode;
            Construct(lencode, lengths, 19);

            int index = 0;
            uint16_t all[320] = {};
            while (index < nlen + ndist)
            {
                int sym = Decode(in, lencode);
                if (sym < 16)
                {
                    all[index++] = (uint16_t)sym;
                }
                else
                {
                    uint16_t value = 0;
                    int rep = 0;
                    if (sym == 16)
                    {
                        if (index == 0) throw std::runtime_error("deflate: repeat without previous");
                        value = all[index - 1];
                        rep = 3 + (int)in.Get(2);
                    }
                    else if (sym == 17)
                    {
                        rep = 3 + (int)in.Get(3);
                    }
                    else
                    {
                        rep = 11 + (int)in.Get(7);
                    }
                    if (index + rep > nlen + ndist) throw std::runtime_error("deflate: too many lengths");
                    while (rep--) all[index++] = value;
                }
            }
            Huffman litcode, distcode;
            Construct(litcode, all, nlen);
            Construct(distcode, all + nlen, ndist);
            CodesBlock(in, out, litcode, distcode);
        }
        else
        {
            throw std::runtime_error("deflate: invalid block type");
        }
    } while (!last);
}

// ---- ZIP ----------------------------------------------------------------------

bool LoadFile(const rtl::OUString& path, std::vector<unsigned char>& data)
{
    std::wstring w(path.getStr(), path.getStr() + path.getLength());
    std::ifstream f(w, std::ios::binary);
    if (!f) return false;
    f.seekg(0, std::ios::end);
    std::streamoff n = f.tellg();
    f.seekg(0, std::ios::beg);
    data.resize((size_t)n);
    if (n > 0) f.read(reinterpret_cast<char*>(data.data()), n);
    return (bool)f;
}

std::string XmlUnescape(std::string s)
{
    const std::pair<const char*, const char*> table[] = {
        { "&amp;", "&" }, { "&lt;", "<" }, { "&gt;", ">" }, { "&quot;", "\"" }, { "&apos;", "'" } };
    for (const auto& e : table)
    {
        size_t pos = 0;
        std::string from = e.first, to = e.second;
        while ((pos = s.find(from, pos)) != std::string::npos)
        {
            s.replace(pos, from.size(), to);
            pos += to.size();
        }
    }
    return s;
}

// Returns the value of attribute 'name' inside the element that starts at or before 'pos'.
std::string AttributeOf(const std::string& xml, size_t pos, const std::string& name)
{
    size_t start = xml.rfind('<', pos);
    size_t end = xml.find('>', pos);
    if (start == std::string::npos || end == std::string::npos) return "";
    std::string element = xml.substr(start, end - start);
    std::string key = name + "=\"";
    size_t k = element.find(key);
    if (k == std::string::npos) return "";
    k += key.size();
    size_t q = element.find('"', k);
    if (q == std::string::npos) return "";
    return XmlUnescape(element.substr(k, q - k));
}

} // namespace

bool ReadEntry(const rtl::OUString& zipPath, const char* entryName, std::string& out)
{
    out.clear();
    try
    {
        std::vector<unsigned char> d;
        if (!LoadFile(zipPath, d)) return false;

        // End of central directory record (search from the end; a comment can be up to 64 KB).
        size_t eocd = std::string::npos;
        size_t minPos = d.size() > 65557 ? d.size() - 65557 : 0;
        for (size_t p = d.size() >= 22 ? d.size() - 22 : 0; ; --p)
        {
            if (U32(d, p) == 0x06054b50u) { eocd = p; break; }
            if (p == minPos) break;
        }
        if (eocd == std::string::npos) return false;

        uint16_t entries = U16(d, eocd + 10);
        size_t cdPos = U32(d, eocd + 16);

        std::string wanted = entryName;
        for (uint16_t i = 0; i < entries; ++i)
        {
            if (U32(d, cdPos) != 0x02014b50u) return false;
            uint16_t method = U16(d, cdPos + 10);
            uint32_t compSize = U32(d, cdPos + 20);
            uint32_t uncompSize = U32(d, cdPos + 24);
            uint16_t nameLen = U16(d, cdPos + 28);
            uint16_t extraLen = U16(d, cdPos + 30);
            uint16_t commentLen = U16(d, cdPos + 32);
            uint32_t localPos = U32(d, cdPos + 42);
            std::string name((const char*)&d[cdPos + 46], nameLen);

            if (name == wanted)
            {
                if (U32(d, localPos) != 0x04034b50u) return false;
                size_t dataPos = localPos + 30 + U16(d, localPos + 26) + U16(d, localPos + 28);
                if (dataPos + compSize > d.size()) return false;
                if (method == 0)
                {
                    out.assign((const char*)&d[dataPos], compSize);
                }
                else if (method == 8)
                {
                    out.reserve(uncompSize);
                    Inflate(&d[dataPos], compSize, out);
                }
                else
                {
                    return false;
                }
                return true;
            }
            cdPos += 46 + nameLen + extraLen + commentLen;
        }
    }
    catch (...)
    {
        out.clear();
    }
    return false;
}

std::string FindAttachedTemplateTarget(const std::string& settingsXml, const std::string& relsXml)
{
    size_t at = settingsXml.find("attachedTemplate");
    if (at == std::string::npos) return "";
    std::string rid = AttributeOf(settingsXml, at, "r:id");
    if (rid.empty()) return "";

    std::string needle = "Id=\"" + rid + "\"";
    size_t pos = relsXml.find(needle);
    if (pos == std::string::npos) return "";
    return AttributeOf(relsXml, pos, "Target");
}

} // namespace lo_zip
