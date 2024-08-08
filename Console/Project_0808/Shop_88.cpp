#include "Shop_88.h"

#include "UseItem_88.h"
#include "EquipItem_88.h"

Shop_88::Shop_88()
{
}

Shop_88::~Shop_88()
{
	std::vector<UseItem_88*>::iterator It = Item.begin();
	if (*It != nullptr)
	{
		for (;It != Item.end(); It++)
		{
			delete *It;
			*It = nullptr;
		}
	}
}

void Shop_88::CreateItem()
{
	if (Item.size() == 0)
	{
		Item.reserve(5);
		Item.push_back(new UseItem_88("���", 100, 0, 99));
		Item.push_back(new UseItem_88("����", 150, 0, 99));
		Item.push_back(new UseItem_88("������", 0, 30, 99));
		Item.push_back(new UseItem_88("������", -10, 0, 99));
		Item.push_back(new UseItem_88("����", -70, 0, 99));
	}

	if (EquipItem.size() == 0)
	{
	
	}

}

void Shop_88::PrintItem()
{
	if (Item.capacity() != 0)
	{
		for (int i = 0; i < Item.size(); i++)
		{
			Item[i]->UseItemInfoPrint();
		}
	}
}

void Shop_88::BuyItem()
{
	std::cout << "������ ��ȣ�� �Է����ּ��� : " << std::endl;
	int Num;
	std::cin >> Num;
	if (Num == 2)
	{
		Item[2]->SubCount(5);
	}
}