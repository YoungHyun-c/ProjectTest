#pragma once
#include "UnitManager.h"

class Warrior_87 : public UnitManager
{
public:
	Warrior_87()
		:UnitManager("������", Rand.RandNum(300, 500), Rand.RandNum(40, 70), Rand.RandNum(60, 100))
	{
		Weapon = new std::string("��");
		Job = "����";
		Level = 3;
		DefPower = 0.6f;
	}

protected:
	void Attack() const override;
	void Move() const override;

private:

};

