#include "Screen_88.h"

#include "Player_88.h"
#include "Shop_88.h"

void Screen_88::ListSet()
{
	List.push_back("1. �������� �̵��Ѵ�.");
	List.push_back("2. ĳ���� �κ��丮�� �̵��Ѵ�.");
}

void Screen_88::PrintScreen()
{
	for (auto& Num : List)
	{
		std::cout << Num << std::endl;
	}
}

void Screen_88::CheckPoint()
{
	/*while (true)
	{
		char Ch;
		
		Ch = _getch();

		switch (Ch)
		{
		case 'w':
		case 'W':
			if (List[1].find('��'))
			{
				List[1].pop_back();
			}
			List[0].push_back('��');
			system("cls");
			PrintScreen();
			break;
		case 's':
		case 'S':
			if (List[0].find('��'))
			{
				List[0].pop_back();
			}

			system("cls");
			PrintScreen();
			break;	
		default:
			break;
		}
	}*/
}
