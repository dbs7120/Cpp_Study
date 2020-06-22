#include <iostream>
#include "MyConstants.h"

extern int test_a = 321;		// 반드시 초기화 필요

void doSomethingTest()
{
	using namespace std;
	cout << "Hello " << endl;
}

void doPi()
{
	using namespace std;
	cout << "In test.cpp file " << Constants::pi << " address: " << &Constants::pi << endl;
}