#pragma once // 실질적으로 중복 정의를 막아주는 것.

#ifndef UNIT_H // 한번 컴파일되고, 포함이 되는 순간, 또 포함시키진 않는다. 고전적인 방법.
#define UNIT_H

#include <iostream>
// 여긴 부모 클래스
class Unit
{
protected:
	std::string name;
	int health;

public:
	Unit();
	Unit(const std::string& n, const int h);
	~Unit();

public:
	void TakeDamage(const int damage);

};


#endif // UNIT_H
