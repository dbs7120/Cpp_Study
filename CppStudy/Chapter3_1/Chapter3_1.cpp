/*
	인프런 홍정모의 따라하며 배우는 C++

	◆연산자 우선순위, 결합법칙	https://ko.wikipedia.org/wiki/C%EC%99%80_C%2B%2B%EC%9D%98_%EC%97%B0%EC%82%B0%EC%9E%90
	 사칙연산: 괄호 > 일반 사칙연산규칙(*,/ > +,-)

	◆산술연산자
	 +,-,*, /:몫, %:나머지

	◆증감연산자

	◆sizeof, 쉼표, 조건부(삼항) 연산자
	 간단한형태의 if문형태 ==> 조건부연산자 활용
*/

#include <iostream>

using namespace std;

int add(int a, int b)
{
	return a + b;
}
int main()
{
	cout << std::pow(2, 3) << endl;		// pow: 거듭제곱 함수(double으로 반환)
	int x = 5;
	int y = 2;
	cout << x / y << " " << float(x) / y << " " << x / float(y) << " " << float(x) / float(y) << endl;
	cout << -5 / 2 << " " << endl;								// 음의값 몫값연산: 나머지값 나누기는 버림으로(절삭)
	cout << -5 % 2 << " " << 5 % -2 << " " << -5 % -2 << endl;	// 음의값 나머지연산: 좌측값음수=>음수나머지, 우측값음수=>양수나머지, 둘모두=>음수나머지

	//int z = x; <==> z += y;		// 동일결과(복합대입연산자)

	/*----------------------------------------------------------------------------------*/

	x = 6, y = 6;				// ++,--가 앞과 뒤 위치에 따라 값이 달라짐 주의
	cout << "1:" << x << " " << y << endl;
	cout << "2:" << ++x << " " << --y << endl;
	cout << "3:" << x++ << " " << y-- << endl;
	cout << "4:" << x << " " << y << endl << endl;

	x = 1;
	int v = add(x, ++x);		// 이러한 동일변수 증감사용 금지(컴파일러마다 값이달라질 수 있고 결과가 모호해질수 있음)
	cout << v << endl;
	x = 1, y = 2;
	v = add(x, ++y);
	cout << v << endl;

	/*----------------------------------------------------------------------------------*/
	float a;
	cout << sizeof(float) << " " << sizeof(a) << endl;		// sizeof연산자는 타입, 변수, 구조체 ,클래스등 크기값을 byte단위로 반환

	x = 3, y = 10;
	int z = (++x, ++y);		// 1. 앞계산(콤마앞), 2. 뒷계산(콤마뒤), 3. 2번결과를 대입 <==> ++x; ++y; int z = y;	// 주로 for반복문에서 사용
	cout << x << " " << y << " " << z << endl;

	x = 3, y = 10;
	z = x, y;				// 콤마연산자는 대입보다 우선 순위가 낮음 <==> (z = x) , y;
	cout << z << endl << endl;

	/*----------------------------------------------------------------------------------*/

	// conditional operator (arithmetric if)
	bool onSale = true;
	/*int price;

	if (onSale)
		price = 10;
	else
		price = 100;
	cout << price << endl;*/

	const int price = (onSale == true) ? 10 : 100;		// 조건부연산자를 통해 상수값 조건할당 가능함(if문으로는 함수형태로만 가능)
	cout << price << endl;

	cout << ((x % 2 == 0) ? "even" : "odd") << endl;	// 식전체 소괄호 필요(연산자 우선순위), 조건부연산자의 참,거짓 반환값은 가능한 같은 타입으로

	return 0;
}