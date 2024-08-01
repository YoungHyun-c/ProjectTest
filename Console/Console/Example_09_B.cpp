#include <iostream>

#pragma region �迭�� ������
/*
�ڡڡڡڡڡ� ���� ����
������
callbyRef
callbyValue

���� ���� ���� -> CallByValue
�Լ��� �μ��� �����Ҷ� �μ��� ���� ����Ǿ� �Լ��� �Ű������� ����.
�Լ� ���ο��� �Ű������� �����ϴ���, ȣ���� �Լ��� ���� �μ��� ������ �ʴ´�.

*/


int Sum(int a, int b)
{
	int Res;

	return 0;
}

void Value(int n);

//������ ���� ȣ��
void Address(int* n);
// �Լ� ȣ��� �μ��� ������ �ּҸ� �����ϴ� ���
// �Լ��� �Ű������� ���� ������ ���� ���� �μ��� ���� ���� ��������
// �Լ� ���ο��� �Ű������� ���� �����ϸ� ȣ���� �Լ��� ���� �μ��� ����
// ���� �����ϴ� ��� �ּҸ� ����. -> �޸𸮿� ������ ȿ���� ����.
// ����ü��.. Ŭ������

// �Լ��� ���������Ϳ� ���� �����ϰ�, ������ �� �ְ� ���ش�.
// ������ ����, ��Ī�� �����Ѵ�.
// �Լ��� ���� ���� ������ �� �ְ��Ѵ�.
void Reference(int& n);
// �갡 ���� �� �����ϰ� ����� �� �ִ�.
// �޸� �ּҰ� �����ϴ�.
// �����ʹ� Null�� ������ �� �ִ�. �� ��ȿ���� ���� �ּҸ� ������ �� �ִ�.
// -> �� �� �� �޸� ������ �߻��� �� �ִ�.

// �Ʒ��� ���� ���´� ������ �ƴ϶� ������ ����
// Num1, Num2�� ���� ����� 10, 20�� ����.
// �� Swap���ο����� ���� ����ǰ�, �����Լ��� �ִ� Num1, Num2�� ���� ������ ���� �ʴ´�.
void Swap(int a, int b);

void SwapAddress(int* a, int* b);

void SwapReference(int& a, int& b);

#pragma endregion


int main()
{
	/*{
		int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

		for (int i = 0; i < 10; i++)
		{
			std::cout << &arr[i] << std::endl;
		}
	}*/

	//�迭�� �������� ����
	// �����ͷε� �迭 ���ҿ� ������ ������!
	// ��, �迭�� ���ۺκ��� ����Ű�� �����͸� �����ϰ�,
	// �����Ϳ� 1�� ���ϸ� �� ���� ���Ҹ� ����Ű��
	// 2�� ���ϸ� �� �������� ���Ҹ� ����Ű�� �ȴ�.

	//{
	//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	//	int* Parr; // ������ ������
	//	int i;
	//	// parr�����͸� �迭�� ù��° ����� �ּҸ� ����
	//	Parr = &arr[0];

	//	for (i = 0; i < 10; i++)
	//	{
	//		std::cout << "arr�� �ּ� " << &arr[i] << std::endl;
	//		std::cout << "parr�� ��(�ּ�) : " << (Parr + i) << std::endl;
	//		std::cout << "parr�� �� : " << *(Parr + i) << std::endl;
	//	}
	//}

	// �� ����.
	//{
	//	int Num = 30;
	//	Value(Num);
	//	std::cout << "Num�� �� :" << Num << std::endl;
	//	std::cout << "Num�� �ּҰ� :" << &Num << std::endl;
	//}
	//{
	//	std::cout << "============" << std::endl;
	//	int Num = 40;
	//	Address(&Num);
	//	std::cout << "Num �� �� : " << Num << std::endl;
	//	std::cout << "Num �� �ּҰ� : " << &Num << std::endl;
	//}
	//{
	//	std::cout << "============" << std::endl;
	//	int Num = 50;
	//	Reference(Num);
	//	std::cout << "Num �� �� : " << Num << std::endl;
	//	std::cout << "Num �� �ּҰ� : " << &Num << std::endl;
	//}


	// Swap
	{
		std::cout << "Swap" << std::endl;
		int Num1 = 10;
		int Num2 = 20;

		std::cout << "������ ������ : " << Num1 << ',' << Num2 << std::endl;
		Swap(Num1, Num2);
		std::cout << "������ ������ : " << Num1 << ',' << Num2 << std::endl;
	}
	// SwapPointer
	{
		std::cout << "SwapPointer" << std::endl;
		int SwapNum1 = 10;
		int SwapNum2 = 20;

		std::cout << "������ ������ : " << SwapNum1 << ',' << SwapNum2 << std::endl;
		SwapAddress(&SwapNum1, &SwapNum2);
		std::cout << "������ ������ : " << SwapNum1 << ',' << SwapNum2 << std::endl;
	}
	// SwapReference
	{
		std::cout << "SwapReference" << std::endl;
		int SwapNum1 = 10;
		int SwapNum2 = 20;

		std::cout << "������ ������ : " << SwapNum1 << ',' << SwapNum2 << std::endl;
		SwapReference(SwapNum1, SwapNum2);
		std::cout << "������ ������ : " << SwapNum1 << ',' << SwapNum2 << std::endl;
	}

	{
		/*
		void Pointer
			->�ڷ����� ���� ������ ����
			->�ڷ����� ������ ���� �ʰ�, � �ڷ����� �ּҵ� ���尡��.
			// ���� �����Ϸ��� ��������ȯ�� �ؾ��Ѵ�.
			// ����ȯ�� �� �� ���� ��쿡, ����ġ ���� ������ �߻��� �� �ִ�.
		*/
		void* vp = nullptr;
		int c = 3;
		double d = 3.1;

		int a = 1;
		int* p = &a;
		*p = 3;

		vp = &d;
		//*vp = 1; ->Error //�츮�� �˰� �ִ� ������δ� �Ұ���.
		// -> ���� ����ȯ�� ���ָ� �ȴ�.
		// (�ڷ���*)�� �������ν� �����ϰ� �� : ���� ����ȯ.
		
		*(int*)vp = 5;
		 std::cout << *(int*)vp << std::endl;
	}

	{
		int* ptr = new int(10);

		delete ptr;
		int* Array = new int[5];
		
		for (int i = 0; i < 5; i++)
		{
			Array[i] = i * 2;
		}
		delete[] Array;
		Array = nullptr; // -> ������ �ϰ�, ����Ű�� �ʴ´�.
	}

	{
		int num = 10;
		
		int* p = &num;
		*p = 777;

		int** pp;
		pp = &p;
		std::cout << "pp�� �� : (p�� �ּҰ�)" << pp << std::endl;

		std::cout << "num�� �ּҰ� :"  << *pp << std::endl;
	}

	return 0;
}

void Value(int n)
{
	n = 10;
	std::cout << "n�� �� : " << n << std::endl;
	std::cout << "n�� �ּҰ� : " << &n << std::endl;
}

void Address(int* n)
{
	*n = 10;
	std::cout << "N�� �� : " << *n << std::endl;
	std::cout << "N�� �ּҰ� : " << &n << std::endl;
}

void Reference(int& n)
{
	n = 10;
	std::cout << "N�� �� : " << n << std::endl;
	std::cout << "N�� �ּҰ� : " << &n << std::endl;
}

void Swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
	std::cout << "Swap()�Լ� ������ �� : ";
	std::cout << a << ", " << b << std::endl;
}

void SwapAddress(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void SwapReference(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}


// ����
/*
1. �����Ҵ��, �����Ҵ��� ������.

�޸𸮸� �� �� �����Ҵ��� �ϰ� �Ǹ�, ������ ������ ���־�� �Ѵ�.
������ ���� ���� ���� ������, �޸� ���� ������ �Ͼ��.

C -> malloc memory allocation
	-> free
C++ -> new
	-> delete -> �޸𸮸� ����

	��ȿ���� ���� �޸� �ּҸ� ����Ű�� �����Ͱ� ��۸� ������. (���� �ߴµ� ����Ű�� �Ǹ�)

int* Cptr = (int*)malloc(sizeof(int) * 10); // �޸𸮿��� 10���� �Ҵ�.
int* CppPtr = new int(10); // int�� ���� �ϳ��� �����Ҵ��ϰ�, 10���� �ʱ�ȭ �ϰڴ�.

int* Array = new int[5]; // 5���� int�� ������ �� �ִ� �迭�� �Ҵ�.


2. Ŭ������ �����ΰ���?

3. ����ü�� Ȱ���� �л����� ����ϱ�.
 �� �л������� ����ϴ� �Լ� ����,
 �� �л������� �߰��ϴ� �Լ� ����.

�Ʒ��� ���� ���簡 �ƴ� ���� ������� �ϱ�.
void print(Student s)
{

}

*/
