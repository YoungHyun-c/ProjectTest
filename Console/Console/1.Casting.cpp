

/*
Up + Casting
-> �ڽ� Ŭ������ ��ü�� �θ� Ŭ����Ÿ������ ��ȯ.
-> ������� Ÿ�� ��ȯ�� �ʿ� ����.
Down + Casting
-> �θ����� �ڽ����� �ٲ۴�. -> ���輺�� �ִ�.
-> �ڽ�Ŭ������ ������ ����Լ��� ȣ���� �� ����ϴ� ���.
-> �����ϰ� �ٿ�ĳ������ �ϴ� ����� �����ϰ�, �� �̿��� ������� �ϸ� ����� �ȵ�.

*/

#include <iostream>

class Shape
{
public:
	virtual void Draw() const
	{
		std::cout << "�θ� Ŭ���� Shape" << std::endl;
	}
	virtual ~Shape() = default;
};

class Circle : public Shape
{
public:
	void Draw() const override
	{
		std::cout << "�ڽ� Ŭ���� Circle" << std::endl;
	}
	void CircleFunc()
	{
		std::cout << "CircleŬ������ ����Լ�" << std::endl;
	}
};

class Rectangle : public Shape
{
public:
	void Draw() const override
	{
		std::cout << "�ڽ� Ŭ���� Rectangle" << std::endl;
	}
	void RectangleFunc()
	{
		std::cout << "RectangleŬ������ ����Լ�" << std::endl;
	}
};

int main()
{
	Shape* shape1;
	shape1 = new Circle(); // -> Upcasting �ڽ��� ��ü�� �θ��� �����ͷ� ����Ű�� ��.
	shape1->Draw();

	Shape* shape2 = new Rectangle();

	shape2->Draw();
	// �ڽĵ��� ������ ����Լ����� �θ� �� ���µ�, ����� Downcasting�� �ִ�.

	//
	Circle* C = dynamic_cast<Circle*>(shape1);

	/*
	UpDownCasting

	C++ 4�� ĳ���� Casting.
	static_cast, ������ Ÿ�ӿ� Ÿ���� ��ȯ�ϴµ� ���.
	// -> �޸� ũ�⸸ �ٸ� �� �� �� ����ȯ�� ���ȴ�.
	(int)Test <= static_cast<int>�� �ٽ� �ٲ�� �ִ� �����Ͻ� �� ���� �ɸ���.

	dynamic_cast, ��Ÿ�ӿ� �������ϰ�, �ٿ�ĳ���ÿ��� �Ϲ������� ����� �Ѵ�.
	// �θ� �ڽ� �������� ���ȴ�. �ٿ�ĳ���ÿ� �̿�.
	-> �����Լ� ���̺��� �����ؼ�, �ٿ�ĳ������ ���������� �˾ƺ��ش�.

	const_cast, Ÿ����ü�� �ٲٴ°� �ƴ� ��ü�� ������� �����Ѵ�. �����ͳ� ������ ��ȯ�Ҷ��� ���.
	-> ���縸 �Ѵ�. ���� ��ߵǳ� �ʹ�.

	reinterpret_cast �����Ͱ� �ٸ� ������ �������� ��ȯ�� �� �ֵ��� �Ѵ�. -> ������ �����ͷ�, �����͸� ������ ������ �� ���.
	*/
	//dynamic_cast
	 {
		// �ٿ�ĳ������ �����ϰ� �� �� �ְ� �����ش�.
		/*A* PtrC = new C();
		B* Test = dynamic_cast<B*>(PtrC);*/

		// �̷��� �ɰ��� ������ ���� �� �ִ�. <- B�� C�� �Ȱ�.
		// B* Test1 = (B*)PtrC;
	 }
	//reinterpret_cast
	{
		int Value = 3;
		int* Ptr = &Value; // 3
		__int64 Addrees = reinterpret_cast<__int64>(Ptr); // �ּ�
		__int64 Address3 = (__int64)Ptr; // �ּ�
		int* Ptr2 = reinterpret_cast<int*>(Addrees); // 3���� ��ȯ
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