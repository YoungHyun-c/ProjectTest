#include "Shop_88.h"

#include "Util.h"
#include "ItemManager.h"

#define ShopX 4
#define ShopY 1


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

void Shop_88::BuyItem(ItemManager* _Item)
{
	std::cout << "������ ��ȣ�� �Է����ּ��� : ";
	int Num;
	std::cin >> Num;
	std::cout << std::endl;
	std::cout << "� �������� �Է����ּ��� : ";
	int Count;
	std::cin >> Count;
	
	{
		_Item[Num].SubCount(Count);
	}

	std::cout << "��ǰ�� �����߽��ϴ�..." << std::endl;
}

void Shop_88::SellItem()
{
	
}

static int Y = ShopY;
void Shop_88::PrintProduct(ItemManager* _Item)
{
	int X = ShopX;
	ComManager->Gotoxy(25, 0);
	std::cout << "~~����~~" << std::endl;
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