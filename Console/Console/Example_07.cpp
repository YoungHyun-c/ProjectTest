#include <iostream>

using namespace std;

// ���׿�����
// �ڵ��� ������ ���̰� ������ ������ ǥ���ϴµ� �����ϰ� ����.
// ������ ��찡 ����ٸ� �б⿡ ���� if else�� ó���ϴ°� �� ���� �� �ִ�.
// ���� �ʹ� ������ ���ǽĿ��� �������.
int main()
{
	int num1 = 2;
	int num2 = 3;

	int Result;

	Result = (num1 > num2) ? num1 : num2;

	cout << Result << endl;

	
	/*int a = 5;
	int b = 10;
	int c = 15;

	int Result;

	if (a < b)
	{
		if (b < c)
		{
			Result = a + b;
		}
		else
		{
			Result = a - b;
		}
	}
	else
	{
		if (b > c)
		{
			Result = a * b;
		}
		else
		{
			Result = a / b;
		}
	}

	cout << "��� : " << Result << endl;*/


	int a = 5;
	int b = 10;
	int c = 15;

	if (a < b)
	{
		if (b < c)
		{
			Result = a + b;
		}
		else
		{
			Result = a - b;
		}
	}
	//1. ������ ���ǹ�. ������ ����
	Result = (a < b) ? ((b < c) ? a + b : a - b) : ((b > c) ? a * b : a / b);


}