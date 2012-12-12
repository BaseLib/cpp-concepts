#include "StdAfx.h"
#include "WaitThread.h"

volatile long lSwitchCounter =0;
HANDLE			hGlobalEvent =  CreateEvent(NULL,TRUE,FALSE,NULL);

CWaitThread::CWaitThread(void)
{
	m_hEvent	= CreateEvent(NULL,FALSE,FALSE,NULL);
	m_lEventCount =0;
	m_hThread	= NULL;
	m_dwThreadID= 0;
}

CWaitThread::~CWaitThread(void)
{
	CloseHandle(m_hEvent);
}
 
DWORD WINAPI CWaitThread::ThreadFunc(LPVOID pParam)
{
	CWaitThread *pThis = (CWaitThread *)pParam;

	while(!WaitForSingleObject(pThis->m_hEvent,INFINITE))
	{
		pThis->m_lEventCount ++;
		//break;
	}

	return 1;
}


DWORD WINAPI CWaitThread::SingleEventThreadFunc(LPVOID pParam)
{
	CWaitThread *pThis = (CWaitThread *)pParam;

	while(!WaitForSingleObject(hGlobalEvent,INFINITE))
	{
		++lSwitchCounter;

//nothing should happen if Event reseted multiple times ..same as SetEvent set only once ..right ?
		//if(!lSwitchCounter++)			
			ResetEvent(hGlobalEvent);


		pThis->m_lEventCount ++;
		printf("lSwitchCounter  = %ld",lSwitchCounter);
		//break;
	}
	//printf(" lSwitchCounter  = %ld",lSwitchCounter);
	
	return 1;
}