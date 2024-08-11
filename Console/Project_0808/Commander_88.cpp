#include "Commander_88.h"

#include "Util.h"
#include "Screen_88.h"
#include "ItemManager.h"
#include "Shop_88.h"

#include "Player_88.h"

#define InterFrame 1000

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
	Player->PlayerListSet();
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
		case 0:
			std::cout << "상점으로 이동합니다..." << std::endl;
			Sleep(InterFrame);
			system("cls");
			ShopManager(ItemM, Player);
			Done = true;
			break;
		case 1:
			std::cout << "인벤토리로 이동합니다..." << std::endl;
			Sleep(InterFrame);
			system("cls");
			PlayerManager(Player);
			Done = true;
			break;
		case 2:
			std::cout << "종료합니다..." << std::endl;
			Sleep(InterFrame);
			Done = false;
			break;
		}
	}
}

void Commander_88::End()
{
}


void Commander_88::ShopManager(ItemManager* _Item, Player_88* _Player)
{
	while (Done)
	{
		Shop->PrintProduct(_Item);
		int Num = Shop->ActionList();
		switch (Num)
		{
		case 0:
			Shop->BuyItem(*_Item, *_Player);
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
	while (Done)
	{
		_Player->PlayerInfoPrint();
		int Num = Player->PlayerActionList();
		switch (Num)
		{
		case 0:
			std::cout << "장착할 아이템을 입력해주세요 : " << std::endl;
			break;
		case 1:
			std::cout << "해제할 아이템을 입력해주세요 : " << std::endl;
			break;
		case 2:
			std::cout << "사용할 아이템을 입력해주세요 : " << std::endl;
			break;
		case 3:
			std::cout << "플레이어 정보창에서 나갑니다... " << std::endl;
			Sleep(2000);
			system("cls");
			Done = false;
			break;
		}
		Sleep(1000);
		system("cls");
	}
}