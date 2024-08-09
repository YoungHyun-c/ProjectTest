#pragma once

#include <iostream>
#include <string>
#include <vector>

class ItemManager
{
public:
	void Start();

	void UseItemInfo(int& _X , int& _Y);
	void ArmorItemInfo(int& _X , int& _Y);
	void WeaponItemInfo(int& _X , int& _Y);

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

	const int& GetCount()
	{
		return Count;
	}

	void AddCount(int _Num)
	{
		Count += _Num;
		if (MaxCount <= Count)
		{
			Count = MaxCount;
			return;
		}
	}

	void SubCount(int _Num)
	{
		Count -= _Num;
		if (Count <= 0)
		{
			Count = 0;
			return;
		}
	}

	void SetName(std::string _Name)
	{
		Name = _Name;
	}

protected:
	void CreateUseItem();
	void CreateEuqipItem();

	std::string Name;
	int Hp = 0;
	int Def = 0;

	int Atk = 0;
	int AtkSpeed = 0;

	int Gold = 0;

	int MaxCount = 0;
	int Mp = 0;
	int Count = 1;

private:
	std::vector<class UseItem_88*> UseItem;
	std::vector<class EquipItem_88*> EquipArmorItem;
	std::vector<class EquipItem_88*> EquipWeaponItem;

	class Util* Handle;

};

