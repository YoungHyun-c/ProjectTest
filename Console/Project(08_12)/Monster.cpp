#include "Monster.h"
#include "GameEngineRandom.h"

#define MonsterChase 3000
#define Monster_Find 1500
#define Monster_Move 100

Monster::~Monster()
{
}


void Monster::ChangeState(MonsterState _State)
{
	if (_State != State)
	{
		switch (_State)
		{
		case MonsterState::Normal:
			NormalStart();
			break;
		case MonsterState::Attack:
			AttackStart();
			break;
		case MonsterState::Run:
			RunStart();
			break;
		default:
			break;
		}
	}
	State = _State;
}

void Monster::StateUpdate()
{
	switch (State)
	{
	case MonsterState::Normal:
		return NormalUpdate();
	case MonsterState::Attack:
		return AttackUpdate();
	case MonsterState::Run:
		return RunUpdate();
	default:
		break;
	}
}

void Monster::Update()
{
	StateUpdate();
	//MonsterInfoPrint();
}

void Monster::MonsterInfoPrint()
{
	Handle.Gotoxy(55, 48);
	Handle.TextColor(15, 0);

	switch (State)
	{
	case MonsterState::Normal:
		std::cout << "몬스터 상태 : 노말                         ";
		break;
	case MonsterState::Attack:
		std::cout << "몬스터 상태 : 공격! 찾았다!!                ";
		break;
	case MonsterState::Run:
		std::cout << "몬스터 상태 : 도망! 비상!                   ";
		break;
	case MonsterState::Max:
		break;
	default:
		break;
	}
}

void Monster::NormalStart()
{
}

void Monster::NormalUpdate()
{
	if (pPlayer == nullptr)
	{
		return;
	}
	if (Col.CheckMonsterCollision(MonsterColPos, pPlayer->GetPos()))
	{
		ChangeState(MonsterState::Attack);
		return;
	}

	int2 NextPos = MonsterPos;
	switch (Dir) {
	case 0:
		NextPos = MonsterPos;
		NextPos.X -= 1;
		MoveMonster(NextPos.X, NextPos.Y);
		break;
	case 1:
		NextPos = MonsterPos;
		NextPos.X += 1;
		MoveMonster(NextPos.X, NextPos.Y);
		break;
	case 2:
		NextPos = MonsterPos;
		NextPos.Y -= 1;
		MoveMonster(NextPos.X, NextPos.Y);
		break;
	case 3:
		NextPos = MonsterPos;
		NextPos.Y += 1;
		MoveMonster(NextPos.X, NextPos.Y);
		break;
	}

}

const std::chrono::milliseconds Monster::MoveChase(MonsterChase);
const std::chrono::milliseconds Monster::MoveInterval(Monster_Find);
const std::chrono::milliseconds Monster::Move(Monster_Move);
void Monster::AttackStart()
{
	LastMonsterChaseTime = std::chrono::steady_clock::now();
	LastMonsterFindTime = std::chrono::steady_clock::now();
	LastMonsterMoveTime = std::chrono::steady_clock::now();
	FindMonsterToPlayer(pPlayer);
}
void Monster::AttackUpdate()
{
	auto CurrentTime = std::chrono::steady_clock::now();
	if (!Col.CheckMonsterCollision(MonsterColPos, pPlayer->GetPos()) && CurrentTime - LastMonsterChaseTime >= MoveChase)
	{
		LastMonsterChaseTime = CurrentTime;
		LastMonsterFindTime = CurrentTime;
		LastMonsterMoveTime = CurrentTime;
		ChangeState(MonsterState::Normal);
		return;
	}
	if (CurrentTime - LastMonsterFindTime >= MoveInterval)
	{
		LastMonsterFindTime = CurrentTime;
		FindMonsterToPlayer(pPlayer);
	}
	if (CurrentTime - LastMonsterMoveTime >= Move)
	{
		LastMonsterMoveTime = CurrentTime;
		MoveMonsterToPlayer();
	}
}

const std::chrono::milliseconds Monster::Runner(6000);
void Monster::RunStart()
{
	RunTime = std::chrono::steady_clock::now();
}
void Monster::RunUpdate()
{
	auto CurrentTime = std::chrono::steady_clock::now();
	if (CurrentTime - RunTime >= Runner)
	{
		RunTime = CurrentTime;
		ChangeState(MonsterState::Normal);
		return;
	}

	for (short i = 0; i < YSize; i++)
	{
		for (short j = 0; j < XSize - 1; j++)
		{
			COORD Pos = {static_cast<short>(MonsterPos.X )+ j, static_cast<short>(MonsterPos.Y) + i };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
			switch (MonsterArr1[i][j])
			{
			case '4':
				Handle.TextColor(11, 9);
				std::cout << "■";
				break;
			case '5':
				Handle.TextColor(0, 12);
				std::cout << "■";
				break;
			default:
				Handle.TextColor(0, 0);
				std::cout << " ";
				break;
			}
		}
		Handle.TextColor(0, 0);
		std::cout << std::endl;
	}
}


void Monster::MonsterPrint()
{
	if (State == MonsterState::Run)
	{
		return;
	}

	end = clock();
	CheckTime = double(end - start) / CLOCKS_PER_SEC;
	if (CheckTime < 0.3)
	{
		DrawChar(MonsterPos.X, MonsterPos.Y, MonsterArr1);
	}
	if (CheckTime >= 0.3)
	{
		DrawChar(MonsterPos.X, MonsterPos.Y, MonsterArr2);
		start = clock();
	}
}

void Monster::MonsterColPrint()
{
	for (short i = 0; i < 18; i++)
	{
		for (short j = 0; j < 40; j++)
		{
			COORD Pos = { static_cast<short>(MonsterColPos.X) + j, static_cast<short>(MonsterColPos.Y) + i };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
			switch (MonsterColArr[i][j])
			{
			case '8':
				Handle.TextColor(15, 15);
				std::cout << "■";
				break;
			}
		}
		Handle.TextColor(0, 0);
		std::cout << std::endl;
	}
}

void Monster::MoveMonster(int _X, int _Y)
{
	if (PackManScreen::GetMainScreen().CanMove(_X, _Y))
	{
		DrawChar(MonsterPos.X, MonsterPos.Y, MonsterPreveArr);

		MonsterPos.X = _X;
		MonsterPos.Y = _Y;
		MonsterColPos.X = _X - 14;
		MonsterColPos.Y = _Y - 8;
	}
	else
	{
		GameEngineRandom Rand;
		Dir = Rand.RandNum(0, 3);
	}
}

void Monster::FindMonsterToPlayer(Player* _Player)
{
	Path = AStar.FindPath(MonsterPos, _Player->GetPos());
	IndexCount = 2;
}

void Monster::MoveMonsterToPlayer()
{
	if (Path.size() > 1)
	{
		if (IndexCount > Path.size())
		{
			return;
		}
		/*if (PackManScreen::GetMainScreen().CheckMonsterCollision())
		{
			MonsterPrevePrint(PrevePos.X, PrevePos.Y);
			SetPos(PrevePos);
			return;
		}*/
		const size_t HomeIndex = Path.size() - (IndexCount - 1);
		PrevePos = Path[HomeIndex];
		int2 NextPos = { Path[Path.size() - IndexCount].X - PrevePos.X, Path[Path.size() - IndexCount].Y - PrevePos.Y };

		/*if (PackManScreen::GetMainScreen().CheckMonsterCollision())
		{
			return;
		}*/
		MonsterPrevePrint(MonsterPos.X, MonsterPos.Y);
		SetPos(Path[Path.size() - IndexCount++]);
	}
}

void Monster::DrawChar(short _X, short _Y, const char C[YSize][XSize])
{
	for (short i = 0; i < YSize; i++)
	{
		for (short j = 0; j < XSize - 1; j++)
		{
			COORD Pos = { _X + j, _Y + i};
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
			switch (C[i][j])
			{
			case '4':
				Handle.TextColor(FontColor, BackColor);
				std::cout << "■";
				break;
			case '5':
				Handle.TextColor(0, 12);
				std::cout << "■";
				break;
			default:
				Handle.TextColor(0, 0);
				std::cout << " ";
				break;
			}
		}
		Handle.TextColor(0, 0);
		std::cout << std::endl;
	}
}

void Monster::MonsterPrevePrint(int _X, int _Y)
{
	DrawChar(MonsterPos.X, MonsterPos.Y, MonsterPreveArr);

	MonsterPos.X = _X;
	MonsterPos.Y = _Y;
	MonsterColPos.X = _X - 14;
	MonsterColPos.Y = _Y - 8;
}

void Monster::MonsterReset()
{
	DrawChar(MonsterPos.X, MonsterPos.Y, MonsterPreveArr);
	MonsterPos = InitMonsterPos;
	MonsterColPos = MonsterPos;
}