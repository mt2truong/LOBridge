// writer::Document: implementation.
#include "writer/Document.h"
#include "writer/PageSetup.h"
#include "writer/Style.h"
#include "writer/Paragraph.h"
#include "writer/Table.h"
#include "writer/Shape.h"

namespace writer {

Document::Document(const Reference<css_text::XTextDocument>& doc) : m_doc(doc) {}

STDMETHODIMP Document::Dispose()
{
    return Close();
}

STDMETHODIMP Document::Close()
{
    if (!m_doc.is()) return S_OK;
    try
    {
        Reference<css::util::XCloseable> closeable(m_doc, UNO_QUERY);
        if (closeable.is()) closeable->close(false);
    }
    catch (const css::uno::Exception&) {}
    return S_OK;
}

STDMETHODIMP Document::get_PageCount(long* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    Reference<XPropertySet> controller(m_doc->getCurrentController(), UNO_QUERY);
    *pVal = (long)GetProp<sal_Int32>(controller, "PageCount");
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP Document::get_CharacterCount(long* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    *pVal = (long)GetProp<sal_Int32>(PS(m_doc), "CharacterCount");
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP Document::get_TableCount(long* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    *pVal = 0;
    Reference<css::container::XNameAccess> tables = Reference<css_text::XTextTablesSupplier>(m_doc, UNO_QUERY)->getTextTables();
    if (!tables.is()) return S_OK;
    *pVal = (long)Reference<css::container::XIndexAccess>(tables, UNO_QUERY)->getCount();
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP Document::GetTable(long index, IWriterTable** ppVal)
{
    LO_COM_TRY
    Reference<css::container::XNameAccess> tables = Reference<css_text::XTextTablesSupplier>(m_doc, UNO_QUERY)->getTextTables();
    if (!tables.is())
    {
        *ppVal = nullptr;
        return S_OK;
    }
    Any a = Reference<css::container::XIndexAccess>(tables, UNO_QUERY)->getByIndex((sal_Int32)index);
    Reference<css_text::XTextTable> t;
    a >>= t;
    return ReturnNew<IWriterTable>(new Table(m_doc, t), ppVal);
    LO_COM_CATCH
}

void Document::EnsureStyleList()
{
    if (m_styleListLoaded) return;
    m_styleListLoaded = true;

    Reference<css::container::XNameAccess> families =
        Reference<css::style::XStyleFamiliesSupplier>(m_doc, UNO_QUERY)->getStyleFamilies();
    if (!families.is()) return;

    css::uno::Sequence<OUString> names = families->getElementNames();
    for (sal_Int32 i = 0; i < names.getLength(); ++i)
    {
        Reference<css::container::XNameContainer> container;
        families->getByName(names[i]) >>= container;
        if (!container.is()) continue;
        Reference<css::container::XIndexAccess> index(container, UNO_QUERY);
        sal_Int32 count = index->getCount();
        for (sal_Int32 j = 0; j < count; ++j)
        {
            Reference<css::style::XStyle> st;
            index->getByIndex(j) >>= st;
            if (!st.is()) continue;
            try
            {
                m_styleList.emplace_back(names[i], st->getName());
            }
            catch (const css::uno::Exception&) {}
        }
    }
}

STDMETHODIMP Document::get_StyleCount(long* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    EnsureStyleList();
    *pVal = (long)m_styleList.size();
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP Document::GetStyle(long index, IWriterStyle** ppVal)
{
    LO_COM_TRY
    EnsureStyleList();
    if (index < 0 || (size_t)index >= m_styleList.size()) return E_INVALIDARG;
    const auto item = m_styleList[(size_t)index];

    Reference<css::container::XNameAccess> families =
        Reference<css::style::XStyleFamiliesSupplier>(m_doc, UNO_QUERY)->getStyleFamilies();
    Reference<css::container::XNameContainer> container;
    families->getByName(item.first) >>= container;
    Reference<XPropertySet> ps;
    container->getByName(item.second) >>= ps;
    return ReturnNew<IWriterStyle>(new Style(ps, item.second), ppVal);
    LO_COM_CATCH
}

STDMETHODIMP Document::GetStyleByName(BSTR name, IWriterStyle** ppVal)
{
    LO_COM_TRY
    EnsureStyleList();
    OUString wanted = ToOUString(name);
    for (const auto& item : m_styleList)
    {
        if (item.second != wanted) continue;
        Reference<css::container::XNameAccess> families =
            Reference<css::style::XStyleFamiliesSupplier>(m_doc, UNO_QUERY)->getStyleFamilies();
        Reference<css::container::XNameContainer> container;
        families->getByName(item.first) >>= container;
        Reference<XPropertySet> ps;
        container->getByName(item.second) >>= ps;
        return ReturnNew<IWriterStyle>(new Style(ps, item.second), ppVal);
    }
    *ppVal = nullptr;
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP Document::get_ShapeCount(long* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    Reference<css::drawing::XDrawPage> page = Reference<css::drawing::XDrawPageSupplier>(m_doc, UNO_QUERY)->getDrawPage();
    *pVal = (long)Reference<css::container::XIndexAccess>(page, UNO_QUERY)->getCount();
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP Document::GetShape(long index, IWriterShape** ppVal)
{
    LO_COM_TRY
    Reference<css::drawing::XDrawPage> page = Reference<css::drawing::XDrawPageSupplier>(m_doc, UNO_QUERY)->getDrawPage();
    Reference<css::drawing::XShape> shape;
    Reference<css::container::XIndexAccess>(page, UNO_QUERY)->getByIndex((sal_Int32)index) >>= shape;
    return ReturnNew<IWriterShape>(new Shape(m_doc, shape), ppVal);
    LO_COM_CATCH
}

STDMETHODIMP Document::AddTextBox(long pageIndex, IWriterShape** ppVal)
{
    LO_COM_TRY
    short pageNum = (short)(pageIndex + 1);
    Reference<css_text::XTextViewCursor> viewCursor = Reference<css_text::XTextViewCursorSupplier>(
        m_doc->getCurrentController(), UNO_QUERY)->getViewCursor();
    Reference<css_text::XPageCursor> pageCursor(viewCursor, UNO_QUERY);
    pageCursor->jumpToPage(pageNum);

    Reference<css_text::XText> text = viewCursor->getText();
    Reference<css_text::XTextCursor> modelCursor = text->createTextCursorByRange(viewCursor->getStart());

    // Insert a paragraph break and a page break at the position of the view cursor.
    text->insertControlCharacter(Reference<css_text::XTextRange>(modelCursor, UNO_QUERY),
                                 css_text::ControlCharacter::PARAGRAPH_BREAK, false);
    Reference<XPropertySet>(modelCursor, UNO_QUERY)->setPropertyValue(
        Ascii("BreakType"), css::uno::makeAny(css::style::BreakType_PAGE_AFTER));

    Reference<css::lang::XMultiServiceFactory> factory(m_doc, UNO_QUERY);
    Reference<css_text::XTextFrame> frame(factory->createInstance(Ascii("com.sun.star.text.TextFrame")), UNO_QUERY);
    text->insertTextContent(Reference<css_text::XTextRange>(modelCursor, UNO_QUERY),
                            Reference<css_text::XTextContent>(frame, UNO_QUERY), false);

    Reference<css::drawing::XShape> shape(frame, UNO_QUERY);
    return ReturnNew<IWriterShape>(new Shape(m_doc, shape), ppVal);
    LO_COM_CATCH
}

STDMETHODIMP Document::CreateShape(long, IWriterShape*, IWriterShape** ppVal)
{
    if (ppVal) *ppVal = nullptr;
    return E_NOTIMPL;   // not implemented in the .NET version either
}

STDMETHODIMP Document::CreateShape_2(long, BSTR, IWriterShape** ppVal)
{
    if (ppVal) *ppVal = nullptr;
    return E_NOTIMPL;
}

STDMETHODIMP Document::DeletePageByIndex(long pageIndex)
{
    LO_COM_TRY
    Reference<css_text::XTextViewCursor> viewCursor = Reference<css_text::XTextViewCursorSupplier>(
        m_doc->getCurrentController(), UNO_QUERY)->getViewCursor();
    Reference<css_text::XPageCursor> pageCursor(viewCursor, UNO_QUERY);

    long pageCount = 0;
    get_PageCount(&pageCount);
    bool isFirstPage = pageIndex == 0;
    bool isLastPage = pageIndex == pageCount - 1;

    if (!isFirstPage)
    {
        // go to the last of the previous page
        pageCursor->jumpToPage((short)pageIndex);
        pageCursor->jumpToEndOfPage();
    }
    else
    {
        pageCursor->jumpToPage((short)(pageIndex + 1));   // top of the target page
    }

    Reference<css_text::XText> text = viewCursor->getText();
    Reference<css_text::XTextCursor> modelCursor = text->createTextCursorByRange(viewCursor->getStart());

    if (!isFirstPage)
    {
        // go to the end of the deleted page
        pageCursor->jumpToPage((short)(pageIndex + 1));
        pageCursor->jumpToEndOfPage();
    }
    else
    {
        if (isLastPage)
        {
            pageCursor->jumpToEndOfPage();
        }
        else
        {
            pageCursor->jumpToNextPage();
            pageCursor->jumpToEndOfPage();
        }
    }

    modelCursor->gotoRange(viewCursor->getStart(), true);   // select the whole page
    modelCursor->setString(OUString());
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP Document::get_PageSetup(IWriterPageSetup** ppVal)
{
    LO_COM_TRY
    return ReturnNew<IWriterPageSetup>(new PageSetup(m_doc, Ascii("Standard")), ppVal);
    LO_COM_CATCH
}

long Document::ParagraphCountInternal()
{
    long count = 0;
    Reference<css::container::XEnumerationAccess> access(m_doc->getText(), UNO_QUERY);
    Reference<css::container::XEnumeration> en = access->createEnumeration();
    while (en->hasMoreElements())
    {
        en->nextElement();
        ++count;
    }
    return count;
}

STDMETHODIMP Document::get_ParagraphCount(long* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    *pVal = ParagraphCountInternal();
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP Document::GetParagraph(long index, IWriterParagraph** ppVal)
{
    LO_COM_TRY
    // A table cell is a paragraph in Word, but not in LibreOffice.
    Reference<css::container::XEnumerationAccess> access(m_doc->getText(), UNO_QUERY);
    Reference<css::container::XEnumeration> en = access->createEnumeration();
    long i = 0;
    while (en->hasMoreElements())
    {
        Any a = en->nextElement();
        if (i++ != index) continue;
        Reference<css_text::XTextContent> content;
        a >>= content;
        if (!content.is()) break;
        return ReturnNew<IWriterParagraph>(new Paragraph(content->getAnchor()), ppVal);
    }
    *ppVal = nullptr;
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP Document::AddNewParagraph(IWriterParagraph** ppVal)
{
    LO_COM_TRY
    Reference<css_text::XText> text = m_doc->getText();
    Reference<css_text::XTextCursor> cursor = text->createTextCursor();
    cursor->gotoEnd(false);

    if (HasContentInternal())
    {
        // Create a paragraph break.
        text->insertControlCharacter(Reference<css_text::XTextRange>(cursor, UNO_QUERY),
                                     css_text::ControlCharacter::PARAGRAPH_BREAK, false);
    }
    return ReturnNew<IWriterParagraph>(new Paragraph(Reference<css_text::XTextRange>(cursor, UNO_QUERY)), ppVal);
    LO_COM_CATCH
}

STDMETHODIMP Document::HasContent(VARIANT_BOOL* pVal)
{
    if (!pVal) return E_POINTER;
    LO_COM_TRY
    *pVal = ToVB(HasContentInternal());
    return S_OK;
    LO_COM_CATCH
}

bool Document::HasContentInternal()
{
    long chars = 0, tables = 0, shapes = 0, paragraphs = 0;
    get_CharacterCount(&chars);
    get_TableCount(&tables);
    get_ShapeCount(&shapes);
    paragraphs = ParagraphCountInternal();
    return chars > 0 || paragraphs > 0 || tables > 0 || shapes > 0;
}

STDMETHODIMP Document::GetTemplateName(BSTR filePath, BSTR* pVal)
{
    if (!pVal) return E_POINTER;
    *pVal = ToBSTR(OUString());
    OUString path = ToOUString(filePath);
    if (path.isEmpty()) return S_OK;

    std::string settings;
    if (!lo_zip::ReadEntry(ToOUString(filePath), "word/settings.xml", settings)) return S_OK;
    std::string rels;
    lo_zip::ReadEntry(ToOUString(filePath), "word/_rels/settings.xml.rels", rels);

    std::string templateTarget = lo_zip::FindAttachedTemplateTarget(settings, rels);
    *pVal = ToBSTR(templateTarget);
    return S_OK;
}

STDMETHODIMP Document::SaveAs(BSTR filePath)
{
    LO_COM_TRY
    Reference<css::frame::XStorable> storable(m_doc, UNO_QUERY);
    OUString location = storable->getLocation();
    OUString path = ToOUString(filePath);
    OUString fileUrl = path.isEmpty() ? location : ToUrl(path);
    if (fileUrl == location)
    {
        storable->store();
        return S_OK;
    }
    std::wstring wpath(path.getStr(), path.getStr() + path.getLength());
    std::wstring ext = ExtensionOf(wpath);
    return ExportInternal(path, OUString(ext.c_str()));
    LO_COM_CATCH
}

STDMETHODIMP Document::Export(BSTR filePath, BSTR format)
{
    LO_COM_TRY
    return ExportInternal(ToOUString(filePath), ToOUString(format));
    LO_COM_CATCH
}

// Port of Document.Export. XML is produced by saving a .docx and extracting word/document.xml.
HRESULT Document::ExportInternal(const OUString& filePath, const OUString& format)
{
    std::wstring fmt = ToLowerW(std::wstring(format.getStr(), format.getStr() + format.getLength()));
    OUString tempFile = filePath;
    OUString exportFilter;
    if (fmt == L"pdf")
    {
        exportFilter = Ascii("writer_pdf_Export");
    }
    else if (fmt == L"xml")
    {
        wchar_t tempDir[MAX_PATH] = {};
        wchar_t tempName[MAX_PATH] = {};
        GetTempPathW(MAX_PATH, tempDir);
        GetTempFileNameW(tempDir, L"lot", 0, tempName);
        tempFile = OUString(reinterpret_cast<const sal_Unicode*>(tempName), (sal_Int32)wcslen(tempName));
        exportFilter = Ascii("Office Open XML Text");
    }
    else if (fmt == L"docx")
    {
        exportFilter = Ascii("Office Open XML Text");
    }
    else if (fmt == L"doc")
    {
        exportFilter = Ascii("MS Word 97");
    }
    else if (fmt == L"rtf")
    {
        exportFilter = Ascii("Rich Text Format");
    }
    else
    {
        return S_OK;   // unsupported format: nothing happens (same as the .NET version)
    }

    css::uno::Sequence<css::beans::PropertyValue> props = MakeProps({
        MakeProp("Overwrite", css::uno::makeAny(true)),
        MakeProp("FilterName", css::uno::makeAny(exportFilter))
    });
    if (fmt == L"pdf")
    {
        // Do not export bookmarks: headings would otherwise become bookmarks.
        props.realloc(3);
        props[2] = MakeProp("FilterOptions", css::uno::makeAny(
            OUString::createFromAscii("{\"ExportBookmarks\":{\"type\":\"boolean\",\"value\":\"false\"}}")));
    }

    Reference<css::frame::XStorable> storable(m_doc, UNO_QUERY);
    storable->storeToURL(ToUrl(tempFile), props);

    if (fmt == L"xml")
    {
        std::string xml;
        bool ok = lo_zip::ReadEntry(tempFile, "word/document.xml", xml);
        std::wstring tmp(tempFile.getStr(), tempFile.getStr() + tempFile.getLength());
        DeleteFileW(tmp.c_str());
        if (!ok) return E_FAIL;
        std::wstring target(filePath.getStr(), filePath.getStr() + filePath.getLength());
        std::ofstream out(target, std::ios::binary);
        if (!out) return E_FAIL;
        out.write(xml.data(), (std::streamsize)xml.size());
    }
    return S_OK;
}

STDMETHODIMP Document::ToggleShowHiddenText(VARIANT_BOOL flag)
{
    LO_COM_TRY
    Reference<XPropertySet> viewSettings = Reference<css::view::XViewSettingsSupplier>(
        m_doc->getCurrentController(), UNO_QUERY)->getViewSettings();
    bool value = FromVB(flag);
    viewSettings->setPropertyValue(Ascii("ShowHiddenCharacters"), css::uno::makeAny(value));
    viewSettings->setPropertyValue(Ascii("ShowNonprintingCharacters"), css::uno::makeAny(value));
    return S_OK;
    LO_COM_CATCH
}

} // namespace writer
