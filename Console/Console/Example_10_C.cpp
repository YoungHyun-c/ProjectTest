#include <iostream>

/*
�Ҹ���
-> ��ü�� �Ҹ�ɶ� �ڵ����� ȣ��Ǵ� ����Լ��̴�.
-> �Ű������� ���� �� ����, ��ȯ���� ���ó� ���� �����ε� �Ұ���
->

*/

class MyClass
{
public:
	MyClass(int size); // ������
	~MyClass(); // �Ҹ���

private:
	int* Data;
};

MyClass::MyClass(int Size)
{
	Data = new int[Size];
	std::cout << "���� ������ ���� ~ ȣ��!" << std::endl;
}
MyClass::~MyClass()
{
	delete[] Data; // �ݳ��̿�~
	Data = nullptr;
	std::cout << "���� �Ҹ����� ~ ȣ��!" << std::endl;
}


int main()
{
	MyClass* m = new MyClass(10);
	delete m;

	return 0;
}