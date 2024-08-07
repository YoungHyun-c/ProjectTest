#pragma once

#include <iostream>

class UnitManager 
{
public:
	UnitManager(const std::string& _Name, int _Hp, int _Atk, int _Def);
	~UnitManager();

	void PrintInfo();

	virtual void Attack() const = 0;
	virtual void Move() const = 0;

	virtual void TakeAttack(int _Damage);
	

	void AddExp(int _Exp)
	{
		if (MaxExp <= Exp)
		{
			Level += 1;
			Exp = 0;
			Atk += 10;
			Def += 5;
			MaxHp += 15;
			Hp = MaxHp;
			return;
		}

		Exp += _Exp;
	}

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

private:
	class UnitSelect* Unit;

};

