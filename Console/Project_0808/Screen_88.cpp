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
	List.push_back("3. 종료한다.");
}

int Screen_88::PrintScreen()
{
	return ComManager->PrintScreen(1, Y, List);
}