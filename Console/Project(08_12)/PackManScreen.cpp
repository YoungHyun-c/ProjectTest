#include "PackManScreen.h"
#include <iostream>

#define InterFrame 1000

PackManScreen PackManScreen::MainScreen;

void PackManScreen::ScreenClear()
{
	system("cls");

	for (size_t Y = 0; Y < this->Size.Y; Y++)
	{
		for (size_t X = 0; X < this->Size.X; X++)
		{
			ArrScreen[Y][X] = L'■';
		}
	}
}

void PackManScreen::ScreenPrint()
{
	setlocale(LC_ALL, "KOR");
	for (size_t Y = 0; Y < this->Size.Y; Y++)
	{
		for (size_t X = 0; X < this->Size.X; X++)
		{
			wprintf_s(L"%c", ArrScreen[Y][X]);
		}
		wprintf_s(L"\n");
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

	if (_Pos.X >= XScreenSize)
	{
		return true;
	}

	if (_Pos.Y >= YScreenSize)
	{
		return true;
	}

	return false;
}

void PackManScreen::SetScreenCharacter(const int2& _Pos, wchar_t _Ch)
{
	if (true == IsScreenOver(_Pos))
	{
		return;
	}
	
	ArrScreen[_Pos.X][_Pos.Y] = _Ch;
}

wchar_t PackManScreen::GetScreenCharacter(const int2& _Pos) const
{
	return ArrScreen[_Pos.X][_Pos.Y];
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

void PackManScreen::PackManMapPrint()
{
	std::cout << "=======" << std::endl;
	std::cout << "==   ==" << std::endl;
	std::cout << "== = ==" << std::endl;
	std::cout << "== = ==" << std::endl;
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
	PackManMapPrint();
}

