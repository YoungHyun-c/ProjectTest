#include <iostream>

#include "Screen_88.h"

#include "Shop_88.h"

int main()
{
	Screen_88 MainScreen;
	MainScreen.ListSet();
	MainScreen.PrintScreen();
	MainScreen.CheckPoint();

	Shop_88 MainShop;
	MainShop.CreateItem();
	MainShop.PrintItem();
	MainShop.BuyItem();
	MainShop.PrintItem();



	return 0;
}