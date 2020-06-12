/*
	인프런 홍정모의 따라하며 배우는 C++

	*정수형
	 char (최소크기: 1byte) / short (2) / int (2, 대부분은 4) / long (4) / long long (8)
	 int i = 1;		<=>		00000000 | 00000000 | 00000000 | 00000001
	 int i = -1;	<=>		10000000 | 00000000 | 00000000 | 00000001

	*오버플로우(Overflow) 주의

	*고정 너비 정수(Fixed-width Integers) C++ 11

	*무치형(void) 타입
*/

#include <iostream>
#include <cmath>
#include <limits>		
//#include <cstdint>	// <iostream> 에 포함됨 (int16_t, int8_t, int_fast8_t, int_least64_t)

int main()
{
	using namespace std;

	short s = 1;		// 2byte = 2*8bits = 16bits : 2^16가지 표현
	int i = 1;
	long l = 1;
	long long ll = 1;
	cout << sizeof(short) << " " << sizeof(int) << " " << sizeof(long) << " " << sizeof(long long) << endl;

	cout << std::pow(2, sizeof(short) * 8 - 1) - 1 << endl;		// 부호있는(signed), 0제외의 short 형 표현수 
	cout << std::numeric_limits<short>::max() << endl;			// limts 을 통해 자료형 최대 최소값 구하기
	cout << std::numeric_limits<short>::min() << endl;
	cout << std::numeric_limits<short>::lowest() << endl << endl;

	s = 32767;
	s += 1;		// (복합대입연산자) <=> s = s + 1 

	cout << "max + 1: " << s << endl;	// Overflow

	s = -32768;
	s -= 1;
	cout << "min - 1: " << s << endl;	// Overflow

	/*----------------------------------------------------------------------------------*/

	cout << std::numeric_limits<long long>::max() << endl;
	cout << std::numeric_limits<long long>::lowest() << endl;

	ll = std::numeric_limits<long long>::max();
	ll += 1;
	cout << "max + 1: " << ll << endl << endl;	// Overflow

	unsigned int ui = -1;
	cout << ui << endl;		// 이진수 표기때문에 Overeflow로 인해 unsigned int 최대값이 나옴
	cout << std::numeric_limits<unsigned int>::max() << endl;
	cout << std::numeric_limits<unsigned int>::lowest() << endl << endl;

	/*----------------------------------------------------------------------------------*/

	cout << 22 / 4 << endl;					// 5, 정수의 연산 => 정수,소수점 손실(버림)
	cout << (float)22 / 4 << endl << endl;	// 5.5, 실수/정수 => 실수값

	/*----------------------------------------------------------------------------------*/

	// 고정 너비 정수, 주로 멀티 플랫폼프로그래밍에서 활용
	std::int16_t i16(5);
	std::int8_t myint = 65;
	std::int_fast64_t fi(65);
	std::int_least64_t li(-1);

	cout << myint << " " << sizeof(myint) << endl;
	cout << fi << " " << sizeof(fi) << endl;
	cout << li << " " << sizeof(li) << endl;
	cout << std::numeric_limits<int_least64_t>::lowest() << endl << endl;

	/*----------------------------------------------------------------------------------*/

	//	void vd					// void 는 메모리를 차지하지 않기 때문에 선언 불가
	void *my_void;				// void타입 포인터형으로 선언
	int num = 123;
	float flo = 123.456f;

	my_void = (void*)&num;
	my_void = (void*)&flo;		// 데이터 타입이 다르고 사이즈가 다르더라도 데이터의 주소의 데이터 타입은 동일


	return 0;
}