// Sample: an application that codes against interfaces only, the same layering the TRS PdfCom
// wrapper uses. Nothing in this project references the COM interop types.
//
//   LOBridge.InterfaceSample.exe <output-folder> <csv-file> <docx-file>
using LOBridge.Abstractions;
using LOBridge.ComAdapter;

if (args.Length < 3)
{
    Console.Error.WriteLine("usage: LOBridge.InterfaceSample <output-folder> <csv-file> <docx-file>");
    return 2;
}

var outputFolder = Path.GetFullPath(args[0]);
var csvPath = Path.GetFullPath(args[1]);
var docxPath = Path.GetFullPath(args[2]);
Directory.CreateDirectory(outputFolder);

WriterSample(outputFolder);
TablesSample(docxPath);
CalcSample(csvPath);
return 0;

static void WriterSample(string outputFolder)
{
    Console.WriteLine("== Writer");
    using IWriterApplication writer = OfficeFactory.CreateWriterApplication();

    // A4 portrait: 595 x 842 points.
    using IDocument document = writer.NewDocument(false, 595f, 842f);
    document.AddParagraph("Interface sample document", 18f);
    document.AddParagraph("Created through interfaces only. Unicode: Xin chào.", 11f);

    Console.WriteLine($"  paragraphs: {document.ParagraphCount}, pages: {document.PageCount}");
    // Paragraph 0 is the empty paragraph that a new document starts with, so read paragraph 1.
    Console.WriteLine($"  first text paragraph: {document.GetParagraph(1).Text}");

    var docx = Path.Combine(outputFolder, "interface-sample.docx");
    var pdf = Path.Combine(outputFolder, "interface-sample.pdf");
    document.SaveAs(docx);
    document.Export(pdf, "pdf");
    Console.WriteLine($"  saved: {docx}");
    Console.WriteLine($"  exported: {pdf}");
}

static void TablesSample(string docxPath)
{
    Console.WriteLine("== Tables in " + docxPath);
    using IWriterApplication writer = OfficeFactory.CreateWriterApplication();
    using IDocument document = writer.Open(docxPath, true);

    int tableCount = document.TableCount;
    Console.WriteLine($"  tables: {tableCount}");

    for (int t = 0; t < tableCount; t++)
    {
        using ITable table = document.GetTable(t);
        Console.WriteLine($"  table {t + 1}: {table.RowCount} rows x {table.ColumnCount} columns");

        for (int r = 0; r < table.RowCount; r++)
        {
            using ITableRow row = table.GetRow(r);
            var cells = new List<string>();

            for (int c = 0; c < row.CellCount; c++)
            {
                using ITableCell cell = row.GetCell(c);
                cells.Add(cell.Text);
            }

            Console.WriteLine($"    row {r + 1}: {string.Join(" | ", cells)}");
        }
    }
}

static void CalcSample(string csvPath)
{
    Console.WriteLine("== Calc");
    using ICalcApplication calc = OfficeFactory.CreateCalcApplication();
    using IWorkbook workbook = calc.Open(csvPath, true);

    IWorksheet sheet = workbook.GetWorksheet(0);
    Console.WriteLine($"  sheet: {sheet.Name}, used range: {sheet.RowCount} x {sheet.ColumnCount}");

    for (int row = 0; row < sheet.RowCount; row++)
    {
        var cells = new List<string>();
        for (int column = 0; column < sheet.ColumnCount; column++)
        {
            cells.Add(sheet.GetText(row, column));
        }
        Console.WriteLine("  " + string.Join(" | ", cells));
    }
}
