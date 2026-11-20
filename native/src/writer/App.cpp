// writer::App: implementation.
#include "writer/App.h"
#include "writer/PageSetup.h"
#include "writer/Document.h"

namespace writer {

App::App()
{
    try
    {
        m_session = StartSession();
    }
    catch (const css::uno::Exception& ex) { lo_com::LogException(ex.Message); }
    catch (...) { lo_com::LogException(OUString::createFromAscii("StartSession: unknown C++ exception")); }
}

App::~App()
{
    if (!m_disposed) EndSession(m_session);
}

STDMETHODIMP App::Dispose()
{
    if (!m_disposed)
    {
        EndSession(m_session);
        m_disposed = true;
    }
    return S_OK;
}

HRESULT App::OpenInternal(const OUString& url, bool readOnly, IWriterDocument** ppDoc)
{
    if (!ppDoc) return E_POINTER;
    *ppDoc = nullptr;
    if (!m_session.loader.is()) return E_FAIL;

    css::uno::Sequence<css::beans::PropertyValue> props = MakeProps({
        MakeProp("Hidden", css::uno::makeAny(true)),
        MakeProp("ReadOnly", css::uno::makeAny(readOnly))
    });

    Reference<css::lang::XComponent> component =
        m_session.loader->loadComponentFromURL(url, Ascii("_blank"), 0, props);
    Reference<css_text::XTextDocument> document(component, UNO_QUERY);
    if (!document.is()) return S_OK;

    // SetPreconditions: fit the page width so that the view cursor X coordinate is correct.
    if (SetZoomFitWidth())
    {
        try
        {
            Reference<XPropertySet> view = Reference<css::view::XViewSettingsSupplier>(
                document->getCurrentController(), UNO_QUERY)->getViewSettings();
            view->setPropertyValue(Ascii("ZoomType"),
                                   css::uno::makeAny(css::view::DocumentZoomType::PAGE_WIDTH));
        }
        catch (const css::uno::Exception&) {}
    }

    return ReturnNew<IWriterDocument>(new Document(document), ppDoc);
}

STDMETHODIMP App::NewDoc(VARIANT_BOOL landscape, float pageHeight, float pageWidth, IWriterDocument** ppDoc)
{
    LO_COM_TRY
    if (!ppDoc) return E_POINTER;
    IWriterDocument* doc = nullptr;
    HRESULT hr = OpenInternal(Ascii("private:factory/swriter"), false, &doc);
    if (FAILED(hr)) return hr;
    if (!doc)
    {
        *ppDoc = nullptr;
        return S_OK;
    }
    Document* impl = static_cast<Document*>(doc);
    PageSetup setup(impl->m_doc, Ascii("Standard"));
    setup.SetPageSize(pageWidth, pageHeight);
    setup.SetLandscape(FromVB(landscape));
    *ppDoc = doc;
    return S_OK;
    LO_COM_CATCH
}

STDMETHODIMP App::Open(BSTR filePath, VARIANT_BOOL readOnly, IWriterDocument** ppDoc)
{
    LO_COM_TRY
    return OpenInternal(ToUrl(ToOUString(filePath)), FromVB(readOnly), ppDoc);
    LO_COM_CATCH
}

STDMETHODIMP App::get_ActiveDocument(IWriterDocument** ppDoc)
{
    LO_COM_TRY
    if (!ppDoc) return E_POINTER;
    *ppDoc = nullptr;
    if (!m_session.desktop.is()) return S_OK;

    // The last opened text document is returned, as in the .NET version.
    Reference<css::container::XEnumerationAccess> components = m_session.desktop->getComponents();
    Reference<css_text::XTextDocument> last;
    Reference<css::container::XEnumeration> en = components->createEnumeration();
    while (en->hasMoreElements())
    {
        Any a = en->nextElement();
        Reference<css_text::XTextDocument> doc;
        if (a >>= doc) last = doc;
    }
    if (!last.is()) return S_OK;
    return ReturnNew<IWriterDocument>(new Document(last), ppDoc);
    LO_COM_CATCH
}

} // namespace writer
