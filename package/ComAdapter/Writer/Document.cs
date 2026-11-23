using LOBridge.Abstractions.Writer;
using Com = Interop.LOBridge;

namespace LOBridge.ComAdapter.Writer;

/// <summary>Writer document backed by a native WriterDocument COM object.</summary>
internal sealed class Document : IDocument
{
    private Com.IWriterDocument? _doc;

    internal Document(Com.IWriterDocument doc)
    {
        _doc = doc;
    }

    public int ParagraphCount => Live().ParagraphCount;

    public int PageCount => Live().PageCount;

    public IParagraph AddParagraph(string text, float fontSize)
    {
        var paragraph = Live().AddNewParagraph();
        try
        {
            paragraph.Text = text;
            paragraph.Font.Size = fontSize;
            return new Paragraph(paragraph);
        }
        catch
        {
            ComRelease.Release(paragraph);
            throw;
        }
    }

    public int TableCount => Live().TableCount;

    public ITable GetTable(int index) => new Table(Live().GetTable(index));

    public IParagraph GetParagraph(int index)
    {
        return new Paragraph(Live().GetParagraph(index));
    }

    public void SaveAs(string filePath) => Live().SaveAs(filePath);

    public void Export(string filePath, string format) => Live().Export(filePath, format);

    public void Close()
    {
        if (_doc is null) return;
        _doc.Close();
    }

    public void Dispose()
    {
        if (_doc is null) return;
        Close();
        ComRelease.Release(_doc);
        _doc = null;
    }

    private Com.IWriterDocument Live() =>
        _doc ?? throw new ObjectDisposedException(nameof(Document));
}
