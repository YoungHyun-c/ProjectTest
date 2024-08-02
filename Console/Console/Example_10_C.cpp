#include <iostream>

/*
소멸자
-> 객체가 소멸될때 자동으로 호출되는 멤버함수이다.
-> 매개변수를 가질 수 없고, 반환값도 역시나 없고 오버로딩 불가능
->

*/

class MyClass
{
public:
	MyClass(int size); // 생성자
	~MyClass(); // 소멸자

private:
	int* Data;
};

MyClass::MyClass(int Size)
{
	Data = new int[Size];
	std::cout << "여긴 생성자 영역 ~ 호출!" << std::endl;
}
MyClass::~MyClass()
{
	delete[] Data; // 반납이요~
	Data = nullptr;
	std::cout << "여긴 소멸자임 ~ 호출!" << std::endl;
}


int main()
{
	MyClass* m = new MyClass(10);
	delete m;

	return 0;
}