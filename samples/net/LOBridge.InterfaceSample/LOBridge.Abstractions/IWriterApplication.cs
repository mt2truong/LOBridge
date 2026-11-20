namespace LOBridge.Abstractions;

/// <summary>Entry point for Writer (Word-compatible) documents.</summary>
public interface IWriterApplication : IDisposable
{
    /// <summary>Creates an empty document. Page sizes are in points.</summary>
    IDocument NewDocument(bool landscape, float pageWidth, float pageHeight);

    /// <summary>Opens an existing file such as a .docx.</summary>
    IDocument Open(string filePath, bool readOnly);
}
