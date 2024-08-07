#pragma once

#include "UnitManager.h"

class Wizard_87 : public UnitManager
{
public:
	Wizard_87()
	:UnitManager("������", Rand.RandNum(50,80), Rand.RandNum(80, 150), Rand.RandNum(40, 70))
	{
		Weapon = new std::string("������");
		Job = "������";
		Level = 2;
		DefPower = 0.2f;
	}

protected:
	void Attack() const override;
	void Move() const override;

};

