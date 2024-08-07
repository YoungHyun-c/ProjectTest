#pragma once
#include "UnitManager.h"
#include "Random_87.h"

class Monster_87 : public UnitManager
{
public:
	Monster_87(const std::string& _Name, const std::string& _Job, const std::string& _Weapon, int _Hp, int _Atk, int _Def)
		: UnitManager(_Name, _Hp, _Atk, _Def)
	{
		Job = _Job;
		Weapon = new std::string(_Weapon);
		Random_87 Rand;
		Exp = Rand.RandNum(70, 150);
		DefPower = static_cast<float>(_Def * 0.03f);
	}

protected:
	void Attack() const override;
	void Move() const override;


};

