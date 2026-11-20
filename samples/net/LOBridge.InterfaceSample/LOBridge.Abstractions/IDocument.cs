namespace LOBridge.Abstractions;

/// <summary>A Writer document. Dispose releases the document and its COM references.</summary>
public interface IDocument : IDisposable
{
    int ParagraphCount { get; }

    int PageCount { get; }

    int TableCount { get; }

    /// <summary>Returns a table by zero-based index. Dispose the table when finished with it.</summary>
    ITable GetTable(int index);

    IParagraph AddParagraph(string text, float fontSize);

    IParagraph GetParagraph(int index);

    void SaveAs(string filePath);

    /// <summary>Exports the document. The format is a LibreOffice filter name such as "pdf".</summary>
    void Export(string filePath, string format);

    void Close();
}
