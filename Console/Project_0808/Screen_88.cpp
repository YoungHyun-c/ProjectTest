#include "Screen_88.h"

#include "Util.h"

#include "Player_88.h"
#include "Shop_88.h"

#define Up 72
#define Down 80
#define Left 75
#define Right 77
#define Enter 13 

#define InterFrame 1000

// 커서 없애기
void Screen_88::Start()
{
	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(ConsoleHandle, &ConsoleCursor);
}


void Screen_88::MenuListSet()
{
	List.push_back("1. 상점으로 이동한다.");
	List.push_back("2. 캐릭터 인벤토리로 이동한다.");
}

int Screen_88::PrintScreen()
{
	short X = 3;
	short Y = 1;

	Util Cursor;
	Cursor.Gotoxy(X- 2, Y);
	for (auto& Num : List)
	{
		Cursor.Gotoxy(X + 2, Y++);
		std::cout << Num << std::endl;
	}
	Y = 1;
	Cursor.Gotoxy(X - 2, Y);
	printf("=>");
	while (true)
	{
		int N = KeyControl();
		switch (N)
		{
		case Up:
			if (Y > 1)
			{
				Cursor.Gotoxy(X - 2, Y);
				printf("  ");
				Cursor.Gotoxy(X - 2, --Y);
				printf("=>");
			}
			break;
		case Down:
			if (Y < 2)
			{
				Cursor.Gotoxy(X - 2, Y);
				printf("  ");
				Cursor.Gotoxy(X - 2, ++Y);
				printf("=>");
			}
			break;
		case Enter:
			Cursor.Gotoxy(0, 3);
			if (Y == 1)
			{
				std::cout << "상점으로 이동합니다..." << std::endl;
				// Sleep(InterFrame);

			}
			if (Y == 2)
			{
				std::cout << "인벤토리로 이동합니다..." << std::endl;
				// Sleep(InterFrame);

			}
			return 0;
		}
	}
}

int Screen_88::KeyControl()
{
	char Ch;
		
	Ch = _getch();

	switch (Ch)
	{
	case Up :
		return Up;
	case Down:
		return Down;
	case Right:
		return Right;
	case Left:
		return Left;
	case Enter:
		return Enter;
	default:
		return NULL;
		break;
	}
}
