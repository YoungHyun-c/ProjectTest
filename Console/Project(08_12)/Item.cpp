#include "Item.h"

Item::~Item()
{
	if (UtillMan != nullptr)
	{
		delete UtillMan;
		UtillMan = nullptr;
	}
}


void Item::AppleItemPrint()
{
	UtillMan;
	while (true)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 4; j++)
			{
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
		Sleep(300);
		system("cls");
	}
}

void Item::BananaItemPrint()
{
	UtillMan;
	while (true)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 4; j++)
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
		Sleep(300);
		system("cls");
	}
}

void Item::TransItemPrint()
{

}
