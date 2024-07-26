#include <iostream>
#include <string>
#include <algorithm>


// 객관식 문제
// 1. C++ 에서 for 루프의 기본 형식으로 올바른 것은 무엇인가?
// 답 : 1.

// 2. 다음 중 if 문을 사용하는 올바른 구문은 무엇인가?
// 답 : 2.

// 3. 다음코드에서 array[2]의 값은 무엇인가?
// 답 : 3.

// 4. 다음 중 switch 문에서 사용되는 키워드가 아닌 것은 무엇인가?
// 답 : 4.

// 5. 다음 중 if 문이 참일 경우 실행되지 않은 문장은 무엇인가?
// 답 : 1.

// 구현문제.
// 1. a 와 b는 각각 얼마인가? 완
void ResultAB();

// 2. 숫자가 주어지면 소수인지 아닌지 판별하는 프로그램을 작성하라. 완
void Decimal();

// 3. 2개의 정수를 입력받아 그 구간에 속한 모든 수의 합 구하기 완
int ABSum(int _A, int _B);

// 4. 배열에 1 ~ 10까지 데이터가 저장되어있다고 가정할때 짝수만 출력하는 프로그램을 작성해라. 완
void EvenPrint();

// 5. 10진수를 2진수로 바꾸기 완
void TenToE();

// 6. 문자열 단어 갯수 세기 완
void WordCount();

// 7. 다음과 같이 배열이 존재한다고 가정할때 공통 항목을 찾는 프로그램을 작성하기 완
void ArrCompare();

// 8. 입력한 월, 일로 어떤요일인지 맞춰보기. 완
void PrintCalendar();

int main()
{
	// 구현 1번. 완
	ResultAB();

	// 구현 2번. 완
	Decimal();

	// 구현 3번. 완
	int A, B;
	std::cout << "두 개의 정수를 입력해라) : ";
	std::cin >> A;
	std::cin >> B;
	int Sum = ABSum(A, B);
	std::cout << "모든 수의 합 : " << Sum << std::endl;

	// 구현 4번. 완
	EvenPrint();

	// 구현 5번. 완
	TenToE();

	// 구현 6번. 완 따로 실행
	// WordCount();

	// 구현 7번. 완
	ArrCompare();

	// 구현 8번. 완
	PrintCalendar();


	return 0;
}

// 1 번
void ResultAB()
{
	int a = 32 >> 1;
	int b = a >> 3;

	std::cout << a << std::endl; // 16
	std::cout << b << std::endl; // 2
	// 풀이
	/*
	비트연산자로서 , 32는 0010 0000 인데, >> 우측으로 시프트 되기 때문에
	a는 0001 0000 = 16이 된다.
	따라서 b는 또 a에서 3번 우측으로 시프트 되면, 0000 0010 이 되어 2가 나온다.
	*/
}

// 2번
void Decimal()
{
	std::cout << "숫자를 입력하세요: ";
	int Num;
	std::cin >> Num;
	std::string Result = "YES";
	if (Num == 1)
	{
		Result = "NO";
	}
	for (int i = 2; i < Num; i++)
	{
		if (Num % i == 0)
		{
			Result = "NO";
		}
	}

	std::cout << Result << std::endl;
}

// 3번
int ABSum(int _A, int _B)
{
	int Sum = 0;
	for (int i = _A; i <= _B; i++)
	{
		Sum += i;
	}
	return Sum;
}

// 4번
void EvenPrint()
{
	int Arr[11] = {};
	std::cout << "배열에 저장된 데이터 ";
	for (int i = 1; i < 11; i++)
	{
		Arr[i] = i;
		std::cout << Arr[i] << " ";
	}

	std::cout << '\n';
	std::cout << "짝수만 출력 : ";

	for (int i = 1; i < 11; i++)
	{
		if (Arr[i] % 2 == 0)
		{
			std::cout << Arr[i] << " ";
		}
	}
	std::cout << std::endl;
}

// 5번
void TenToE()
{
	std::cout << "숫자를 입력하세요: ";
	int Num;
	std::cin >> Num;
	int Result[9] = {};
	int Count = 0;

	while (Num)
	{
		if (Num % 2 == 1)
		{
			Result[Count] = 1;
		}
		Num /= 2;

		Count++;
	}

	std::cout << "입력한 숫자의 2진수 표현: ";
	for (int i = Count - 1; i >= 0; i--)
	{
		std::cout << Result[i];
	}

	std::cout << std::endl;
}

// 6번
void WordCount()
{
	std::string MyString = "";
	std::cout << "문자열을 입력하세요: ";
	getline(std::cin, MyString ,'\n');

	int Count = 1;
	if (MyString.length() == 0)
	{
		Count = 0;
	}
	for (int i = 0; i < MyString.length(); i++)
	{
		if (MyString[i] == ' ')
		{
			Count++;
		}
	}

	std::cout << "입력한 문자열의 단어 수: " << Count << std::endl;
}

// 7번
void ArrCompare()
{
	int arr1[] = { 1, 5, 5, 10 };
	int arr2[] = { 3, 4, 5, 5, 10 };
	int arr3[] = { 5, 5, 10, 20 };

	int Len1 = sizeof(arr1) / sizeof(int);
	int Len2 = sizeof(arr2) / sizeof(int);
	int Len3 = sizeof(arr3) / sizeof(int);

	int Result[100] = {};
	int Index = 0;

	for (int i = 0; i < Len1; i++)
	{
		for (int j = 0; j < Len2; j++)
		{
			if (arr1[i] == arr2[j])
			{
				Result[Index] = arr1[i];
				Index++;
			}
		}
	}
	int ResultLen = Index - 1;
	for (int i = 0; i < ResultLen; i++)
	{
		for (int j = 0; j < Len3; j++)
		{
			if (Result[i] == arr3[j])
			{
				Result[Index] = arr3[j];
				Index++;
			}
		}
	}

	int Answer[10] = {};
	int AIndex = 0;

	std::sort(Result, Result + Index);
	std::cout << "결과 : ";
	for (int i = 0; i < Index; i++)
	{
		if (Result[i] != Result[i + 1])
		{
			Answer[AIndex] = Result[i];
			AIndex++;
			//std::cout << Result[i] << " ";
		}
	}

	// 쉼표하려고 만듬.
	for (int i = 0; i < AIndex; i++)
	{
		if (Answer[i + 1] != '\n')
		{
			std::cout << ",";
		}
		std::cout << Answer[i];
	}

	std::cout << std::endl;
}

// 8번.
void PrintCalendar()
{
	std::string Day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
	int Month[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int InputMonth, InputDay;
	std::cout << "월, 일을 입력 해라 : ";
	std::cin >> InputMonth;
	std::cin >> InputDay;

	int Sum = 0;
	for (int i = 0; i < InputMonth - 1; i++)
	{
		Sum += Month[i];
	}
	Sum += InputDay;

	std::cout << InputMonth << "월 " << InputDay << " 일은" << Day[Sum % 7] << " 입니다.";
}
