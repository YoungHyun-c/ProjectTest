#include <iostream>
#include <string>

#pragma region 클래스란
/*
========================================
class
- 객체지향 프로그래밍?
 ㄴ 우리가 살고 있는 실제 세계가 객체들로 구성되어, 있는 것 처럼
 소프트웨어도 객체로 구성하는 방법.
 ㄴ 사람, TV, 세탁기, 냉장고 등등... 많은 객체가 존재
 ㄴ 고유한 기능을 수행하고, 다른 객체들과 상호작용을 한다.

 -> 객체?
 ㄴ 클래스-> 틀이나 설계도 -> 객체를 정의하는 틀이나 설계도
 ㄴ 틀만 만들었으면 되나? -> 써먹어야 된다.
 ㄴ 객체는 설계도를 기반으로 실체화 시키는 것. -> 그래야 쓸수있으니까
========================================
*/
#pragma endregion
// 구조체
struct Circle
{
public:
	int Radius;
	std::string Color;
	double calArea()
	{
		return 3.14 * Radius * Radius;
	}
};
// 클래스
// 구조체와 클래스가 다른점?
class Circle1
{
private:
	int radius;
	std::string Color;
	double claArea()
	{
		return 3.14 * radius * radius;
	}
};

class MyClass
{
public:

private:

private:

};

class Student
{
private:

public:

	void Print() { std::cout << "스튜던트 클래스의 프린트 함수"; }
	void Print(int a, int b) {}
	void Print(std::string Str = "디폴트 매개변수") { std::cout << Str << std::endl; }

	int Sum(int a, int b);
};

class Square
{
public:
	void SetXY(int _X, int _Y)
	{
		X = _X;
		Y = _Y;
		std::cout << "사각형의 X : " << X << std::endl;
		std::cout << "사각형의 Y : " << Y << std::endl;
	}

	void AreaCalcul()
	{
		Area = X * Y;
	}

	void AreaPrint() const
	{
		std::cout << "사각형의 넓이 : " << Area << std::endl;
	}

private:
	int X = 0;
	int Y = 0;
	int Area = 0;
};

int main()
{
	// 구조체
	Circle C;
	C.Radius = 5;

	// 클래스
	Circle1 CC;
	// 접근이 안된다. default 접근제한 지시자가 다르기 때문이다.
	//CC.radius = 5;
	
	// 구조체와 클래스의 차이는 디폴트 접근제어지시자가 다르다.
	// private, public, protected.
	// 구조체는 암묵적으로 public:
	// 클래스는 암묵적으로 Private:
	// private: 클래스 내부에서만 참조가능. -> 정보은닉
	// ㄴ숨겨야할 멤버변수 
	// public : 함수(멤버), 생성자, 소멸자, 

	/*
	접근제어		클래스내부		클래스외부		상속클래스
	private			O				X				X
	public			O				O				O
	protectd		O				X				O
	*/

	Square N;
	int X, Y = 0;
	std::cout << "X 값을 입력해주세요 : ";
	std::cin >> X;
	std::cout << "Y 값을 입력해주세요 : ";
	std::cin >> Y;
	N.SetXY(X, Y);
	N.AreaCalcul();
	N.AreaPrint();



	return 0;
}

int Student::Sum(int a, int b)
{
	return 0;
}

/*
사각형의 클래스를 만들어보세용
-멤버 함수로는 사각형의 넓이를 계산.
ㄴ 출력까지 해보세용


*/