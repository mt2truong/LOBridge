# COM API reference

The native server exposes the same COM surface as the .NET Framework library it replaces. Source of truth: [`native/idl/LOBridge.idl`](../native/idl/LOBridge.idl).

All interfaces are dual (`IDispatch` + vtable), so they can be used from late-bound (`dynamic`) callers, from early-bound callers through a type library, and from C++.

## Coclasses

| ProgID | CLSID | Default interface |
| --- | --- | --- |
| `LOBridge.Writer.App` | `{596EF499-A61F-4977-A257-D06A8C8D8E03}` | `IWriterApp` |
| `LOBridge.Calc.App` | `{65ED3120-936C-4BEA-996E-C6C9CF35B179}` | `ICalcApp` |

Library: `LOBridge` `{6B1E2C7A-3F0D-4E8B-9A57-2D4C8F1B6E90}`, version 1.0.

## Writer (the Word-compatible API)

Each Writer interface keeps the IID of the .NET interface it replaces. Only the names differ (`IApp` became `IWriterApp`, and so on). The Writer and Calc names follow LibreOffice, and the ProgIDs use the same names.

### IWriterApp

| Member | Signature | Notes |
| --- | --- | --- |
| `Dispose` | `void` | Releases the office session (references only; see [TROUBLESHOOTING.md](TROUBLESHOOTING.md) §4). |
| `NewDoc` | `IWriterDocument NewDoc(bool landscape, float pageHeight, float pageWidth)` | Page sizes in points. |
| `Open` | `IWriterDocument Open(string filePath, bool readOnly)` | Returns `null` when the file cannot be loaded. |
| `ActiveDocument` | `IWriterDocument ActiveDocument { get; }` | The last text document opened in the office. |

### IWriterDocument

| Member | Signature | Notes |
| --- | --- | --- |
| `Dispose`, `Close` | `void` | Close the document. |
| `SaveAs` | `void SaveAs(string filePath)` | Empty path saves in place. Other extensions go through `Export`. |
| `Export` | `void Export(string filePath, string format)` | `pdf`, `docx`, `doc`, `rtf`, `xml`. Unknown formats do nothing. |
| `PageCount`, `CharacterCount`, `ParagraphCount`, `TableCount`, `StyleCount`, `ShapeCount` | `int { get; }` | |
| `HasContent` | `bool HasContent()` | |
| `GetTemplateName` | `string GetTemplateName(string filePath)` | Reads the attached template from the `.docx` package. |
| `DeletePageByIndex` | `void DeletePageByIndex(int pageIndex)` | |
| `GetTable` | `IWriterTable GetTable(int index)` | |
| `GetStyle` / `GetStyleByName` | `IWriterStyle` | |
| `GetShape` | `IWriterShape GetShape(int index)` | |
| `AddTextBox` | `IWriterShape AddTextBox(int pageIndex)` | |
| `CreateShape` | `IWriterShape CreateShape(int pageIndex, IWriterShape sourceShape)` | Not implemented (`E_NOTIMPL`). |
| `CreateShape_2` | `IWriterShape CreateShape_2(int pageIndex, string shapeType)` | Not implemented (`E_NOTIMPL`). COM name for the second overload. |
| `PageSetup` | `IWriterPageSetup PageSetup { get; }` | Page style "Standard". |
| `GetParagraph` / `AddNewParagraph` | `IWriterParagraph` | |
| `ToggleShowHiddenText` | `void ToggleShowHiddenText(bool flag)` | |

### IWriterParagraph

`string Text { get; set; }`, `string GetRawText()`, `IWriterFont Font { get; }`.

### IWriterRange

`IWriterPageSetup PageSetup { get; }`, `int LineSpacingMode`, `float LineSpacingHeight`, `int Start`, `int End`, `float SpaceBefore`, `float SpaceAfter`, `bool KeepTogetherNextParagraph` (all get/set), `float GetRangeHeight()` (not implemented), `float GetVerticalPositionRelativeToPage()`, `int GetStaticLines()`, `float LinesToPoints(float)`.

### IWriterFont

`string Name { get; }`, `float Size { get; set; }`, `int Bold { get; }`, `int Italic { get; }`, `int Underline { get; }`, `int Color { get; }` (ARGB as written by the .NET version), `bool Hidden { get; set; }`.

### IWriterStyle

`string Name { get; }`, `IWriterFont Font { get; }`.

### IWriterPageSetup

`string PaperSize { get; }`, `float PageWidth { get; }`, `float PageHeight { get; }`, and `float LeftMargin`, `RightMargin`, `TopMargin`, `BottomMargin` (all get/set). Sizes are in points. The margin setters write 1/100 mm integers, as LibreOffice expects.

### IWriterShape

`float Width`, `float Height` (get/set), `float LeftPosition`, `float TopPosition` (get), `string ShapeType { get; }`, `int GetAlignment()`, `IWriterFont GetTextFont()`, `void CopyFrom(IWriterShape)`, `string Text` (get/set), `IWriterPageSetup PageSetup { get; }`.

### IWriterTable

`bool AllowAutoFit` (get/set, always false), `int RowCount`, `int ColumnCount` (get), `float LeftPadding`, `TopPadding`, `BottomPadding`, `RightPadding` (get/set), `IWriterTableRow GetRow(int)`, `IWriterTableColumn GetColumn(int)`, `void Normalize()`, `IWriterTableRow AddRow(IWriterTableRow rowAfter)`, `void DeleteRow(IWriterTableRow)`, `bool SetTabStops()`.

### IWriterTableRow

`IWriterRange Range { get; }`, `float Height` (get/set), `RowHeightRule HeightRule` (get/set), `bool AllowSplit` (get/set), `int CellCount { get; }`, `IWriterTableCell GetCell(int)`, `bool IsRepeatingRow()`, `void SetStyle(IWriterStyle)`.

`RowHeightRule` values: `Auto = 0`, `AtLeast = 1`, `Exactly = 2`.

### IWriterTableColumn

`int CellCount { get; }`, `IWriterTableCell GetCell(int rowIndex)`.

### IWriterTableCell

`IWriterStyle Style { get; }`, `IWriterRange Range { get; }`, `string Text` (get/set), `IWriterFont Font { get; }`, `int VerticalAlignment` (get/set; 0 top, 1 center, 2 bottom), `int HorizontalAlignment` (get/set; 0 left, 1 center, 2 right, 3 justified), `float Width` (get; set is a no-op), `float Height`, `RightPadding`, `LeftPadding`, `TopPadding`, `BottomPadding` (get/set), `int GetActiveEndPageNumber()`, `void ScrollIntoView(bool)` (no-op), `double GetFirstColLeftDistance()`.

## Calc (the Excel-compatible API)

### ICalcApp

`void Dispose()`, `ICalcWorkbook Open(string filePath, bool readOnly)`. Returns `null` when the file cannot be loaded.

### ICalcWorkbook

`void Dispose()`, `void Save()`, `void Close()`, `int WorksheetCount { get; }`, `ICalcWorksheet GetWorksheet(int index)`.

### ICalcWorksheet

`void Dispose()`, `ICalcRange UsedRange { get; }`, `string Name { get; }`.

### ICalcRange

`void Dispose()`, `int RowCount`, `int ColumnCount` (get), `ICalcCell GetCell(int rowIndex, int columnIndex)`.

### ICalcCell

`void Dispose()`, `bool RowIsHidden { get; }`, `float RowHeight { get; }`, `int Color { get; }` (ARGB), `string Text { get; }`, `object Value { get; }` (`double` for numbers, `string` for text and formulas, empty for blank cells).

## Differences from the .NET Framework library

| Area | .NET Framework | Native |
| --- | --- | --- |
| Interface names | `IApp`, `IDocument`, `IRange`, ... (one set for Word, one for Excel) | Named after LibreOffice: `IWriterApp`, `ICalcApp`, ... IIDs unchanged. |
| `CreateShape` overload | Two overloads with the same name | `CreateShape` and `CreateShape_2` (the name `tlbexp` gives the second overload). |
| `ICell.Color` | `System.Drawing.Color` | `int` ARGB (`System.Drawing.Color` is not COM-marshalable). |
| `RowHeightRule` | C# enum `RowHeightRule.Auto` | Same names in the type library. |
| XML export | Used DocumentFormat.OpenXml | A small ZIP and DEFLATE reader (`native/src/common/Zip.cpp`) reads `word/document.xml`. |
| Office lifetime | Each `App` started and shut down its own office | The office runs out of process and is shared; `Dispose` releases references only. |
| Margins | Written as floats | Written as 32-bit integers (1/100 mm), which is the type LibreOffice expects. |
| Not implemented | `GetRangeHeight`, `CreateShape` overloads | Same, returning `E_NOTIMPL`. |

## HRESULT behaviour

- Any UNO exception is logged to stderr (`[LOBridge] ...`) and mapped to `E_FAIL`.
- Null results (for example `Open` on a missing file) are returned as `S_OK` with a null pointer, as the .NET version did.
- Invalid index arguments return `E_INVALIDARG`.
