#pragma once

#include <iostream>
#include <string>
#include <vector>

#define ListX 4
#define ListY 10

class Player_88
{
public:
	Player_88();
	~Player_88();

	const int& GetMaxHp()
	{
		return MaxHp;
	}
	const int& GetMaxMp()
	{
		return MaxMp;
	}
	const int& GetHp()
	{
		return Hp;
	}
	const int& GetMp()
	{
		return Mp;
	}	
	const int& GetAtk()
	{
		return Atk;
	}
	const int& GetDef()
	{
		return Def;
	}
	const int& GetAtkSpeed()
	{
		return AtkSpeed;
	}

	const std::string& GetWeapon()
	{
		return Weapon;
	}
	const std::string& GetHat()
	{
		return Hat;
	}
	const std::string& GetArmor()
	{
		return Armor;
	}
	const std::string& GetBoots()
	{
		return Boots;
	}

	const int& GetGold()
	{
		return Gold;
	}

	void AddHp(int _Hp)
	{
		Hp += _Hp;
		if (MaxHp <= Hp)
		{
			Hp = MaxHp;
			return;
		}
	}
	void AddMp(int _Mp)
	{
		Mp += _Mp;
		if (MaxMp <= Mp)
		{
			Mp = MaxMp;
			return;
		}
	}

	void AddAtk(int _Atk)
	{
		Atk += _Atk;
	}
	void AddDef(int _Def)
	{
		Def += _Def;
	}
	void AddAtkSpeed(int _Speed)
	{
		AtkSpeed += _Speed;
	}

	void SubGold(int _Gold)
	{
		if (_Gold > Gold)
		{
			std::cout << "�������� �� ����" << std::endl;
			return;
		}
		Gold -= _Gold;
	}

	void const PlayerInfoPrint();

	void SetArmor(std::string _Name)
	{
		if (_Name == "����")
		{
			Hat = _Name;
		}
		if (_Name == "����")
		{
			Armor = _Name;
		}
		if (_Name == "�Ź�")
		{
			Boots = _Name;
		}
	}

	void PlayerListSet();
	int PlayerActionList();

private:
	int MaxHp = 300;
	int Hp = 200;
	int MaxMp = 200;
	int Mp = 150;
	int Atk = 70;
	int Def = 50;
	int AtkSpeed = 6;
	int Gold = 9999;


	std::string Weapon = " ";
	std::string Hat = " ";
	std::string Armor = " ";
	std::string Boots = " ";
	
	std::vector<std::string> List;
	int X = ListX;
	int Y = ListY;

	class Util* UManager;
};

