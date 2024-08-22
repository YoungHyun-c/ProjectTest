#include "PackManScreen.h"

#include <cmath>

#define InterFrame 1000
//#define Monster_Find 600
//#define Monster_Move 200

#define AppleValue 100
#define BananaValue 330
#define TransValue 200

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

// Ŀ�� ���ֱ�
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
	PackManSetList();
	GameSetList();
}

void PackManScreen::GameSetList()
{
	while (Done)
	{
		PackManTitleScreen();
		int Num = PackManSetting();
		switch (Num)
		{
		case 0:
			std::cout << "�������� �̵��մϴ�.." << std::endl;
			Sleep(InterFrame);
			system("cls");
			PackManUpdate();
			Done = true;
			break;
		case 1:
			std::cout << "���� ������ Ȯ���մϴ�..." << std::endl;
			Sleep(InterFrame);
			system("cls");
			PackManInfo();
			Done = true;
			break;
		case 2:
			std::cout << "�����մϴ�..." << std::endl;
			Sleep(InterFrame);
			system("cls");
			Done = false;
			break;
		default:
			break;
		}
	}
}

void PackManScreen::PackManTitleScreen()
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
	std::cout << "||        *   ~ �Ѹǰ��ӿ� ���Ű� ȯ���մϴ� ~   *    * ||" << std::endl;
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
	List.push_back("1. ������ �����Ѵ�.");
	List.push_back("2. ���� ���� Ȯ��");
	List.push_back("3. ������ �����Ѵ�.");
}

int PackManScreen::PackManSetting()
{
	return Handle.PrintScreen(X + 14, Y, List);
}

void PackManScreen::GameInfoPrint()
{
	for (int i = 0; i < MonsterCount; i++)
	{
		Handle.Gotoxy((i * 30), 48);
		Handle.TextColor(15, 0);
		switch (MonsterList[i]->GetState())
		{
		case MonsterState::Normal:
			std::cout << "���� ���� : �븻                      ";
			break;
		case MonsterState::Attack:
			std::cout << "���� ���� : ����! ã�Ҵ�!!           ";
			break;
		case MonsterState::Run:
			std::cout << "���� ���� : ���!!!!                ";
			break;
		case MonsterState::Max:
			std::cout << "���� ���� : Zzz...                 ";
			break;
		default:
			break;
		}
	}
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


	for (auto& Monster : MonsterList)
	{
		Monster->RecievepPlayer(PlayMan);
	}

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
			Items.push_back(new Item(TransValue, + 20));
		}
		else
		{
			Items.push_back(new Item(BananaValue, -10));
		}
	}
	std::string ItemName = "����";
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
			switch (MapArr[Stage][Y][X])
			{
			case '0':
			case '5':
				Handle.TextColor(0, 0);
				std::cout << " ";
				break;
			case '1':
				Handle.TextColor(15, 15);
				std::cout << "��";
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
	Handle.Gotoxy(0, 49);
	std::cout << "����� �������ϴ�!                                           ";
	PlayMan->SubLifeCount();
	if (PlayMan->GetLifeCount() <= 0)
	{
		Handle.TextColor(15, 0);
		Handle.Gotoxy(0, 49);
		std::cout << " ó������ ���ư��ϴ�....								";
		Sleep(1000);
		system("cls");
		Stage = 0;
		for (auto& Item : Items)
		{
			Item->IsDeath();
		}
		GameSetList();
	}

	Sleep(2000);
	for (auto& Monster : MonsterList)
	{
		Monster->MonsterReset();
	}

	PlayMan->PlayerReset();
	Handle.TextColor(15, 0);
	Handle.Gotoxy(0, 49);
	std::cout << "�ʱ� ��ġ���� �ٽ� �����մϴ�.";
}

bool PackManScreen::CanMove(int _X, int _Y) const
{
	for (int i = 0; i < ENTITYSIZE; i++)
	{
		for (int j = 0; j < ENTITYSIZE; j++)
		{
			if (MapArr[Stage][_Y + i][_X + j] == '1')
			{
				return false;
			}
		}
	}
	return true;
}

bool PackManScreen::CheckCollision()
{
	for (int dY = 0; dY < ENTITYSIZE; dY++)
	{
		for (int dX = 0; dX < ENTITYSIZE; dX++)
		{
			for (auto& Monster : MonsterList)
			{
				if (Monster->GetPos().X + dX >= PlayMan->GetPos().X && Monster->GetPos().X + dX < PlayMan->GetPos().X + ENTITYSIZE
						&& Monster->GetPos().Y + dY >= PlayMan->GetPos().Y && Monster->GetPos().Y + dY < PlayMan->GetPos().Y + ENTITYSIZE)
				{
					if (PlayMan->GetState() == PlayerState::Attacker)
					{
						Monster->MonsterReset();
						return false;
					}
					else
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool PackManScreen::CheckMonsterCol()
{
	for (int i = 0; i < MonsterCount - 1; i++)
	{
		for (int j = i + 1; j < MonsterCount; j++)
		{
			if (Col.CheckCollision(MonsterList[i]->GetPos(), MonsterList[j]->GetPos()))
			{
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

void PackManScreen::StageClear()
{
	int Y = 15;
	if (Stage + 1 < MaxStageNum)
	{
		Stage++;
		Handle.TextColor(15, 0);
		Handle.Gotoxy(30, Y++); printf("�ǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢ�");
		Handle.Gotoxy(30, Y++); printf("��                              ��");
		Handle.Gotoxy(30, Y++); printf("��       Stage C L E A R !      ��");
		Handle.Gotoxy(30, Y++); printf("��                              ��");
		Handle.Gotoxy(30, Y++); printf("�ǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢ�");
		Handle.Gotoxy(30, Y++);

		if (_getch())
		{
			system("cls");
		}
	}
	else
	{
		Handle.TextColor(15, 0);
		Handle.Gotoxy(30, Y++); printf("�ǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢ�");
		Handle.Gotoxy(30, Y++); printf("��                              ��");
		Handle.Gotoxy(30, Y++); printf("��       A L L C L E A R !      ��");
		Handle.Gotoxy(30, Y++); printf("��                              ��");
		Handle.Gotoxy(30, Y++); printf("�ǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢ�");
		Handle.Gotoxy(30, Y++);
		Stage = 0;
		if (_getch())
		{
			system("cls");
		}
	}

	/*for (auto& ItemIndex : Items)
	{
		if (ItemIndex->IsDeath())
		{
			ItemIndex->Resolve();
		}
	}*/
}

void PackManScreen::GameProcess()
{
	// ������
	for (auto& ItemIndex : Items)
	{
		if (ItemIndex->IsDeath() == false
			&& Col.CheckItemCollision({ ItemIndex->GetPos().X, ItemIndex->GetPos().Y }, PlayMan->GetPos()))
		{
			PlayMan->AddScore(ItemIndex->GetValue());
			PlayMan->AddSpeed(ItemIndex->GetSpeed());
			if (ItemIndex->GetName() == "����")
			{
				PlayMan->ChangeState(PlayerState::Attacker);
				
				for (auto& Monster : MonsterList)
				{
					Monster->ChangeState(MonsterState::Run);
				}
			}
			ItemIndex->Death();
			break;
		}
	}

	/*if (Stage == 2)
	{
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
	}*/
	
	PlayMan->Update();
	PlayMan->PlayerPrint();


	// �÷��̾�, ���� ����
	if (_kbhit())
	{
		Key = _getch();
		if (Key == '3')
		{
			MonsterList[0]->ChangeState(MonsterState::Normal);
		}
		else if (Key == '4')
		{
			MonsterList[0]->ChangeState(MonsterState::Attack);
		}
		else if (Key == '5')
		{
			MonsterList[0]->ChangeState(MonsterState::Run);
		}
		else if (Key == '7')
		{
			MonsterList[0]->MonsterColPrint();
		}
		else if (Key == '8')
		{
			MonsterList[0]->MonsterColOff();
		}
	}
}

void PackManScreen::ItemMade()
{
	GameEngineRandom Rand;
	int RandNumX, RandNumY;


	for (auto& Item : Items)
	{
		if (MapArr[Stage][Item->GetPos().Y][Item->GetPos().X] == '5')
		{
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					MapArr[Stage][Item->GetPos().Y + i][Item->GetPos().X + j] = '0';
					Item->ItemOff(Item->GetPos());
					Item->IsDeath();
				}
			}
		}
	}

	for (int k = 0; k < ItemCount; k++)
	{
		RandNumX = Rand.RandNum(5, 95);
		RandNumY = Rand.RandNum(5, 40);
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				while(MapArr[Stage][RandNumY + i][RandNumX + j] == '1' || MapArr[Stage][RandNumY + i][RandNumX + j] == '5')
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
				MapArr[Stage][RandNumY + i][RandNumX + j] = '5';
			}
		}
		Items[k]->SetPos({ RandNumX, RandNumY });
		Items[k]->Resolve();
		Items[k]->SetItemRender(true);
	}
}

void PackManScreen::PackManUpdate()
{
	StageProcess();
}

void PackManScreen::StageProcess()
{
	if (Stage == 0)
	{
		ScreenPrint();
		PlayMan->SetLifeCount(3);
		PlayMan->SetPos({ 10, 10 });
		PlayMan->ChangeState(PlayerState::Normal);
		PlayMan->PlayerPrint();
		Items[0]->SetPos({ 25, 10 });
		Items[0]->AppleItemPrint({ 25,10 });
		Items[0]->Resolve();
		while (true)
		{
			GameProcess();
			if (Items[0]->IsDeath() == true)
			{
				StageClear();
				break;
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
		}
	}
	if (Stage == 1)
	{
		ScreenPrint();
		Items[20]->SetPos({ 40, 5 });
		Items[20]->Resolve();
		PlayMan->SetPos({ 10, 10 });
		PlayMan->SetInitPos({ 10, 10 });
		PlayMan->PlayerPrint();
		PlayMan->SetSpeed(20);
		MonsterList[0]->SetPos({ 50, 10 });
		MonsterList[0]->SetInitPos({ 50, 10 });
		MonsterList[0]->SetColPos({ 50, 10 });
		MonsterList[0]->ChangeState(MonsterState::Max);
		while (true)
		{
			if (Stage1Clear())
			{
				break;
			}
		}
	}
	if (Stage == 2)
	{
		ScreenPrint();
		ItemMade();

		PlayMan->SetInitPos({ 50, 40 });
		PlayMan->SetPos({ 50, 40 });
		PlayMan->ChangeState(PlayerState::Normal);
		PlayMan->SetSpeed(100);

		MonsterList[0]->SetPos({ 35, 23 });
		MonsterList[0]->SetInitPos({ 35, 23 });
		MonsterList[0]->SetColPos({ 35, 23 });
		MonsterList[1]->SetPos({ 45, 22 });
		MonsterList[2]->SetPos({ 55, 23 });

		for (auto& Monster : MonsterList)
		{
			Monster->ChangeState(MonsterState::Normal);
		}

		PlayMan->PlayerReset();
		PlayMan->PlayerPrint();

		while (true)
		{
			GameProcess();
			if (CheckCollision() == true)
			{
				ScreenClear();
			}

			for (auto& Monster : MonsterList)
			{
				Monster->Update();
				Monster->MonsterPrint();
			}
			GameInfoPrint();

			PlayMan->Update();
			PlayMan->PlayerPrint();

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

			if (Stage2Clear())
			{
				StageClear();
				break;
			}

			std::this_thread::sleep_for(std::chrono::milliseconds(50));
		}
	}
}

bool PackManScreen::Stage1Clear()
{
	if (Items[20]->IsDeath() == true)
	{
		Items[20]->ItemOff(Items[20]->GetPos());
	}
	else
	{
		Items[20]->TransItemPrint({ 40, 5 });
	}

	MonsterList[0]->Update();
	MonsterList[0]->MonsterPrint();

	for (int dY = 0; dY < ENTITYSIZE; dY++)
	{
		for (int dX = 0; dX < ENTITYSIZE; dX++)
		{
			if (MonsterList[0]->GetPos().X + dX >= PlayMan->GetPos().X && MonsterList[0]->GetPos().X + dX < PlayMan->GetPos().X + ENTITYSIZE
				&& MonsterList[0]->GetPos().Y + dY >= PlayMan->GetPos().Y && MonsterList[0]->GetPos().Y + dY < PlayMan->GetPos().Y + ENTITYSIZE)
			{
				if (PlayMan->GetState() == PlayerState::Attacker)
				{
					StageClear();
					return true;
				}
				else
				{
					Handle.TextColor(15, 0);
					Handle.Gotoxy(0, 49);
					std::cout << "����� �������ϴ�!                                           ";
					PlayMan->SubLifeCount();
					Sleep(2000);

					MonsterList[0]->ChangeState(MonsterState::Max);
					MonsterList[0]->MonsterReset();
					PlayMan->PlayerReset();
					Handle.TextColor(15, 0);
					Handle.Gotoxy(0, 49);
					std::cout << "�ʱ� ��ġ���� �ٽ� �����մϴ�.";
				}
			}
		}
	}

	GameProcess();
	GameInfoPrint();

	std::this_thread::sleep_for(std::chrono::milliseconds(50));
	return false;
}

bool PackManScreen::Stage2Clear()
{
	for (Item* item : Items)
	{
		if (item->IsDeath() == false)
		{
			return false;
		}
	}
	return true;
}

void PackManScreen::PackManInfo()
{
	Handle.Gotoxy(3, 4);
	std::cout << "���� Ű ���� : " << std::endl;
	Handle.Gotoxy(3, 5); printf("  ��   : Up");
	Handle.Gotoxy(3, 6); printf("��   �� : Left | Right");
	Handle.Gotoxy(3, 7); printf("  ��   : Down");

	Items[0]->AppleItemPrint({ 3, 11 });
	Handle.TextColor(15, 0);
	Handle.Gotoxy(6, 11); printf("��� ������! ������ Player�� Score�� %d���� �ö󰩴ϴ�!", AppleValue);
	Items[1]->BananaItemPrint({ 3, 14 });
	Handle.TextColor(15, 0);
	Handle.Gotoxy(6, 14); printf("�ٳ��� ������! ������ Player�� Score�� %d���� �ö󰡸�, �÷��̾� ���ǵ尡 10 �ö󰩴ϴ�.", BananaValue);
	Items[2]->TransItemPrint({ 3, 17 });
	Handle.TextColor(15, 0);
	Handle.Gotoxy(6, 17); printf("���� ������! ������ Player�� Score�� %d���� ��������, �÷��̾��� ���ǵ�� 20�پ��ϴ�. ", TransValue);
	Handle.Gotoxy(6, 18); printf("��� ���͸� ���� �� �ִ� ���°� �Ǹ�, ���� ������ ��ġ�� �ʱ�ȭ �˴ϴ�.");

	Handle.Gotoxy(6, 19); printf("��� �������� ������, ������ Ŭ���� �� �� �ֽ��ϴ�!");

	Handle.Gotoxy(3, 25);
	std::cout << "�ʱ�ȭ������ ���ư��÷���, �ƹ�Ű�� �����ּ���~" << std::endl;
	if (_getch())
	{
		std::cout << "�ʱ� ȭ������ �̵��մϴ�...." << std::endl;
	}
	Sleep(3000);
	system("cls");
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
			MapArr[Stage][_Pos.Y + i][_Pos.X + j] = _Ch[i][j];
		}
	}
}

char PackManScreen::GetScreenCharacter(const int2& _Pos) const
{
	return MapArr[Stage][_Pos.Y][_Pos.X];
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