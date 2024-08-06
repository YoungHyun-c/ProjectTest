#pragma once

#include <iostream>

class UnitProject_86
{
public:
	UnitProject_86(const std::string& _Name, const int _Health, const int _Atk, const int _Def)
		: Name(_Name), Health(_Health), Atk(_Atk), Def(_Def)
	{
	}
	virtual ~UnitProject_86();

	void PrintInfo() const;

	virtual void TakeAttack(int _Damage);

	void GetWeapon() const
	{
		std::cout << Name << "의 무기는 : " << *Weapon << std::endl;
	}

	virtual void Attack() const = 0;
	virtual void Move() const = 0;
protected:
	std::string Name = "";
	std::string Job = "";
	int Health = 0;
	int Atk = 0;
	int Def = 0;
	std::string* Weapon = NULL;
private:

};

