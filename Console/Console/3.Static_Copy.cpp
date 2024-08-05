#include <iostream>

/*
===========================
���� ������
- ������ Ŭ������ ��ü�� �����ؼ� ������ �� ����ϴ� ������.

��������
-> ��ü�� �����Ҷ� ��ü�� ��� ��������� �ܼ��� ����.
���� ��������� �������� �����, �������� �ּҰ� ���� -> ���� �޸� ������ ����Ű�� ��.
-> ���� �� ��ü���� �ش� �޸𸮸� �����ϸ� ������ ����.
-> �� ��ü�� ���� �޸� �ּҸ� ����Ű�� ������ �� ��ü�� �Ҹ�Ǹ鼭 �޸𸮸�
�����ϸ� �ٸ� ��ü�� �� �̻� ��ȿ���� ���� �޸𸮸� ����Ű�� �Ǿ� ������ �߻���.

��������
-> ��ü�� �����޸𸮸� ����� �� �ʿ���.
-> ���� ��ü�� ������ ���� ������ ���ο� �޸𸮸� �Ҵ��Ͽ�, �����ϴ� ���� �ǹ���.
-> �ٸ� �޸𸮸� ����ϰ� �ǹǷ�, ���� ������ ���� �ʴ´�.


�ڡڡڡڡڡ�
��������
�������� �� ���������� ������.

*/

class Person
{
public:
	Person(int a) : age(a) {};

	// �����Ϸ��� �����ϴ� �⺻���� ������ ����.
	// ��� �����Ϸ��� �� ~ �ϰ� �����Ѵ�.
	// ���������. �̷��� ���¸� ��� �ִ�. ��������.
	// -> ��ü�� �����Ҷ�, ��ü�� ��� ������ �ܼ��ϰ� �����ϴ� ���� ���� ����.
	Person(const Person& other) : age(other.age) {}

public:
	void SetAge(int age) { this->age = age; }
	int GetAge() { return age; }

private:
	int age;
	int* data; // ��������� ���࿡ �����Ͱ� �ִٸ�, �ּҰ��� �����Ѵ�.
	// -> ���� �޸� ������ �������� �ȴ�.
};

// �躹
class MyArray
{
private:
	int* data;
	int size;

public:
	MyArray(int size):size(size), data(new int[size]) {}
	~MyArray()
	{
		delete[] data;
	}

	void SetValue(int index, int value) { data[index] = value; }
	int GetValue(int index) { return data[index]; }
};

// ��
class DeepArray
{
public:
	int* data;
	int Size;
	
	DeepArray(int size);
	// ��������
	DeepArray(const DeepArray& other);
	~DeepArray();
};

int main()
{
	Person Kim(21);
	Person Clone(Kim); // ��������� ȣ��
	// ���࿡ Kim�� �����, �ٸ� ��ü�� ���̻��� ��ȿ���� ���� �޸𸮸� ����Ű�� �ȴ�. ���������� ������.
	// �׷��� ��������� ���� ����.


	// ���� ���� -> ������.
	/*{
		MyArray arr1(10);
		arr1.SetValue(0, 42);

		MyArray arr2(arr1);

		std::cout << "arr1 �� : " << arr1.GetValue(0) << std::endl;
		std::cout << "arr2 �� : " << arr2.GetValue(0) << std::endl;
		arr1.SetValue(0, 100);
		std::cout << "arr1 ��(������) : " << arr1.GetValue(0) << std::endl;
		std::cout << "arr2 ��(arr1 �������) : " << arr2.GetValue(0) << std::endl;
	}*/

	// ���� ����.
	{
		DeepArray Arr1(10);
		Arr1.data[0] = 1;

		std::cout << Arr1.data[0] << std::endl;

		DeepArray Clone = Arr1; // ���Կ����ڳ� Clone(Arr1)�̳� ����.

		Arr1.data[0] = 2;
		std::cout << Arr1.data[0] << std::endl;
		std::cout << &Arr1.data[0] << std::endl;

		std::cout << Clone.data[0] << std::endl;
		std::cout << &Clone.data[0] << std::endl;

	}

	return 0;
} 

DeepArray::DeepArray(int size)
{
	this->Size = size;
	data = new int[size]; // �����ڿ��� �����޸� �Ҵ�.
}

// ���� ������ ���� (��������)
DeepArray::DeepArray(const DeepArray& Other)
{
	this->Size = Other.Size;
	this->data = new int[Other.Size]; // ���ο� ���� �Ҵ�.
	for (int i = 0; i < Size; i++) // ������ ����.
	{
		this->data[i] = Other.data[i];
	}
}

DeepArray::~DeepArray()
{
	if (data != nullptr)
	{
		delete[] this->data;
		data = nullptr;
	}
}