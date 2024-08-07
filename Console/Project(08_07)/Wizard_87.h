#pragma once

#include "UnitManager.h"

class Wizard_87 : public UnitManager
{
public:
	Wizard_87()
	:UnitManager("������", 200, 80, 70)
	{
		Weapon = new std::string("������");
		Job = "������";
		Level = 2;
		DefPower = 0.6f;
	}

protected:
	void Attack() const override;
	void Move() const override;
};

