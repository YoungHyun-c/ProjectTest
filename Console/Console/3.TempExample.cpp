#include <iostream>

template <typename T>
class Shape
{
public:
	virtual void draw() const = 0; // 순수한 그아이
	virtual T area() const = 0; // 순수한 그아이
};

template <typename T>
class Circle : public Shape<T>
{
private:
	T radius;
public:
	Circle(T r) : radius(r) {}

	void draw() const override
	{
		std::cout << "원의 반지름 : " << radius << std::endl;
	}

	T area() const override
	{
		return 3.14 * radius * radius;
	}
};

template <typename T>
class Rectangle : public Shape<T> {
private:
	T width;
	T height;
public:
	Rectangle(T w, T h) : width(w), height(h) {}

	void draw() const override
	{
		std::cout << "가로 : " << width << " 세로 : " << height << std::endl;
	}

	T area() const override
	{
		return width * height;
	}
};

// 함수 템플릿 : Shape 포인터를 인자로 받아서 draw와 area를 출력하고 시펑
template <typename T>
void Show(Shape<T>* shape)
{
	shape->draw();
	std::cout << "면적 : " << shape->area() << std::endl;
}

int main()
{
	Circle <double> circle(3.14);
	Rectangle<int> rectangle(4, 3);

	Show(&circle);
	Show(&rectangle);

	Shape<int>* Test = new Circle<int>(3);

	std::cout << "면적 : " << Test->area() << std::endl;
	Test->draw();

	delete Test;

	return 0;
}


/*
 추상클래스 받아서 캐릭터 클래스 3개 만들기.

 1. GameScene 이라는 클래스를 생성.
  ㄴ 요기 Scene에서 전투로직을 구현하세요.

 int main()
 {
	GameScene
 }

 콘솔 프로젝트(개인)
 -> 언어 숙지를 위한 프로젝트.
 -> 절대 하면 안되는 것. 도박장, 지금까지 했던 것 불러오기.
 -> 테트리스 X

*/