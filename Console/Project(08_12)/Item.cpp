#include "Item.h"
#include "PackManScreen.h"

Item::Item()
{
	int X = 5;
	int Y = 5;
	SetPos({ X, Y });
}

Item::~Item()
{
	if (UtillMan != nullptr)
	{
		delete UtillMan;
		UtillMan = nullptr;
	}
}

void Item::Update()
{
	int Num = 0;
	for (size_t X = 0; X < PackManScreen::GetMainScreen().GetScreenSize().X; X++)
	{
		for (size_t Y = 0; Y < PackManScreen::GetMainScreen().GetScreenSize().Y; Y++)
		{
			if (X != Item::GetPos().X || Y != Item::GetPos().X)
			{
				Num = 0;
			}
			else
			{
				Num = 1;
			}
		}
	}

	if (Num == 1)
	{
		Death();
	}
}


void Item::AppleItemPrint(const int2& _Pos)
{
	UtillMan;
	for (short i = 0; i < 2; i++)
	{
		for (short j = 0; j < 2; j++)
		{
			COORD pos = { static_cast<short>(_Pos.X) + j, static_cast<short>(_Pos.Y) + i};
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			switch (AppleItemArr[i][j])
			{
			case '5':
				UtillMan->TextColor(12, 5);
				std::cout << "��";
				break;
			default:
				UtillMan->TextColor(0, 0);
				std::cout << " ";
				break;
			}
		}
		UtillMan->TextColor(0, 0);
		std::cout << std::endl;
	}
}


void Item::BananaItemPrint(const int2& _Pos)
{
	UtillMan;
	for (short i = 0; i < 2; i++)
	{
		for (short j = 0; j < 2; j++)
		{
			COORD pos = { static_cast<short>(_Pos.X) + j, static_cast<short>(_Pos.Y) + i };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			switch (BanaanaItemArr[i][j])
			{
			case '5':
				UtillMan->TextColor(14, 14);
				std::cout << "��";
				break;
			default:
				UtillMan->TextColor(0, 0);
				std::cout << " ";
				break;
			}
		}
		UtillMan->TextColor(0, 0);
		std::cout << std::endl;
	}
}

void Item::ItemOff(const int2& _Pos)
{
	UtillMan;
	if (ItemRender)
	{
		for (short i = 0; i < 2; i++)
		{
			for (short j = 0; j < 2; j++)
			{
				COORD pos = { static_cast<short>(_Pos.X) + j, static_cast<short>(_Pos.Y) + i };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

				UtillMan->TextColor(0, 0);
				std::cout << " ";
			}
			UtillMan->TextColor(0, 0);
			std::cout << std::endl;
		}
		ItemRender = false;
	}
}


void Item::TransItemPrint(const int2& _Pos)
{
	UtillMan;
	for (short i = 0; i < 2; i++)
	{
		for (short j = 0; j < 2; j++)
		{
			COORD pos = { static_cast<short>(_Pos.X) + j, static_cast<short>(_Pos.Y) + i };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			switch (TransItemArr[i][j])
			{
			case '5':
				UtillMan->TextColor(4, 8);
				std::cout << "��";
				break;
			default:
				UtillMan->TextColor(0, 0);
				std::cout << " ";
				break;
			}
		}
		UtillMan->TextColor(0, 0);
		std::cout << std::endl;
	}
}
