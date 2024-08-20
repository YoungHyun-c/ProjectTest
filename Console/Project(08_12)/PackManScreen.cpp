#include "PackManScreen.h"

#define InterFrame 1000
#define MonsterMove 1500

PackManScreen PackManScreen::MainScreen;
stConsole Console;

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

	if (!MonsterList.empty())
	{
		for (auto& Index : MonsterList)
		{
			delete Index;
			Index = nullptr;
		}
	}

	if (!ItemList.empty())
	{
		for (auto& Index : ItemList)
		{
			delete Index;
			Index = nullptr;
		}
	}
}

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

	MonsterList[0]->SetPos({38, 15 });
	MonsterList[1]->SetPos({46, 15 });
	MonsterList[2]->SetPos({54, 15 });

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

bool PackManScreen::CanMove(int _X, int _Y) const
{
	for (int i = 0; i < ENTITYSIZE; i++)
	{
		for (int j = 0; j < ENTITYSIZE; j++)
		{
			if (MapArr[_Y + i][_X + j] == '1')
			{
				return false;
			}
		}
	}
	return true;
}

int PackManScreen::IndexCount1 = 2;

void PackManScreen::FindMonsterToPlayer()
{
	Path1 = AStar.FindPath(MonsterList[0]->GetPos(), PlayMan->GetPos());

	IndexCount1 = 2;
}

void PackManScreen::MoveMonsterToPlayer()
{
	if (Path1.size() > 1 && CanMove(MonsterList[0]->GetPos().X, MonsterList[0]->GetPos().Y))
	{
		MonsterList[0]->MonsterPrevePrint(MonsterList[0]->GetPos().X, MonsterList[0]->GetPos().Y);
		MonsterList[0]->SetPos(Path1[Path1.size() - IndexCount1++]);
	}
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
	std::cout << "||                    *                         *       ||" << std::endl;
	Handle.Gotoxy(X, Y++);
	std::cout << "||                         *                            ||" << std::endl;
	Handle.Gotoxy(X, Y++);
	std::cout << "||                                          *           ||" << std::endl;
	Handle.Gotoxy(X, Y++);
	std::cout << "||             *                       *                ||" << std::endl;
	Handle.Gotoxy(X, Y++);
	std::cout << "||                           *                   *      ||" << std::endl;
	Handle.Gotoxy(X, Y++);
	std::cout << "||        *     팩맨게임에 오신걸 환영합니다.    *    * ||" << std::endl;
	Handle.Gotoxy(X, Y++);
	std::cout << "||                                                      ||" << std::endl;
	Handle.Gotoxy(X, Y++);
	std::cout << "||                 *                                    ||" << std::endl;
	Handle.Gotoxy(X, Y++);
	std::cout << "||                                *                     ||" << std::endl;
	Handle.Gotoxy(X, Y++);
	std::cout << "||                          *                           ||" << std::endl;
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

bool PackManScreen::CheckCollision()
{
	for (int dY = 0; dY < ENTITYSIZE; dY++)
	{
		for (int dX = 0; dX < ENTITYSIZE; dX++)
		{
			for (auto& Index : MonsterList)
			{
				if (Index->GetPos().X + dX >= PlayMan->GetPos().X && Index->GetPos().X + dX < PlayMan->GetPos().X + ENTITYSIZE
					&& Index->GetPos().Y + dY >= PlayMan->GetPos().Y && Index->GetPos().Y + dY < PlayMan->GetPos().Y + ENTITYSIZE)
				{
					return true;
				}
			}
		}
	}

	return false;
}

void PackManScreen::GameProcess()
{
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
	GameEngineRandom Rand;
	int RandNumX, RandNumY;

	for (int k = 0; k < ItemCount; k++)
	{
		RandNumX = Rand.RandNum(5, 95);
		RandNumY = Rand.RandNum(5, 40);
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				while(MapArr[RandNumY + i][RandNumX + j] == '1')
				{
					RandNumX = Rand.RandNum(5, 95);
					RandNumY = Rand.RandNum(5, 40);
					i = 0;
					j = 0;
				}
			}
		}
		MapArr[RandNumY][RandNumX] = '5';
		ItemList[k]->SetPos({ RandNumX, RandNumY });
	}
}

void PackManScreen::PackManUpdate()
{
	ScreenPrint();
	ItemMade();

	PlayMan->PlayerPrint();

	auto LastMonsterFindTime = std::chrono::steady_clock::now();
	auto LastMonsterMoveTime = std::chrono::steady_clock::now();
	const std::chrono::milliseconds MoveInterval(1000);
	const std::chrono::milliseconds Move(150);
	while (true)
	{
		GameProcess();

		if (CheckCollision())
		{
			Handle.TextColor(15, 0);
			Handle.Gotoxy(0, 48);
			std::cout << "당신은 잡혔습니다!								";
			PlayMan->SubLifeCount();
			if (PlayMan->GetLifeCount() <= 0)
			{
				Handle.TextColor(15, 0);
				Handle.Gotoxy(0, 48);
				std::cout << " 게임이 종료됩니다...								";
				Sleep(1000);
				system("cls");
				break;
			}

			Sleep(2000);
			MonsterList[0]->MonsterReset();
			PlayMan->PlayerReset();
			Handle.TextColor(15, 0);
			Handle.Gotoxy(0, 48);
			std::cout << "초기 위치에서 다시 시작합니다.";
		}

		auto CurrentTime = std::chrono::steady_clock::now();
		if (CurrentTime - LastMonsterFindTime >= MoveInterval)
		{
			//FindMonsterToPlayer();
			for (auto& Index : MonsterList)
			{
				Index->FindMonsterToPlayer(PlayMan);
			}
			LastMonsterFindTime = CurrentTime;
		}
		if (CurrentTime - LastMonsterMoveTime >= Move)
		{
			//MoveMonsterToPlayer();
			for (auto& Index : MonsterList)
			{
				Index->MoveMonsterToPlayer();
			}
			LastMonsterMoveTime = CurrentTime;
		}
		
		for (auto& Item : ItemList)
		{
			if (Item->IsDeath() == false)
			{
				Item->AppleItemPrint(Item->GetPos());
			}
		}

		for (auto& Monster : MonsterList)
		{
			//Monster->MonsterUpdate();
			Monster->MonsterPrint();
		}

		PlayMan->Update();
		PlayMan->PlayerPrint();

		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
}
