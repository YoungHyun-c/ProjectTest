#pragma once
#include "UnitProject_86.h"

class Warrior_86 : public UnitProject_86
{
public:
	Warrior_86(const std::string& _Name, const int _Health, const int _Atk, const int _Def);
	~Warrior_86();

protected:
	void Attack() const override;
	//void TakeAttack(int _Damage) override;
	void Move() const override;
	

private:

};

