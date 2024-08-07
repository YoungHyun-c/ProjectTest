#pragma once

#include "UnitManager.h"

class Archer_87 : public UnitManager
{
public:
	Archer_87()
	: UnitManager("±ÃºØÀÌ", 250, 60, 30)
	{
		Weapon = new std::string("È°");
		Job = "±Ã¼ö";
		Level = 1;
		DefPower = 0.6f;
	}

protected:
	void Attack() const override;
	void Move() const override;

};

