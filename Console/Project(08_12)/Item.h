#pragma once
#include "Utill.h"
#include "ConsoleGameObject.h"

class PackManScreen;
class Item : public ConsoleGameObject
{
public:
	Item();
	Item(int _Value, int _Speed = 0) :
		Value(_Value), Speed(_Speed)
	{
	}
	~Item();

	void AppleItemPrint(int2 _Pos);
	void BananaItemPrint(int2 _Pos);
	void ItemOff(int2 _Pos);

	void TransItemPrint();

	int GetValue()
	{
		return Value;
	}

	int GetSpeed()
	{
		return Speed;
	}

protected:
	void Update() override;
private:
	int Value;
	int Speed = 0;

	char AppleItemArr[2][3] =
	{ " 5",
	  "55",
	};

	char BanaanaItemArr[2][3] =
	{ "5 ",
	  "55" };

	char TransItemArr[3][4] =
	{ " 5 ",
	  "555",
	  " 5 " };

	Utill* UtillMan;
	bool ItemRender = true;
};

