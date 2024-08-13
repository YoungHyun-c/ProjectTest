#pragma once

#include "Utill.h"

class Item
{
public:
	Item(int _Value) :
		Value(_Value)
	{
	}
	~Item();

	void AppleItemPrint();
	void BananaItemPrint();
	void TransItemPrint();

private:
	int Value;

	char AppleItemArr[3][4] =
	{ " 5 ",
	  "555",
	  "5 5"};

	char BanaanaItemArr[3][4] =
	{ "  5",
	  " 55",
	  "55 " };

	char TransItemArr[3][4] =
	{ " 5 ",
	  "555",
	  " 5 " };

	Utill* UtillMan;
};

