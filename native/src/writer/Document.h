// writer::Document. See writer/Helpers.h for the shared includes.
#pragma once

#include "writer/Helpers.h"

namespace writer {

// ---------------------------------------------------------------------------
// Document.
// ---------------------------------------------------------------------------
class Document final : public IWriterDocument
{
public:
    explicit Document(const Reference<css::text::XTextDocument>& doc);
    LO_COM_IUNKNOWN_AND_DISPATCH(IWriterDocument)

    STDMETHODIMP Dispose() override;
    STDMETHODIMP SaveAs(BSTR filePath) override;
    STDMETHODIMP Export(BSTR filePath, BSTR format) override;
    STDMETHODIMP Close() override;
    STDMETHODIMP get_PageCount(long* pVal) override;
    STDMETHODIMP get_CharacterCount(long* pVal) override;
    STDMETHODIMP HasContent(VARIANT_BOOL* pVal) override;
    STDMETHODIMP GetTemplateName(BSTR filePath, BSTR* pVal) override;
    STDMETHODIMP DeletePageByIndex(long pageIndex) override;
    STDMETHODIMP get_TableCount(long* pVal) override;
    STDMETHODIMP GetTable(long index, IWriterTable** ppVal) override;
    STDMETHODIMP get_StyleCount(long* pVal) override;
    STDMETHODIMP GetStyle(long index, IWriterStyle** ppVal) override;
    STDMETHODIMP GetStyleByName(BSTR name, IWriterStyle** ppVal) override;
    STDMETHODIMP get_ShapeCount(long* pVal) override;
    STDMETHODIMP GetShape(long index, IWriterShape** ppVal) override;
    STDMETHODIMP AddTextBox(long pageIndex, IWriterShape** ppVal) override;
    STDMETHODIMP CreateShape(long pageIndex, IWriterShape* sourceShape, IWriterShape** ppVal) override;
    STDMETHODIMP CreateShape_2(long pageIndex, BSTR shapeType, IWriterShape** ppVal) override;
    STDMETHODIMP get_PageSetup(IWriterPageSetup** ppVal) override;
    STDMETHODIMP get_ParagraphCount(long* pVal) override;
    STDMETHODIMP GetParagraph(long index, IWriterParagraph** ppVal) override;
    STDMETHODIMP AddNewParagraph(IWriterParagraph** ppVal) override;
    STDMETHODIMP ToggleShowHiddenText(VARIANT_BOOL flag) override;

    // Used by other classes of this namespace.
    Reference<css::text::XTextDocument> m_doc;

    // Export helper (used by the XML export of the .docx package).
    HRESULT ExportInternal(const OUString& filePath, const OUString& format);

private:
    std::vector<std::pair<OUString, OUString>> m_styleList;  // (family, name)
    bool m_styleListLoaded = false;
    void EnsureStyleList();
    bool HasContentInternal();
    long ParagraphCountInternal();
};

} // namespace writer
