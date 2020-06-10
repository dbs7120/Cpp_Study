/*
	인프런 홍정모의 따라하며 배우는 C++

	*함수 리턴값 매개변수 인수
	 함수내부에서 함수정의 불가(클래스는 네스티드클래스로가능)

	*키워드, 식별자 이름짓기 ==> 기본적으로 환경에 맞게, 주석활용
	 변수, 함수 명명시 숫자시작X, 기호시작X(언더바는가능), camel case 적용
	 변수는 소문자로, 띄어쓰기-> _(언더바)로 활용 ex) number_of_apples
	 함수 -> 동사, 명사 복합으로 짓기

	*지역범위(local scope)
	 변수의 범위 ==> 중괄호
*/

#include <iostream>

using namespace std;	// <- 전역범위 namespace (범위구역: 중괄호)

// 리턴값 함수명(매개변수) 형식
int multiplyTwoNumbers(int num_a, int num_b)
{
	int sum = num_a * num_b;
	return sum;
}

void printHelloWorld()
{
	cout << "Hello World" << endl;
}

int main()
{
	printHelloWorld();
	cout << multiplyTwoNumbers(1, 2) << endl;
	cout << multiplyTwoNumbers(3, 4) << endl;
	cout << multiplyTwoNumbers(1024, 2048) << endl;

	int x, y;
	cin >> x >> y;	// cin 변수 연속 입력(스페이스, 탭, 엔터에 구분)
	cout << multiplyTwoNumbers(x, y) << endl;


	int num(1);	// num = 0;
	cout << "A: " << num << " " << &num << endl;		// --A
	{
		int num = 2;
		cout << "B: " << num << " " << &num << endl;	// --B
	}

	{
		int num = 3;
		cout << "C: " << num << " " << &num << endl;	// --C
	}
	cout << "D: " << num << " " << &num << endl;		// --D

	// A==D 같은 주소 공간, A,B,C는 서로다른 주소 공간
	// 지역공간을 벗어나면(중괄호를 빠져나옴) 메모리반납됨
	{
		num = 4;
		cout << "E: " << num << " " << &num << endl;	// --E
	}
	cout << "F: " << num << " " << &num << endl;		// --F

	return 0;
}


class MyClass
{
public:
	int _variable;
	int m_variable;
	int variable_;
	int variable;
};