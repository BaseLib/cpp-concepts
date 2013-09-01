// mutex.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>

using namespace std;

class thread
{
private:
	HANDLE m_hThread;
	DWORD m_dwThreadId;
public:
	virtual int run() = 0;

	int start()
	{
		m_hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadFunction, this, 0, &m_dwThreadId);
		return 1;
	}

	static int ThreadFunction(void* pArg)
	{
		thread* pThread = (thread*)pArg;

		if(!pThread->run())
		{
			return 0;
		}

		return 1;
	}
};


HANDLE g_synMutex;

HANDLE g_synSemA;
HANDLE g_synSemB;
HANDLE g_synSemC;


class PrintA : public thread
{
public:
	int run()
	{
		
		while(1)
		{
			//DWORD lData = WaitForSingleObject(g_mutexA, INFINITE);
			DWORD lData = WaitForSingleObject(g_synSemA, INFINITE);
			
			//long nRet = ReleaseMutex(g_mutexA);
			cout<<"A"<<endl;
			ReleaseSemaphore(g_synSemB, 1, NULL);
		
		}
		return 1;
	}
};

class PrintB : public thread
{
public:
	int run()
	{
		//g_mutexB = CreateMutex(NULL, TRUE, "B");
		
		while(1)
		{
			DWORD lData = WaitForSingleObject(g_synSemB, INFINITE);
			cout<<"B"<<endl;
			ReleaseSemaphore(g_synSemC, 1, NULL);
		}
		return 1;
	}
};

class PrintC : public thread
{
public:
	int run()
	{
		//g_mutexC = CreateMutex(NULL, TRUE, "C");
		
		while(1)
		{
			DWORD lData = WaitForSingleObject(g_synSemC, INFINITE);
			cout<<"C"<<endl;
			Sleep(1000);
			ReleaseSemaphore(g_synSemA, 1, NULL);
			
		}
		return 1;
	}
};

class MultiOwnerMutex : public thread
{
//public:
private:
	int run()
	{
		int nCount = 0;
		while(1)
		{
			WaitForSingleObject(g_synMutex, INFINITE);
			cout<<"In multi : "<<nCount+1<<endl;
			nCount++;
			if(nCount%3 == 0)
			{
				Sleep(2000);
				cout<<"Release Mutex 1"<<endl;
				ReleaseMutex(g_synMutex);
				cout<<"Release Mutex 2"<<endl;
				ReleaseMutex(g_synMutex);
				cout<<"Release Mutex 3"<<endl;
				ReleaseMutex(g_synMutex);
				Sleep(1000);
			}else if(nCount > 4)
			{
				cout<<"In else : "<<nCount<<endl;
				Sleep(2000);
			}
		}
	}
};

class SingleOwnerMutex : public thread
{
//public:
private:
	int run()
	{
		while(1)
		{
			cout<<"in single wait"<<endl;
			WaitForSingleObject(g_synMutex, INFINITE);
			cout<<"in single wait out"<<endl;
			ReleaseMutex(g_synMutex);
			Sleep(1500);
		}
	}

};
int _tmain(int argc, _TCHAR* argv[])
{

	//******************************************  Semaphore test ****************************************//
	long nRet = 0;
	PrintA A;
	PrintB B;
	PrintC C;


	g_synSemA = CreateSemaphore(NULL, 1, 1, NULL);
	g_synSemB = CreateSemaphore(NULL, 0, 1, NULL);
	g_synSemC = CreateSemaphore(NULL, 0, 1, NULL);
	//g_mutexC = CreateMutex(NULL, FALSE, "C");
	
	//A.start();
	//B.start();
	//C.start();
	
	//******************************************  mutex ownership test ****************************************//
	g_synMutex = CreateMutex(NULL, FALSE, NULL);
	MultiOwnerMutex multiowner;
	SingleOwnerMutex single;
	
	multiowner.start();
	Sleep(1500);
	single.start();

	cin>>nRet;
	return 0;
}

