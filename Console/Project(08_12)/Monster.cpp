#include "Monster.h"
#include "GameEngineRandom.h"

Monster::~Monster()
{
}

void Monster::Update()
{
	int2 NextPos = MonsterPos;

	switch (Dir)
	{
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

void Monster::MonsterPrint()
{
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

void Monster::MoveMonster(int _X, int _Y)
{
	if (PackManScreen::GetMainScreen().CanMove(_X, _Y))
	{
		DrawChar(MonsterPos.X, MonsterPos.Y, MonsterPreveArr);

		MonsterPos.X = _X;
		MonsterPos.Y = _Y;
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
		if (PackManScreen::GetMainScreen().CheckMonsterCollision());
		PrevePos = Path[Path.size() - (IndexCount - 1)];
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
				std::cout << "бс";
				break;
			case '5':
				Handle.TextColor(0, 12);
				std::cout << "бс";
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
}

void Monster::MonsterReset()
{
	DrawChar(MonsterPos.X, MonsterPos.Y, MonsterPreveArr);
	MonsterPos = InitMonsterPos;
}