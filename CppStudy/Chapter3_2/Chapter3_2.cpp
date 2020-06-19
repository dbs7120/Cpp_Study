/*
	인프런 홍정모의 따라하며 배우는 C++

	◆관계연산자(Relational Operators)
	 >, >=, <, <=, ==, !=
	 부동소수점에서의 값비교 주의(수치해석)

	◆논리연산자(Logical Operators)
	 &&(and), ||(or), !(not)
	 가능하면 명확하고 단순하게 표현
	 논리연산자 사이의 우선순위: ! > && > ||
*/

#include <iostream>
#include <cmath>

int main()
{
	using namespace std;

	int x, y;
	cin >> x >> y;
	cout << "Your input values are : " << x << " " << y << endl;

	if (x == y)	cout << "equal" << endl;
	if (x != y)	cout << "Not equal" << endl;
	if (x > y)	cout << "x is greater than y" << endl;
	if (x < y)	cout << "x is less than y" << endl;
	if (x >= y)	cout << "x is greater than y or equal to y" << endl;
	if (x <= y)	cout << "x is less than or equal to y" << endl;

	cout << endl;

	/*----------------------------------------------------------------------------------*/

	// 부동소수점에서의 비교 주의

	double d1(100 - 99.99);		// 0.001
	double d2(10 - 9.99);		// 0.001
	cout << d1 << " " << d2 << endl;

	if (d1 == d2)
		cout << "d1==d2" << endl;
	else
	{
		cout << "d1!=d2" << endl;

		if (d1 > d2) cout << "d1 > d2" << endl;
		else cout << "d1 < d2" << endl;				// if(d1 < d2), 상위비교에서 d1 != d2 검증
	}

	cout << std::abs(d1 - d2) << endl << endl;		// d1과 d2차이(절대값)

	const double epsilon = 1e-10;					// 오차한계지정	==> 수치는 분야, 환경에 따라 달리지정

	if (std::abs(d1 - d2) < epsilon)				// 오차한계 직접지정
		cout << "d1, d2 is Approximately equal" << endl;
	else
		cout << "d1, d2 is not equal" << endl;

	cout << endl;

	/*----------------------------------------------------------------------------------*/

	// 논리연산자 활용

	bool hit = true;
	int health = 10;

	if (hit == true && health < 20)						// <== if(hit == true) if(health < 20)
		cout << "die " << endl;
	else
		health -= 20;
	cout << endl;

	int a = 5;
	int b = 7;
	if (!a == b) cout << "a does not equal b" << endl;	// 연산자우선순위 !가 == 보다 높음 ((!a)==b) ==> if(!(a == b)) == if(a != b)
	else cout << "a equals b" << endl;
	cout << endl;

	/*----------------------------------------------------------------------------------*/

	// short circuit evaluation (단축연산)
	x = 1, y = 2;

	if (x == 1 && y++ == 2)
	{
		// do something
	}
	cout << "first" << y << endl;

	x = 2, y = 2;

	if (x == 1 && y++ == 2)				// &&: 좌측항이 false값이되면 우측항무시하고 결과 리턴
	{
		// do something
	}
	cout << "second" << y << endl;
	cout << endl;

	/*----------------------------------------------------------------------------------*/

	bool v1 = true;
	bool v2 = false;
	bool v3 = false;

	bool r1 = v1 || v2 && v3;			// &&가 || 보다 우선순위 높음(r1==r3)
	bool r2 = (v1 || v2) && v3;			// 괄호를 통해 코드명확하게 하기
	bool r3 = v1 || (v2 && v3);
	cout << "r1: " << r1 << " r2: " << r2 << " r3: " << r3 << endl << endl;

	/*----------------------------------------------------------------------------------*/

	// De Morgan's Law
	// x = 1, y = 0;
	// !(x && y); <==> !x || !y;
	// !(x || y); <==> !x && !y;

	// XOR	==> if(x != y), x,y는 bool타입만
	// TT=>F, TF=>T, FT=>T, FF=>F

	/*----------------------------------------------------------------------------------*/

	//ex
	cout << ((true && true) || false) << endl;				// T
	cout << ((false && true) || true) << endl;				// T
	cout << ((false && true) || false || true) << endl;		// T
	cout << ((14 > 13 || 2 > 1) && (9 > 1)) << endl;		// T
	cout << (!(2314123 > 2 || 123123 > 2387)) << endl;		// F

	return 0;
}
