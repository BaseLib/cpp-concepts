// ThreadTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WaitThread.h"

extern HANDLE			hGlobalEvent;

const int iThreadCount	= 1000;

void TestEventPerThread()
{
	int iSleepTime		= 100;
	int iIterations		= 10;

	CWaitThread objThread[iThreadCount];

	for(int iCounter=0;iCounter < iThreadCount;iCounter++)
	{
		objThread[iCounter].m_hThread = CreateThread(NULL,0,CWaitThread::ThreadFunc,&objThread[iCounter],0,&objThread[iCounter].m_dwThreadID);
	}

	while (iIterations>0)
	{
		for(int iCounter=0;iCounter < iThreadCount;iCounter++)
		{
			SetEvent(objThread[iCounter].m_hEvent);
		}
		iIterations--;
		Sleep(iSleepTime);
	}

	Sleep(5000);	//Give chance to Threads

	for(int iCounter=0;iCounter < iThreadCount;iCounter++)
	{
		printf("\nThread %2d : Event Triggered %2d times",iCounter,objThread[iCounter].m_lEventCount);
	}
}

void TestOneEventForMultipleThreads()
{
	CWaitThread objThread[iThreadCount];

	for(int iCounter=0;iCounter < iThreadCount;iCounter++)
	{
		objThread[iCounter].m_hThread = CreateThread(NULL,0,CWaitThread::SingleEventThreadFunc,&objThread[iCounter],0,&objThread[iCounter].m_dwThreadID);
	}

	SetEvent(hGlobalEvent);

	Sleep(3000);	//Give chance to Threads

	for(int iCounter=0;iCounter < iThreadCount;iCounter++)
	{
		printf("\nThread %2d : Event Triggered %2d times",iCounter,objThread[iCounter].m_lEventCount);
	}

}

int _tmain(int argc, _TCHAR* argv[])
{

	TestEventPerThread();

	//TestOneEventForMultipleThreads();


 	return 0;

}

