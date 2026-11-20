# Creates the small Office Open XML fixtures used by LOBridge.Tests (a .docx and an .xlsx).
# The files are plain OOXML packages written with System.IO.Compression, so no Office install is needed.
#
# Usage: powershell -ExecutionPolicy Bypass -File New-Fixtures.ps1 [-OutDir <path>]
param(
    [string]$OutDir = (Join-Path $PSScriptRoot "..\LOBridge.Tests\Fixtures")
)

$ErrorActionPreference = "Stop"
Add-Type -AssemblyName System.IO.Compression
Add-Type -AssemblyName System.IO.Compression.FileSystem

$OutDir = (New-Item -ItemType Directory -Force -Path $OutDir).FullName
$utf8 = New-Object System.Text.UTF8Encoding($false)

function New-Package([string]$path, [hashtable]$parts) {
    if (Test-Path $path) { Remove-Item $path -Force }
    $zip = [System.IO.Compression.ZipFile]::Open($path, [System.IO.Compression.ZipArchiveMode]::Create)
    try {
        foreach ($name in $parts.Keys) {
            $entry = $zip.CreateEntry($name, [System.IO.Compression.CompressionLevel]::Optimal)
            $stream = $entry.Open()
            try {
                $bytes = $utf8.GetBytes($parts[$name])
                $stream.Write($bytes, 0, $bytes.Length)
            } finally { $stream.Dispose() }
        }
    } finally { $zip.Dispose() }
}

$rootRels = '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>' +
'<Relationships xmlns="http://schemas.openxmlformats.org/package/2006/relationships">' +
'<Relationship Id="rId1" Type="http://schemas.openxmlformats.org/officeDocument/2006/relationships/officeDocument" Target="{0}"/>' +
'</Relationships>'

# ---- sample.docx: three paragraphs, the first one is a heading-like line ----
$docxContent = '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>' +
'<w:document xmlns:w="http://schemas.openxmlformats.org/wordprocessingml/2006/main"><w:body>' +
'<w:p><w:r><w:t>Fixture heading</w:t></w:r></w:p>' +
'<w:p><w:r><w:t>First body paragraph with Unicode: Xin chào.</w:t></w:r></w:p>' +
'<w:p><w:r><w:t>Second body paragraph.</w:t></w:r></w:p>' +
'<w:sectPr><w:pgSz w:w="11906" w:h="16838"/><w:pgMar w:top="1440" w:right="1440" w:bottom="1440" w:left="1440"/></w:sectPr>' +
'</w:body></w:document>'

New-Package (Join-Path $OutDir "sample.docx") @{
    "[Content_Types].xml" = '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>' +
        '<Types xmlns="http://schemas.openxmlformats.org/package/2006/content-types">' +
        '<Default Extension="rels" ContentType="application/vnd.openxmlformats-package.relationships+xml"/>' +
        '<Default Extension="xml" ContentType="application/xml"/>' +
        '<Override PartName="/word/document.xml" ContentType="application/vnd.openxmlformats-officedocument.wordprocessingml.document.main+xml"/>' +
        '</Types>'
    "_rels/.rels" = ($rootRels -f "word/document.xml")
    "word/document.xml" = $docxContent
}

# ---- sample.xlsx: one sheet "Data" with a header row and two numeric rows ----
$sheetContent = '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>' +
'<worksheet xmlns="http://schemas.openxmlformats.org/spreadsheetml/2006/main"><sheetData>' +
'<row r="1"><c r="A1" t="inlineStr"><is><t>Name</t></is></c><c r="B1" t="inlineStr"><is><t>Value</t></is></c></row>' +
'<row r="2"><c r="A2" t="inlineStr"><is><t>Alpha</t></is></c><c r="B2"><v>1.5</v></c></row>' +
'<row r="3"><c r="A3" t="inlineStr"><is><t>Beta</t></is></c><c r="B3"><v>42</v></c></row>' +
'</sheetData></worksheet>'

New-Package (Join-Path $OutDir "sample.xlsx") @{
    "[Content_Types].xml" = '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>' +
        '<Types xmlns="http://schemas.openxmlformats.org/package/2006/content-types">' +
        '<Default Extension="rels" ContentType="application/vnd.openxmlformats-package.relationships+xml"/>' +
        '<Default Extension="xml" ContentType="application/xml"/>' +
        '<Override PartName="/xl/workbook.xml" ContentType="application/vnd.openxmlformats-officedocument.spreadsheetml.sheet.main+xml"/>' +
        '<Override PartName="/xl/worksheets/sheet1.xml" ContentType="application/vnd.openxmlformats-officedocument.spreadsheetml.worksheet+xml"/>' +
        '</Types>'
    "_rels/.rels" = ($rootRels -f "xl/workbook.xml")
    "xl/workbook.xml" = '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>' +
        '<workbook xmlns="http://schemas.openxmlformats.org/spreadsheetml/2006/main" xmlns:r="http://schemas.openxmlformats.org/officeDocument/2006/relationships">' +
        '<sheets><sheet name="Data" sheetId="1" r:id="rId1"/></sheets></workbook>'
    "xl/_rels/workbook.xml.rels" = '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>' +
        '<Relationships xmlns="http://schemas.openxmlformats.org/package/2006/relationships">' +
        '<Relationship Id="rId1" Type="http://schemas.openxmlformats.org/officeDocument/2006/relationships/worksheet" Target="worksheets/sheet1.xml"/>' +
        '</Relationships>'
    "xl/worksheets/sheet1.xml" = $sheetContent
}

# ---- tables.docx: two tables with a paragraph before each, for table and cell enumeration ----
function New-TableXml([string[][]]$rows) {
    $xml = '<w:tbl><w:tblPr><w:tblW w:w="0" w:type="auto"/><w:tblBorders>' +
        '<w:top w:val="single" w:sz="4"/><w:left w:val="single" w:sz="4"/><w:bottom w:val="single" w:sz="4"/>' +
        '<w:right w:val="single" w:sz="4"/><w:insideH w:val="single" w:sz="4"/><w:insideV w:val="single" w:sz="4"/>' +
        '</w:tblBorders></w:tblPr><w:tblGrid>'
    for ($c = 0; $c -lt $rows[0].Count; $c++) { $xml += '<w:gridCol w:w="2400"/>' }
    $xml += '</w:tblGrid>'
    foreach ($row in $rows) {
        $xml += '<w:tr>'
        foreach ($cell in $row) {
            $xml += '<w:tc><w:p><w:r><w:t>' + $cell + '</w:t></w:r></w:p></w:tc>'
        }
        $xml += '</w:tr>'
    }
    return $xml + '</w:tbl>'
}

$tablesBody = '<w:p><w:r><w:t>Table one lists the products.</w:t></w:r></w:p>' +
    (New-TableXml @(@('Item', 'Quantity'), @('Paper', '500'), @('Toner', '3'))) +
    '<w:p><w:r><w:t>Table two lists the shipping options.</w:t></w:r></w:p>' +
    (New-TableXml @(@('Route', 'Days', 'Carrier'), @('Local', '1', 'Express'), @('Export', '7', 'Sea')))

New-Package (Join-Path $OutDir "tables.docx") @{
    "[Content_Types].xml" = '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>' +
        '<Types xmlns="http://schemas.openxmlformats.org/package/2006/content-types">' +
        '<Default Extension="rels" ContentType="application/vnd.openxmlformats-package.relationships+xml"/>' +
        '<Default Extension="xml" ContentType="application/xml"/>' +
        '<Override PartName="/word/document.xml" ContentType="application/vnd.openxmlformats-officedocument.wordprocessingml.document.main+xml"/>' +
        '</Types>'
    "_rels/.rels" = ($rootRels -f "word/document.xml")
    "word/document.xml" = '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>' +
        '<w:document xmlns:w="http://schemas.openxmlformats.org/wordprocessingml/2006/main"><w:body>' +
        $tablesBody +
        '<w:sectPr><w:pgSz w:w="11906" w:h="16838"/><w:pgMar w:top="1440" w:right="1440" w:bottom="1440" w:left="1440"/></w:sectPr>' +
        '</w:body></w:document>'
}

"Fixtures written to $OutDir"
