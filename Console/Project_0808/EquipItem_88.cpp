#include "EquipItem_88.h"

EquipItem_88::EquipItem_88()
{
}


EquipItem_88::~EquipItem_88()
{
}


void EquipItem_88::Start()
{
	const int Num = 3;

	EquipArmorItem.reserve(Num);
	EquipWeaponItem.reserve(Num);

	for (int i = 0; i < Num; i++)
	{
		EquipArmorItem.push_back(EquipItem_88());
		EquipWeaponItem.push_back(EquipItem_88());
	}

	// 방어구
	EquipArmorItem[0].SetArmor("모자", 10, 11, 500);
	EquipArmorItem[1].SetArmor("갑옷", 100, 25, 2000);
	EquipArmorItem[2].SetArmor("신발", 25, 7, 700);

	// 무기
	EquipWeaponItem[0].SetWeapon("대검", 150, -1, 1000);
	EquipWeaponItem[0].SetWeapon("목검", 90, 2, 800);
	EquipWeaponItem[0].SetWeapon("도로쿠대거", 130, 31, 1200);
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