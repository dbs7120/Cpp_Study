/*
	인프런 홍정모의 따라하며 배우는 C++

	*헤더(Header) 파일 만들기(코드의 분리) 헤더부(함수이름,라이브러리) - 기능별.cpp - main.cpp
	 재사용성 증가
	 헤더: 함수선언부, 이름공간 등등

	*헤더가드(Header Guards) #pragma once
	 중복될경우 한번만 include ==> 다중헤더에서 중복 include "header" 방지 (#ifndef ~ #endif와 동일)

	*실제 함수 몸체를 찾지 못 할 경우 Linking error 발생가능 ==> 파일분리시 파일존재 여부주의

	*이름 공간(namespace)
	 이름공간 접근 ::

	*전처리기(Preprocessor)
	 #define을 통한 함수생성가능, #define의 효력 범위 : 파일안에서만
	 #ifdef ~ #endif / #ifndef ~ #endif 로 전처리기 분기 가능
*/

#include <iostream>
#include "calc.h"

using namespace std;

namespace MySpace1
{
	int doSomething(int a, int b) {
		return a + b + 1024;
	}
}

namespace MySpace2
{
	int doSomething(int a, int b)
	{
		return -a - b - 1024;
	}
	namespace InnerSpace	// namespace 안의 namespace
	{
		int doSomething(int a, int b)
		{
			return a + b + 2048;
		}
	}
}

/*----------------------------------------------------------------------------------*/

#define MY_NUMBER 777						// 매크로(교체), 주로 대문자 매크로문 만날시 해당값과 교체
#define MY_STRING "Hello World!"
#define MAX(a,b) (((a)>(b)) ? (a) : (b))	// 삼항연산자 활용

#define LIKE_APPLE							// define은 전처리기안에서는 다르게 작동

int main()
{
	cout << addCalc(1, 2) << endl;
	// cout << minus(3, 4) << endl;		// std 이름공간에 minus가 존재함
	cout << minusCalc(3, 4) << endl;
	cout << multiplyCalc(3, 5) << endl;

	/*----------------------------------------------------------------------------------*/

	cout << MySpace1::doSomething(1, 2) << endl;
	cout << MySpace2::doSomething(1, 2) << endl;

	using namespace MySpace1;			// using 선언 이후 MySpace1:: 생략후 MySpace1 공간 접근
	cout << doSomething(1, 2) << endl;
	cout << MySpace2::InnerSpace::doSomething(1, 2) << endl;

	/*----------------------------------------------------------------------------------*/

	cout << MY_NUMBER << endl;
	cout << MY_STRING << endl;
	cout << MAX(3, 9) << endl;
	cout << MAX(3 + 12, 9) << endl;

#ifdef LIKE_APPLE					// 전처리기 ==> 빌드이전에 결정됨(시스템,플랫폼 등에서 주로사용)
	cout << "Apple " << endl;
#endif

#ifndef LIKE_APPLE
	cout << "Orange" << endl;
#endif // !LIKE_APPLE

	return 0;
}
