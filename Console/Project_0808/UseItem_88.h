#pragma once

#include "ItemManager.h"

class UseItem_88 : public ItemManager
{
public:
	UseItem_88(int _MaxCount)
		: ItemManager()
	{
		Count = _MaxCount;
	}

	void UseItemInfoPrint();

	const int& GetCount()
	{
		return Count;
	}

	void SetUseItem(const std::string& _Name, int _Hp, int _Mp, int _Gold);

	void Start();
protected:

private:
	std::vector<UseItem_88*> Items;


};

