// constptr_and_ptrtoconst.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int j=10;
int *const g_ptr=&j;
int const g_data=10;
const int g_data1=10;
int _tmain(int argc, _TCHAR* argv[])
{
	int j=10,i=20;
	const int * const x= &j; 

	int const* constptr;// = &j;
	constptr = &j;
//	*constptr = 20;


	int* const constptr1 = &j;
	constptr1 = &j;
	*constptr1 = 20;


	const int* ptrtoconst;
//	*ptrtoconst = 10;
	ptrtoconst = &j;
	
	/*const* int ptrtoconst1;
	ptrtoconst1 = &j;
	j = 10;*/
	//*ptrtoconst = 30;
	//g_ptr = &j;
//	ptr = &i;
	char ch = 'y';
	char * const str = "hello, world";
	char szArr[5] = "asda";
	char const * sz[1];
	sz[0] = "rohit";


	int const* ptrtoconstarr[2];
		//int const* ptr;
	ptrtoconstarr[0] = new int[2];
	ptrtoconstarr[0] = (int*)12;
	(ptrtoconstarr[0]+1) = (int*)13;
	return 0;
}

