#include "ItemManager.h"

#include "UseItem_88.h"
#include "EquipItem_88.h"
#include "Player_88.h"

#include "Util.h"

#define ItemNum 5
#define EquipNum 3

ItemManager::~ItemManager()
{
	if (!UseItem.empty())
	{
		for (auto& Num : UseItem)
		{
			delete Num;
			Num = nullptr;
		}
	}

	if (!EquipArmorItem.empty())
	{
		for (auto& Num : EquipArmorItem)
		{
			delete Num;
			Num = nullptr;
		}
	}

	if (!EquipWeaponItem.empty())
	{
		for (auto& Num : EquipWeaponItem)
		{
			delete Num;
			Num = nullptr;
		}
	}

	if (Handle != nullptr)
	{
		delete Handle;
		Handle = nullptr;
	}
}

void ItemManager::Start()
{
	if (UseItem.empty())
	{
		UseItem.reserve(ItemNum);
		for (int i = 0; i < ItemNum; i++)
		{
			UseItem.push_back(new UseItem_88(99));
		}
	}
	if (EquipArmorItem.empty())
	{
		EquipArmorItem.reserve(EquipNum);
		for (int i = 0; i < EquipNum; i++)
		{
			EquipArmorItem.push_back(new EquipItem_88());
		}
	}
	if (EquipWeaponItem.empty())
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

int ItemManager::BuyArmor(int _Num, Player_88* _Player)
{
	if (_Player->GetGold() > EquipArmorItem[_Num - 1]->GetGold())
	{
		std::cout << EquipArmorItem[_Num - 1]->GetName() << "��(��) �����߽��ϴ�." << std::endl;
		_Player->SetArmor(EquipArmorItem[_Num - 1]->GetName());
		return EquipArmorItem[_Num - 1]->GetGold();
	}

	std::cout << "����� �������� �����մϴ�..." << std::endl;
	return 0;
}

int ItemManager::BuyWeapon(int _Num, int _PlayerGold)
{
	if (_PlayerGold > EquipWeaponItem[_Num - 1]->GetGold())
	{
		std::cout << EquipWeaponItem[_Num - 1]->GetName() << "��(��) �����߽��ϴ�." << std::endl;
		return EquipWeaponItem[_Num - 1]->GetGold();
	}

	std::cout << "����� �������� �����մϴ�..." << std::endl;
	return 0;
}

void ItemManager::CreateUseItem()
{
	UseItem[0]->SetUseItem("���", 100, 0, 30);
	UseItem[1]->SetUseItem("����", 150, 0, 40);
	UseItem[2]->SetUseItem("������", 0, 30, 50);
	UseItem[3]->SetUseItem("������", -10, 0, 100);
	UseItem[4]->SetUseItem("������ź", -70, 0, 999);
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
		EquipWeaponItem[i]->WeaponInfo();
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
	EquipWeaponItem[2]->SetWeapon("��������", 130, 3, 1200);
}

int ItemManager::BuyUseItem(int _Num, int _Count)
{
	int Gold = UseItem[_Num - 1]->GetGold() * _Count;
	return Gold;
}

void ItemManager::SubCount(int _Num, int& _Count)
{
	Count = UseItem[_Num - 1]->GetUseCount();
	Count -= _Count;
	if (Count <= 0)
	{
		Count = 0;
		UseItem[_Num - 1]->SetCount(_Num - 1, Count);
		std::cout << "��ǰ�� �� �����߽��ϴ�." << std::endl;
		return;
	}
	UseItem[_Num - 1]->SetCount(_Num - 1, Count);
}

void ItemManager::SetCount(int _Num, int& _Count)
{
	Count = _Count;
}

int ItemManager::GetUseCount()
{
	return Count;
}