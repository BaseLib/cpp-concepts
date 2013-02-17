
// MainFrm.h : interface of the CMainFrame class
//

#pragma once
//#include "UIThread.h"

class CUIThread;

class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar        m_wndStatusBar;

	//CUIThread		m_UIThread;
	CUIThread		*m_pThread;

// Generated message map functions
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnThreadStart();
	afx_msg void OnThreadSendmessage();
	afx_msg void OnThreadStop();
	afx_msg void OnUpdateThreadStart(CCmdUI *pCmdUI);
	afx_msg void OnUpdateThreadSendmessage(CCmdUI *pCmdUI);
	afx_msg void OnUpdateThreadStop(CCmdUI *pCmdUI);
};


