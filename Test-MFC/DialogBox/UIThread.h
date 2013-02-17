#pragma once

#define WM_FIRST_MESSAGE		WM_USER+1
#define WM_SECOND_MESSAGE		WM_USER+2
#define WM_THIRD_MESSAGE		WM_USER+3
//const UINT WM_FIRST_MESSAGE = RegisterWindowMessage (_T("WM_FIRST_MESSAGE"));
//const UINT WM_SECOND_MESSAGE = RegisterWindowMessage (_T("WM_SECOND_MESSAGE"));
//const UINT WM_THIRD_MESSAGE = RegisterWindowMessage (_T("WM_THIRD_MESSAGE"));

// CUIThread

class CUIThread : public CWinThread
{
public:
	DECLARE_DYNCREATE(CUIThread)

//protected:
public:
	CUIThread();           // protected constructor used by dynamic creation
	virtual ~CUIThread();

public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

protected:
	DECLARE_MESSAGE_MAP()
public:
	void FirstMsgHandler(WPARAM wParam , LPARAM lParam);
	void SecondMsgHandler(WPARAM wParam , LPARAM lParam);
	void ThirdMsgHandler(WPARAM wParam , LPARAM lParam);
};


