using LOBridge.Abstractions.Writer;
using Com = Interop.LOBridge;

namespace LOBridge.ComAdapter.Writer;

/// <summary>Paragraph backed by a native WriterParagraph COM object.</summary>
internal sealed class Paragraph : IParagraph
{
    private readonly Com.IWriterParagraph _paragraph;

    internal Paragraph(Com.IWriterParagraph paragraph)
    {
        _paragraph = paragraph;
    }

    public string Text
    {
        get => _paragraph.Text;
        set => _paragraph.Text = value;
    }
}
