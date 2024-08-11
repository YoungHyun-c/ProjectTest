#pragma once

#include <iostream>
#include <string>
#include <vector>

#define ShopX 4
#define ShopY 1

class Shop_88
{
public:
	Shop_88();
	~Shop_88();

	void ShopListSet();

	int ActionList();

	void BuyItem(class ItemManager& _Item);

	void SellItem();

	void PrintProduct(class ItemManager* _Item);

private:
	std::vector<std::string> List;


	class Util* ComManager;


	int X = ShopX;
	int Y = ShopY;
};

