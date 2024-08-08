#pragma once

#include <iostream>
#include <string>


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

	void const PlayerInfoPrint();


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
	
};

