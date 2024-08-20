#include "Item.h"
#include "PackManScreen.h"
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


void Item::AppleItemPrint(int2 _Pos)
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
				UtillMan->TextColor(12, 12);
				std::cout << "бс";
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

void Item::BananaItemPrint()
{
	UtillMan;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			switch (BanaanaItemArr[i][j])
			{
			case '5':
				UtillMan->TextColor(14, 14);
				std::cout << "бс";
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

void Item::TransItemPrint()
{

}
