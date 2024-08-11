#include "EquipItem_88.h"

EquipItem_88::EquipItem_88()
{
}


EquipItem_88::~EquipItem_88()
{
}


void EquipItem_88::Start()
{
}

void  EquipItem_88::SetArmor(const std::string& _Name, const int& _Hp, const int& _Def, const int& _Gold)
{
	Name = _Name;
	Hp = _Hp;
	Def = _Def;
	Gold = _Gold;
}

void EquipItem_88::SetWeapon(const std::string& _Name, const int& _Atk, const int& _AtkSpeed, const int& _Gold)
{
	Name = _Name;
	Atk = _Atk;
	AtkSpeed = _AtkSpeed;
	Gold = _Gold;
}

void EquipItem_88::WeaponInfo() const
{
	std::string Speed = "AtkSpeed : +";
	if (AtkSpeed < 0)
	{
		Speed = "AtkSpeed : ";
	}
	std::cout << "장비 : " << Name << " Atk : +" << Atk << Speed << AtkSpeed << " Gold : "<< Gold << std::endl;
}

void EquipItem_88::ArmorInfo() const
{
	std::cout << "장비 : " << Name << " Hp : +" << Hp << " Def : + " << Def << " Gold : " << Gold << std::endl;
}
