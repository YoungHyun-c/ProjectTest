#pragma once
#include "ItemManager.h"

class EquipItem_88 : public ItemManager
{
public:
	EquipItem_88();
	~EquipItem_88();

	void WeaponInfo() const;

	void ArmorInfo() const;

	void SetArmor(const std::string& _Name, const int& _Hp, const int& _Def, const int& _Gold);

	void SetWeapon(const std::string& _Name, const int& _Atk, const int& _AtkSpeed, const int& _Gold);
protected:
	void Start();

private:

};

