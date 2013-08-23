// virtualtest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include <iostream>

using namespace std;

class base
{
public:
	virtual void func()
	{
		cout<<"in base"<<endl;
	}
	virtual void func1(int j)
	{
	
	}
	void basefunc()
	{
	
	}
};

class child : base
{
public:
	void func() override
	{
		cout<<"in child"<<endl;
	}

	void testchild()
	{
	
	}
};

class child2 : child
{
public:
	void func()
	{
	}
	void child2func()
	{
	
	}
	

};

class BaseA
{
public:
    virtual int foo() = 0;
};


class ChildNew : public BaseA
{
public:
    int foo() { return 42; }
};


void TestOverride()
{
	base objBase;
	child objChild;
	child2 objChild2;
	objBase.func();
	objChild.func();
	
	child *pobjBase = (child*)new base;
	child *pobjChild = new child;
	child2 *pobjChild2 =(child2*) new child;
	child2 *pobjChild3 =(child2*) new base;
	child2 *pobjChild4 =(child2*) new child2;
	//pobjChild3->
	base* pbase =(base*) new child;
	pbase->basefunc();
	//pbase->testchild();
	((child*)pbase)->testchild();

	pobjChild2->func();
	pobjBase->func();
	pobjChild->func();

	BaseA * pNewBase1 = new ChildNew();

}

void TestVirtualTable()
{

//Referance
//	http://bytes.com/topic/c/answers/942922-virtual-pointer-accessing-vtable-class-inside-program
//
	ChildNew objClindNew;
	//BaseA	objBaseA;

	
	
	base	objbase;

	int *pVtable=(int*)&objClindNew;
	printf("\nClass ChildNew Virtual Table Pointer = %u",*pVtable);

	
///////////////////////////////////////////////////////////////////////////////
	pVtable=(int*)&objbase;
	printf("\nClass base Virtual Table Pointer = %u",*pVtable);

	base b2;

	pVtable=(int*)&b2;
	printf("\nClass base Object-2 Virtual Table Pointer = %u",*pVtable);

	base b3;
	pVtable=(int*)&b3;
	printf("\nClass base Object-3 Virtual Table Pointer = %u",*pVtable);
////////////////////////////////////////////////////////////////////////////////
	child2	objClild2;
	pVtable=(int*)&objClild2;
	printf("\nClass child2 Virtual Table Pointer = %u",*pVtable);

	child2 obj2Clild2;
	pVtable=(int*)&obj2Clild2;
	printf("\nClass child2 Object 2 Virtual Table Pointer = %u",*pVtable);

	child2 obj3Clild2;
	pVtable=(int*)&obj3Clild2;
	printf("\nClass child2 Object 3 Virtual Table Pointer = %u",*pVtable);
////////////////////////////////////////////////////////////////////////////////
	child	objClild;
	pVtable=(int*)&objClild;
	printf("\nClass child Virtual Table Pointer = %u",*pVtable);

	child	obj2Clild;
	pVtable=(int*)&obj2Clild;
	printf("\nClass child Object 2 Virtual Table Pointer = %u",*pVtable);

	child	obj3Clild;
	pVtable=(int*)&obj3Clild;
	printf("\nClass child Object 3Virtual Table Pointer = %u",*pVtable);

}

int _tmain(int argc, _TCHAR* argv[])
{

	TestVirtualTable();

	//TestOverride();
	
	return 0;
}















class parent {
public:
  virtual void handle_event(int something) const = 0 {
    // boring default code
  }

  void funcdata()
  {
  
  }
};

//class parent {
//public:
//  virtual void handle_event(int something) {
//    // boring default code
//  }
//};

class mychild : public parent {
public:
  virtual void handle_event(int something) const/* override  */{
    // new exciting code
  }
  
};

//int main() 
//{
//  parent *p = new mychild();
// // p->handle_event(1);
//}




/************************************************* Data Hiding *********************************************/
#include <iostream>
//class Base {
//private:
//	  virtual void f(int) { std::cout << "Base::Int!" << std::endl; } // (1)
//public:
//  virtual void f(double){ std::cout << "Base::Double!" << std::endl; }
//  // virtual void f(int) { std::cout << "Base::Int!" << std::endl; } // (1)
//  virtual ~Base() {}
//};
//
//class Derived : public Base {
//public:
//  // using Base::f; // (2)
//  void f(double) { std::cout << "Derived::Double!" << std::endl; }
//};



class Base {

public:
  void f(int){ std::cout << "Base::int!" << std::endl; }
  void f(double) { std::cout << "Base::Double!" << std::endl; } // (1)
  virtual ~Base() {}
};

class Derived : public Base {
public:
	//using Base::f; // (2)
	void f(int) { std::cout << "Derived::int!" << std::endl; }
	
};

//int main(int, char **) {
//  Derived d;
//  d.f(21.0578);
//  return 0;
//}


using std::cout;
using std::endl;

class A {};
class B {};

class X
{
public:
    void spray(A&)
    {
        cout << "Class A" << endl;
    }
};

class Y : public X
{
public:
	//using X::spray;
    void spray(B&)
    {
        cout << "Class B" << endl;
    }
};
//
//int main()
//{
//    A a;
//    B b;
//    Y y;
//
//	y.spray(a);
//    y.spray(b);
//
//    return 0;
//}





//***********************************	co-variant return types		********************************//
//#include <iostream>
//
//using namespace std;
//
//class base22
//{
//   public:
//      virtual int func()
//      {
//         cout << "vfunc in base class\n";
//         return 0;
//      }
//};
//
//class derived22: public base22
//{
//   public:
//      double func() 
//      {
//         cout << "vfunc in derived class\n";
//         return 0;
//      }
//};
//
//int main()
//{
//   base22 *bptr = new derived22;
//   bptr->func();
//
// 
//	/*base22 bptr;
//	bptr.func();*/
//   return 0;	
//}
