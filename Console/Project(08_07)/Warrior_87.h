#pragma once
#include "UnitManager.h"

class Warrior_87 : public UnitManager
{
public:
	Warrior_87()
		:UnitManager("전붕이", 300, 40, 60)
	{
		Weapon = new std::string("검");
		Job = "전사";
		Level = 3;
		DefPower = 0.6f;
	}

protected:
	void Attack() const override;
	void Move() const override;

private:

};

