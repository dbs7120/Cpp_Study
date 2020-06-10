/*
	인프런 홍정모의 따라하며 배우는 C++

	*연산자
	 리터럴(literal), 피연산자(operand), 단항, 이항, 삼항

	*서식 맞추기(Formatting)
	 여백 빈칸 빈줄 ==> 프로그래머 가시성 (비주얼 스튜디오 자동정렬 단축키 : ctrl + K + F)
	 여백(indenting) ==> tab 키 활용

	*함수 선언(Declaration) 정의(Definition) 분리
	 선언부(함수이름)는 항상 main이전에 있어야함(순차적 컴파일)
*/

#include <iostream>

using namespace std;

// 1 규모가 작은 함수
int addCalc(int x, int y) { return x + y; }
// 2
int minusCalc(int x, int y)
{
	return x - y;	// indenting 여백 tab == space * 4
}
// 3
int multi(int x, int y) {
	return x * y;
}
// 2,3 환경에 맞게 적용

/*----------------------------------------------------------------------------------*/

void printHello();			// 함수 전방 선언부(forward declaration)
double circleArea(double);	// 전방 선언부에서 매개변수명은 생략가능

int main()
{
	int x = 2;					// x is a variable, 2 is a literal
	cout << 1 + 2 << endl;		// 1: literal, 2: literal, 1 + 2: expression
	cout << x + 2 << endl;		// 이항연산자 : +,-,*,/
	cout << -x << endl;			// 단항연산자 : -,++,--

	int y = (x > 0) ? 1 : 2;	// 삼항연산자 : (조건) ? 참실행 : 거짓실행
	cout << y << endl;

	/*----------------------------------------------------------------------------------*/

	// 1
	cout << "가나다라마바사" << "아자차카타파하"
		<< "abvakl;sjdlkasjdkasldkasoiodjaslkjdlasjdlaksjdlajskdajsdjaslkdjaslkjds" << endl;
	// 2
	cout << "가나다라마바사" << "아자차카타파하" <<
		"abvakl;sjdlkasjdkasldkasoiodjaslkjdlasjdlaksjdlajskdajsdjaslkdjaslkjds" << endl;

	/*----------------------------------------------------------------------------------*/

	cout << "반지름 3의 원넓이: " << circleArea(3) << endl;


	return 0;
}


void printHello()		// 함수 정의부(definition)
{
	cout << "Hello" << endl;
}

double circleArea(double r)
{
	return r * r * 3.14;
}
