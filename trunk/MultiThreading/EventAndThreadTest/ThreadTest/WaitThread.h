#pragma once

class CWaitThread
{
public:
	CWaitThread(void);
	~CWaitThread(void);

	static DWORD WINAPI ThreadFunc(LPVOID pParam);
	static DWORD WINAPI SingleEventThreadFunc(LPVOID pParam);

public:
	HANDLE	m_hEvent;
	HANDLE	m_hThread;
	DWORD	m_dwThreadID;
	LONG	m_lEventCount;
};
