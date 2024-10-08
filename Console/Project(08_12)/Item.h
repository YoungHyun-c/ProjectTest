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

	void AppleItemPrint(const int2& _Pos);
	void BananaItemPrint(const int2& _Pos);
	void TransItemPrint(const int2& _Pos);
	void ItemOff(const int2& _Pos);


	int GetValue()
	{
		return Value;
	}

	int GetSpeed()
	{
		return Speed;
	}

	const std::string& GetName()
	{
		return ItemName;
	}

	void SetItemName(std::string& _Name)
	{
		ItemName = _Name;
	}

	void SetItemRender(bool _Render)
	{
		ItemRender = _Render;
	}

protected:
	void Update() override;
private:
	int Value;
	int Speed = 0;
	std::string ItemName = "";

	char AppleItemArr[2][3] =
	{ " 5",
	  "55",
	};

	char BanaanaItemArr[2][3] =
	{ "5 ",
	  "55" };

	char TransItemArr[2][3] =
	{ "55",
	  "55"};

	Utill* UtillMan;
	bool ItemRender = true;
};

