#include "PackManScreen.h"
#include <iostream>

#define InterFrame 1000

PackManScreen PackManScreen::MainScreen;
stConsole Console;

// 커서 없애기
void PackManScreen::VoidCursor()
{
	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(ConsoleHandle, &ConsoleCursor);
}

void PackManScreen::InitGame(bool bInitConsole)
{
	if (bInitConsole)
	{
		Console.hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		Console.nCurBuffer = 0;


		CONSOLE_CURSOR_INFO ConsoleCursor{ 1, FALSE };
		CONSOLE_SCREEN_BUFFER_INFO ConsoleInfo{ 0 , };
		GetConsoleScreenBufferInfo(Console.hConsole, &ConsoleInfo);
		ConsoleInfo.dwSize.X = 100;
		ConsoleInfo.dwSize.Y = 40;

		Console.rtConsole.nWidht = ConsoleInfo.srWindow.Right - ConsoleInfo.srWindow.Left;
		Console.rtConsole.nHeight = ConsoleInfo.srWindow.Bottom - ConsoleInfo.srWindow.Top;

		Console.hBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
		SetConsoleScreenBufferSize(Console.hBuffer[0], ConsoleInfo.dwSize);
		SetConsoleWindowInfo(Console.hBuffer[0], TRUE, &ConsoleInfo.srWindow);
		SetConsoleCursorInfo(Console.hBuffer[0], &ConsoleCursor);

		Console.hBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
		SetConsoleScreenBufferSize(Console.hBuffer[1], ConsoleInfo.dwSize);
		SetConsoleWindowInfo(Console.hBuffer[1], TRUE, &ConsoleInfo.srWindow);
		SetConsoleCursorInfo(Console.hBuffer[1], &ConsoleCursor);
	}
}

void PackManScreen::ScreenClear()
{
	//COORD Pos{ 0, };
	//DWORD dwWritten = 0;
	//unsigned Size = Console.rtConsole.nWidht * Console.rtConsole.nHeight;

	//FillConsoleOutputCharacter(Console.hConsole, ' ', Size, Pos, &dwWritten);
	//SetConsoleCursorPosition(Console.hConsole, Pos);

	//system("cls");
	//for (size_t Y = 0; Y < this->Size.Y; Y++)
	//{
	//	for (size_t X = 0; X < this->Size.X; X++)
	//	{
	//		//MapArr[Y][X] = '0';
	//	}
	//}
}

void PackManScreen::ScreenPrint()
{
	Handle.Gotoxy(0, 0);

	for (int Y = 0; Y < YScreen - 1; Y++)
	{
		for (int X = 0; X < XScreen; X++)
		{
			switch (MapArr[Y][X])
			{
			case '0':
				Handle.TextColor(0, 0);
				std::cout << " ";
				break;
			case '1':
				Handle.TextColor(15, 15);
				std::cout << "■";
				break;
			case '2':
				// 플레이어
				Handle.TextColor(14, 14);
				std::cout << "■";
				break;
			case 'A':
			case 'a':
				Handle.TextColor(2, 2);
				std::cout << "A";
				break;
			case ' ':
				Handle.TextColor(0, 0);
				std::cout << " ";
				break;
			}
		}
		Handle.TextColor(0, 0);
		std::cout << std::endl;
	}
	


	//Sleep(1);
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

void PackManScreen::SetScreenCharacter(const int2& _Pos, char _Ch[][6])
{
	if (true == IsScreenOver(_Pos))
	{
		return;
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			MapArr[_Pos.Y + i][_Pos.X + j] = _Ch[i][j];
		}
	}
}

void PackManScreen::SetScreenCharacter(const int2& _Pos, char _Ch)
{
	if (true == IsScreenOver(_Pos))
	{
		return;
	}

	MapArr[_Pos.Y ][_Pos.X ] = _Ch;
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
	
	//InitGame();
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



/*memset(chBuf, 0, sizeof(chBuf));
	int nLen = sprintf_s(chBuf, sizeof(chBuf), *MapArr);

	SetConsoleCursorPosition(Console.hBuffer[Console.nCurBuffer], coord);
	WriteFile(Console.hBuffer[Console.nCurBuffer], chBuf, nLen, &dw, NULL);*/

	//ScreenClear();
	//static char front_buffer[YScreen][XScreen] = { ' ' };

	//for (int i = 0; i < YScreen; i++)
	//{
	//	for (int j = 0, j2 = 0; j < XScreen; j++)
	//	{
	//		char Check = MapArr[i][j];
	//		if (front_buffer[i][j] != MapArr[i][j])
	//		{
	//			switch (MapArr[i][j])
	//			{
	//			case '0':
	//				Handle.TextColor(0, 0);
	//				std::cout << " ";
	//				break;
	//			case '1':
	//				Handle.TextColor(15, 15);
	//				std::cout << "■";
	//				break;
	//			case '2':
	//				// 플레이어
	//				Handle.TextColor(14, 14);
	//				std::cout << "■";
	//				break;
	//			case 'A':
	//			case 'a':
	//				Handle.TextColor(2, 2);
	//				std::cout << "A";
	//				break;
	//			case ' ':
	//				Handle.TextColor(0, 0);
	//				std::cout << " ";
	//				break;
	//			}
	//			front_buffer[i][j] = MapArr[i][j];
	//		}
	//		j2 += 2;
	//	}
	//	Handle.TextColor(0, 0);
	//	std::cout << std::endl;
	//}
	// 화면 버퍼 설정
	//SetConsoleActiveScreenBuffer(Console.hBuffer[Console.nCurBuffer]);
	//// 화면 버퍼 인덱스를 교체
	//Console.nCurBuffer = Console.nCurBuffer ? 0 : 1;