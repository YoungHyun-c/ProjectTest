#include "PackManScreen.h"

#include <cmath>

#define InterFrame 1000
#define Monster_Find 600
#define Monster_Move 200

#define AppleValue 100
#define BananaValue 330

PackManScreen PackManScreen::MainScreen;

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

	if (!Items.empty())
	{
		for (auto& Index : Items)
		{
			delete Index;
			Index = nullptr;
		}
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

// 커서 없애기
void PackManScreen::VoidCursor()
{
	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(ConsoleHandle, &ConsoleCursor);
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
	MonsterList.push_back(new Monster(9, 9, 42, 20));
	MonsterList.push_back(new Monster(12, 12, 45, 20));
	MonsterList.push_back(new Monster(13, 13, 54, 20));

	MonsterList[0]->SetPos({35, 23 });
	MonsterList[1]->SetPos({45, 22 });
	MonsterList[2]->SetPos({55, 23 });

	if (Items.empty())
	{
		Items.reserve(ItemCount);
	}
	for (int i = 0; i < ItemCount; i++)
	{
		if (i < 10)
		{
			Items.push_back(new Item(AppleValue));
		}
		else if (i >= 20)
		{
			Items.push_back(new Item(50, + 20));
		}
		else
		{
			Items.push_back(new Item(BananaValue, -10));
		}
	}
	std::string ItemName = "공격";
	Items[20]->SetItemName(ItemName);
	Items[21]->SetItemName(ItemName);
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
			case ' ':
				Handle.TextColor(0, 0);
				std::cout << " ";
				break;
			}
		}
		Handle.TextColor(0, 0);
		std::cout << std::endl;
	}
}

void PackManScreen::ScreenClear()
{
	Handle.TextColor(15, 0);
	Handle.Gotoxy(0, 48);
	std::cout << "당신은 잡혔습니다!                                           ";
	PlayMan->SubLifeCount();
	if (PlayMan->GetLifeCount() <= 0)
	{
		Handle.TextColor(15, 0);
		Handle.Gotoxy(0, 48);
		std::cout << " 게임이 종료됩니다...								";
		Sleep(1000);
		system("cls");
	}

	Sleep(2000);
	for (auto& Monster : MonsterList)
	{
		Monster->MonsterReset();
	}

	PlayMan->PlayerReset();
	Handle.TextColor(15, 0);
	Handle.Gotoxy(0, 48);
	std::cout << "초기 위치에서 다시 시작합니다.";
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

bool PackManScreen::CheckCollision()
{
	//for (int dY = 0; dY < ENTITYSIZE; dY++)
	//{
	//	for (int dX = 0; dX < ENTITYSIZE; dX++)
	//	{
	//		for (auto& Monster : MonsterList)
	//		{
	//			if (Monster->GetPos().X + dX >= PlayMan->GetPos().X && Monster->GetPos().X + dX < PlayMan->GetPos().X + ENTITYSIZE
	//					&& Monster->GetPos().Y + dY >= PlayMan->GetPos().Y && Monster->GetPos().Y + dY < PlayMan->GetPos().Y + ENTITYSIZE)
	//			{
	//				if (PlayMan->GetState() == PlayerState::Attacker)
	//				{
	//					Monster->MonsterReset();
	//					return false;
	//				}
	//				else
	//				{
	//					//return true;
	//				}
	//			}
	//		}
	//	}
	//}
	for (auto& Monster : MonsterList)
	{
		if (Col.CheckCollision(Monster->GetPos(), PlayMan->GetPos()))
		{
			if (PlayMan->GetState() == PlayerState::Attacker)
			{
				Monster->MonsterReset();
				return false;
			}
			else
			{
				//return true;
			}
		}
	}
	return false;
}

bool PackManScreen::CheckMonsterCollision()
{
	for (int i = 0; i < MonsterCount - 1; i++)
	{
		for (int j = i + 1; j < MonsterCount; j++)
		{
			if (Col.CheckCollision(MonsterList[i]->GetPos(), MonsterList[j]->GetPos()))
			{
				MonsterList[i]->MonsterReset();
				return true;
			}
		}
	}
	return false;
}

bool PackManScreen::CheckTest(const int2& _Pos)
{
	for (const auto& Monster : MonsterList)
	{
		if (Col.CheckCollision({Monster->GetPos().X, Monster->GetPos().Y}, _Pos))
		{
			Monster->MonsterReset();
			return true;
		}
	}
	return false;
}

void PackManScreen::GameProcess()
{
	// 아이템
	 for (auto& ItemIndex : Items)
	{
		if (ItemIndex->IsDeath() == false
			&& Col.CheckItemCollision({ ItemIndex->GetPos().X, ItemIndex->GetPos().Y }, PlayMan->GetPos()))
		{
			PlayMan->AddScore(ItemIndex->GetValue());
			PlayMan->AddSpeed(ItemIndex->GetSpeed());
			if (ItemIndex->GetName() == "공격")
			{
				PlayMan->ChangeState(PlayerState::Attacker);
			}
			ItemIndex->Death();
			break;
		}
	}
	
	for (int Index = 0; Index < ItemCount; Index++)
	{
		if (Items[Index]->IsDeath() == true)
		{
			Items[Index]->ItemOff(Items[Index]->GetPos());
		}
		else if (Index < 10)
		{
			Items[Index]->AppleItemPrint(Items[Index]->GetPos());
		}
		else if (20 <= Index)
		{
			Items[Index]->TransItemPrint(Items[Index]->GetPos());
		}
		else if (10 <= Index)
		{
			Items[Index]->BananaItemPrint(Items[Index]->GetPos());
		}

	}
	
	// 플레이어 관련
	if (_kbhit())
	{
		Key = _getch();

		if (Key == '9')
		{
			PlayMan->AddSpeed(-10);
		}
		else if (Key == '0')
		{
			PlayMan->AddSpeed(10);
		}
		else if (Key == '1')
		{
			PlayMan->ChangeState(PlayerState::Normal);
		}
		else if (Key == '2')
		{
			PlayMan->ChangeState(PlayerState::Attacker);
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
				while(MapArr[RandNumY + i][RandNumX + j] == '1' || MapArr[RandNumY + i][RandNumX + j] == '5')
				{
					RandNumX = Rand.RandNum(5, 95);
					RandNumY = Rand.RandNum(5, 40);
					i = 0;
					j = 0;
				}
			}
		}
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				MapArr[RandNumY + i][RandNumX + j] = '5';
			}
		}
		Items[k]->SetPos({ RandNumX, RandNumY });
	}
}

void PackManScreen::PackManUpdate()
{
	ScreenPrint();
	ItemMade();

	PlayMan->PlayerPrint();

	auto LastMonsterFindTime = std::chrono::steady_clock::now();
	auto LastMonsterMoveTime = std::chrono::steady_clock::now();
	const std::chrono::milliseconds MoveInterval(Monster_Find);
	const std::chrono::milliseconds Move(Monster_Move);

	while (true)
	{
		GameProcess();

		auto CurrentTime = std::chrono::steady_clock::now();
		if (CurrentTime - LastMonsterFindTime >= MoveInterval)
		{
			for (auto& Index : MonsterList)
			{
				Index->FindMonsterToPlayer(PlayMan);
			}
			LastMonsterFindTime = CurrentTime;
		}
		if (CurrentTime - LastMonsterMoveTime >= Move)
		{
			for (auto& Index : MonsterList)
			{
				Index->MoveMonsterToPlayer();
			}
			LastMonsterMoveTime = CurrentTime;
		}

		if (CheckCollision() == true)
		{
			ScreenClear();
		}

		for (auto& Monster : MonsterList)
		{
			Monster->MonsterPrint();
		}

		PlayMan->Update();
		PlayMan->PlayerPrint();

		std::this_thread::sleep_for(std::chrono::milliseconds(50));
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

char PackManScreen::GetScreenCharacter(const int2& _Pos) const
{
	return MapArr[_Pos.Y][_Pos.X];
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