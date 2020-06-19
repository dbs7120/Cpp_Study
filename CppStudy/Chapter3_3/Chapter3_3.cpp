/*
	인프런 홍정모의 따라하며 배우는 C++

	◆이진수(Binary Numbers)

	◆비트단위 연산자(Bitwise Operators)
	 ~, &, ^, |, <<, >>
	 2진수 각자리에대한 연산, 계산속도가 빠름

	◆비트 플래그, 비트마스크(Bit flags, Bit masks) 활용

*/

#include <iostream>
#include <bitset>	// 2진수 활용 라이브러리

int main()
{
	using namespace std;

	/*
	10진법	337 = 300 + 30 + 7 = 10^2 * 3 + 10^1 * 3 + 10^0 * 7
	2진법	10 = 2^1 * 1 + 2^0 * 0

		0000 0101 <=> 5
	보수 complement
		0000 0101 -> 1111 1010
	보수 + 1(숫자 +0,-0 방지)
		1111 1010 + 1 -> 1111 1010 <=> -5

	// signed vs unsigned
		1001 1110 -> 2^7*1 + 2^4*1 + 2^3*1+1 + 2^2*1+1 + 2^1*1+1 = 128+16+8+4+2=158
	*/

	/*----------------------------------------------------------------------------------*/

	// << : left shift, >> : right shift		(cout의 <<, cin의 >> 와 다른용도(오버로딩됨))
	// ~ : not, & : and, | : or, ^ : xor
	// 일반적으로 unsigned 2진수로 연산

	unsigned int a = 3;
	cout << std::bitset<8>(a) << endl;			// 정수 a를 <size>자리의 2진법으로 출력

	unsigned int b = a << 3;					// a를 왼쪽으로 n칸 옮김(left shift)  10진수로 2의 n승 곱 효과
	cout << std::bitset<8>(b) << endl;

	cout << a << " " << b << endl << endl;

	a = 1024;
	cout << std::bitset<16>(a) << endl;
	b = a >> 4;									// 10진수로 2의 n승 나눈 결과
	cout << std::bitset<16>(b) << endl;
	cout << a << " " << b << endl;

	cout << std::bitset<16>(a) << " " << (a) << " " << std::bitset<16>(~a) << " " << (~a) << endl << endl;	// bit not (~)

	a = 0b1100;
	b = 0b0110;

	cout << std::bitset<4>(a & b) << endl;		// bitwise AND
	cout << std::bitset<4>(a | b) << endl;		// bitwise OR
	cout << std::bitset<4>(a ^ b) << endl;		// bitwise XOR

	a &= b; a ^= b; a |= b;						// 복합대입형태로 사용가능
	cout << endl;

	/*----------------------------------------------------------------------------------*/

	//ex
	cout << (0b0110 >> 2) << endl;
	cout << (5 | 12) << endl;		// 0101 | 1100 => 1101
	cout << (5 & 12) << endl;		// 0101 & 1100 => 0100
	cout << (5 ^ 12) << endl;		// 0101 ^ 1100 => 1001 
	cout << endl;

	/*----------------------------------------------------------------------------------*/

	/*
	bool item1_flag = false;
	bool item2_flag = false;
	bool item3_flag = false;
	...
	bool item8_flag = false;
	==>
	*/

	// byte구조를활용(8bit) 시나리오
	const unsigned char opt0 = 1 << 0;
	const unsigned char opt1 = 1 << 1;
	const unsigned char opt2 = 1 << 2;
	const unsigned char opt3 = 1 << 3;
	// ...opt4, 5, 6, 7

	cout << bitset<8>(opt0) << endl;
	cout << bitset<8>(opt1) << endl;
	cout << bitset<8>(opt2) << endl;
	cout << bitset<8>(opt3) << endl;
	cout << endl;

	unsigned char items_flag = 0;									// 1byte = 8bit
	cout << "No item \t\t" << bitset<8>(items_flag) << endl;

	// item 0 on
	items_flag |= opt0;
	cout << "Item0 obtained \t\t" << bitset<8>(items_flag) << endl;

	// item 3 on
	items_flag |= opt3;
	cout << "Item3 obtained \t\t" << bitset<8>(items_flag) << endl;

	// item 3 lost
	items_flag &= ~opt3;
	cout << "Item3 lost \t\t" << bitset<8>(items_flag) << endl;

	// item 1 check
	if (items_flag & opt1) { cout << "Item1 exist \t\t" << bitset<8>(items_flag) << endl; }
	else { cout << "Item1 not exist \t" << bitset<8>(items_flag) << endl; }

	// item 0 check
	if (items_flag & opt0) { cout << "Item0 exist \t\t" << bitset<8>(items_flag) << endl; }
	else { cout << "Item0 not exist \t\t" << bitset<8>(items_flag) << endl; }

	// item 2,3 on
	items_flag |= (opt2 | opt3);
	cout << "Item2,3 obtained \t" << bitset<8>(items_flag) << endl;

	// item 1 x->o, item 2 o->x
	if ((items_flag & opt2) && !(items_flag &opt1))
	{
		items_flag ^= opt2;
		items_flag ^= opt1;
	}
	cout << "Item1,2 exchange \t" << bitset<8>(items_flag) << endl;
	cout << endl;

	/*----------------------------------------------------------------------------------*/

	// glCler(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)	// API디자인 옵션 => bitflag사용(|)

	// rgb == 3byte(255,255,255)
	// rgb 추출
	const unsigned int red_mask = 0xFF0000;					// mask: 해당구역 지정
	const unsigned int green_mask = 0x00FF00;
	const unsigned int blue_mask = 0x0000FF;

	unsigned int pixel_color = 0xDAA520;
	cout << std::bitset<32>(pixel_color) << endl;

	unsigned int red, green, blue;
	red = (pixel_color & red_mask) >> 16;				// 기존자리 옮기기(shift)
	green = (pixel_color & green_mask) >> 8;		
	blue = pixel_color & blue_mask;

	cout << "red\t" << bitset<8>(red) << " " << int(red) << endl;
	cout << "green\t" << bitset<8>(green) << " " << int(green) << endl;
	cout << "blue\t" << bitset<8>(blue) << " " << int(blue) << endl;
	cout << endl;

	/*----------------------------------------------------------------------------------*/

	//ex
	unsigned char option_viewed = 0x01;
	unsigned char option_edited = 0x02;
	unsigned char option_liked = 0x04;
	unsigned char option_shared = 0x08;
	unsigned char option_deleted = 0x80;

	unsigned char my_article_flags = 0;
	cout << "Init: \t\t" << bitset<8>(my_article_flags) << endl;

	// 기사를 봤을때
	my_article_flags |= option_viewed;
	cout << "Viewed: \t" << bitset<8>(my_article_flags) << endl;
	// 기사의 좋아요를 클릭
	my_article_flags |= option_liked;
	cout << "Liked: \t\t" << bitset<8>(my_article_flags) << endl;
	// 기사의 좋아요를 다시 클릭
	my_article_flags &= ~option_liked;
	cout << "Cancled: \t" << bitset<8>(my_article_flags) << endl;
	// 본기사만 삭제
	if(my_article_flags & option_viewed)			// Viewd 값 1이면
		my_article_flags |= option_deleted;			// 해당값 or
	cout << "Deleted: \t" << bitset<8>(my_article_flags) << endl;

	return 0;
}