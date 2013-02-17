// UIThread.cpp : implementation file
//

#include "stdafx.h"
#include "DialogBox.h"
#include "UIThread.h"



// CUIThread

IMPLEMENT_DYNCREATE(CUIThread, CWinThread)

CUIThread::CUIThread()
{
}

CUIThread::~CUIThread()
{
}

BOOL CUIThread::InitInstance()
{
	// TODO:  perform and per-thread initialization here
	return TRUE;
}

int CUIThread::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CUIThread, CWinThread)
	ON_THREAD_MESSAGE(WM_FIRST_MESSAGE, FirstMsgHandler)
	ON_THREAD_MESSAGE(WM_SECOND_MESSAGE, SecondMsgHandler)
	ON_THREAD_MESSAGE(WM_THIRD_MESSAGE, ThirdMsgHandler)
END_MESSAGE_MAP()


// CUIThread message handlers

void CUIThread::FirstMsgHandler(WPARAM wParam , LPARAM lParam)
{
	CWnd*	main_wnd = AfxGetMainWnd();
	HWND	hParentWnd = main_wnd?main_wnd->GetSafeHwnd():NULL;  
	CAboutDlg aboutDlg(main_wnd);
	aboutDlg.DoModal();
}

void CUIThread::SecondMsgHandler(WPARAM wParam , LPARAM lParam)
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

void CUIThread::ThirdMsgHandler(WPARAM wParam , LPARAM lParam)
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}
