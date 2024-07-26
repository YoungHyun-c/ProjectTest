#include <iostream>
#include <string>
#include <algorithm>


// ������ ����
// 1. C++ ���� for ������ �⺻ �������� �ùٸ� ���� �����ΰ�?
// �� : 1.

// 2. ���� �� if ���� ����ϴ� �ùٸ� ������ �����ΰ�?
// �� : 2.

// 3. �����ڵ忡�� array[2]�� ���� �����ΰ�?
// �� : 3.

// 4. ���� �� switch ������ ���Ǵ� Ű���尡 �ƴ� ���� �����ΰ�?
// �� : 4.

// 5. ���� �� if ���� ���� ��� ������� ���� ������ �����ΰ�?
// �� : 1.

// ��������.
// 1. a �� b�� ���� ���ΰ�? ��
void ResultAB();

// 2. ���ڰ� �־����� �Ҽ����� �ƴ��� �Ǻ��ϴ� ���α׷��� �ۼ��϶�. ��
void Decimal();

// 3. 2���� ������ �Է¹޾� �� ������ ���� ��� ���� �� ���ϱ� ��
int ABSum(int _A, int _B);

// 4. �迭�� 1 ~ 10���� �����Ͱ� ����Ǿ��ִٰ� �����Ҷ� ¦���� ����ϴ� ���α׷��� �ۼ��ض�. ��
void EvenPrint();

// 5. 10������ 2������ �ٲٱ� ��
void TenToE();

// 6. ���ڿ� �ܾ� ���� ���� ��
void WordCount();

// 7. ������ ���� �迭�� �����Ѵٰ� �����Ҷ� ���� �׸��� ã�� ���α׷��� �ۼ��ϱ� ��
void ArrCompare();

// 8. �Է��� ��, �Ϸ� ��������� ���纸��. ��
void PrintCalendar();

int main()
{
	// ���� 1��. ��
	ResultAB();

	// ���� 2��. ��
	Decimal();

	// ���� 3��. ��
	int A, B;
	std::cout << "�� ���� ������ �Է��ض�) : ";
	std::cin >> A;
	std::cin >> B;
	int Sum = ABSum(A, B);
	std::cout << "��� ���� �� : " << Sum << std::endl;

	// ���� 4��. ��
	EvenPrint();

	// ���� 5��. ��
	TenToE();

	// ���� 6��. �� ���� ����
	// WordCount();

	// ���� 7��. ��
	ArrCompare();

	// ���� 8��. ��
	PrintCalendar();


	return 0;
}

// 1 ��
void ResultAB()
{
	int a = 32 >> 1;
	int b = a >> 3;

	std::cout << a << std::endl; // 16
	std::cout << b << std::endl; // 2
	// Ǯ��
	/*
	��Ʈ�����ڷμ� , 32�� 0010 0000 �ε�, >> �������� ����Ʈ �Ǳ� ������
	a�� 0001 0000 = 16�� �ȴ�.
	���� b�� �� a���� 3�� �������� ����Ʈ �Ǹ�, 0000 0010 �� �Ǿ� 2�� ���´�.
	*/
}

// 2��
void Decimal()
{
	std::cout << "���ڸ� �Է��ϼ���: ";
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

// 3��
int ABSum(int _A, int _B)
{
	int Sum = 0;
	for (int i = _A; i <= _B; i++)
	{
		Sum += i;
	}
	return Sum;
}

// 4��
void EvenPrint()
{
	int Arr[11] = {};
	std::cout << "�迭�� ����� ������ ";
	for (int i = 1; i < 11; i++)
	{
		Arr[i] = i;
		std::cout << Arr[i] << " ";
	}

	std::cout << '\n';
	std::cout << "¦���� ��� : ";

	for (int i = 1; i < 11; i++)
	{
		if (Arr[i] % 2 == 0)
		{
			std::cout << Arr[i] << " ";
		}
	}
	std::cout << std::endl;
}

// 5��
void TenToE()
{
	std::cout << "���ڸ� �Է��ϼ���: ";
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

	std::cout << "�Է��� ������ 2���� ǥ��: ";
	for (int i = Count - 1; i >= 0; i--)
	{
		std::cout << Result[i];
	}

	std::cout << std::endl;
}

// 6��
void WordCount()
{
	std::string MyString = "";
	std::cout << "���ڿ��� �Է��ϼ���: ";
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

	std::cout << "�Է��� ���ڿ��� �ܾ� ��: " << Count << std::endl;
}

// 7��
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
	std::cout << "��� : ";
	for (int i = 0; i < Index; i++)
	{
		if (Result[i] != Result[i + 1])
		{
			Answer[AIndex] = Result[i];
			AIndex++;
			//std::cout << Result[i] << " ";
		}
	}

	// ��ǥ�Ϸ��� ����.
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

// 8��.
void PrintCalendar()
{
	std::string Day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
	int Month[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int InputMonth, InputDay;
	std::cout << "��, ���� �Է� �ض� : ";
	std::cin >> InputMonth;
	std::cin >> InputDay;

	int Sum = 0;
	for (int i = 0; i < InputMonth - 1; i++)
	{
		Sum += Month[i];
	}
	Sum += InputDay;

	std::cout << InputMonth << "�� " << InputDay << " ����" << Day[Sum % 7] << " �Դϴ�.";
}
