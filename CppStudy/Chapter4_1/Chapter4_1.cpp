/*
	인프런 홍정모의 따라하며 배우는 C++

	◆지역 변수의 범위와 지속기간(Scope, Duration)
	 가능한 살아남는 범위를 작게(사용하는곳 근처에서만 선언 및 소멸할 수 있게)
	 이름이 같을경우 한영역에 하나만 존재해야함(함수의 경우 매개변수가 다를경우 충돌 X)
	 :: 영역(범위)결정 연산자

	◆전역(Global), 정적(Static) 변수
	 내부(internal), 외부(External) 연결(Linkage)
	 링킹과정중 파일과의 연결
	 한 cpp 파일에서 변수 연결 사용: 내부 연결
	 다른 cpp 파일에서 변수연결 사용: 외부 연결
	 전역변수는 가급적 자제(파일내,외부 어디서나 접근, 값변경)
	 static 변수: 반드시 초기화1회 필요, 외부에서 접근 불가
	 Local Linkage: X (필요성X)
	 Internal Linkage: static 사용
	 External Linkage: forward declaration(extern), 변수의 경우 대상 변수는 반드시 초기화

*/

#include <iostream>
#include "MyConstants.h"

using namespace std;

namespace work1::work11::work111		// nested namespace 다른 표기 (C++ 17표준 이후 가능)
{
	int a = 1;
	void doSomething()
	{
		cout << "Something " << endl;
	}
}

int value = 123;					// global variable (main함수 외부)

void doSomething()
{
	//int a = 1;					// block 밖으로(함수종료) 나갈시 사라짐
	static int a = 1;				// static duration variable: 초기화 1회, 이후 초기화 X
	cout << ++a << endl;
}

// Internal Linkage
static int s_a = 1;					// 해당 전역변수는 다른 cpp 파일에서 접근 불가

// External Linkage(forward declaration)
extern void doSomethingTest();		// 함수의 경우 extern키워드 생략 가능
extern int test_a;					// 초기화가 되어있다면 초기화 X
void doPi();

/*	변수선언방식정리

	int g_x;					// extern linkage 사용가능 (초기화 안된 전역변수)
	static int g_x;				// internal linkage
	const int g_x;				// X (const: 초기화 필요)

	extern int g_z;
	extern const int g_z		// 반드시 한번은 (다른곳에서) 초기화 필요

	int g_y(1);					// 초기화된 전역변수
	static int g_y(1);			// 외부에서(다른cpp) 접근 불가
	const int g_y(1);			// 일반적인 상수 외부에서(다른cpp) 접근 불가

	extern int g_w(1);			// 다른곳에서는 초기화 X
	extern const int g_w(1);
*/

int main()
{
	int apple = 5;
	cout << apple << endl;			// -- apple (5)
	{
		int apple = 1;
		cout << apple << endl;		// -- apple (1), 중괄호 영역, 상위구역 apple과 하위구역 apple은 변수
	}
	cout << apple << endl;			// -- apple (5)

	//int apple = 3;				// 같은 영역 내부에는 정의시 이름 충돌	

	work1::work11::work111::doSomething;
	cout << endl;

	/*----------------------------------------------------------------------------------*/

	int value = 1;						// local varialbe
	cout << value << endl;
	cout << ::value << endl << endl;	// global scope operator(내부에서 전역변수 접근,사용)

	doSomething();
	doSomething();

	/*----------------------------------------------------------------------------------*/

	doSomethingTest();					// 외부파일 함수 사용 
	cout << test_a << endl;				// 외부파일 변수 사용

	/*----------------------------------------------------------------------------------*/
	
	cout << "In main.cpp file " << Constants::pi << " address: " << &Constants::pi << endl;	
	doPi();		// main과 test파일 각자의 호출값의 주소값이 다름(사본이 생김->메모리낭비)
	// ==> 헤더파일은 extern 변수 선언, cpp파일을 통해 extern 변수 초기화(강의 참고)
	
	return 0;
}
