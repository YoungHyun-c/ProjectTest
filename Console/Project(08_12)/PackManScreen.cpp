#include "PackManScreen.h"


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
	if (PlayMan == nullptr)
	{
		PlayMan = new Player();
	}

	if (MonsterList.empty())
	{
		MonsterList.reserve(MonsterCount);
	}
	MonsterList.push_back(new Monster(9, 9, 38, 15));
	MonsterList.push_back(new Monster(12, 12, 46, 15));
	MonsterList.push_back(new Monster(13, 13, 54, 15));

	if (ItemList.empty())
	{
		ItemList.reserve(ItemCount);
	}

	for (int i = 0; i < ItemCount; i++)
	{
		ItemList.push_back(new Item(99));
	}

	srand(time(NULL));
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

bool PackManScreen::CanMove(int _X, int _Y)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (MapArr[_Y + i][_X + j] == '1')
			{
				return false;
			}
		}
	}
	return true;
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
	if (PlayMan != nullptr)
	{
		delete PlayMan;
		PlayMan = nullptr;
	}
}

void PackManScreen::Start()
{
	InitGame();
	VoidCursor();
	//PackManSetList();
	//GameSetList();

	// 바로 겜 가서 테스트용
	PackManUpdate();
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

void PackManScreen::GameInfoPrint()
{
	
}

void PackManScreen::GameProcess()
{
	// 몬스터
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (int2{ PlayMan->GetPos().X + j, PlayMan->GetPos().Y + i } == int2{ MonsterList[0]->GetPos().X + 1, MonsterList[0]->GetPos().Y + 1 })
			{
				PlayMan->SubLifeCount();
				break;
			}
			if (int2{ PlayMan->GetPos().X + j, PlayMan->GetPos().Y + i } == int2{ MonsterList[1]->GetPos().X + 1, MonsterList[1]->GetPos().Y + 1 })
			{
				PlayMan->SubLifeCount();
				break;
			}
			if (int2{ PlayMan->GetPos().X + j, PlayMan->GetPos().Y + i } == int2{ MonsterList[2]->GetPos().X + 1, MonsterList[2]->GetPos().Y + 1 })
			{
				PlayMan->SubLifeCount();
				break;
			}
		}
	}

	// 아이템
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < ItemCount; k++)
			{
				if (ItemList[k]->IsDeath() == false && int2 { PlayMan->GetPos().X + j, PlayMan->GetPos().Y + i } == int2{ItemList[k]->GetPos().X , ItemList[k]->GetPos().Y})
				{
					PlayMan->AddScore(100);
					ItemList[k]->Death();
					break;
				}
			}
		}
	}
	
}

void PackManScreen::ItemMade()
{
	int RandNumX = rand() % 90 + 5;
	int RandNumY = rand() % 45;

	for (int k = 0; k < ItemCount; k++)
	{
		RandNumX = rand() % 90 + 5;
		RandNumY = rand() % 45;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				while(MapArr[RandNumY + i][RandNumX + j] == '1')
				{
					RandNumX = rand() % 90 + 5;
					RandNumY = rand() % 45;
					i = 0;
					j = 0;
				}
			}
		}
		ItemList[k]->SetPos({ RandNumX, RandNumY });
		ItemList[k]->AppleItemPrint(ItemList[k]->GetPos());
	}
	
}

void PackManScreen::PackManUpdate()
{
	ScreenPrint();
	ItemMade();

	PlayMan->PlayerPrint();
	for (int i = 0; i < 3; i++)
	{
		//MonsterList[i]->MonsterPrint();
	}

	//MonsterList[0]->SetPos({ PlayMan->GetPos().X + 13, PlayMan->GetPos().Y - 10 });

	while (true)
	{
		PlayMan->Update();
		GameProcess();
		PlayMan->PlayerPrint();


		// 몬스터
		/*for (int i = 0; i < 3; i++)
		{
			MonsterList[i]->MonsterPrint();
		}*/

		//MonsterList[0]->MonsterPrint();

		/*end = clock();
		CheckTime = double(end - start) / CLOCKS_PER_SEC;
		if (CheckTime >= 0.3)
		{
			MonsterList[0]->SetPos({ MonsterList[0]->MonsterMove(PlayMan).Y, MonsterList[0]->MonsterMove(PlayMan).X});
			start = clock();
		}*/
	}
}
