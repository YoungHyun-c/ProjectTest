#include <iostream>

// 함수 호출을 결정.

// 정적이냐, 동적이냐.

// 1. 정적바인딩이란?
// 컴파일 타임에 함수 호출이 어떤 함수로 연결될지 결정하는 녀석이다.
// 컴파일 타임에 결정되기 때문에 실행 속도가 빠르다.
// 런타임 성능에 영향을 미치지 않는다.
// 단. 프로그램 실행중에 어떠한 변경도 불가능하다.

// 2. 동적바인딩.
// 런타임에 함수 호출이 어떤 함수로 연결될지 결정하는 바인딩이다.
// 호출할 때 오버라이딩 된 가상함수를 찾아서 동적으로 호출하게 된다.
// 실행중에 결정이 됨.
// 정적바인딩 보다, 오버헤드가 발생하여 성능이 좀 떨어진다.
// 동적바인딩 자체는 포인터에 의해 접근되어있는지 상관없이, 참조된 인스턴스에
// 실제 클레스에 따라서 재정의된 함수 호출 가능. (다형성)을 지원한다.

// 순수 가상함수는
// virtual void Move()const = 0;
// 클래스 내에서 선언만 하고, 구현은 하지 않는다.


class CPrint
{
public:
	void Print(int a)
	{
		std::cout << "int형 출력" << a << std::endl;
	}

	void Print(double a)
	{
		std::cout << "double형 출력" << a << std::endl;
	}
};

class Parent
{
public:
	virtual void Show()
	{
		std::cout << "부모 클래스 show 함수" << std::endl;
	}
	virtual ~Parent() = default; // 가상 소멸자를 기본 구현을 컴파일러한테 자동으로 생성되게 해야됨.
};

class Child : public Parent
{
public:
	void Show() override
	{
		std::cout << "자식클래스 Show" << std::endl;
	}
};

#include "Player_86.h"
int main()
{
	CPrint C;
	C.Print(10); // 정적 바인딩. 자료형에 의해서 결정되고 있다.
	C.Print(20.5);

	Parent* pPtr = new Child(); // 동적 바인딩. 런타임에서 함수호출에 따라 결정. 실제 객체의 자료형에 따라..
	pPtr->Show();
	// 가상함수테이블 -> 가상함수에 대한 포인터를 저장하는 테이블.
	// 각 클래스는 가상함수 테이블을 가지고 있다. 가상함수 테이블이 있으면, 가상 함수가 메모리에 어느 위치에 있는지 가리키게 된다.
	// 해당 객체는 그 클래스의 가상함수의 포인터를 가지는 애가 되고, 런타임에 적절한 함수 호출.
	
	// 동적바인딩 과정.
	// 클래스에서 가상함수를 선언하면, 해당 클래스의 가상함수 테이블 생성.
	// 그 가상함수 테이블은, 클래스의 가상함수의 주소를 저장하게 되고, 객체가 생성이 되는 순간.
	// 객체의 가상함수 포인터가, 해당 클래스의 가상함수 테이블을 가리키게 되고, 함수호출을 하게 되면,
	// 객체의 가상함수 테이블의 포인터를 통해서, 호출할 함수를 찾고 호출한다.
	delete pPtr;


	// 순수 가상함수.
	Player_86* pP = new Player_86("홍", 200);
	pP->Attack();
	pP->TakeDamage(10);
	// Unit_86* uP = new Unit_86("asdsad", 200); // Error -> 추상클래스는 인스턴스화 시킬 수 없음. 순수 가상함수를 사용한 클래스 = 추상클래스.

	return 0;
}

/*
과제.
1. OOP 특성 조사 -> 파일로 제출할 것. (이왕이면 pdf로)
2. 클래스 전방선언-> 컴파일러한테 미리 알려주는 것. -> 과제 (위와 동일함)
3. 추상클래스를 활용한. 3가지 캐릭터 클래스를 구현하세요.
-> 기본스탯, 움직이는 함수, 공격하는 함수, 데미지 먹는 함수.. 기타 등등


만약에 두개의 클래스가 있음.
Player
Weapon

// 파일은 서로 각각.
#include "Weapon" -> 헤더 파일 말고 -> class weapon; <- 전방선언.
class Player
{
private:
	weapon* weapon;
}

#include "Player"
class weapon
{
private:
	Player* player;
}
이렇게 만들시, 서로 참조를 하고 있어서 상호참조로 무조건 터짐. 순환참조 오류 이러한 상황은 오류 찾기도 힘듬.

-> 얘를 해결하기 위해서 클래스 전방선언.

*/