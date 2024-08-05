#include <iostream>

/*
===========================
복사 생성자
- 동일한 클래스의 객체를 복사해서 생성할 때 사용하는 생성자.

얕은복사
-> 객체를 복사할때 객체의 모든 멤버변수를 단순히 복사.
만약 멤버변수가 포인터인 경우라면, 포인터의 주소값 복사 -> 같은 메모리 영역을 가리키게 됨.
-> 만약 한 객체에서 해당 메모리를 수정하면 영향을 받음.
-> 두 객체가 같은 메모리 주소를 가리키기 때문에 한 객체가 소멸되면서 메모리를
해제하면 다른 객체는 더 이상 유효하지 않은 메모리를 가리키게 되어 문제가 발생함.

깊은복사
-> 객체가 동적메모리를 사용할 때 필요함.
-> 원본 객체와 동일한 값을 가지는 새로운 메모리를 할당하여, 복사하는 것을 의미함.
-> 다른 메모리를 사용하게 되므로, 서로 영향을 주지 않는다.


★★★★★★
면접질문
깊은복사 와 얕은복사의 차이점.

*/

class Person
{
public:
	Person(int a) : age(a) {};

	// 컴파일러가 생성하는 기본복사 생성자 형태.
	// 없어도 컴파일러가 훅 ~ 하고 삽입한다.
	// 복사생성자. 이러한 형태를 띄고 있다. 얕은복사.
	// -> 객체를 복사할때, 객체의 모든 변수를 단순하게 복사하는 것을 얕은 복사.
	Person(const Person& other) : age(other.age) {}

public:
	void SetAge(int age) { this->age = age; }
	int GetAge() { return age; }

private:
	int age;
	int* data; // 멤버변수에 만약에 포인터가 있다면, 주소값만 복사한다.
	// -> 같은 메모리 영역을 가리기케 된다.
};

// 얕복
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

// 깊복
class DeepArray
{
public:
	int* data;
	int Size;
	
	DeepArray(int size);
	// 깊은복사
	DeepArray(const DeepArray& other);
	~DeepArray();
};

int main()
{
	Person Kim(21);
	Person Clone(Kim); // 복사생성자 호출
	// 만약에 Kim을 지우면, 다른 객체는 더이상의 유효하지 않은 메모리를 가리키게 된다. 얕은복사의 문제점.
	// 그래서 만들어진게 깊은 복사.


	// 얕은 복사 -> 터진다.
	/*{
		MyArray arr1(10);
		arr1.SetValue(0, 42);

		MyArray arr2(arr1);

		std::cout << "arr1 값 : " << arr1.GetValue(0) << std::endl;
		std::cout << "arr2 값 : " << arr2.GetValue(0) << std::endl;
		arr1.SetValue(0, 100);
		std::cout << "arr1 값(변경후) : " << arr1.GetValue(0) << std::endl;
		std::cout << "arr2 값(arr1 변경된후) : " << arr2.GetValue(0) << std::endl;
	}*/

	// 깊은 복사.
	{
		DeepArray Arr1(10);
		Arr1.data[0] = 1;

		std::cout << Arr1.data[0] << std::endl;

		DeepArray Clone = Arr1; // 대입연산자나 Clone(Arr1)이나 같다.

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
	data = new int[size]; // 생성자에서 동적메모리 할당.
}

// 복사 생성자 정의 (깊은복사)
DeepArray::DeepArray(const DeepArray& Other)
{
	this->Size = Other.Size;
	this->data = new int[Other.Size]; // 새로운 공간 할당.
	for (int i = 0; i < Size; i++) // 데이터 복사.
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