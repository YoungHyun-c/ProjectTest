#pragma once

#include <iostream>
#include "Random_87.h"

class UnitManager 
{
public:
	UnitManager(const std::string& _Name, int _Hp, int _Atk, int _Def);
	~UnitManager();

	void PrintInfo();

	virtual void Attack() const = 0;
	virtual void Move() const = 0;

	virtual void TakeAttack(int _Damage);
	

	void AddExp(int _Exp);

	const std::string& GetName()
	{
		return Name;
	}

	const int GetHp()
	{
		return Hp;
	}
	const int GetAtk()
	{
		return Atk;
	}
	const int GetDef()
	{
		return Def;
	}
	const int GetExp()
	{
		return Exp;
	}
	const int GetLevel()
	{
		return Level;
	}
	const std::string& Getclass()
	{
		return Job;
	}

	void SetHp(int _Hp)
	{
		Hp = _Hp;
	}

	void SetLevel(int _Level)
	{
		Level = _Level;
	}

	void SetMonster(const std::string& _Name, const std::string& _Job, std::string _Weapon, int _Hp, int _Atk, int _Def, float _DefP, int _Exp)
	{
		Name = _Name;
		Job = _Job;
		*Weapon = _Weapon;
		Hp = _Hp;
		Atk = _Atk;
		Def = _Def;
		DefPower = _DefP;
		Exp = _Exp;
	}

protected:
	std::string Name = "";
	std::string Job = "";
	std::string* Weapon = NULL;

	int Level = 1;
	int Atk = 0;
	int Def = 0;
	int MaxHp = 0;
	int Hp = 0;
	int MaxExp = 100;
	int Exp = 0;
	float DefPower = 0.0f;

	class Random_87 Rand;
private:
	class UnitSelect* Unit;

};

