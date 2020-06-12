/*
	인프런 홍정모의 따라하며 배우는 C++

	*부동소수점 수(Floating Point Numbers)
	 float (최소크기: 4byte) / double (8) / long double (8)	// double은 float의 두배 공간
	 연산 속도 공간측면에서 float형으로 많이 사용
	 부호부(sign) 지수(exponent) 가수(mantissa)로 구성됨

	*불리언(Boolean), 조건문 if
	 Bool ==> true(1) or flase(0)
	 조건문 조건식 0이아닌 값 ==> true

*/

#include <iostream>
#include <limits>
#include <iomanip>		// 입출력을 제어 (소수점 자릿수등)
#include <cmath>

bool isEqual(int a, int b) 
{
	bool result = (a == b);
	return result;
}

int main()
{
	using namespace std;

	float f(3.141592f);
	double d(3.141592f);
	long double ld(3.141592f);

	cout << 3.14 << endl;		// 3.14 = 31.4 * 0.1
	cout << 31.4e-1 << endl;	// 지수 표기법
	cout << 31.4e2 << endl << endl;

	cout << sizeof(float) << " " << sizeof(double) << " " << sizeof(long double) << endl;
	cout << numeric_limits<float>::max() << ", " << numeric_limits<float>::min() << ", " << numeric_limits<float>::lowest() << endl;		// min(): 표현할 수 있는 가장 작은 절대 값
	cout << numeric_limits<double>::max() << ", " << numeric_limits<double>::min() << ", " << numeric_limits<double>::lowest() << endl;
	cout << numeric_limits<long double>::max() << ", " << numeric_limits<long double>::min() << ", " << numeric_limits<long double>::lowest() << endl << endl;

	/*----------------------------------------------------------------------------------*/

	f = 123456789.0f;
	d = 0.1;
	double d1 = 1.0;
	double d2 = 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1;

	cout << 1.0 / 3.0 << endl;
	cout << f << endl;
	cout << d << endl;
	cout << d1 << " equals " << d2 << endl << endl;

	cout << std::setprecision(16);				// cout의 소수점 16 지정
	cout << 1.0 / 3.0 << endl;
	cout << f << endl;							// 정밀도 손실
	cout << d << endl;
	cout << d1 << " equals " << d2 << endl << endl;		// 오차의 누적

	/*----------------------------------------------------------------------------------*/

	double zero = 0.0;
	double posinf = 5.0 / zero;
	double neginf = -5.0 / zero;
	double nan = zero / zero;		// Not a Number
	cout << "1: " << posinf << " 2: " << neginf << " 3: " << nan << endl << endl;		// inf , -inf , -nan(ind) ==> 디버깅시의 문제 isnan, isinf 함수로 확인

	// std::isnan() 숫자가 아닌 값인지 확인, std::isinf() inf값 인지 확인
	cout << neginf << " " << std::isinf(neginf) << endl;
	cout << nan << " " << std::isnan(nan) << endl;
	cout << 1.0 << " " << std::isnan(1.0) << endl << endl;

	/*----------------------------------------------------------------------------------*/

	bool b1 = true;		// true = 1
	bool b2(false);	// false = 0
	bool b3{ true };

	cout << b1 << " " << b2 << " " << b3 << endl;
	cout << std::boolalpha;								// cout 1=>true 0=>false로 출력
	cout << b1 << " " << b2 << " " << b3 << endl;
	cout << std::noboolalpha;
	cout << !b1 << endl << endl;

	cout << (true && true) << " " << (true && false) << " " << (false && true) << " " << (false && false) << endl;		// &&(and) 논리 연산
	cout << (true || true) << " " << (true || false) << " " << (false || true) << " " << (false || false) << endl;		// ||(or) 논리 연산

	/**/
	int num = 10;
	cout << (true || (3 == 1 ? num = 1 : num = 2)) << endl;		// 논리연산 단축평가
	cout << num << endl;
	cout << (false && (3 == 1 ? num = 1 : num = 0)) << endl;	// 논리연산 단축평가
	cout << num << endl << endl;

	/*----------------------------------------------------------------------------------*/

	// if문
	if (3 > 1)	// 조건식
		cout << "This is true" << endl;				// 조건식이 참일경우 실행
	else
		cout << "This is false" << endl << endl;	// 조건식이 참일경우 실행 X

	if ('a')										// 0이 아닌값은 True
		cout << "a is true " << endl;

	/*----------------------------------------------------------------------------------*/

	cout << std::boolalpha;
	cout << isEqual(1, 1) << endl;
	cout << isEqual(3, 4) << endl;

	/*----------------------------------------------------------------------------------*/

	int input;	
	cout << "Your input: ";
	cin >> input; 
	if (input % 2 == 0)
		cout << input << "is Even number" << endl;
	else
		cout << input << "is Odd number" << endl;

	return 0;
}
