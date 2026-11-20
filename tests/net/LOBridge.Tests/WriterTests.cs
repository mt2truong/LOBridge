using System.Runtime.InteropServices;
using System.Text;
using Interop.LOBridge;
using Xunit;

namespace LOBridge.Tests;

/// <summary>Writer (Word-compatible) API: documents, paragraphs, fonts, page setup, export and import.</summary>
public class WriterTests
{
    private const float A4Width = 595f;
    private const float A4Height = 842f;

    [Fact]
    public void NewDoc_UsesRequestedPaperSize()
    {
        var app = new WriterAppClass();
        try
        {
            IWriterDocument doc = app.NewDoc(false, A4Height, A4Width);
            try
            {
                IWriterPageSetup page = doc.PageSetup;
                Assert.InRange(page.PageWidth, A4Width - 1f, A4Width + 1f);
                Assert.InRange(page.PageHeight, A4Height - 1f, A4Height + 1f);
                TestSupport.Release(page);
            }
            finally
            {
                doc.Close();
                TestSupport.Release(doc);
            }
        }
        finally
        {
            app.Dispose();
            TestSupport.Release(app);
        }
    }

    [Fact]
    public void NewDoc_Landscape_IsWiderThanItIsHigh()
    {
        var app = new WriterAppClass();
        try
        {
            IWriterDocument doc = app.NewDoc(true, A4Width, A4Height);
            try
            {
                IWriterPageSetup page = doc.PageSetup;
                Assert.True(page.PageWidth > page.PageHeight, "a landscape page is wider than it is high");
                TestSupport.Release(page);
            }
            finally
            {
                doc.Close();
                TestSupport.Release(doc);
            }
        }
        finally
        {
            app.Dispose();
            TestSupport.Release(app);
        }
    }

    [Fact]
    public void Paragraph_TextAndFontSize_RoundTripIncludingUnicode()
    {
        const string text = "Xin chào from .NET 10";
        var app = new WriterAppClass();
        try
        {
            IWriterDocument doc = app.NewDoc(false, A4Height, A4Width);
            try
            {
                // A new document already holds one empty paragraph. AddNewParagraph inserts a break
                // after it, as the .NET Framework version does, so the count grows by one.
                int before = doc.ParagraphCount;
                IWriterParagraph paragraph = doc.AddNewParagraph();
                paragraph.Text = text;
                IWriterFont font = paragraph.Font;
                font.Size = 18f;

                Assert.Equal(text, paragraph.Text);
                Assert.Equal(18f, font.Size, precision: 1);
                Assert.Equal(before + 1, doc.ParagraphCount);

                TestSupport.Release(font);
                TestSupport.Release(paragraph);
            }
            finally
            {
                doc.Close();
                TestSupport.Release(doc);
            }
        }
        finally
        {
            app.Dispose();
            TestSupport.Release(app);
        }
    }

    [Fact]
    public void SaveAs_Docx_WritesPackageWithParagraphText()
    {
        var scratch = TestSupport.NewScratchDir();
        var app = new WriterAppClass();
        try
        {
            var docx = Path.Combine(scratch, "saved.docx");
            IWriterDocument doc = app.NewDoc(false, A4Height, A4Width);
            try
            {
                IWriterParagraph paragraph = doc.AddNewParagraph();
                paragraph.Text = "Saved by the bridge";
                doc.SaveAs(docx);
                TestSupport.Release(paragraph);
            }
            finally
            {
                doc.Close();
                TestSupport.Release(doc);
            }

            Assert.True(File.Exists(docx));
            Assert.Contains("Saved by the bridge", TestSupport.ReadPart(docx, "word/document.xml"));
        }
        finally
        {
            app.Dispose();
            TestSupport.Release(app);
            TestSupport.DeleteScratchDir(scratch);
        }
    }

    [Fact]
    public void Export_Pdf_WritesPdfSignature()
    {
        var scratch = TestSupport.NewScratchDir();
        var app = new WriterAppClass();
        try
        {
            var pdf = Path.Combine(scratch, "export.pdf");
            IWriterDocument doc = app.NewDoc(false, A4Height, A4Width);
            try
            {
                IWriterParagraph paragraph = doc.AddNewParagraph();
                paragraph.Text = "PDF export";
                doc.Export(pdf, "pdf");
                TestSupport.Release(paragraph);
            }
            finally
            {
                doc.Close();
                TestSupport.Release(doc);
            }

            var header = new byte[5];
            using (var stream = File.OpenRead(pdf))
            {
                Assert.Equal(5, stream.Read(header, 0, 5));
            }
            Assert.Equal("%PDF-", Encoding.ASCII.GetString(header));
        }
        finally
        {
            app.Dispose();
            TestSupport.Release(app);
            TestSupport.DeleteScratchDir(scratch);
        }
    }

    [Fact]
    public void Open_DocxFixture_ReadsParagraphsAndTables()
    {
        var app = new WriterAppClass();
        try
        {
            IWriterDocument doc = app.Open(TestSupport.FixturePath("sample.docx"), true);
            try
            {
                Assert.Equal(3, doc.ParagraphCount);
                Assert.Equal(0, doc.TableCount);

                IWriterParagraph first = doc.GetParagraph(0);
                Assert.Equal("Fixture heading", first.Text);
                TestSupport.Release(first);
            }
            finally
            {
                doc.Close();
                TestSupport.Release(doc);
            }
        }
        finally
        {
            app.Dispose();
            TestSupport.Release(app);
        }
    }

    [Fact]
    public void Open_MissingFile_ThrowsCOMException()
    {
        var app = new WriterAppClass();
        try
        {
            var missing = Path.Combine(TestSupport.NewScratchDir(), "does-not-exist.docx");
            var ex = Assert.Throws<COMException>(() => app.Open(missing, true));
            Assert.NotEqual(0, ex.HResult);
        }
        finally
        {
            app.Dispose();
            TestSupport.Release(app);
        }
    }
}
