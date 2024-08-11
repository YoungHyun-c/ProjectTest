#include "Shop_88.h"

#include "Util.h"
#include "ItemManager.h"
#include "Player_88.h"

Shop_88::Shop_88()
{
}

Shop_88::~Shop_88()
{
	if (ComManager != nullptr)
	{
		delete ComManager;
		ComManager = nullptr;
	}
}

void Shop_88::BuyItem(ItemManager& _Item, Player_88& _Player)
{
	int Product;
	int Num;
	int Count;
	bool Done = true;
	while (Done)
	{
		std::cout << "����� ������ : " << _Player.GetGold() << std::endl;
		std::cout << "������ ��ǰ�� �����ּ���. (1. ��, 2. ����, 3. �Һ�) : ";
		std::cin >> Product;
		std::cout << "������ ��ȣ�� �Է����ּ��� : ";
		std::cin >> Num;
		int Gold;
		switch (Product)
		{
		case 1:
			Gold = _Item.BuyArmor(Num, &_Player);
			if (0 != Gold)
			{
				_Player.SubGold(Gold);
			}
			Done = false;
			break;
		case 2:
			Gold = _Item.BuyWeapon(Num, _Player.GetGold());
			if (0 != Gold)
			{
				_Player.SubGold(Gold);
			}
			Done = false;
			break;
		case 3:
			std::cout << "� �������� �Է����ּ��� : ";
			std::cin >> Count;
			if (Num <= 0 || Num > _Item.GetUseItemSize())
			{
				std::cout << "�ٽ� �Է����ּ���..." << std::endl;
			}
			else
			{
				Gold = _Item.BuyUseItem(Num, Count);
				if (_Player.GetGold() > Gold)
				{
					_Player.SubGold(Gold);
					_Item.SubCount(Num, Count);
					std::cout << "��ǰ�� �����߽��ϴ�." << std::endl;
				}
				else
				{
					_Player.SubGold(Gold);
				}
				Done = false;
				break;
			}
		}
	}
}

void Shop_88::SellItem()
{
	
}

void Shop_88::PrintProduct(ItemManager* _Item)
{
	ComManager->Gotoxy(25, 0);
	std::cout << "~~����~~" << std::endl;
	Y = 1;
	ComManager->Gotoxy(X, Y++);
	std::cout << "========================================================" << std::endl;
	_Item->ArmorItemInfo(X, Y);
	ComManager->Gotoxy(X, Y++);
	std::cout << "========================================================" << std::endl;
	_Item->WeaponItemInfo(X, Y);
	ComManager->Gotoxy(X, Y++);
	std::cout << "========================================================" << std::endl;
	_Item->UseItemInfo(X, Y);
	ComManager->Gotoxy(X, Y++);
	std::cout << "========================================================" << std::endl;
	ComManager->Gotoxy(X, Y++);
	std::cout << "~~~~~~~~~~~~�������� ���������� �����ּ���~~~~~~~~" << std::endl;
}

void Shop_88::ShopListSet()
{
	List.push_back("1. �����Ѵ�.");
	List.push_back("2. �Ǹ��Ѵ�.");
	List.push_back("3. ������.");
}

int Shop_88::ActionList()
{
	return ComManager->PrintScreen(1, Y, List);
}