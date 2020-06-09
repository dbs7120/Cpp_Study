/*
	������ ȫ������ �����ϸ� ���� C++
	�ּ�
	���� l-value, r-value https://effort4137.tistory.com/entry/Lvalue-Rvalue
	������ �ʱ�ȭ �ʿ�
	����� ��Ʈ��
*/

#include <iostream>	// cout, cin, endl, ...

int main()
{
	std::cout << "Chapter1_1" << std::endl;

	int x = 123;	// initialization �ʱ�ȭ
	x = 5;			// assignment ����

	int y(123);		// initialization �ʱ�ȭ��� 2
	std::cout << x << std::endl;
	std::cout << y << std::endl;
	std::cout << &x << std::endl;	// �޸� �ּҰ� (&�����ڴ� l-value���� �䱸��)


	int z;		// ������ z�� ���������� �޸� ���� �Ҵ�

	/*
		�ʱ�ȭ �����ʰ� ��� X
		int z;
		std::cout << z << std::endl;
	*/

	/*----------------------------------------------------------------------------------*/

	// std �̸����� cout�� ����ϱ����� :: ���

	int num = 1024;
	double pi = 3.141592;
	std::cout << "C++ lecture" << std::endl;
	std::cout << "num is " << num << std::endl;
	std::cout << "pi is " << pi << std::endl;

	std::cout << "abc" << "\t" << "def" << std::endl;
	std::cout << "ab" << "\t" << "cdef" << std::endl;	// \t : �� (�̽������� '����')
	std::cout << "ab" << "\n\n" << "cdef" << std::endl;	// \n : ����

	using namespace std;	// std ������ ��� �������� std:: ��������

	cout << "\nnum is " << num << endl;

	cout << "\a";	// \a : ������ �˸�(alert)

	cin >> x;
	cout << "Your input is " << x << endl;

	return 0;
}