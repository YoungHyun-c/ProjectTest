#pragma once
#include "UnitManager.h"

class Warrior_87 : public UnitManager
{
public:
	Warrior_87()
		:UnitManager("������", 300, 40, 60)
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

