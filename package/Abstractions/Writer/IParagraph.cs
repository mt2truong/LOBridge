namespace LOBridge.Abstractions.Writer;

/// <summary>One paragraph of a Writer document.</summary>
public interface IParagraph
{
    string Text { get; set; }
}
