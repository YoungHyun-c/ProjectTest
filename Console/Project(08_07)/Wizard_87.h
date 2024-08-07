#pragma once

#include "UnitManager.h"

class Wizard_87 : public UnitManager
{
public:
	Wizard_87()
	:UnitManager("마붕이", 200, 80, 70)
	{
		Weapon = new std::string("지팡이");
		Job = "마법사";
		Level = 2;
		DefPower = 0.6f;
	}

protected:
	void Attack() const override;
	void Move() const override;
};

