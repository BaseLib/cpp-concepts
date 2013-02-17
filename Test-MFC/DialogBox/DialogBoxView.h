
// DialogBoxView.h : interface of the CDialogBoxView class
//


#pragma once


class CDialogBoxView : public CView
{
protected: // create from serialization only
	CDialogBoxView();
	DECLARE_DYNCREATE(CDialogBoxView)

// Attributes
public:
	CDialogBoxDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CDialogBoxView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DialogBoxView.cpp
inline CDialogBoxDoc* CDialogBoxView::GetDocument() const
   { return reinterpret_cast<CDialogBoxDoc*>(m_pDocument); }
#endif

