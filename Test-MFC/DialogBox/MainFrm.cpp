
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "DialogBox.h"

#include "UIThread.h"
#include "MainFrm.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_THREAD_START, &CMainFrame::OnThreadStart)
	ON_COMMAND(ID_THREAD_SENDMESSAGE, &CMainFrame::OnThreadSendmessage)
	ON_COMMAND(ID_THREAD_STOP, &CMainFrame::OnThreadStop)
	ON_UPDATE_COMMAND_UI(ID_THREAD_START, &CMainFrame::OnUpdateThreadStart)
	ON_UPDATE_COMMAND_UI(ID_THREAD_SENDMESSAGE, &CMainFrame::OnUpdateThreadSendmessage)
	ON_UPDATE_COMMAND_UI(ID_THREAD_STOP, &CMainFrame::OnUpdateThreadStop)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	m_pThread = NULL;
}

CMainFrame::~CMainFrame()
{
	if(m_pThread)
	{
		m_pThread->PostThreadMessage(WM_QUIT,0,0);
		delete m_pThread;
		m_pThread = NULL;
	}
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame message handlers

void CMainFrame::OnThreadStart()
{
	if(!m_pThread)
	{
		m_pThread = new CUIThread();
		m_pThread->CreateThread();
	}
}

void CMainFrame::OnThreadSendmessage()
{
	if(m_pThread)
	{
		m_pThread->PostThreadMessage(WM_FIRST_MESSAGE,0,0);
		m_pThread->PostThreadMessage(WM_SECOND_MESSAGE,0,0);
		m_pThread->PostThreadMessage(WM_THIRD_MESSAGE,0,0);		
	}
}

void CMainFrame::OnThreadStop()
{
	if(m_pThread)
	{
		m_pThread->PostThreadMessage(WM_QUIT,0,0);
		delete m_pThread;
		m_pThread = NULL;
	}
}

void CMainFrame::OnUpdateThreadStart(CCmdUI *pCmdUI)
{
	pCmdUI->Enable(!m_pThread);
}

void CMainFrame::OnUpdateThreadSendmessage(CCmdUI *pCmdUI)
{
	pCmdUI->Enable(!!m_pThread);
}

void CMainFrame::OnUpdateThreadStop(CCmdUI *pCmdUI)
{
	pCmdUI->Enable(!!m_pThread);
}
