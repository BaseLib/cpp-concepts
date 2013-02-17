
// DialogBoxView.cpp : implementation of the CDialogBoxView class
//

#include "stdafx.h"
#include "DialogBox.h"

#include "DialogBoxDoc.h"
#include "DialogBoxView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDialogBoxView

IMPLEMENT_DYNCREATE(CDialogBoxView, CView)

BEGIN_MESSAGE_MAP(CDialogBoxView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDialogBoxView construction/destruction

CDialogBoxView::CDialogBoxView()
{
	// TODO: add construction code here

}

CDialogBoxView::~CDialogBoxView()
{
}

BOOL CDialogBoxView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CDialogBoxView drawing

void CDialogBoxView::OnDraw(CDC* /*pDC*/)
{
	CDialogBoxDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CDialogBoxView printing

BOOL CDialogBoxView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDialogBoxView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDialogBoxView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CDialogBoxView diagnostics

#ifdef _DEBUG
void CDialogBoxView::AssertValid() const
{
	CView::AssertValid();
}

void CDialogBoxView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDialogBoxDoc* CDialogBoxView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDialogBoxDoc)));
	return (CDialogBoxDoc*)m_pDocument;
}
#endif //_DEBUG


// CDialogBoxView message handlers
