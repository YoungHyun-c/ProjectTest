#pragma once
#include <iostream>
#include <vector>

class EquipItem_88
{
public:
	EquipItem_88();
	~EquipItem_88();

	void WeaponInfo() const;

	void ArmorInfo() const;

	const std::string& GetName()
	{
		return Name;
	}

	const int& GetHp()
	{
		return Hp;
	}

	const int& GetDef()
	{
		return Def;
	}

	const int& GetAtk()
	{
		return Atk;
	}

	const int& GetAtkSpeed()
	{
		return AtkSpeed;
	}

	const int& GetGold()
	{
		return Gold;
	}

	void SetGold(int _Gold)
	{
		if (Gold <= _Gold || _Gold < 0)
		{
			return;
		}

		Gold = _Gold;
	}


protected:
	void Start();

	void SetArmor(const std::string& _Name, const int& _Hp, const int& _Def, const int& _Gold);

	void SetWeapon(const std::string& _Name, const int& _Atk, const int& _AtkSpeed, const int& _Gold);

private:
	std::string Name;
	int Hp = 0;
	int Def = 0;

	int Atk = 0;
	int AtkSpeed = 0;

	int Gold = 0;

	std::vector<EquipItem_88> EquipArmorItem;
	std::vector<EquipItem_88> EquipWeaponItem;
};

