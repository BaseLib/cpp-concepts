
// DialogBoxDoc.cpp : implementation of the CDialogBoxDoc class
//

#include "stdafx.h"
#include "DialogBox.h"

#include "DialogBoxDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDialogBoxDoc

IMPLEMENT_DYNCREATE(CDialogBoxDoc, CDocument)

BEGIN_MESSAGE_MAP(CDialogBoxDoc, CDocument)
END_MESSAGE_MAP()


// CDialogBoxDoc construction/destruction

CDialogBoxDoc::CDialogBoxDoc()
{
	// TODO: add one-time construction code here

}

CDialogBoxDoc::~CDialogBoxDoc()
{
}

BOOL CDialogBoxDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CDialogBoxDoc serialization

void CDialogBoxDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}


// CDialogBoxDoc diagnostics

#ifdef _DEBUG
void CDialogBoxDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDialogBoxDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDialogBoxDoc commands
