#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Shop_88
{
public:
	Shop_88();
	~Shop_88();

	void CreateItem();

	void PrintItem();

	void BuyItem();

private:
	
	std::vector<class UseItem_88*> Item;
	std::vector<class EquipItem_88*> EquipItem;
};

