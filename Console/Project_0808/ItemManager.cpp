#include "ItemManager.h"

#include "UseItem_88.h"
#include "EquipItem_88.h"

#include "Util.h"

#define ItemNum 5
#define EquipNum 3

void ItemManager::Start()
{
	if (UseItem.size() == 0)
	{
		UseItem.reserve(ItemNum);
		for (int i = 0; i < ItemNum; i++)
		{
			UseItem.push_back(new UseItem_88(99));
		}
	}
	if (EquipArmorItem.size() == 0)
	{
		EquipArmorItem.reserve(EquipNum);
		for (int i = 0; i < EquipNum; i++)
		{
			EquipArmorItem.push_back(new EquipItem_88());
		}
	}
	if (EquipWeaponItem.size() == 0)
	{
		EquipWeaponItem.reserve(EquipNum);
		for (int i = 0; i < EquipNum; i++)
		{
			EquipWeaponItem.push_back(new EquipItem_88());
		}
	}

	CreateUseItem();
	CreateEuqipItem();

	if (Handle == nullptr)
	{
		Handle = new Util();
	}
}

void ItemManager::CreateUseItem()
{
	UseItem[0]->SetUseItem("���", 100, 0, 300);
	UseItem[1]->SetUseItem("����", 150, 0, 300);
	UseItem[2]->SetUseItem("������", 0, 30, 300);
	UseItem[3]->SetUseItem("������", -10, 0, 300);
	UseItem[4]->SetUseItem("������ź", -70, 0, 300);
}

void ItemManager::UseItemInfo(int& _X, int& _Y)
{
	for (int i = 0; i < ItemNum; i++)
	{
		Handle->Gotoxy(_X, _Y++);
		UseItem[i]->UseItemInfoPrint();
	}
}

void ItemManager::ArmorItemInfo(int& _X, int& _Y)
{
	for (int i = 0; i < EquipNum; i++)
	{
		Handle->Gotoxy(_X, _Y++);
		EquipArmorItem[i]->ArmorInfo();
	}
}

void ItemManager::WeaponItemInfo(int& _X, int& _Y)
{
	for (int i = 0; i < EquipNum; i++)
	{
		Handle->Gotoxy(_X, _Y++);
		EquipWeaponItem[i]->ArmorInfo();
	}
}

void ItemManager::CreateEuqipItem()
{
	// ��
	EquipArmorItem[0]->SetArmor("����", 10, 11, 500);
	EquipArmorItem[1]->SetArmor("����", 100, 25, 2000);
	EquipArmorItem[2]->SetArmor("�Ź�", 25, 7, 700);

	//// ����
	EquipWeaponItem[0]->SetWeapon("���", 150, -1, 1000);
	EquipWeaponItem[1]->SetWeapon("���", 90, 2, 800);
	EquipWeaponItem[2]->SetWeapon("��������", 130, 31, 1200);
}