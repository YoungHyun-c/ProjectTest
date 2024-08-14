#include "PackManScreen.h"
#include <iostream>

#define InterFrame 1000

PackManScreen PackManScreen::MainScreen;

// 커서 없애기
void PackManScreen::VoidCursor()
{
	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(ConsoleHandle, &ConsoleCursor);
}

void PackManScreen::ScreenClear()
{
	system("cls");

	for (size_t Y = 0; Y < this->Size.Y; Y++)
	{
		for (size_t X = 0; X < this->Size.X; X++)
		{
			//MapArr[Y][X] = '0';
		}
	}
}

void PackManScreen::ScreenPrint()
{
	/*setlocale(LC_ALL, "KOR");
	for (size_t Y = 0; Y < this->Size.Y; Y++)
	{
		for (size_t X = 0; X < this->Size.X; X++)
		{
			wprintf_s(L"%c", ArrScreen[Y][X]);
		}
		wprintf_s(L"\n");
	}*/

	for (int Y = 0; Y < YScreen; Y++)
	{
		for (int X = 0; X < XScreen; X++)
		{
			if (MapArr[Y][X] == '1')
			{
				Handle.TextColor(15, 15);
				std::cout << "■";
			}
			else if (MapArr[Y][X] == '0')
			{
				Handle.TextColor(0, 0);
				std::cout << " ";
			}
			else if (MapArr[Y][X] == 'A')
			{
				Handle.TextColor(2, 2);
				std::cout << "A";
			}
		}
		Handle.TextColor(0, 0);
		std::cout << std::endl;
	}
}

void PackManScreen::SetScreenSize(int2 _Size)
{
	Size = _Size;

	ArrScreen.resize(Size.Y);

	for (size_t i = 0; i < Size.Y; i++)
	{
		ArrScreen[i].resize(Size.X);
	}
}

bool PackManScreen::IsScreenOver(const int2& _Pos) const
{
	if (_Pos.X < 0)
	{
		return true;
	}

	if (_Pos.Y < 0)
	{
		return true;
	}

	if (_Pos.X >= this->Size.X)
	{
		return true;
	}

	if (_Pos.Y >= this->Size.Y)
	{
		return true;
	}

	return false;
}

void PackManScreen::SetScreenCharacter(const int2& _Pos, char _Ch)
{
	if (true == IsScreenOver(_Pos))
	{
		return;
	}
	

	MapArr[_Pos.Y][_Pos.X] = _Ch;
}

char PackManScreen::GetScreenCharacter(const int2& _Pos) const
{
	return MapArr[_Pos.Y][_Pos.X];
}


PackManScreen::PackManScreen()
{
}

PackManScreen::~PackManScreen()
{
}

void PackManScreen::Start()
{
	PackManSetList();
	GameSetList();

	//VoidCursor();
}

void PackManScreen::GameSetList()
{
	while (Done)
	{
		PackManStartScreen();
		int Num = PackManSetting();
		switch (Num)
		{
		case 0:
			std::cout << "게임으로 이동합니다.." << std::endl;
			Sleep(InterFrame);
			system("cls");
			PackManUpdate();
			Done = true;
			break;
		case 1:
			std::cout << "종료합니다..." << std::endl;
			Sleep(InterFrame);
			system("cls");
			Done = false;
			break;
		case 2:
			std::cout << "초기화면으로 돌아갑니다.." << std::endl;
			Sleep(InterFrame);
			system("cls");
			Done = true;
			break;
		default:
			break;
		}
	}
}

void PackManScreen::PackManStartScreen()
{
	Y = 3;
	Handle.Gotoxy(X, Y++);
	std::cout << "==========================================================" << std::endl;
	Handle.Gotoxy(X, Y++);
	std::cout << "||                                                      ||" << std::endl;
	Handle.Gotoxy(X, Y++);
	std::cout << "||                                                      ||" << std::endl;
	Handle.Gotoxy(X, Y++);
	std::cout << "||                                                      ||" << std::endl;
	Handle.Gotoxy(X, Y++);
	std::cout << "||                                                      ||" << std::endl;
	Handle.Gotoxy(X, Y++);
	std::cout << "||                                                      ||" << std::endl;
	Handle.Gotoxy(X, Y++);
	std::cout << "||                게임에 오신걸 환영합니다.             ||" << std::endl;
	Handle.Gotoxy(X, Y++);
	std::cout << "||                                                      ||" << std::endl;
	Handle.Gotoxy(X, Y++);
	std::cout << "||                                                      ||" << std::endl;
	Handle.Gotoxy(X, Y++);
	std::cout << "||                                                      ||" << std::endl;
	Handle.Gotoxy(X, Y++);
	std::cout << "||                                                      ||" << std::endl;
	Handle.Gotoxy(X, Y++);
	std::cout << "||                                                      ||" << std::endl;
	Handle.Gotoxy(X, Y++);
	std::cout << "||                                                      ||" << std::endl;
	Handle.Gotoxy(X, Y++);
	std::cout << "||                                                      ||" << std::endl;
	Handle.Gotoxy(X, Y++);
	std::cout << "==========================================================" << std::endl;
}

void PackManScreen::PackManSetList()
{
	List.push_back("1. 게임을 시작한다.");
	List.push_back("2. 게임을 종료한다.");
}

int PackManScreen::PackManSetting()
{
	return Handle.PrintScreen(X + 14, Y, List);
}

void PackManScreen::PackManUpdate()
{
	
}

