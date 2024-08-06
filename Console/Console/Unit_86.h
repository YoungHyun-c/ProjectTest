#pragma once

// virtual void Move()const = 0;
// 순수가상함수 : 선언만하고 구현하지 않음.
// 순수가상함수를 포함하고 있는 클래스는. 추상클래스라고 불린다.
// 다형성과도 연관이 있다.
// 특정함수를 강제로 구현하게 만든다.

// 순수가상함수를 한개 이상을 포함한다면 추상클래스라고 함.
// 추상클래스 : 인스턴스화 시킬 수 없음. -> 실체화 시킬 수 없다.
// 다른 클래스들이 상속받아야 하는 기본 인터페이스나 정의하는데 사용.
// 다형성, 코드 재사용성...
// 특정 함수들이 자식클래스에 의해 구현되도록 강제함.
#include <iostream>
// 추상클래스
class Unit_86 abstract // 명시를 해주는게 있다.
{
protected:
	std::string name;
	int health;

public:
	Unit_86(const std::string& _name, const int h);
	virtual ~Unit_86();

public:
	// 순수 가상함수.
	virtual void Attack() const = 0;
	virtual void TakeDamage(int damage) = 0;
};

