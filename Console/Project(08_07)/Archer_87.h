#pragma once

#include "UnitManager.h"

class Archer_87 : public UnitManager
{
public:
	Archer_87()
	: UnitManager("�ú���", 250, 60, 30)
	{
		Weapon = new std::string("Ȱ");
		Job = "�ü�";
		Level = 1;
		DefPower = 0.6f;
	}

protected:
	void Attack() const override;
	void Move() const override;

};

