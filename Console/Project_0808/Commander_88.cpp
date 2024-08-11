#include "Commander_88.h"

#include "Util.h"
#include "Screen_88.h"
#include "ItemManager.h"
#include "Shop_88.h"

#include "Player_88.h"

Commander_88::~Commander_88()
{
	if (ItemM != nullptr)
	{
		delete ItemM;
		ItemM = nullptr;
	}
	if (MainScreen != nullptr)
	{
		delete MainScreen;
		MainScreen = nullptr;
	}
	if (Shop != nullptr)
	{
		delete Shop;
		Shop = nullptr;
	}
	if (Player != nullptr)
	{
		delete Player;
		Player = nullptr;
	}
}

void Commander_88::Start()
{
	MainScreen = new Screen_88();
	//MainScreen->Start();
	MainScreen->MenuListSet();

	ItemM = new ItemManager();
	ItemM->Start();

	Shop = new Shop_88();
	Shop->ShopListSet();

	Player = new Player_88();
}

void Commander_88::ShoptoItem(ItemManager* _Item)
{

}

void Commander_88::Update()
{
	while (Done)
	{
		int Num = MainScreen->PrintScreen();
		switch (Num)
		{
		case 1:
			system("cls");
			ShopManager(ItemM);
			Done = true;
			break;
		case 2:
			system("cls");
			PlayerManager(Player);
			Done = true;
			break;
		case 3:
			Done = false;
			break;
		}
	}
}

void Commander_88::End()
{
}


void Commander_88::ShopManager(ItemManager* _Item)
{
	while (Done)
	{
		Shop->PrintProduct(ItemM);
		int Num = Shop->ActionList();
		switch (Num)
		{
		case 0:
			std::cout << "구매할 상품을 정해주세요. " << std::endl;
			Shop->BuyItem(*_Item);
			break;
		case 1:
			std::cout << "판매할 상품을 정해주세요. " << std::endl;

			break;
		case 2:
			std::cout << "상점에서 나갑니다... " << std::endl;

			Sleep(1000);
			system("cls");
			Done = false;
			break;
		}
		Sleep(1000);
		system("cls");
	}
}

void Commander_88::PlayerManager(Player_88* _Player)
{
	_Player->PlayerInfoPrint();
	while (Done)
	{

	}

	int Num;
	std::cin >> Num;
}