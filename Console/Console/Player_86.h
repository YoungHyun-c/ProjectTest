#pragma once
#include "Unit_86.h"

class Player_86 : public Unit_86
{
public:
	Player_86(const std::string& _name, const int h);
	~Player_86();

	void Attack() const override;
	void TakeDamage(int damage) override;
	// 반드시 순수가상함수는 자식클래스에서 재정의 해야한다. 강제.
};

