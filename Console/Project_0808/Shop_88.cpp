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
		std::cout << "당신의 소지금 : " << _Player.GetGold() << std::endl;
		std::cout << "구매할 상품을 정해주세요. (1. 방어구, 2. 무기, 3. 소비) : ";
		std::cin >> Product;
		std::cout << "구매할 번호를 입력해주세요 : ";
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
			std::cout << "몇개 구매할지 입력해주세요 : ";
			std::cin >> Count;
			if (Num <= 0 || Num > _Item.GetUseItemSize())
			{
				std::cout << "다시 입력해주세요..." << std::endl;
			}
			else
			{
				Gold = _Item.BuyUseItem(Num, Count);
				if (_Player.GetGold() > Gold)
				{
					_Player.SubGold(Gold);
					_Item.SubCount(Num, Count);
					std::cout << "상품을 구매했습니다." << std::endl;
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
	std::cout << "~~상점~~" << std::endl;
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
	std::cout << "~~~~~~~~~~~~상점에서 무엇을할지 정해주세요~~~~~~~~" << std::endl;
}

void Shop_88::ShopListSet()
{
	List.push_back("1. 구매한다.");
	List.push_back("2. 판매한다.");
	List.push_back("3. 나간다.");
}

int Shop_88::ActionList()
{
	return ComManager->PrintScreen(1, Y, List);
}