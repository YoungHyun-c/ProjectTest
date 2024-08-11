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

// Ŀ�� ���ֱ�
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
	List.push_back("1. �������� �̵��Ѵ�.");
	List.push_back("2. ĳ���� �κ��丮�� �̵��Ѵ�.");
	List.push_back("3. �����Ѵ�.");
}

int Screen_88::PrintScreen()
{
	return ComManager->PrintScreen(1, Y, List);
}