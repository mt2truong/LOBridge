

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0628 */
/* at Tue Jan 19 10:14:07 2038
 */
/* Compiler settings for idl\LOBridge.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0628 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __LOBridge_h_h__
#define __LOBridge_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef DECLSPEC_XFGVIRT
#if defined(_CONTROL_FLOW_GUARD_XFG)
#define DECLSPEC_XFGVIRT(base, func) __declspec(xfg_virtual(base, func))
#else
#define DECLSPEC_XFGVIRT(base, func)
#endif
#endif

/* Forward Declarations */ 

#ifndef __IWriterApp_FWD_DEFINED__
#define __IWriterApp_FWD_DEFINED__
typedef interface IWriterApp IWriterApp;

#endif 	/* __IWriterApp_FWD_DEFINED__ */


#ifndef __IWriterDocument_FWD_DEFINED__
#define __IWriterDocument_FWD_DEFINED__
typedef interface IWriterDocument IWriterDocument;

#endif 	/* __IWriterDocument_FWD_DEFINED__ */


#ifndef __IWriterRange_FWD_DEFINED__
#define __IWriterRange_FWD_DEFINED__
typedef interface IWriterRange IWriterRange;

#endif 	/* __IWriterRange_FWD_DEFINED__ */


#ifndef __IWriterParagraph_FWD_DEFINED__
#define __IWriterParagraph_FWD_DEFINED__
typedef interface IWriterParagraph IWriterParagraph;

#endif 	/* __IWriterParagraph_FWD_DEFINED__ */


#ifndef __IWriterStyle_FWD_DEFINED__
#define __IWriterStyle_FWD_DEFINED__
typedef interface IWriterStyle IWriterStyle;

#endif 	/* __IWriterStyle_FWD_DEFINED__ */


#ifndef __IWriterFont_FWD_DEFINED__
#define __IWriterFont_FWD_DEFINED__
typedef interface IWriterFont IWriterFont;

#endif 	/* __IWriterFont_FWD_DEFINED__ */


#ifndef __IWriterPageSetup_FWD_DEFINED__
#define __IWriterPageSetup_FWD_DEFINED__
typedef interface IWriterPageSetup IWriterPageSetup;

#endif 	/* __IWriterPageSetup_FWD_DEFINED__ */


#ifndef __IWriterShape_FWD_DEFINED__
#define __IWriterShape_FWD_DEFINED__
typedef interface IWriterShape IWriterShape;

#endif 	/* __IWriterShape_FWD_DEFINED__ */


#ifndef __IWriterTable_FWD_DEFINED__
#define __IWriterTable_FWD_DEFINED__
typedef interface IWriterTable IWriterTable;

#endif 	/* __IWriterTable_FWD_DEFINED__ */


#ifndef __IWriterTableRow_FWD_DEFINED__
#define __IWriterTableRow_FWD_DEFINED__
typedef interface IWriterTableRow IWriterTableRow;

#endif 	/* __IWriterTableRow_FWD_DEFINED__ */


#ifndef __IWriterTableColumn_FWD_DEFINED__
#define __IWriterTableColumn_FWD_DEFINED__
typedef interface IWriterTableColumn IWriterTableColumn;

#endif 	/* __IWriterTableColumn_FWD_DEFINED__ */


#ifndef __IWriterTableCell_FWD_DEFINED__
#define __IWriterTableCell_FWD_DEFINED__
typedef interface IWriterTableCell IWriterTableCell;

#endif 	/* __IWriterTableCell_FWD_DEFINED__ */


#ifndef __ICalcApp_FWD_DEFINED__
#define __ICalcApp_FWD_DEFINED__
typedef interface ICalcApp ICalcApp;

#endif 	/* __ICalcApp_FWD_DEFINED__ */


#ifndef __ICalcWorkbook_FWD_DEFINED__
#define __ICalcWorkbook_FWD_DEFINED__
typedef interface ICalcWorkbook ICalcWorkbook;

#endif 	/* __ICalcWorkbook_FWD_DEFINED__ */


#ifndef __ICalcWorksheet_FWD_DEFINED__
#define __ICalcWorksheet_FWD_DEFINED__
typedef interface ICalcWorksheet ICalcWorksheet;

#endif 	/* __ICalcWorksheet_FWD_DEFINED__ */


#ifndef __ICalcRange_FWD_DEFINED__
#define __ICalcRange_FWD_DEFINED__
typedef interface ICalcRange ICalcRange;

#endif 	/* __ICalcRange_FWD_DEFINED__ */


#ifndef __ICalcCell_FWD_DEFINED__
#define __ICalcCell_FWD_DEFINED__
typedef interface ICalcCell ICalcCell;

#endif 	/* __ICalcCell_FWD_DEFINED__ */


#ifndef __IWriterApp_FWD_DEFINED__
#define __IWriterApp_FWD_DEFINED__
typedef interface IWriterApp IWriterApp;

#endif 	/* __IWriterApp_FWD_DEFINED__ */


#ifndef __IWriterDocument_FWD_DEFINED__
#define __IWriterDocument_FWD_DEFINED__
typedef interface IWriterDocument IWriterDocument;

#endif 	/* __IWriterDocument_FWD_DEFINED__ */


#ifndef __IWriterRange_FWD_DEFINED__
#define __IWriterRange_FWD_DEFINED__
typedef interface IWriterRange IWriterRange;

#endif 	/* __IWriterRange_FWD_DEFINED__ */


#ifndef __IWriterParagraph_FWD_DEFINED__
#define __IWriterParagraph_FWD_DEFINED__
typedef interface IWriterParagraph IWriterParagraph;

#endif 	/* __IWriterParagraph_FWD_DEFINED__ */


#ifndef __IWriterStyle_FWD_DEFINED__
#define __IWriterStyle_FWD_DEFINED__
typedef interface IWriterStyle IWriterStyle;

#endif 	/* __IWriterStyle_FWD_DEFINED__ */


#ifndef __IWriterFont_FWD_DEFINED__
#define __IWriterFont_FWD_DEFINED__
typedef interface IWriterFont IWriterFont;

#endif 	/* __IWriterFont_FWD_DEFINED__ */


#ifndef __IWriterPageSetup_FWD_DEFINED__
#define __IWriterPageSetup_FWD_DEFINED__
typedef interface IWriterPageSetup IWriterPageSetup;

#endif 	/* __IWriterPageSetup_FWD_DEFINED__ */


#ifndef __IWriterShape_FWD_DEFINED__
#define __IWriterShape_FWD_DEFINED__
typedef interface IWriterShape IWriterShape;

#endif 	/* __IWriterShape_FWD_DEFINED__ */


#ifndef __IWriterTable_FWD_DEFINED__
#define __IWriterTable_FWD_DEFINED__
typedef interface IWriterTable IWriterTable;

#endif 	/* __IWriterTable_FWD_DEFINED__ */


#ifndef __IWriterTableRow_FWD_DEFINED__
#define __IWriterTableRow_FWD_DEFINED__
typedef interface IWriterTableRow IWriterTableRow;

#endif 	/* __IWriterTableRow_FWD_DEFINED__ */


#ifndef __IWriterTableCell_FWD_DEFINED__
#define __IWriterTableCell_FWD_DEFINED__
typedef interface IWriterTableCell IWriterTableCell;

#endif 	/* __IWriterTableCell_FWD_DEFINED__ */


#ifndef __IWriterTableColumn_FWD_DEFINED__
#define __IWriterTableColumn_FWD_DEFINED__
typedef interface IWriterTableColumn IWriterTableColumn;

#endif 	/* __IWriterTableColumn_FWD_DEFINED__ */


#ifndef __ICalcApp_FWD_DEFINED__
#define __ICalcApp_FWD_DEFINED__
typedef interface ICalcApp ICalcApp;

#endif 	/* __ICalcApp_FWD_DEFINED__ */


#ifndef __ICalcWorkbook_FWD_DEFINED__
#define __ICalcWorkbook_FWD_DEFINED__
typedef interface ICalcWorkbook ICalcWorkbook;

#endif 	/* __ICalcWorkbook_FWD_DEFINED__ */


#ifndef __ICalcWorksheet_FWD_DEFINED__
#define __ICalcWorksheet_FWD_DEFINED__
typedef interface ICalcWorksheet ICalcWorksheet;

#endif 	/* __ICalcWorksheet_FWD_DEFINED__ */


#ifndef __ICalcRange_FWD_DEFINED__
#define __ICalcRange_FWD_DEFINED__
typedef interface ICalcRange ICalcRange;

#endif 	/* __ICalcRange_FWD_DEFINED__ */


#ifndef __ICalcCell_FWD_DEFINED__
#define __ICalcCell_FWD_DEFINED__
typedef interface ICalcCell ICalcCell;

#endif 	/* __ICalcCell_FWD_DEFINED__ */


#ifndef __WriterApp_FWD_DEFINED__
#define __WriterApp_FWD_DEFINED__

#ifdef __cplusplus
typedef class WriterApp WriterApp;
#else
typedef struct WriterApp WriterApp;
#endif /* __cplusplus */

#endif 	/* __WriterApp_FWD_DEFINED__ */


#ifndef __CalcApp_FWD_DEFINED__
#define __CalcApp_FWD_DEFINED__

#ifdef __cplusplus
typedef class CalcApp CalcApp;
#else
typedef struct CalcApp CalcApp;
#endif /* __cplusplus */

#endif 	/* __CalcApp_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_LOBridge_0000_0000 */
/* [local] */ 

typedef /* [uuid][v1_enum] */  DECLSPEC_UUID("A8B5D2E1-4F3C-4A87-9E2B-1D8C5A7F9B3E") 
enum RowHeightRule
    {
        Auto	= 0,
        AtLeast	= 1,
        Exactly	= 2
    } 	RowHeightRule;




















extern RPC_IF_HANDLE __MIDL_itf_LOBridge_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_LOBridge_0000_0000_v0_0_s_ifspec;

#ifndef __IWriterApp_INTERFACE_DEFINED__
#define __IWriterApp_INTERFACE_DEFINED__

/* interface IWriterApp */
/* [uuid][unique][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IWriterApp;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ED59FA07-BA94-4651-AEB1-F861A58B18DB")
    IWriterApp : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Dispose( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE NewDoc( 
            /* [in] */ VARIANT_BOOL landscape,
            /* [in] */ float pageHeight,
            /* [in] */ float pageWidth,
            /* [retval][out] */ IWriterDocument **ppDoc) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [in] */ BSTR filePath,
            /* [in] */ VARIANT_BOOL readOnly,
            /* [retval][out] */ IWriterDocument **ppDoc) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ActiveDocument( 
            /* [retval][out] */ IWriterDocument **ppDoc) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWriterAppVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWriterApp * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWriterApp * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWriterApp * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IWriterApp * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IWriterApp * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IWriterApp * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IWriterApp * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(IWriterApp, Dispose)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Dispose )( 
            IWriterApp * This);
        
        DECLSPEC_XFGVIRT(IWriterApp, NewDoc)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *NewDoc )( 
            IWriterApp * This,
            /* [in] */ VARIANT_BOOL landscape,
            /* [in] */ float pageHeight,
            /* [in] */ float pageWidth,
            /* [retval][out] */ IWriterDocument **ppDoc);
        
        DECLSPEC_XFGVIRT(IWriterApp, Open)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IWriterApp * This,
            /* [in] */ BSTR filePath,
            /* [in] */ VARIANT_BOOL readOnly,
            /* [retval][out] */ IWriterDocument **ppDoc);
        
        DECLSPEC_XFGVIRT(IWriterApp, get_ActiveDocument)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveDocument )( 
            IWriterApp * This,
            /* [retval][out] */ IWriterDocument **ppDoc);
        
        END_INTERFACE
    } IWriterAppVtbl;

    interface IWriterApp
    {
        CONST_VTBL struct IWriterAppVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWriterApp_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWriterApp_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWriterApp_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWriterApp_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IWriterApp_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IWriterApp_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IWriterApp_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IWriterApp_Dispose(This)	\
    ( (This)->lpVtbl -> Dispose(This) ) 

#define IWriterApp_NewDoc(This,landscape,pageHeight,pageWidth,ppDoc)	\
    ( (This)->lpVtbl -> NewDoc(This,landscape,pageHeight,pageWidth,ppDoc) ) 

#define IWriterApp_Open(This,filePath,readOnly,ppDoc)	\
    ( (This)->lpVtbl -> Open(This,filePath,readOnly,ppDoc) ) 

#define IWriterApp_get_ActiveDocument(This,ppDoc)	\
    ( (This)->lpVtbl -> get_ActiveDocument(This,ppDoc) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWriterApp_INTERFACE_DEFINED__ */


#ifndef __IWriterDocument_INTERFACE_DEFINED__
#define __IWriterDocument_INTERFACE_DEFINED__

/* interface IWriterDocument */
/* [uuid][unique][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IWriterDocument;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("04165BCA-4A1E-4727-95BD-1BD3FA124069")
    IWriterDocument : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Dispose( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SaveAs( 
            /* [in] */ BSTR filePath) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Export( 
            /* [in] */ BSTR filePath,
            /* [in] */ BSTR format) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_PageCount( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_CharacterCount( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE HasContent( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetTemplateName( 
            /* [in] */ BSTR filePath,
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE DeletePageByIndex( 
            /* [in] */ long pageIndex) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_TableCount( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetTable( 
            /* [in] */ long index,
            /* [retval][out] */ IWriterTable **ppVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_StyleCount( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetStyle( 
            /* [in] */ long index,
            /* [retval][out] */ IWriterStyle **ppVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetStyleByName( 
            /* [in] */ BSTR name,
            /* [retval][out] */ IWriterStyle **ppVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ShapeCount( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetShape( 
            /* [in] */ long index,
            /* [retval][out] */ IWriterShape **ppVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE AddTextBox( 
            /* [in] */ long pageIndex,
            /* [retval][out] */ IWriterShape **ppVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateShape( 
            /* [in] */ long pageIndex,
            /* [in] */ IWriterShape *sourceShape,
            /* [retval][out] */ IWriterShape **ppVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateShape_2( 
            /* [in] */ long pageIndex,
            /* [in] */ BSTR shapeType,
            /* [retval][out] */ IWriterShape **ppVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_PageSetup( 
            /* [retval][out] */ IWriterPageSetup **ppVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ParagraphCount( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetParagraph( 
            /* [in] */ long index,
            /* [retval][out] */ IWriterParagraph **ppVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE AddNewParagraph( 
            /* [retval][out] */ IWriterParagraph **ppVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ToggleShowHiddenText( 
            /* [in] */ VARIANT_BOOL flag) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWriterDocumentVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWriterDocument * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWriterDocument * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWriterDocument * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IWriterDocument * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IWriterDocument * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IWriterDocument * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IWriterDocument * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(IWriterDocument, Dispose)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Dispose )( 
            IWriterDocument * This);
        
        DECLSPEC_XFGVIRT(IWriterDocument, SaveAs)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SaveAs )( 
            IWriterDocument * This,
            /* [in] */ BSTR filePath);
        
        DECLSPEC_XFGVIRT(IWriterDocument, Export)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Export )( 
            IWriterDocument * This,
            /* [in] */ BSTR filePath,
            /* [in] */ BSTR format);
        
        DECLSPEC_XFGVIRT(IWriterDocument, Close)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IWriterDocument * This);
        
        DECLSPEC_XFGVIRT(IWriterDocument, get_PageCount)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PageCount )( 
            IWriterDocument * This,
            /* [retval][out] */ long *pVal);
        
        DECLSPEC_XFGVIRT(IWriterDocument, get_CharacterCount)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CharacterCount )( 
            IWriterDocument * This,
            /* [retval][out] */ long *pVal);
        
        DECLSPEC_XFGVIRT(IWriterDocument, HasContent)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *HasContent )( 
            IWriterDocument * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        DECLSPEC_XFGVIRT(IWriterDocument, GetTemplateName)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetTemplateName )( 
            IWriterDocument * This,
            /* [in] */ BSTR filePath,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IWriterDocument, DeletePageByIndex)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *DeletePageByIndex )( 
            IWriterDocument * This,
            /* [in] */ long pageIndex);
        
        DECLSPEC_XFGVIRT(IWriterDocument, get_TableCount)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TableCount )( 
            IWriterDocument * This,
            /* [retval][out] */ long *pVal);
        
        DECLSPEC_XFGVIRT(IWriterDocument, GetTable)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetTable )( 
            IWriterDocument * This,
            /* [in] */ long index,
            /* [retval][out] */ IWriterTable **ppVal);
        
        DECLSPEC_XFGVIRT(IWriterDocument, get_StyleCount)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StyleCount )( 
            IWriterDocument * This,
            /* [retval][out] */ long *pVal);
        
        DECLSPEC_XFGVIRT(IWriterDocument, GetStyle)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetStyle )( 
            IWriterDocument * This,
            /* [in] */ long index,
            /* [retval][out] */ IWriterStyle **ppVal);
        
        DECLSPEC_XFGVIRT(IWriterDocument, GetStyleByName)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetStyleByName )( 
            IWriterDocument * This,
            /* [in] */ BSTR name,
            /* [retval][out] */ IWriterStyle **ppVal);
        
        DECLSPEC_XFGVIRT(IWriterDocument, get_ShapeCount)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ShapeCount )( 
            IWriterDocument * This,
            /* [retval][out] */ long *pVal);
        
        DECLSPEC_XFGVIRT(IWriterDocument, GetShape)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetShape )( 
            IWriterDocument * This,
            /* [in] */ long index,
            /* [retval][out] */ IWriterShape **ppVal);
        
        DECLSPEC_XFGVIRT(IWriterDocument, AddTextBox)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *AddTextBox )( 
            IWriterDocument * This,
            /* [in] */ long pageIndex,
            /* [retval][out] */ IWriterShape **ppVal);
        
        DECLSPEC_XFGVIRT(IWriterDocument, CreateShape)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CreateShape )( 
            IWriterDocument * This,
            /* [in] */ long pageIndex,
            /* [in] */ IWriterShape *sourceShape,
            /* [retval][out] */ IWriterShape **ppVal);
        
        DECLSPEC_XFGVIRT(IWriterDocument, CreateShape_2)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CreateShape_2 )( 
            IWriterDocument * This,
            /* [in] */ long pageIndex,
            /* [in] */ BSTR shapeType,
            /* [retval][out] */ IWriterShape **ppVal);
        
        DECLSPEC_XFGVIRT(IWriterDocument, get_PageSetup)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PageSetup )( 
            IWriterDocument * This,
            /* [retval][out] */ IWriterPageSetup **ppVal);
        
        DECLSPEC_XFGVIRT(IWriterDocument, get_ParagraphCount)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ParagraphCount )( 
            IWriterDocument * This,
            /* [retval][out] */ long *pVal);
        
        DECLSPEC_XFGVIRT(IWriterDocument, GetParagraph)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetParagraph )( 
            IWriterDocument * This,
            /* [in] */ long index,
            /* [retval][out] */ IWriterParagraph **ppVal);
        
        DECLSPEC_XFGVIRT(IWriterDocument, AddNewParagraph)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *AddNewParagraph )( 
            IWriterDocument * This,
            /* [retval][out] */ IWriterParagraph **ppVal);
        
        DECLSPEC_XFGVIRT(IWriterDocument, ToggleShowHiddenText)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ToggleShowHiddenText )( 
            IWriterDocument * This,
            /* [in] */ VARIANT_BOOL flag);
        
        END_INTERFACE
    } IWriterDocumentVtbl;

    interface IWriterDocument
    {
        CONST_VTBL struct IWriterDocumentVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWriterDocument_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWriterDocument_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWriterDocument_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWriterDocument_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IWriterDocument_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IWriterDocument_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IWriterDocument_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IWriterDocument_Dispose(This)	\
    ( (This)->lpVtbl -> Dispose(This) ) 

#define IWriterDocument_SaveAs(This,filePath)	\
    ( (This)->lpVtbl -> SaveAs(This,filePath) ) 

#define IWriterDocument_Export(This,filePath,format)	\
    ( (This)->lpVtbl -> Export(This,filePath,format) ) 

#define IWriterDocument_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IWriterDocument_get_PageCount(This,pVal)	\
    ( (This)->lpVtbl -> get_PageCount(This,pVal) ) 

#define IWriterDocument_get_CharacterCount(This,pVal)	\
    ( (This)->lpVtbl -> get_CharacterCount(This,pVal) ) 

#define IWriterDocument_HasContent(This,pVal)	\
    ( (This)->lpVtbl -> HasContent(This,pVal) ) 

#define IWriterDocument_GetTemplateName(This,filePath,pVal)	\
    ( (This)->lpVtbl -> GetTemplateName(This,filePath,pVal) ) 

#define IWriterDocument_DeletePageByIndex(This,pageIndex)	\
    ( (This)->lpVtbl -> DeletePageByIndex(This,pageIndex) ) 

#define IWriterDocument_get_TableCount(This,pVal)	\
    ( (This)->lpVtbl -> get_TableCount(This,pVal) ) 

#define IWriterDocument_GetTable(This,index,ppVal)	\
    ( (This)->lpVtbl -> GetTable(This,index,ppVal) ) 

#define IWriterDocument_get_StyleCount(This,pVal)	\
    ( (This)->lpVtbl -> get_StyleCount(This,pVal) ) 

#define IWriterDocument_GetStyle(This,index,ppVal)	\
    ( (This)->lpVtbl -> GetStyle(This,index,ppVal) ) 

#define IWriterDocument_GetStyleByName(This,name,ppVal)	\
    ( (This)->lpVtbl -> GetStyleByName(This,name,ppVal) ) 

#define IWriterDocument_get_ShapeCount(This,pVal)	\
    ( (This)->lpVtbl -> get_ShapeCount(This,pVal) ) 

#define IWriterDocument_GetShape(This,index,ppVal)	\
    ( (This)->lpVtbl -> GetShape(This,index,ppVal) ) 

#define IWriterDocument_AddTextBox(This,pageIndex,ppVal)	\
    ( (This)->lpVtbl -> AddTextBox(This,pageIndex,ppVal) ) 

#define IWriterDocument_CreateShape(This,pageIndex,sourceShape,ppVal)	\
    ( (This)->lpVtbl -> CreateShape(This,pageIndex,sourceShape,ppVal) ) 

#define IWriterDocument_CreateShape_2(This,pageIndex,shapeType,ppVal)	\
    ( (This)->lpVtbl -> CreateShape_2(This,pageIndex,shapeType,ppVal) ) 

#define IWriterDocument_get_PageSetup(This,ppVal)	\
    ( (This)->lpVtbl -> get_PageSetup(This,ppVal) ) 

#define IWriterDocument_get_ParagraphCount(This,pVal)	\
    ( (This)->lpVtbl -> get_ParagraphCount(This,pVal) ) 

#define IWriterDocument_GetParagraph(This,index,ppVal)	\
    ( (This)->lpVtbl -> GetParagraph(This,index,ppVal) ) 

#define IWriterDocument_AddNewParagraph(This,ppVal)	\
    ( (This)->lpVtbl -> AddNewParagraph(This,ppVal) ) 

#define IWriterDocument_ToggleShowHiddenText(This,flag)	\
    ( (This)->lpVtbl -> ToggleShowHiddenText(This,flag) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWriterDocument_INTERFACE_DEFINED__ */


#ifndef __IWriterRange_INTERFACE_DEFINED__
#define __IWriterRange_INTERFACE_DEFINED__

/* interface IWriterRange */
/* [uuid][unique][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IWriterRange;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("97171A27-24A9-4D4D-82D7-2EFC21D6E060")
    IWriterRange : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_PageSetup( 
            /* [retval][out] */ IWriterPageSetup **ppVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_LineSpacingMode( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_LineSpacingMode( 
            /* [in] */ long value) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_LineSpacingHeight( 
            /* [retval][out] */ float *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_LineSpacingHeight( 
            /* [in] */ float value) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Start( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Start( 
            /* [in] */ long value) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_End( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_End( 
            /* [in] */ long value) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_SpaceBefore( 
            /* [retval][out] */ float *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_SpaceBefore( 
            /* [in] */ float value) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_SpaceAfter( 
            /* [retval][out] */ float *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_SpaceAfter( 
            /* [in] */ float value) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_KeepTogetherNextParagraph( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_KeepTogetherNextParagraph( 
            /* [in] */ VARIANT_BOOL value) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetRangeHeight( 
            /* [retval][out] */ float *pVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetVerticalPositionRelativeToPage( 
            /* [retval][out] */ float *pVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetStaticLines( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE LinesToPoints( 
            /* [in] */ float value,
            /* [retval][out] */ float *pVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWriterRangeVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWriterRange * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWriterRange * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWriterRange * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IWriterRange * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IWriterRange * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IWriterRange * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IWriterRange * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(IWriterRange, get_PageSetup)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PageSetup )( 
            IWriterRange * This,
            /* [retval][out] */ IWriterPageSetup **ppVal);
        
        DECLSPEC_XFGVIRT(IWriterRange, get_LineSpacingMode)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LineSpacingMode )( 
            IWriterRange * This,
            /* [retval][out] */ long *pVal);
        
        DECLSPEC_XFGVIRT(IWriterRange, put_LineSpacingMode)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LineSpacingMode )( 
            IWriterRange * This,
            /* [in] */ long value);
        
        DECLSPEC_XFGVIRT(IWriterRange, get_LineSpacingHeight)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LineSpacingHeight )( 
            IWriterRange * This,
            /* [retval][out] */ float *pVal);
        
        DECLSPEC_XFGVIRT(IWriterRange, put_LineSpacingHeight)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LineSpacingHeight )( 
            IWriterRange * This,
            /* [in] */ float value);
        
        DECLSPEC_XFGVIRT(IWriterRange, get_Start)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Start )( 
            IWriterRange * This,
            /* [retval][out] */ long *pVal);
        
        DECLSPEC_XFGVIRT(IWriterRange, put_Start)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Start )( 
            IWriterRange * This,
            /* [in] */ long value);
        
        DECLSPEC_XFGVIRT(IWriterRange, get_End)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_End )( 
            IWriterRange * This,
            /* [retval][out] */ long *pVal);
        
        DECLSPEC_XFGVIRT(IWriterRange, put_End)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_End )( 
            IWriterRange * This,
            /* [in] */ long value);
        
        DECLSPEC_XFGVIRT(IWriterRange, get_SpaceBefore)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SpaceBefore )( 
            IWriterRange * This,
            /* [retval][out] */ float *pVal);
        
        DECLSPEC_XFGVIRT(IWriterRange, put_SpaceBefore)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SpaceBefore )( 
            IWriterRange * This,
            /* [in] */ float value);
        
        DECLSPEC_XFGVIRT(IWriterRange, get_SpaceAfter)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SpaceAfter )( 
            IWriterRange * This,
            /* [retval][out] */ float *pVal);
        
        DECLSPEC_XFGVIRT(IWriterRange, put_SpaceAfter)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SpaceAfter )( 
            IWriterRange * This,
            /* [in] */ float value);
        
        DECLSPEC_XFGVIRT(IWriterRange, get_KeepTogetherNextParagraph)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_KeepTogetherNextParagraph )( 
            IWriterRange * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        DECLSPEC_XFGVIRT(IWriterRange, put_KeepTogetherNextParagraph)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_KeepTogetherNextParagraph )( 
            IWriterRange * This,
            /* [in] */ VARIANT_BOOL value);
        
        DECLSPEC_XFGVIRT(IWriterRange, GetRangeHeight)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetRangeHeight )( 
            IWriterRange * This,
            /* [retval][out] */ float *pVal);
        
        DECLSPEC_XFGVIRT(IWriterRange, GetVerticalPositionRelativeToPage)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetVerticalPositionRelativeToPage )( 
            IWriterRange * This,
            /* [retval][out] */ float *pVal);
        
        DECLSPEC_XFGVIRT(IWriterRange, GetStaticLines)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetStaticLines )( 
            IWriterRange * This,
            /* [retval][out] */ long *pVal);
        
        DECLSPEC_XFGVIRT(IWriterRange, LinesToPoints)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *LinesToPoints )( 
            IWriterRange * This,
            /* [in] */ float value,
            /* [retval][out] */ float *pVal);
        
        END_INTERFACE
    } IWriterRangeVtbl;

    interface IWriterRange
    {
        CONST_VTBL struct IWriterRangeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWriterRange_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWriterRange_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWriterRange_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWriterRange_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IWriterRange_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IWriterRange_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IWriterRange_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IWriterRange_get_PageSetup(This,ppVal)	\
    ( (This)->lpVtbl -> get_PageSetup(This,ppVal) ) 

#define IWriterRange_get_LineSpacingMode(This,pVal)	\
    ( (This)->lpVtbl -> get_LineSpacingMode(This,pVal) ) 

#define IWriterRange_put_LineSpacingMode(This,value)	\
    ( (This)->lpVtbl -> put_LineSpacingMode(This,value) ) 

#define IWriterRange_get_LineSpacingHeight(This,pVal)	\
    ( (This)->lpVtbl -> get_LineSpacingHeight(This,pVal) ) 

#define IWriterRange_put_LineSpacingHeight(This,value)	\
    ( (This)->lpVtbl -> put_LineSpacingHeight(This,value) ) 

#define IWriterRange_get_Start(This,pVal)	\
    ( (This)->lpVtbl -> get_Start(This,pVal) ) 

#define IWriterRange_put_Start(This,value)	\
    ( (This)->lpVtbl -> put_Start(This,value) ) 

#define IWriterRange_get_End(This,pVal)	\
    ( (This)->lpVtbl -> get_End(This,pVal) ) 

#define IWriterRange_put_End(This,value)	\
    ( (This)->lpVtbl -> put_End(This,value) ) 

#define IWriterRange_get_SpaceBefore(This,pVal)	\
    ( (This)->lpVtbl -> get_SpaceBefore(This,pVal) ) 

#define IWriterRange_put_SpaceBefore(This,value)	\
    ( (This)->lpVtbl -> put_SpaceBefore(This,value) ) 

#define IWriterRange_get_SpaceAfter(This,pVal)	\
    ( (This)->lpVtbl -> get_SpaceAfter(This,pVal) ) 

#define IWriterRange_put_SpaceAfter(This,value)	\
    ( (This)->lpVtbl -> put_SpaceAfter(This,value) ) 

#define IWriterRange_get_KeepTogetherNextParagraph(This,pVal)	\
    ( (This)->lpVtbl -> get_KeepTogetherNextParagraph(This,pVal) ) 

#define IWriterRange_put_KeepTogetherNextParagraph(This,value)	\
    ( (This)->lpVtbl -> put_KeepTogetherNextParagraph(This,value) ) 

#define IWriterRange_GetRangeHeight(This,pVal)	\
    ( (This)->lpVtbl -> GetRangeHeight(This,pVal) ) 

#define IWriterRange_GetVerticalPositionRelativeToPage(This,pVal)	\
    ( (This)->lpVtbl -> GetVerticalPositionRelativeToPage(This,pVal) ) 

#define IWriterRange_GetStaticLines(This,pVal)	\
    ( (This)->lpVtbl -> GetStaticLines(This,pVal) ) 

#define IWriterRange_LinesToPoints(This,value,pVal)	\
    ( (This)->lpVtbl -> LinesToPoints(This,value,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWriterRange_INTERFACE_DEFINED__ */


#ifndef __IWriterParagraph_INTERFACE_DEFINED__
#define __IWriterParagraph_INTERFACE_DEFINED__

/* interface IWriterParagraph */
/* [uuid][unique][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IWriterParagraph;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("32565F22-7707-4474-9EB1-6F26820C9BF3")
    IWriterParagraph : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Text( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Text( 
            /* [in] */ BSTR value) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetRawText( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Font( 
            /* [retval][out] */ IWriterFont **ppVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWriterParagraphVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWriterParagraph * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWriterParagraph * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWriterParagraph * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IWriterParagraph * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IWriterParagraph * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IWriterParagraph * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IWriterParagraph * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(IWriterParagraph, get_Text)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Text )( 
            IWriterParagraph * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IWriterParagraph, put_Text)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Text )( 
            IWriterParagraph * This,
            /* [in] */ BSTR value);
        
        DECLSPEC_XFGVIRT(IWriterParagraph, GetRawText)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetRawText )( 
            IWriterParagraph * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IWriterParagraph, get_Font)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Font )( 
            IWriterParagraph * This,
            /* [retval][out] */ IWriterFont **ppVal);
        
        END_INTERFACE
    } IWriterParagraphVtbl;

    interface IWriterParagraph
    {
        CONST_VTBL struct IWriterParagraphVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWriterParagraph_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWriterParagraph_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWriterParagraph_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWriterParagraph_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IWriterParagraph_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IWriterParagraph_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IWriterParagraph_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IWriterParagraph_get_Text(This,pVal)	\
    ( (This)->lpVtbl -> get_Text(This,pVal) ) 

#define IWriterParagraph_put_Text(This,value)	\
    ( (This)->lpVtbl -> put_Text(This,value) ) 

#define IWriterParagraph_GetRawText(This,pVal)	\
    ( (This)->lpVtbl -> GetRawText(This,pVal) ) 

#define IWriterParagraph_get_Font(This,ppVal)	\
    ( (This)->lpVtbl -> get_Font(This,ppVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWriterParagraph_INTERFACE_DEFINED__ */


#ifndef __IWriterStyle_INTERFACE_DEFINED__
#define __IWriterStyle_INTERFACE_DEFINED__

/* interface IWriterStyle */
/* [uuid][unique][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IWriterStyle;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9FEBE58B-9B2C-43A5-9AFE-CBBE20581F57")
    IWriterStyle : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Font( 
            /* [retval][out] */ IWriterFont **ppVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWriterStyleVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWriterStyle * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWriterStyle * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWriterStyle * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IWriterStyle * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IWriterStyle * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IWriterStyle * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IWriterStyle * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(IWriterStyle, get_Name)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IWriterStyle * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IWriterStyle, get_Font)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Font )( 
            IWriterStyle * This,
            /* [retval][out] */ IWriterFont **ppVal);
        
        END_INTERFACE
    } IWriterStyleVtbl;

    interface IWriterStyle
    {
        CONST_VTBL struct IWriterStyleVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWriterStyle_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWriterStyle_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWriterStyle_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWriterStyle_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IWriterStyle_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IWriterStyle_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IWriterStyle_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IWriterStyle_get_Name(This,pVal)	\
    ( (This)->lpVtbl -> get_Name(This,pVal) ) 

#define IWriterStyle_get_Font(This,ppVal)	\
    ( (This)->lpVtbl -> get_Font(This,ppVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWriterStyle_INTERFACE_DEFINED__ */


#ifndef __IWriterFont_INTERFACE_DEFINED__
#define __IWriterFont_INTERFACE_DEFINED__

/* interface IWriterFont */
/* [uuid][unique][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IWriterFont;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("79D5AAF8-5E30-4690-A60C-1A1099206970")
    IWriterFont : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Size( 
            /* [retval][out] */ float *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Size( 
            /* [in] */ float value) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Bold( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Italic( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Underline( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Color( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Hidden( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Hidden( 
            /* [in] */ VARIANT_BOOL value) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWriterFontVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWriterFont * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWriterFont * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWriterFont * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IWriterFont * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IWriterFont * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IWriterFont * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IWriterFont * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(IWriterFont, get_Name)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IWriterFont * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IWriterFont, get_Size)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )( 
            IWriterFont * This,
            /* [retval][out] */ float *pVal);
        
        DECLSPEC_XFGVIRT(IWriterFont, put_Size)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Size )( 
            IWriterFont * This,
            /* [in] */ float value);
        
        DECLSPEC_XFGVIRT(IWriterFont, get_Bold)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Bold )( 
            IWriterFont * This,
            /* [retval][out] */ long *pVal);
        
        DECLSPEC_XFGVIRT(IWriterFont, get_Italic)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Italic )( 
            IWriterFont * This,
            /* [retval][out] */ long *pVal);
        
        DECLSPEC_XFGVIRT(IWriterFont, get_Underline)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Underline )( 
            IWriterFont * This,
            /* [retval][out] */ long *pVal);
        
        DECLSPEC_XFGVIRT(IWriterFont, get_Color)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Color )( 
            IWriterFont * This,
            /* [retval][out] */ long *pVal);
        
        DECLSPEC_XFGVIRT(IWriterFont, get_Hidden)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Hidden )( 
            IWriterFont * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        DECLSPEC_XFGVIRT(IWriterFont, put_Hidden)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Hidden )( 
            IWriterFont * This,
            /* [in] */ VARIANT_BOOL value);
        
        END_INTERFACE
    } IWriterFontVtbl;

    interface IWriterFont
    {
        CONST_VTBL struct IWriterFontVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWriterFont_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWriterFont_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWriterFont_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWriterFont_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IWriterFont_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IWriterFont_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IWriterFont_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IWriterFont_get_Name(This,pVal)	\
    ( (This)->lpVtbl -> get_Name(This,pVal) ) 

#define IWriterFont_get_Size(This,pVal)	\
    ( (This)->lpVtbl -> get_Size(This,pVal) ) 

#define IWriterFont_put_Size(This,value)	\
    ( (This)->lpVtbl -> put_Size(This,value) ) 

#define IWriterFont_get_Bold(This,pVal)	\
    ( (This)->lpVtbl -> get_Bold(This,pVal) ) 

#define IWriterFont_get_Italic(This,pVal)	\
    ( (This)->lpVtbl -> get_Italic(This,pVal) ) 

#define IWriterFont_get_Underline(This,pVal)	\
    ( (This)->lpVtbl -> get_Underline(This,pVal) ) 

#define IWriterFont_get_Color(This,pVal)	\
    ( (This)->lpVtbl -> get_Color(This,pVal) ) 

#define IWriterFont_get_Hidden(This,pVal)	\
    ( (This)->lpVtbl -> get_Hidden(This,pVal) ) 

#define IWriterFont_put_Hidden(This,value)	\
    ( (This)->lpVtbl -> put_Hidden(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWriterFont_INTERFACE_DEFINED__ */


#ifndef __IWriterPageSetup_INTERFACE_DEFINED__
#define __IWriterPageSetup_INTERFACE_DEFINED__

/* interface IWriterPageSetup */
/* [uuid][unique][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IWriterPageSetup;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("29321D04-DE50-4064-9C9B-E4E942D4021A")
    IWriterPageSetup : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_PaperSize( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_PageWidth( 
            /* [retval][out] */ float *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_PageHeight( 
            /* [retval][out] */ float *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_LeftMargin( 
            /* [retval][out] */ float *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_LeftMargin( 
            /* [in] */ float value) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_RightMargin( 
            /* [retval][out] */ float *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_RightMargin( 
            /* [in] */ float value) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_TopMargin( 
            /* [retval][out] */ float *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_TopMargin( 
            /* [in] */ float value) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_BottomMargin( 
            /* [retval][out] */ float *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_BottomMargin( 
            /* [in] */ float value) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWriterPageSetupVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWriterPageSetup * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWriterPageSetup * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWriterPageSetup * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IWriterPageSetup * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IWriterPageSetup * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IWriterPageSetup * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IWriterPageSetup * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(IWriterPageSetup, get_PaperSize)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PaperSize )( 
            IWriterPageSetup * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IWriterPageSetup, get_PageWidth)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PageWidth )( 
            IWriterPageSetup * This,
            /* [retval][out] */ float *pVal);
        
        DECLSPEC_XFGVIRT(IWriterPageSetup, get_PageHeight)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PageHeight )( 
            IWriterPageSetup * This,
            /* [retval][out] */ float *pVal);
        
        DECLSPEC_XFGVIRT(IWriterPageSetup, get_LeftMargin)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LeftMargin )( 
            IWriterPageSetup * This,
            /* [retval][out] */ float *pVal);
        
        DECLSPEC_XFGVIRT(IWriterPageSetup, put_LeftMargin)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LeftMargin )( 
            IWriterPageSetup * This,
            /* [in] */ float value);
        
        DECLSPEC_XFGVIRT(IWriterPageSetup, get_RightMargin)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RightMargin )( 
            IWriterPageSetup * This,
            /* [retval][out] */ float *pVal);
        
        DECLSPEC_XFGVIRT(IWriterPageSetup, put_RightMargin)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RightMargin )( 
            IWriterPageSetup * This,
            /* [in] */ float value);
        
        DECLSPEC_XFGVIRT(IWriterPageSetup, get_TopMargin)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TopMargin )( 
            IWriterPageSetup * This,
            /* [retval][out] */ float *pVal);
        
        DECLSPEC_XFGVIRT(IWriterPageSetup, put_TopMargin)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TopMargin )( 
            IWriterPageSetup * This,
            /* [in] */ float value);
        
        DECLSPEC_XFGVIRT(IWriterPageSetup, get_BottomMargin)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BottomMargin )( 
            IWriterPageSetup * This,
            /* [retval][out] */ float *pVal);
        
        DECLSPEC_XFGVIRT(IWriterPageSetup, put_BottomMargin)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BottomMargin )( 
            IWriterPageSetup * This,
            /* [in] */ float value);
        
        END_INTERFACE
    } IWriterPageSetupVtbl;

    interface IWriterPageSetup
    {
        CONST_VTBL struct IWriterPageSetupVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWriterPageSetup_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWriterPageSetup_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWriterPageSetup_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWriterPageSetup_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IWriterPageSetup_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IWriterPageSetup_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IWriterPageSetup_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IWriterPageSetup_get_PaperSize(This,pVal)	\
    ( (This)->lpVtbl -> get_PaperSize(This,pVal) ) 

#define IWriterPageSetup_get_PageWidth(This,pVal)	\
    ( (This)->lpVtbl -> get_PageWidth(This,pVal) ) 

#define IWriterPageSetup_get_PageHeight(This,pVal)	\
    ( (This)->lpVtbl -> get_PageHeight(This,pVal) ) 

#define IWriterPageSetup_get_LeftMargin(This,pVal)	\
    ( (This)->lpVtbl -> get_LeftMargin(This,pVal) ) 

#define IWriterPageSetup_put_LeftMargin(This,value)	\
    ( (This)->lpVtbl -> put_LeftMargin(This,value) ) 

#define IWriterPageSetup_get_RightMargin(This,pVal)	\
    ( (This)->lpVtbl -> get_RightMargin(This,pVal) ) 

#define IWriterPageSetup_put_RightMargin(This,value)	\
    ( (This)->lpVtbl -> put_RightMargin(This,value) ) 

#define IWriterPageSetup_get_TopMargin(This,pVal)	\
    ( (This)->lpVtbl -> get_TopMargin(This,pVal) ) 

#define IWriterPageSetup_put_TopMargin(This,value)	\
    ( (This)->lpVtbl -> put_TopMargin(This,value) ) 

#define IWriterPageSetup_get_BottomMargin(This,pVal)	\
    ( (This)->lpVtbl -> get_BottomMargin(This,pVal) ) 

#define IWriterPageSetup_put_BottomMargin(This,value)	\
    ( (This)->lpVtbl -> put_BottomMargin(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWriterPageSetup_INTERFACE_DEFINED__ */


#ifndef __IWriterShape_INTERFACE_DEFINED__
#define __IWriterShape_INTERFACE_DEFINED__

/* interface IWriterShape */
/* [uuid][unique][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IWriterShape;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("88066F85-A66C-4200-A049-D2970240546F")
    IWriterShape : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Width( 
            /* [retval][out] */ float *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Width( 
            /* [in] */ float value) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Height( 
            /* [retval][out] */ float *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Height( 
            /* [in] */ float value) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_LeftPosition( 
            /* [retval][out] */ float *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_TopPosition( 
            /* [retval][out] */ float *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ShapeType( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetAlignment( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetTextFont( 
            /* [retval][out] */ IWriterFont **ppVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CopyFrom( 
            /* [in] */ IWriterShape *shape) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Text( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Text( 
            /* [in] */ BSTR value) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_PageSetup( 
            /* [retval][out] */ IWriterPageSetup **ppVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWriterShapeVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWriterShape * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWriterShape * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWriterShape * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IWriterShape * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IWriterShape * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IWriterShape * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IWriterShape * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(IWriterShape, get_Width)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Width )( 
            IWriterShape * This,
            /* [retval][out] */ float *pVal);
        
        DECLSPEC_XFGVIRT(IWriterShape, put_Width)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Width )( 
            IWriterShape * This,
            /* [in] */ float value);
        
        DECLSPEC_XFGVIRT(IWriterShape, get_Height)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Height )( 
            IWriterShape * This,
            /* [retval][out] */ float *pVal);
        
        DECLSPEC_XFGVIRT(IWriterShape, put_Height)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Height )( 
            IWriterShape * This,
            /* [in] */ float value);
        
        DECLSPEC_XFGVIRT(IWriterShape, get_LeftPosition)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LeftPosition )( 
            IWriterShape * This,
            /* [retval][out] */ float *pVal);
        
        DECLSPEC_XFGVIRT(IWriterShape, get_TopPosition)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TopPosition )( 
            IWriterShape * This,
            /* [retval][out] */ float *pVal);
        
        DECLSPEC_XFGVIRT(IWriterShape, get_ShapeType)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ShapeType )( 
            IWriterShape * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IWriterShape, GetAlignment)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetAlignment )( 
            IWriterShape * This,
            /* [retval][out] */ long *pVal);
        
        DECLSPEC_XFGVIRT(IWriterShape, GetTextFont)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetTextFont )( 
            IWriterShape * This,
            /* [retval][out] */ IWriterFont **ppVal);
        
        DECLSPEC_XFGVIRT(IWriterShape, CopyFrom)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CopyFrom )( 
            IWriterShape * This,
            /* [in] */ IWriterShape *shape);
        
        DECLSPEC_XFGVIRT(IWriterShape, get_Text)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Text )( 
            IWriterShape * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IWriterShape, put_Text)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Text )( 
            IWriterShape * This,
            /* [in] */ BSTR value);
        
        DECLSPEC_XFGVIRT(IWriterShape, get_PageSetup)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PageSetup )( 
            IWriterShape * This,
            /* [retval][out] */ IWriterPageSetup **ppVal);
        
        END_INTERFACE
    } IWriterShapeVtbl;

    interface IWriterShape
    {
        CONST_VTBL struct IWriterShapeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWriterShape_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWriterShape_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWriterShape_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWriterShape_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IWriterShape_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IWriterShape_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IWriterShape_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IWriterShape_get_Width(This,pVal)	\
    ( (This)->lpVtbl -> get_Width(This,pVal) ) 

#define IWriterShape_put_Width(This,value)	\
    ( (This)->lpVtbl -> put_Width(This,value) ) 

#define IWriterShape_get_Height(This,pVal)	\
    ( (This)->lpVtbl -> get_Height(This,pVal) ) 

#define IWriterShape_put_Height(This,value)	\
    ( (This)->lpVtbl -> put_Height(This,value) ) 

#define IWriterShape_get_LeftPosition(This,pVal)	\
    ( (This)->lpVtbl -> get_LeftPosition(This,pVal) ) 

#define IWriterShape_get_TopPosition(This,pVal)	\
    ( (This)->lpVtbl -> get_TopPosition(This,pVal) ) 

#define IWriterShape_get_ShapeType(This,pVal)	\
    ( (This)->lpVtbl -> get_ShapeType(This,pVal) ) 

#define IWriterShape_GetAlignment(This,pVal)	\
    ( (This)->lpVtbl -> GetAlignment(This,pVal) ) 

#define IWriterShape_GetTextFont(This,ppVal)	\
    ( (This)->lpVtbl -> GetTextFont(This,ppVal) ) 

#define IWriterShape_CopyFrom(This,shape)	\
    ( (This)->lpVtbl -> CopyFrom(This,shape) ) 

#define IWriterShape_get_Text(This,pVal)	\
    ( (This)->lpVtbl -> get_Text(This,pVal) ) 

#define IWriterShape_put_Text(This,value)	\
    ( (This)->lpVtbl -> put_Text(This,value) ) 

#define IWriterShape_get_PageSetup(This,ppVal)	\
    ( (This)->lpVtbl -> get_PageSetup(This,ppVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWriterShape_INTERFACE_DEFINED__ */


#ifndef __IWriterTable_INTERFACE_DEFINED__
#define __IWriterTable_INTERFACE_DEFINED__

/* interface IWriterTable */
/* [uuid][unique][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IWriterTable;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B58F6AE4-CE77-4426-BAB2-931279BD19E7")
    IWriterTable : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_AllowAutoFit( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_AllowAutoFit( 
            /* [in] */ VARIANT_BOOL value) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_RowCount( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ColumnCount( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_LeftPadding( 
            /* [retval][out] */ float *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_LeftPadding( 
            /* [in] */ float value) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_TopPadding( 
            /* [retval][out] */ float *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_TopPadding( 
            /* [in] */ float value) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_BottomPadding( 
            /* [retval][out] */ float *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_BottomPadding( 
            /* [in] */ float value) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_RightPadding( 
            /* [retval][out] */ float *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_RightPadding( 
            /* [in] */ float value) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetRow( 
            /* [in] */ long index,
            /* [retval][out] */ IWriterTableRow **ppVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetColumn( 
            /* [in] */ long index,
            /* [retval][out] */ IWriterTableColumn **ppVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Normalize( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE AddRow( 
            /* [in] */ IWriterTableRow *rowAfter,
            /* [retval][out] */ IWriterTableRow **ppVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE DeleteRow( 
            /* [in] */ IWriterTableRow *row) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetTabStops( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWriterTableVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWriterTable * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWriterTable * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWriterTable * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IWriterTable * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IWriterTable * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IWriterTable * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IWriterTable * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(IWriterTable, get_AllowAutoFit)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AllowAutoFit )( 
            IWriterTable * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        DECLSPEC_XFGVIRT(IWriterTable, put_AllowAutoFit)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AllowAutoFit )( 
            IWriterTable * This,
            /* [in] */ VARIANT_BOOL value);
        
        DECLSPEC_XFGVIRT(IWriterTable, get_RowCount)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RowCount )( 
            IWriterTable * This,
            /* [retval][out] */ long *pVal);
        
        DECLSPEC_XFGVIRT(IWriterTable, get_ColumnCount)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ColumnCount )( 
            IWriterTable * This,
            /* [retval][out] */ long *pVal);
        
        DECLSPEC_XFGVIRT(IWriterTable, get_LeftPadding)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LeftPadding )( 
            IWriterTable * This,
            /* [retval][out] */ float *pVal);
        
        DECLSPEC_XFGVIRT(IWriterTable, put_LeftPadding)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LeftPadding )( 
            IWriterTable * This,
            /* [in] */ float value);
        
        DECLSPEC_XFGVIRT(IWriterTable, get_TopPadding)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TopPadding )( 
            IWriterTable * This,
            /* [retval][out] */ float *pVal);
        
        DECLSPEC_XFGVIRT(IWriterTable, put_TopPadding)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TopPadding )( 
            IWriterTable * This,
            /* [in] */ float value);
        
        DECLSPEC_XFGVIRT(IWriterTable, get_BottomPadding)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BottomPadding )( 
            IWriterTable * This,
            /* [retval][out] */ float *pVal);
        
        DECLSPEC_XFGVIRT(IWriterTable, put_BottomPadding)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BottomPadding )( 
            IWriterTable * This,
            /* [in] */ float value);
        
        DECLSPEC_XFGVIRT(IWriterTable, get_RightPadding)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RightPadding )( 
            IWriterTable * This,
            /* [retval][out] */ float *pVal);
        
        DECLSPEC_XFGVIRT(IWriterTable, put_RightPadding)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RightPadding )( 
            IWriterTable * This,
            /* [in] */ float value);
        
        DECLSPEC_XFGVIRT(IWriterTable, GetRow)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetRow )( 
            IWriterTable * This,
            /* [in] */ long index,
            /* [retval][out] */ IWriterTableRow **ppVal);
        
        DECLSPEC_XFGVIRT(IWriterTable, GetColumn)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetColumn )( 
            IWriterTable * This,
            /* [in] */ long index,
            /* [retval][out] */ IWriterTableColumn **ppVal);
        
        DECLSPEC_XFGVIRT(IWriterTable, Normalize)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Normalize )( 
            IWriterTable * This);
        
        DECLSPEC_XFGVIRT(IWriterTable, AddRow)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *AddRow )( 
            IWriterTable * This,
            /* [in] */ IWriterTableRow *rowAfter,
            /* [retval][out] */ IWriterTableRow **ppVal);
        
        DECLSPEC_XFGVIRT(IWriterTable, DeleteRow)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *DeleteRow )( 
            IWriterTable * This,
            /* [in] */ IWriterTableRow *row);
        
        DECLSPEC_XFGVIRT(IWriterTable, SetTabStops)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetTabStops )( 
            IWriterTable * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        END_INTERFACE
    } IWriterTableVtbl;

    interface IWriterTable
    {
        CONST_VTBL struct IWriterTableVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWriterTable_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWriterTable_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWriterTable_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWriterTable_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IWriterTable_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IWriterTable_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IWriterTable_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IWriterTable_get_AllowAutoFit(This,pVal)	\
    ( (This)->lpVtbl -> get_AllowAutoFit(This,pVal) ) 

#define IWriterTable_put_AllowAutoFit(This,value)	\
    ( (This)->lpVtbl -> put_AllowAutoFit(This,value) ) 

#define IWriterTable_get_RowCount(This,pVal)	\
    ( (This)->lpVtbl -> get_RowCount(This,pVal) ) 

#define IWriterTable_get_ColumnCount(This,pVal)	\
    ( (This)->lpVtbl -> get_ColumnCount(This,pVal) ) 

#define IWriterTable_get_LeftPadding(This,pVal)	\
    ( (This)->lpVtbl -> get_LeftPadding(This,pVal) ) 

#define IWriterTable_put_LeftPadding(This,value)	\
    ( (This)->lpVtbl -> put_LeftPadding(This,value) ) 

#define IWriterTable_get_TopPadding(This,pVal)	\
    ( (This)->lpVtbl -> get_TopPadding(This,pVal) ) 

#define IWriterTable_put_TopPadding(This,value)	\
    ( (This)->lpVtbl -> put_TopPadding(This,value) ) 

#define IWriterTable_get_BottomPadding(This,pVal)	\
    ( (This)->lpVtbl -> get_BottomPadding(This,pVal) ) 

#define IWriterTable_put_BottomPadding(This,value)	\
    ( (This)->lpVtbl -> put_BottomPadding(This,value) ) 

#define IWriterTable_get_RightPadding(This,pVal)	\
    ( (This)->lpVtbl -> get_RightPadding(This,pVal) ) 

#define IWriterTable_put_RightPadding(This,value)	\
    ( (This)->lpVtbl -> put_RightPadding(This,value) ) 

#define IWriterTable_GetRow(This,index,ppVal)	\
    ( (This)->lpVtbl -> GetRow(This,index,ppVal) ) 

#define IWriterTable_GetColumn(This,index,ppVal)	\
    ( (This)->lpVtbl -> GetColumn(This,index,ppVal) ) 

#define IWriterTable_Normalize(This)	\
    ( (This)->lpVtbl -> Normalize(This) ) 

#define IWriterTable_AddRow(This,rowAfter,ppVal)	\
    ( (This)->lpVtbl -> AddRow(This,rowAfter,ppVal) ) 

#define IWriterTable_DeleteRow(This,row)	\
    ( (This)->lpVtbl -> DeleteRow(This,row) ) 

#define IWriterTable_SetTabStops(This,pVal)	\
    ( (This)->lpVtbl -> SetTabStops(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWriterTable_INTERFACE_DEFINED__ */


#ifndef __IWriterTableRow_INTERFACE_DEFINED__
#define __IWriterTableRow_INTERFACE_DEFINED__

/* interface IWriterTableRow */
/* [uuid][unique][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IWriterTableRow;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("77B5CBCB-ADA4-4468-B189-5446B957CA86")
    IWriterTableRow : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Range( 
            /* [retval][out] */ IWriterRange **ppVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Height( 
            /* [retval][out] */ float *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Height( 
            /* [in] */ float value) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_HeightRule( 
            /* [retval][out] */ RowHeightRule *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_HeightRule( 
            /* [in] */ RowHeightRule value) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_AllowSplit( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_AllowSplit( 
            /* [in] */ VARIANT_BOOL value) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_CellCount( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetCell( 
            /* [in] */ long index,
            /* [retval][out] */ IWriterTableCell **ppVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsRepeatingRow( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetStyle( 
            /* [in] */ IWriterStyle *style) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWriterTableRowVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWriterTableRow * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWriterTableRow * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWriterTableRow * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IWriterTableRow * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IWriterTableRow * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IWriterTableRow * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IWriterTableRow * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(IWriterTableRow, get_Range)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Range )( 
            IWriterTableRow * This,
            /* [retval][out] */ IWriterRange **ppVal);
        
        DECLSPEC_XFGVIRT(IWriterTableRow, get_Height)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Height )( 
            IWriterTableRow * This,
            /* [retval][out] */ float *pVal);
        
        DECLSPEC_XFGVIRT(IWriterTableRow, put_Height)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Height )( 
            IWriterTableRow * This,
            /* [in] */ float value);
        
        DECLSPEC_XFGVIRT(IWriterTableRow, get_HeightRule)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HeightRule )( 
            IWriterTableRow * This,
            /* [retval][out] */ RowHeightRule *pVal);
        
        DECLSPEC_XFGVIRT(IWriterTableRow, put_HeightRule)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_HeightRule )( 
            IWriterTableRow * This,
            /* [in] */ RowHeightRule value);
        
        DECLSPEC_XFGVIRT(IWriterTableRow, get_AllowSplit)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AllowSplit )( 
            IWriterTableRow * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        DECLSPEC_XFGVIRT(IWriterTableRow, put_AllowSplit)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AllowSplit )( 
            IWriterTableRow * This,
            /* [in] */ VARIANT_BOOL value);
        
        DECLSPEC_XFGVIRT(IWriterTableRow, get_CellCount)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CellCount )( 
            IWriterTableRow * This,
            /* [retval][out] */ long *pVal);
        
        DECLSPEC_XFGVIRT(IWriterTableRow, GetCell)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetCell )( 
            IWriterTableRow * This,
            /* [in] */ long index,
            /* [retval][out] */ IWriterTableCell **ppVal);
        
        DECLSPEC_XFGVIRT(IWriterTableRow, IsRepeatingRow)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsRepeatingRow )( 
            IWriterTableRow * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        DECLSPEC_XFGVIRT(IWriterTableRow, SetStyle)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetStyle )( 
            IWriterTableRow * This,
            /* [in] */ IWriterStyle *style);
        
        END_INTERFACE
    } IWriterTableRowVtbl;

    interface IWriterTableRow
    {
        CONST_VTBL struct IWriterTableRowVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWriterTableRow_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWriterTableRow_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWriterTableRow_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWriterTableRow_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IWriterTableRow_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IWriterTableRow_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IWriterTableRow_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IWriterTableRow_get_Range(This,ppVal)	\
    ( (This)->lpVtbl -> get_Range(This,ppVal) ) 

#define IWriterTableRow_get_Height(This,pVal)	\
    ( (This)->lpVtbl -> get_Height(This,pVal) ) 

#define IWriterTableRow_put_Height(This,value)	\
    ( (This)->lpVtbl -> put_Height(This,value) ) 

#define IWriterTableRow_get_HeightRule(This,pVal)	\
    ( (This)->lpVtbl -> get_HeightRule(This,pVal) ) 

#define IWriterTableRow_put_HeightRule(This,value)	\
    ( (This)->lpVtbl -> put_HeightRule(This,value) ) 

#define IWriterTableRow_get_AllowSplit(This,pVal)	\
    ( (This)->lpVtbl -> get_AllowSplit(This,pVal) ) 

#define IWriterTableRow_put_AllowSplit(This,value)	\
    ( (This)->lpVtbl -> put_AllowSplit(This,value) ) 

#define IWriterTableRow_get_CellCount(This,pVal)	\
    ( (This)->lpVtbl -> get_CellCount(This,pVal) ) 

#define IWriterTableRow_GetCell(This,index,ppVal)	\
    ( (This)->lpVtbl -> GetCell(This,index,ppVal) ) 

#define IWriterTableRow_IsRepeatingRow(This,pVal)	\
    ( (This)->lpVtbl -> IsRepeatingRow(This,pVal) ) 

#define IWriterTableRow_SetStyle(This,style)	\
    ( (This)->lpVtbl -> SetStyle(This,style) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWriterTableRow_INTERFACE_DEFINED__ */


#ifndef __IWriterTableColumn_INTERFACE_DEFINED__
#define __IWriterTableColumn_INTERFACE_DEFINED__

/* interface IWriterTableColumn */
/* [uuid][unique][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IWriterTableColumn;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("35EA0572-5239-47FD-B551-E93114DFD170")
    IWriterTableColumn : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_CellCount( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetCell( 
            /* [in] */ long index,
            /* [retval][out] */ IWriterTableCell **ppVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWriterTableColumnVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWriterTableColumn * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWriterTableColumn * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWriterTableColumn * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IWriterTableColumn * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IWriterTableColumn * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IWriterTableColumn * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IWriterTableColumn * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(IWriterTableColumn, get_CellCount)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CellCount )( 
            IWriterTableColumn * This,
            /* [retval][out] */ long *pVal);
        
        DECLSPEC_XFGVIRT(IWriterTableColumn, GetCell)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetCell )( 
            IWriterTableColumn * This,
            /* [in] */ long index,
            /* [retval][out] */ IWriterTableCell **ppVal);
        
        END_INTERFACE
    } IWriterTableColumnVtbl;

    interface IWriterTableColumn
    {
        CONST_VTBL struct IWriterTableColumnVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWriterTableColumn_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWriterTableColumn_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWriterTableColumn_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWriterTableColumn_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IWriterTableColumn_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IWriterTableColumn_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IWriterTableColumn_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IWriterTableColumn_get_CellCount(This,pVal)	\
    ( (This)->lpVtbl -> get_CellCount(This,pVal) ) 

#define IWriterTableColumn_GetCell(This,index,ppVal)	\
    ( (This)->lpVtbl -> GetCell(This,index,ppVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWriterTableColumn_INTERFACE_DEFINED__ */


#ifndef __IWriterTableCell_INTERFACE_DEFINED__
#define __IWriterTableCell_INTERFACE_DEFINED__

/* interface IWriterTableCell */
/* [uuid][unique][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IWriterTableCell;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("10261806-9F68-4C84-AA9C-C956B966DC2F")
    IWriterTableCell : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Style( 
            /* [retval][out] */ IWriterStyle **ppVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Range( 
            /* [retval][out] */ IWriterRange **ppVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Text( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Text( 
            /* [in] */ BSTR value) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Font( 
            /* [retval][out] */ IWriterFont **ppVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_VerticalAlignment( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_VerticalAlignment( 
            /* [in] */ long value) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_HorizontalAlignment( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_HorizontalAlignment( 
            /* [in] */ long value) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Width( 
            /* [retval][out] */ float *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Width( 
            /* [in] */ float value) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Height( 
            /* [retval][out] */ float *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Height( 
            /* [in] */ float value) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_RightPadding( 
            /* [retval][out] */ float *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_RightPadding( 
            /* [in] */ float value) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_LeftPadding( 
            /* [retval][out] */ float *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_LeftPadding( 
            /* [in] */ float value) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_TopPadding( 
            /* [retval][out] */ float *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_TopPadding( 
            /* [in] */ float value) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_BottomPadding( 
            /* [retval][out] */ float *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_BottomPadding( 
            /* [in] */ float value) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetActiveEndPageNumber( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ScrollIntoView( 
            /* [in] */ VARIANT_BOOL option) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetFirstColLeftDistance( 
            /* [retval][out] */ double *pVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWriterTableCellVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWriterTableCell * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWriterTableCell * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWriterTableCell * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IWriterTableCell * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IWriterTableCell * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IWriterTableCell * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IWriterTableCell * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(IWriterTableCell, get_Style)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Style )( 
            IWriterTableCell * This,
            /* [retval][out] */ IWriterStyle **ppVal);
        
        DECLSPEC_XFGVIRT(IWriterTableCell, get_Range)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Range )( 
            IWriterTableCell * This,
            /* [retval][out] */ IWriterRange **ppVal);
        
        DECLSPEC_XFGVIRT(IWriterTableCell, get_Text)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Text )( 
            IWriterTableCell * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IWriterTableCell, put_Text)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Text )( 
            IWriterTableCell * This,
            /* [in] */ BSTR value);
        
        DECLSPEC_XFGVIRT(IWriterTableCell, get_Font)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Font )( 
            IWriterTableCell * This,
            /* [retval][out] */ IWriterFont **ppVal);
        
        DECLSPEC_XFGVIRT(IWriterTableCell, get_VerticalAlignment)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VerticalAlignment )( 
            IWriterTableCell * This,
            /* [retval][out] */ long *pVal);
        
        DECLSPEC_XFGVIRT(IWriterTableCell, put_VerticalAlignment)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_VerticalAlignment )( 
            IWriterTableCell * This,
            /* [in] */ long value);
        
        DECLSPEC_XFGVIRT(IWriterTableCell, get_HorizontalAlignment)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HorizontalAlignment )( 
            IWriterTableCell * This,
            /* [retval][out] */ long *pVal);
        
        DECLSPEC_XFGVIRT(IWriterTableCell, put_HorizontalAlignment)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_HorizontalAlignment )( 
            IWriterTableCell * This,
            /* [in] */ long value);
        
        DECLSPEC_XFGVIRT(IWriterTableCell, get_Width)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Width )( 
            IWriterTableCell * This,
            /* [retval][out] */ float *pVal);
        
        DECLSPEC_XFGVIRT(IWriterTableCell, put_Width)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Width )( 
            IWriterTableCell * This,
            /* [in] */ float value);
        
        DECLSPEC_XFGVIRT(IWriterTableCell, get_Height)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Height )( 
            IWriterTableCell * This,
            /* [retval][out] */ float *pVal);
        
        DECLSPEC_XFGVIRT(IWriterTableCell, put_Height)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Height )( 
            IWriterTableCell * This,
            /* [in] */ float value);
        
        DECLSPEC_XFGVIRT(IWriterTableCell, get_RightPadding)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RightPadding )( 
            IWriterTableCell * This,
            /* [retval][out] */ float *pVal);
        
        DECLSPEC_XFGVIRT(IWriterTableCell, put_RightPadding)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RightPadding )( 
            IWriterTableCell * This,
            /* [in] */ float value);
        
        DECLSPEC_XFGVIRT(IWriterTableCell, get_LeftPadding)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LeftPadding )( 
            IWriterTableCell * This,
            /* [retval][out] */ float *pVal);
        
        DECLSPEC_XFGVIRT(IWriterTableCell, put_LeftPadding)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LeftPadding )( 
            IWriterTableCell * This,
            /* [in] */ float value);
        
        DECLSPEC_XFGVIRT(IWriterTableCell, get_TopPadding)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TopPadding )( 
            IWriterTableCell * This,
            /* [retval][out] */ float *pVal);
        
        DECLSPEC_XFGVIRT(IWriterTableCell, put_TopPadding)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TopPadding )( 
            IWriterTableCell * This,
            /* [in] */ float value);
        
        DECLSPEC_XFGVIRT(IWriterTableCell, get_BottomPadding)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BottomPadding )( 
            IWriterTableCell * This,
            /* [retval][out] */ float *pVal);
        
        DECLSPEC_XFGVIRT(IWriterTableCell, put_BottomPadding)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BottomPadding )( 
            IWriterTableCell * This,
            /* [in] */ float value);
        
        DECLSPEC_XFGVIRT(IWriterTableCell, GetActiveEndPageNumber)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetActiveEndPageNumber )( 
            IWriterTableCell * This,
            /* [retval][out] */ long *pVal);
        
        DECLSPEC_XFGVIRT(IWriterTableCell, ScrollIntoView)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ScrollIntoView )( 
            IWriterTableCell * This,
            /* [in] */ VARIANT_BOOL option);
        
        DECLSPEC_XFGVIRT(IWriterTableCell, GetFirstColLeftDistance)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetFirstColLeftDistance )( 
            IWriterTableCell * This,
            /* [retval][out] */ double *pVal);
        
        END_INTERFACE
    } IWriterTableCellVtbl;

    interface IWriterTableCell
    {
        CONST_VTBL struct IWriterTableCellVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWriterTableCell_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWriterTableCell_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWriterTableCell_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWriterTableCell_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IWriterTableCell_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IWriterTableCell_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IWriterTableCell_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IWriterTableCell_get_Style(This,ppVal)	\
    ( (This)->lpVtbl -> get_Style(This,ppVal) ) 

#define IWriterTableCell_get_Range(This,ppVal)	\
    ( (This)->lpVtbl -> get_Range(This,ppVal) ) 

#define IWriterTableCell_get_Text(This,pVal)	\
    ( (This)->lpVtbl -> get_Text(This,pVal) ) 

#define IWriterTableCell_put_Text(This,value)	\
    ( (This)->lpVtbl -> put_Text(This,value) ) 

#define IWriterTableCell_get_Font(This,ppVal)	\
    ( (This)->lpVtbl -> get_Font(This,ppVal) ) 

#define IWriterTableCell_get_VerticalAlignment(This,pVal)	\
    ( (This)->lpVtbl -> get_VerticalAlignment(This,pVal) ) 

#define IWriterTableCell_put_VerticalAlignment(This,value)	\
    ( (This)->lpVtbl -> put_VerticalAlignment(This,value) ) 

#define IWriterTableCell_get_HorizontalAlignment(This,pVal)	\
    ( (This)->lpVtbl -> get_HorizontalAlignment(This,pVal) ) 

#define IWriterTableCell_put_HorizontalAlignment(This,value)	\
    ( (This)->lpVtbl -> put_HorizontalAlignment(This,value) ) 

#define IWriterTableCell_get_Width(This,pVal)	\
    ( (This)->lpVtbl -> get_Width(This,pVal) ) 

#define IWriterTableCell_put_Width(This,value)	\
    ( (This)->lpVtbl -> put_Width(This,value) ) 

#define IWriterTableCell_get_Height(This,pVal)	\
    ( (This)->lpVtbl -> get_Height(This,pVal) ) 

#define IWriterTableCell_put_Height(This,value)	\
    ( (This)->lpVtbl -> put_Height(This,value) ) 

#define IWriterTableCell_get_RightPadding(This,pVal)	\
    ( (This)->lpVtbl -> get_RightPadding(This,pVal) ) 

#define IWriterTableCell_put_RightPadding(This,value)	\
    ( (This)->lpVtbl -> put_RightPadding(This,value) ) 

#define IWriterTableCell_get_LeftPadding(This,pVal)	\
    ( (This)->lpVtbl -> get_LeftPadding(This,pVal) ) 

#define IWriterTableCell_put_LeftPadding(This,value)	\
    ( (This)->lpVtbl -> put_LeftPadding(This,value) ) 

#define IWriterTableCell_get_TopPadding(This,pVal)	\
    ( (This)->lpVtbl -> get_TopPadding(This,pVal) ) 

#define IWriterTableCell_put_TopPadding(This,value)	\
    ( (This)->lpVtbl -> put_TopPadding(This,value) ) 

#define IWriterTableCell_get_BottomPadding(This,pVal)	\
    ( (This)->lpVtbl -> get_BottomPadding(This,pVal) ) 

#define IWriterTableCell_put_BottomPadding(This,value)	\
    ( (This)->lpVtbl -> put_BottomPadding(This,value) ) 

#define IWriterTableCell_GetActiveEndPageNumber(This,pVal)	\
    ( (This)->lpVtbl -> GetActiveEndPageNumber(This,pVal) ) 

#define IWriterTableCell_ScrollIntoView(This,option)	\
    ( (This)->lpVtbl -> ScrollIntoView(This,option) ) 

#define IWriterTableCell_GetFirstColLeftDistance(This,pVal)	\
    ( (This)->lpVtbl -> GetFirstColLeftDistance(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWriterTableCell_INTERFACE_DEFINED__ */


#ifndef __ICalcApp_INTERFACE_DEFINED__
#define __ICalcApp_INTERFACE_DEFINED__

/* interface ICalcApp */
/* [uuid][unique][oleautomation][dual][object] */ 


EXTERN_C const IID IID_ICalcApp;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C43A0D8A-B601-4880-B1D2-D4C42E312560")
    ICalcApp : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Dispose( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [in] */ BSTR filePath,
            /* [in] */ VARIANT_BOOL readOnly,
            /* [retval][out] */ ICalcWorkbook **ppVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICalcAppVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICalcApp * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICalcApp * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICalcApp * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICalcApp * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICalcApp * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICalcApp * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICalcApp * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(ICalcApp, Dispose)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Dispose )( 
            ICalcApp * This);
        
        DECLSPEC_XFGVIRT(ICalcApp, Open)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            ICalcApp * This,
            /* [in] */ BSTR filePath,
            /* [in] */ VARIANT_BOOL readOnly,
            /* [retval][out] */ ICalcWorkbook **ppVal);
        
        END_INTERFACE
    } ICalcAppVtbl;

    interface ICalcApp
    {
        CONST_VTBL struct ICalcAppVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICalcApp_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICalcApp_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICalcApp_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICalcApp_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICalcApp_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICalcApp_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICalcApp_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICalcApp_Dispose(This)	\
    ( (This)->lpVtbl -> Dispose(This) ) 

#define ICalcApp_Open(This,filePath,readOnly,ppVal)	\
    ( (This)->lpVtbl -> Open(This,filePath,readOnly,ppVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICalcApp_INTERFACE_DEFINED__ */


#ifndef __ICalcWorkbook_INTERFACE_DEFINED__
#define __ICalcWorkbook_INTERFACE_DEFINED__

/* interface ICalcWorkbook */
/* [uuid][unique][oleautomation][dual][object] */ 


EXTERN_C const IID IID_ICalcWorkbook;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8063F58A-5D3D-46C3-A85C-3748079100AB")
    ICalcWorkbook : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Dispose( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Save( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_WorksheetCount( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetWorksheet( 
            /* [in] */ long index,
            /* [retval][out] */ ICalcWorksheet **ppVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICalcWorkbookVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICalcWorkbook * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICalcWorkbook * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICalcWorkbook * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICalcWorkbook * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICalcWorkbook * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICalcWorkbook * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICalcWorkbook * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(ICalcWorkbook, Dispose)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Dispose )( 
            ICalcWorkbook * This);
        
        DECLSPEC_XFGVIRT(ICalcWorkbook, Save)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            ICalcWorkbook * This);
        
        DECLSPEC_XFGVIRT(ICalcWorkbook, Close)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            ICalcWorkbook * This);
        
        DECLSPEC_XFGVIRT(ICalcWorkbook, get_WorksheetCount)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_WorksheetCount )( 
            ICalcWorkbook * This,
            /* [retval][out] */ long *pVal);
        
        DECLSPEC_XFGVIRT(ICalcWorkbook, GetWorksheet)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetWorksheet )( 
            ICalcWorkbook * This,
            /* [in] */ long index,
            /* [retval][out] */ ICalcWorksheet **ppVal);
        
        END_INTERFACE
    } ICalcWorkbookVtbl;

    interface ICalcWorkbook
    {
        CONST_VTBL struct ICalcWorkbookVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICalcWorkbook_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICalcWorkbook_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICalcWorkbook_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICalcWorkbook_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICalcWorkbook_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICalcWorkbook_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICalcWorkbook_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICalcWorkbook_Dispose(This)	\
    ( (This)->lpVtbl -> Dispose(This) ) 

#define ICalcWorkbook_Save(This)	\
    ( (This)->lpVtbl -> Save(This) ) 

#define ICalcWorkbook_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define ICalcWorkbook_get_WorksheetCount(This,pVal)	\
    ( (This)->lpVtbl -> get_WorksheetCount(This,pVal) ) 

#define ICalcWorkbook_GetWorksheet(This,index,ppVal)	\
    ( (This)->lpVtbl -> GetWorksheet(This,index,ppVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICalcWorkbook_INTERFACE_DEFINED__ */


#ifndef __ICalcWorksheet_INTERFACE_DEFINED__
#define __ICalcWorksheet_INTERFACE_DEFINED__

/* interface ICalcWorksheet */
/* [uuid][unique][oleautomation][dual][object] */ 


EXTERN_C const IID IID_ICalcWorksheet;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C4F94F82-E4B5-4C9F-B5CD-77729CC7C7ED")
    ICalcWorksheet : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Dispose( void) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_UsedRange( 
            /* [retval][out] */ ICalcRange **ppVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICalcWorksheetVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICalcWorksheet * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICalcWorksheet * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICalcWorksheet * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICalcWorksheet * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICalcWorksheet * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICalcWorksheet * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICalcWorksheet * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(ICalcWorksheet, Dispose)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Dispose )( 
            ICalcWorksheet * This);
        
        DECLSPEC_XFGVIRT(ICalcWorksheet, get_UsedRange)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UsedRange )( 
            ICalcWorksheet * This,
            /* [retval][out] */ ICalcRange **ppVal);
        
        DECLSPEC_XFGVIRT(ICalcWorksheet, get_Name)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            ICalcWorksheet * This,
            /* [retval][out] */ BSTR *pVal);
        
        END_INTERFACE
    } ICalcWorksheetVtbl;

    interface ICalcWorksheet
    {
        CONST_VTBL struct ICalcWorksheetVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICalcWorksheet_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICalcWorksheet_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICalcWorksheet_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICalcWorksheet_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICalcWorksheet_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICalcWorksheet_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICalcWorksheet_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICalcWorksheet_Dispose(This)	\
    ( (This)->lpVtbl -> Dispose(This) ) 

#define ICalcWorksheet_get_UsedRange(This,ppVal)	\
    ( (This)->lpVtbl -> get_UsedRange(This,ppVal) ) 

#define ICalcWorksheet_get_Name(This,pVal)	\
    ( (This)->lpVtbl -> get_Name(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICalcWorksheet_INTERFACE_DEFINED__ */


#ifndef __ICalcRange_INTERFACE_DEFINED__
#define __ICalcRange_INTERFACE_DEFINED__

/* interface ICalcRange */
/* [uuid][unique][oleautomation][dual][object] */ 


EXTERN_C const IID IID_ICalcRange;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5EE9CCA2-84C2-49FB-BA17-7151B0B710D7")
    ICalcRange : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Dispose( void) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_RowCount( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ColumnCount( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetCell( 
            /* [in] */ long rowIndex,
            /* [in] */ long columnIndex,
            /* [retval][out] */ ICalcCell **ppVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICalcRangeVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICalcRange * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICalcRange * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICalcRange * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICalcRange * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICalcRange * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICalcRange * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICalcRange * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(ICalcRange, Dispose)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Dispose )( 
            ICalcRange * This);
        
        DECLSPEC_XFGVIRT(ICalcRange, get_RowCount)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RowCount )( 
            ICalcRange * This,
            /* [retval][out] */ long *pVal);
        
        DECLSPEC_XFGVIRT(ICalcRange, get_ColumnCount)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ColumnCount )( 
            ICalcRange * This,
            /* [retval][out] */ long *pVal);
        
        DECLSPEC_XFGVIRT(ICalcRange, GetCell)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetCell )( 
            ICalcRange * This,
            /* [in] */ long rowIndex,
            /* [in] */ long columnIndex,
            /* [retval][out] */ ICalcCell **ppVal);
        
        END_INTERFACE
    } ICalcRangeVtbl;

    interface ICalcRange
    {
        CONST_VTBL struct ICalcRangeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICalcRange_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICalcRange_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICalcRange_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICalcRange_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICalcRange_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICalcRange_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICalcRange_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICalcRange_Dispose(This)	\
    ( (This)->lpVtbl -> Dispose(This) ) 

#define ICalcRange_get_RowCount(This,pVal)	\
    ( (This)->lpVtbl -> get_RowCount(This,pVal) ) 

#define ICalcRange_get_ColumnCount(This,pVal)	\
    ( (This)->lpVtbl -> get_ColumnCount(This,pVal) ) 

#define ICalcRange_GetCell(This,rowIndex,columnIndex,ppVal)	\
    ( (This)->lpVtbl -> GetCell(This,rowIndex,columnIndex,ppVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICalcRange_INTERFACE_DEFINED__ */


#ifndef __ICalcCell_INTERFACE_DEFINED__
#define __ICalcCell_INTERFACE_DEFINED__

/* interface ICalcCell */
/* [uuid][unique][oleautomation][dual][object] */ 


EXTERN_C const IID IID_ICalcCell;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DB18D173-46D9-4964-8CCE-BEFFE5A83D84")
    ICalcCell : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Dispose( void) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_RowIsHidden( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_RowHeight( 
            /* [retval][out] */ float *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Color( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Text( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICalcCellVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICalcCell * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICalcCell * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICalcCell * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICalcCell * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICalcCell * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICalcCell * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICalcCell * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(ICalcCell, Dispose)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Dispose )( 
            ICalcCell * This);
        
        DECLSPEC_XFGVIRT(ICalcCell, get_RowIsHidden)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RowIsHidden )( 
            ICalcCell * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        DECLSPEC_XFGVIRT(ICalcCell, get_RowHeight)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RowHeight )( 
            ICalcCell * This,
            /* [retval][out] */ float *pVal);
        
        DECLSPEC_XFGVIRT(ICalcCell, get_Color)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Color )( 
            ICalcCell * This,
            /* [retval][out] */ long *pVal);
        
        DECLSPEC_XFGVIRT(ICalcCell, get_Text)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Text )( 
            ICalcCell * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(ICalcCell, get_Value)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            ICalcCell * This,
            /* [retval][out] */ VARIANT *pVal);
        
        END_INTERFACE
    } ICalcCellVtbl;

    interface ICalcCell
    {
        CONST_VTBL struct ICalcCellVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICalcCell_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICalcCell_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICalcCell_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICalcCell_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICalcCell_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICalcCell_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICalcCell_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICalcCell_Dispose(This)	\
    ( (This)->lpVtbl -> Dispose(This) ) 

#define ICalcCell_get_RowIsHidden(This,pVal)	\
    ( (This)->lpVtbl -> get_RowIsHidden(This,pVal) ) 

#define ICalcCell_get_RowHeight(This,pVal)	\
    ( (This)->lpVtbl -> get_RowHeight(This,pVal) ) 

#define ICalcCell_get_Color(This,pVal)	\
    ( (This)->lpVtbl -> get_Color(This,pVal) ) 

#define ICalcCell_get_Text(This,pVal)	\
    ( (This)->lpVtbl -> get_Text(This,pVal) ) 

#define ICalcCell_get_Value(This,pVal)	\
    ( (This)->lpVtbl -> get_Value(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICalcCell_INTERFACE_DEFINED__ */



#ifndef __LOBridge_LIBRARY_DEFINED__
#define __LOBridge_LIBRARY_DEFINED__

/* library LOBridge */
/* [helpstring][version][uuid] */ 



















EXTERN_C const IID LIBID_LOBridge;

EXTERN_C const CLSID CLSID_WriterApp;

#ifdef __cplusplus

class DECLSPEC_UUID("596EF499-A61F-4977-A257-D06A8C8D8E03")
WriterApp;
#endif

EXTERN_C const CLSID CLSID_CalcApp;

#ifdef __cplusplus

class DECLSPEC_UUID("65ED3120-936C-4BEA-996E-C6C9CF35B179")
CalcApp;
#endif
#endif /* __LOBridge_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize64(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal64(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal64(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree64(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


