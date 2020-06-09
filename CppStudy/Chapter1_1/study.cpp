/*
	인프런 홍정모의 따라하며 배우는 C++
	주석
	변수 l-value, r-value https://effort4137.tistory.com/entry/Lvalue-Rvalue
	변수는 초기화 필요
	입출력 스트림
*/

#include <iostream>	// cout, cin, endl, ...

int main()
{
	std::cout << "Chapter1_1" << std::endl;

	int x = 123;	// initialization 초기화
	x = 5;			// assignment 대입

	int y(123);		// initialization 초기화방법 2
	std::cout << x << std::endl;
	std::cout << y << std::endl;
	std::cout << &x << std::endl;	// 메모리 주소값 (&연산자는 l-value값을 요구함)


	int z;		// 변수명 z를 정수형으로 메모리 공간 할당

	/*
		초기화 하지않고 사용 X
		int z;
		std::cout << z << std::endl;
	*/

	/*----------------------------------------------------------------------------------*/

	// std 이름공간 cout을 사용하기위해 :: 사용

	int num = 1024;
	double pi = 3.141592;
	std::cout << "C++ lecture" << std::endl;
	std::cout << "num is " << num << std::endl;
	std::cout << "pi is " << pi << std::endl;

	std::cout << "abc" << "\t" << "def" << std::endl;
	std::cout << "ab" << "\t" << "cdef" << std::endl;	// \t : 탭 (이스케이프 '문자')
	std::cout << "ab" << "\n\n" << "cdef" << std::endl;	// \n : 개행

	using namespace std;	// std 사용공간 사용 선언이후 std:: 생략가능

	cout << "\nnum is " << num << endl;

	cout << "\a";	// \a : 윈도우 알림(alert)

	cin >> x;
	cout << "Your input is " << x << endl;

	return 0;
}