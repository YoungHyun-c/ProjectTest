#pragma once
#include "Utill.h"
#include "ConsoleGameObject.h"

class PackManScreen;
class Item : public ConsoleGameObject
{
public:
	Item();
	Item(int _Value) :
		Value(_Value)
	{
	}
	~Item();

	void AppleItemPrint();
	void BananaItemPrint();
	void TransItemPrint();

protected:
	void Update() override;
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

