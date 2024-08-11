#include "Shop_88.h"

#include "Util.h"
#include "ItemManager.h"

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

void Shop_88::BuyItem(ItemManager& _Item)
{
	int Num;
	int Count;

	while (true)
	{
		std::cout << "������ ��ȣ�� �Է����ּ��� : ";
		std::cin >> Num;
		std::cout << "� �������� �Է����ּ��� : ";
		std::cin >> Count;
		if (Num <= 0 || Num > _Item.GetUseItemSize())
		{
			std::cout << "�ٽ� �Է����ּ���..." << std::endl;
		}
		else
		{
			break;
		}
	}
	
	_Item.SubCount(Num - 1, Count);
	

	if (_Item.GetUseCount() == 0)
	{
		std::cout << "��ǰ�� �� �����߽��ϴ�." << std::endl;
		return;
	}
	std::cout << "��ǰ�� �����߽��ϴ�..." << std::endl;
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