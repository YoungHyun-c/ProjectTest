#pragma once

#include "UnitManager.h"

class Archer_87 : public UnitManager
{
public:
	Archer_87()
	: UnitManager("±ÃºØÀÌ", Rand.RandNum(100, 300), Rand.RandNum(100, 150), Rand.RandNum(20, 60))
	{
		Weapon = new std::string("È°");
		Job = "±Ã¼ö";
		Level = 1;
		DefPower = 0.3f;
	}

protected:
	void Attack() const override;
	void Move() const override;

};

