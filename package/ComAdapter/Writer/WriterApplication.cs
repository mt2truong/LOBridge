using LOBridge.Abstractions.Writer;
using Com = Interop.LOBridge;

namespace LOBridge.ComAdapter.Writer;

/// <summary>Writer application backed by the native WriterApp COM object.</summary>
internal sealed class WriterApplication : IWriterApplication
{
    private Com.WriterAppClass? _app = new();

    public IDocument NewDocument(bool landscape, float pageWidth, float pageHeight)
    {
        var app = Live();
        return new Document(app.NewDoc(landscape, pageHeight, pageWidth));
    }

    public IDocument Open(string filePath, bool readOnly)
    {
        var app = Live();
        return new Document(app.Open(filePath, readOnly));
    }

    public void Dispose()
    {
        if (_app is null) return;
        _app.Dispose();
        ComRelease.Release(_app);
        _app = null;
    }

    private Com.WriterAppClass Live() =>
        _app ?? throw new ObjectDisposedException(nameof(WriterApplication));
}
