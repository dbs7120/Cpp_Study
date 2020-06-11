/*
	인프런 홍정모의 따라하며 배우는 C++

	*기본 자료형	http://www.cplusplus.com/doc/tutorial/variables/
	 char(문자형):	1byte(8bit)		// char16_t, char32_t wchar_t 등 문자 메모리 크기확장 (이모티콘, 특수 활용)
	 int(정수형):	4byte(32bit)	// (signed) int : 음, 0, 양의정수 포함 / unsigned int : 양의정수, 0 (특별한 경우에 unsigned가 빠를 수 있음)
		小(char - short - int - long - long long)大
	 float(4byte), double(8byte), long double (부동소수점, 실수형)
	 bool(불리언, true or false)
	 void(no storage)
	 auto: 자동적으로 자료형 탐지 (modern c++)

	*변수 선언의 위치: 코드상단 or 사용하기직전(디버깅,리팩토링에 용이)

	*sizeof() 연산자 : 자료형의 byte 단위 메모리크기 반환
*/

#include <iostream>
#include <bitset>

int main()
{
	using namespace std;

	char chValue = 'A';
	bool bValue = false;
	float fValue = 3.141592f;		// f 없을시 warning 발생 (double to float으로 손실)
	double dValue = 3.141592;
	auto aValue = 3.141592;			// 자동 double
	auto aValue2 = 3.141592f;		// 자동 float

	cout << bValue << endl;
	cout << (bValue ? 1 : 0) << endl;

	cout << chValue << endl;
	cout << (int)chValue << endl;
	chValue = 66;
	cout << chValue << endl;

	cout << fValue << endl;
	cout << dValue << endl << endl;
	cout << aValue << " " << sizeof(aValue) << "byte" << endl;
	cout << aValue2 << " " << sizeof(aValue2) << "byte" << endl;

	/*----------------------------------------------------------------------------------*/

	// 초기화의 3가지 방법
	int a = 123;	// copy initialization									int a1 = 3.1415;	// warning (자동변환) a1 = (int)3.1415
	int b(123);		// direct initialization	==> 주로 객체타입 초기화	int b1(3.1415);		// warning (자동변환) b1((int)3.1415)
	int c{ 123 };	// uniform initialization	==> 주로 객체타입 초기화	int c{ 3.1415 };	// error

	int k = 1, l = 2, m = 123;	// 여러 변수 초기화


	return 0;

}