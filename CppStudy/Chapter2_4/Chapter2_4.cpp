/*
	인프런 홍정모의 따라하며 배우는 C++

	◆문자형(Char)
	 ASCII 테이블 https://ko.wikipedia.org/wiki/ASCII
	 이스케이프 시퀀스(제어문자, Escape sequence) https://docs.microsoft.com/ko-kr/cpp/c-language/escape-sequences?view=vs-2019

	◆리터럴 상수(Literal constants)
	 바이너리 리터럴(Binary Literal)	int b = 0b1010

	◆심볼릭 상수(Symbolic Constants)	C++11 constexpr
	 const: 상수(고정된 값), 반드시 선언과 동시에 초기화 필요
	 일반적으로 다른 header 파일을 상수값 전체 관리
*/

#include <iostream>
#include <limits>
#include "MY_CONSTANTS.h"

using namespace std;

void printNumber(const int my_number)
{
	//my_number = 456;				// my_number는 printNumber함수의 입력값
	cout << my_number << endl;		// 입력은 못바꾸게해야함 ==> 인자를 const int my_number;
}

int main()
{
	char c1(65);
	char c2('A');

	cout << c1 << " " << c2 << " " << int(c1) << " " << int(c2) << endl;

	cout << (char)65 << " " << (int)'A' << endl;			// C스타일 캐스팅
	cout << char(65) << " " << int('A') << endl << endl;	// C++스타일 캐스팅

	cout << static_cast<char>(65) << endl;					// static_cast(타입캐스트연산자)
	cout << static_cast<char>('A') << endl;					// 컴파일러에게 체크후 변환(타입 변환 오류 감지)

	cout << sizeof(char) << endl;
	cout << (int)std::numeric_limits<char>::max() <<		// 모든 ascii값을 출력하지 못하기때문에 (int)캐스팅 필요
		" ~ " << (int)std::numeric_limits<char>::lowest() << endl;

	cout << "This is first line \nseconde line\n";			// \n: newline (endl효과)
	cout << "This is first line " << std::flush;			// flush: 줄바꿈을 하지않고 버퍼내용 모두 출력
	cout << "second line";

	cout << "\aThis is first line \tseconde line\n";		// \a: alert(시스템 알림음)	\t: tab
	cout << "\"This is first line \\seconde line\"\n";		// \": "출력				\\: \출력

	/*----------------------------------------------------------------------------------*/

	cin >> c1;												// stream operator(>>)는여러문자 입력시 buffer에 남아있음
	cout << c1 << " " << static_cast<int>(c1) << endl;
	cin >> c1;
	cout << c1 << " " << static_cast<int>(c1) << endl << endl;

	/*----------------------------------------------------------------------------------*/

	float pi = 3.14f;
	int i = 12345u;			// u,U: unsigned, l,L: Long, ll,LL: Long Long
	long j = 12345UL;
	cout << pi << " " << i << " " << j << endl << endl;

	/*----------------------------------------------------------------------------------*/

	// Deciamal	: 0 1 2 3 4 5 6 7 8 9 10..
	// Octal	: 0 1 2 3 4 5 6 7 10 11 12 13..
	// Hexa		: 0 1 2 3 4 5 6 7 8 9 A B C D E F 10..
	// 0011 1010 1111 1111(2) == 3A7F(16)

	int x = 012;	// 8진수 표기
	int y = 0xF;	// 16진수 표기

	cout << x << " " << y << endl;	// 8진수, 16진수를 10진수로 표기

	int b1 = 0b101111111010;		 
	int b2 = 0b1011'1111'1010;		// 컴파일러는 코드상의 ' 문자 무시함 (코드 숫자가동성 증가)
	
	cout << b1 << " " << b2 << endl << endl;

	/*----------------------------------------------------------------------------------*/

	// magin number(하드코딩된 숫자) 대신 리터럴 상수를 만들어 사용하기

	//#define PRICE_PER_ITEM 30		// C++에서는 상수값을 위해 #define을 사용 X ==> 디버깅이어려움, 상수적용범위가 너무 넓어짐
	const int price_per_item = 10;
	int num_items = 123;	
	int price = num_items * price_per_item;			//int price = num_items * 10; 
	

	/*----------------------------------------------------------------------------------*/

	const double gravity{ 9.8 };
	double const PI = 3.14f;		// 두 순서모두 가능하지만 const를 먼저 사용		// 컴파일 할때 상수값 결정됨(컴파일 상수)

	// gravity = 1.2;				// const로 선언시 값 변경 불가

	printNumber(123);

	int number;
	cin >> number;

	const int special_number(number);		// special_number는		// 런타임에서 상수값 결정됨(런타임 상수)

	constexpr int my_const(123);				// constexpr: 컴파일 상수값 명시
	//constexpr int special_number(number)		// 불가능(런타임상수)

	/*----------------------------------------------------------------------------------*/

	double radius;
	cout << "반지름 입력: ";
	cin >> radius;
	double circumference = 2.0 * radius * constants::pi_number;
	double cirsize = radius * radius * constants::pi_number;

	cout << "원둘레: " << circumference << " 원넓이: " << cirsize << endl;

	return 0;
}