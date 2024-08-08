#include <iostream>

#include "Screen_88.h"

#include "Shop_88.h"

int main()
{
	Screen_88 MainScreen;
	// 커서 없애기
	//MainScreen.Start();

	MainScreen.MenuListSet();
	MainScreen.PrintScreen();
	MainScreen.KeyControl();

	//Shop_88 MainShop;
	//MainShop.CreateItem();
	//MainShop.PrintItem();
	//MainShop.BuyItem();
	//MainShop.PrintItem();



	return 0;
}