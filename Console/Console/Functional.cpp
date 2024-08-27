#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int Sum(int& a, int& b, std::function<void(int* a, int* b)> Func)
{
	if (Func != nullptr)
	{
		Func(&a, &b);
	}

	return a + b;
}

void Test(int* a, int* b)
{
	if (*a < *b)
	{
		*b -= *a;
	}
}

// �Լ���ü�� ����Ͽ� �ݹ��Լ�
class CallBack
{
public:
	CallBack()
		: Count(0)
	{
	}

	void operator()(int _Value)
	{
		std::cout << "CallBack Function Was Called : " << ++Count + _Value << std::endl;
	}

	int GetCount() const
	{
		return Count;
	}
private:
	int Count;
};

void TriggerEvent(CallBack& CallBack, int _Value)
{
	CallBack(_Value);
}

// �Լ� ��ü�� ȣ���ϴ� ������ �����ε�
class CountingComparator
{
public:
	CountingComparator() : Count(0) {}

	// �Լ� ��ü�� ȣ���ϴ� ������ �����ε�
	bool operator()(int a, int b)
	{
		++Count;
		return a < b;
	}

	int GetCount() const {
		return Count;
	}

private:
	int Count;
};

int main()
{
	int A = 10;
	int B = 20;

	std::cout << Sum(A, B, NULL) << std::endl;
	std::cout << Sum(A, B, Test) << std::endl;

	CallBack MyCall;
	TriggerEvent(MyCall, 3);
	std::cout << MyCall.GetCount() << std::endl;
	TriggerEvent(MyCall, 5);
	std::cout << MyCall.GetCount() << std::endl;

	std::vector<int> numbers = { 4, 2, 5, 1, 3 };
	CountingComparator Cmp;

	std::sort(numbers.begin(), numbers.end(), Cmp);

	for (int i = 0; i < numbers.size(); i++)
	{
		std::cout << numbers[i] << std::endl;
	}
	std::cout << "ComP : " << Cmp.GetCount();

	return 0;
}