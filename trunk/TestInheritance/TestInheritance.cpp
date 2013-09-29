// TestInheritance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//Default inheritance access specifier
//http://stackoverflow.com/questions/4796789/default-inheritance-access-specifier

class A {};
struct B: /* public */ A {};

struct SA {};
class SB: /* private */ SA {};

//Multiple Inheritance 
//http://www.cprogramming.com/tutorial/multiple_inheritance.html


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

