

/*
Up + Casting
-> 자식 클래스의 객체를 부모 클래스타입으로 변환.
-> 명시적인 타입 변환이 필요 없음.
Down + Casting
-> 부모형을 자식으로 바꾼다. -> 위험성이 있다.
-> 자식클래스의 고유한 멤버함수를 호출할 때 사용하는 방법.
-> 안전하게 다운캐스팅을 하는 방법이 존재하고, 그 이외의 방식으로 하면 절대로 안됨.

*/

#include <iostream>

class Shape
{
public:
	virtual void Draw() const
	{
		std::cout << "부모 클래스 Shape" << std::endl;
	}
	virtual ~Shape() = default;
};

class Circle : public Shape
{
public:
	void Draw() const override
	{
		std::cout << "자식 클래스 Circle" << std::endl;
	}
	void CircleFunc()
	{
		std::cout << "Circle클래스의 멤버함수" << std::endl;
	}
};

class Rectangle : public Shape
{
public:
	void Draw() const override
	{
		std::cout << "자식 클래스 Rectangle" << std::endl;
	}
	void RectangleFunc()
	{
		std::cout << "Rectangle클래스의 멤버함수" << std::endl;
	}
};

int main()
{
	Shape* shape1;
	shape1 = new Circle(); // -> Upcasting 자식의 객체를 부모의 포인터로 가르키는 것.
	shape1->Draw();

	Shape* shape2 = new Rectangle();

	shape2->Draw();
	// 자식들의 고유한 멤버함수들은 부를 수 없는데, 방법은 Downcasting이 있다.

	//
	Circle* C = dynamic_cast<Circle*>(shape1);

	/*
	UpDownCasting

	C++ 4대 캐스팅 Casting.
	static_cast, 컴파일 타임에 타입을 변환하는데 사용.
	// -> 메모리 크기만 다른 값 대 값 형변환에 사용된다.
	(int)Test <= static_cast<int>로 다시 바뀌어 애는 컴파일시 더 오래 걸린다.

	dynamic_cast, 런타임에 수행을하고, 다운캐스팅에서 일반적으로 사용을 한다.
	// 부모 자식 구조에서 사용된다. 다운캐스팅에 이용.
	-> 가상함수 테이블을 참조해서, 다운캐스팅이 가능한지를 알아봐준다.

	const_cast, 타입자체를 바꾸는건 아닌 객체의 상수성을 제거한다. 포인터나 참조를 변환할때만 사용.
	-> 존재만 한다. 굳이 써야되나 싶다.

	reinterpret_cast 포인터가 다른 포인터 형식으로 변환될 수 있도록 한다. -> 정수를 포인터로, 포인터를 정수로 변경할 때 사용.
	*/
	//dynamic_cast
	 {
		// 다운캐스팅을 안전하게 할 수 있게 도와준다.
		/*A* PtrC = new C();
		B* Test = dynamic_cast<B*>(PtrC);*/

		// 이러면 심각한 오류가 생길 수 있다. <- B가 C가 된것.
		// B* Test1 = (B*)PtrC;
	 }
	//reinterpret_cast
	{
		int Value = 3;
		int* Ptr = &Value; // 3
		__int64 Addrees = reinterpret_cast<__int64>(Ptr); // 주소
		__int64 Address3 = (__int64)Ptr; // 주소
		int* Ptr2 = reinterpret_cast<int*>(Addrees); // 3으로 변환
		int a = 0;
	}

	return 0;
}

// const_cast 
void Print(const int* _Value)
{
	int* NewValue = const_cast<int*>(_Value);
	*NewValue = 100;
}