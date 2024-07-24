#include <iostream>

using namespace std;

// 삼항연산자
// 코드의 가독성 높이고 간결한 조건을 표현하는데 유용하게 쓰임.
// 복잡한 경우가 생긴다면 분기에 따라서 if else로 처리하는게 더 좋을 수 있다.
// 따라서 너무 복잡한 조건식에는 사용지양.
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

	cout << "결과 : " << Result << endl;*/


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
	//1. 복잡한 조건문. 안좋은 예시
	Result = (a < b) ? ((b < c) ? a + b : a - b) : ((b > c) ? a * b : a / b);


}