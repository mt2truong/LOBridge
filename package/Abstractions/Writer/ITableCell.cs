namespace LOBridge.Abstractions.Writer;

/// <summary>One cell of a table. Dispose releases its COM reference.</summary>
public interface ITableCell : IDisposable
{
    string Text { get; }
}
