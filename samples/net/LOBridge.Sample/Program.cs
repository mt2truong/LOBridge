// Sample: drives the native LibreOffice COM bridge from .NET 10 with early-bound interop types.
//
//   LOBridge.Sample.exe <output-folder> <csv-file>
//
// Prerequisites: the native DLL is registered (see docs/BUILD.md), LibreOffice is installed, and
// lib\Interop.LOBridge.dll exists (run tools\Generate-Interop.ps1).
using System.Runtime.InteropServices;
using Interop.LOBridge;

if (args.Length < 2)
{
    Console.Error.WriteLine("usage: LOBridge.Sample <output-folder> <csv-file>");
    return 2;
}

var outputFolder = Path.GetFullPath(args[0]);
var csvPath = Path.GetFullPath(args[1]);
Directory.CreateDirectory(outputFolder);

WriterSample(outputFolder);
CalcSample(csvPath);
return 0;

static void WriterSample(string outputFolder)
{
    Console.WriteLine("== Writer");
    var app = new WriterAppClass();
    try
    {
        // A4 portrait: 595 x 842 points.
        IWriterDocument doc = app.NewDoc(false, 842f, 595f);
        try
        {
            IWriterParagraph title = doc.AddNewParagraph();
            title.Text = "LOBridge sample document";
            title.Font.Size = 18f;

            IWriterParagraph body = doc.AddNewParagraph();
            body.Text = "Created from .NET 10 through the native C++ COM bridge. Unicode: Xin chào.";

            Console.WriteLine($"  paragraphs: {doc.ParagraphCount}, characters: {doc.CharacterCount}");
            IWriterPageSetup page = doc.PageSetup;
            Console.WriteLine($"  paper: {page.PaperSize}, width {page.PageWidth} pt");

            var docx = Path.Combine(outputFolder, "sample.docx");
            var pdf = Path.Combine(outputFolder, "sample.pdf");
            doc.SaveAs(docx);
            doc.Export(pdf, "pdf");
            Console.WriteLine($"  saved: {docx}");
            Console.WriteLine($"  exported: {pdf}");
        }
        finally
        {
            doc.Close();
            Marshal.FinalReleaseComObject(doc);
        }
    }
    finally
    {
        app.Dispose();
        Marshal.FinalReleaseComObject(app);
    }
}

static void CalcSample(string csvPath)
{
    Console.WriteLine("== Calc");
    var app = new CalcAppClass();
    try
    {
        ICalcWorkbook workbook = app.Open(csvPath, true);
        try
        {
            ICalcWorksheet sheet = workbook.GetWorksheet(0);
            Console.WriteLine($"  sheet: {sheet.Name}");
            ICalcRange used = sheet.UsedRange;
            int rows = used.RowCount;
            int cols = used.ColumnCount;
            Console.WriteLine($"  used range: {rows} x {cols}");
            for (int r = 0; r < rows; r++)
            {
                var line = new List<string>();
                for (int c = 0; c < cols; c++)
                {
                    ICalcCell cell = used.GetCell(r, c);
                    line.Add(cell.Text);
                    Marshal.FinalReleaseComObject(cell);
                }
                Console.WriteLine("  " + string.Join(" | ", line));
            }
            Marshal.FinalReleaseComObject(used);
            Marshal.FinalReleaseComObject(sheet);
        }
        finally
        {
            workbook.Close();
            Marshal.FinalReleaseComObject(workbook);
        }
    }
    finally
    {
        app.Dispose();
        Marshal.FinalReleaseComObject(app);
    }
}
