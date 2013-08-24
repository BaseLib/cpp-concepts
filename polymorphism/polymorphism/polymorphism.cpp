// polymorphism.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Windows.h"

class thread
{
	HANDLE hThreadHwnd;

public:
	int start()
	{
		DWORD threadid;
		hThreadHwnd = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)thread::runthread,this,0,&threadid);

		return true;
	}

	virtual int run()=0;
	static int runthread(void *lpData)
	{
		((thread*)lpData)->run();
		return 1;
	}

};

class recvdata : public thread
{
public:
	int run()
	{
		while(1)
		{
			Sleep(1000);
		}
	}
};





int _tmain(int argc, _TCHAR* argv[])
{
	recvdata objRec;
	objRec.start();

		Sleep(100000000000);
	return 0;
}

