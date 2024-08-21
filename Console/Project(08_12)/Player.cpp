#include "Player.h"

#include "PackManScreen.h"
#include "Item.h"
#include "GameEnum.h"

bool Player::IsGameUpdate = true;

Player::Player()
{
	// SetPos(PackManScreen::GetMainScreen().GetScreenSize().Half());
}

bool Player::IsItemCheck()
{
	std::list<ConsoleGameObject*>& ItemGroup
		= GameObjectManager::GetGroup(ObjectOrder::Item);

	for (ConsoleGameObject* Ptr : ItemGroup)
	{
		if (nullptr == Ptr)
		{
			continue;
		}

		int2 ItemPos = Ptr->GetPos();
		if (GetPos() == ItemPos)
		{
			Ptr->Death();
			return true;
		}
	}
	return false;
}

void Player::PlayerInfoPrint()
{
	Handle.Gotoxy(0, 47);
	Handle.TextColor(15, 0);
	std::cout << "Life : " << PlayerLifeCount;

	Handle.Gotoxy(15, 47);
	std::cout << "Score : " << PlayerScore;

	Handle.Gotoxy(30, 47);
	std::cout << "플레이어스피드 : " << 210 - PlayerSpeed ;

	Handle.Gotoxy(55, 47);
	switch (State)
	{
	case PlayerState::Normal:
		std::cout << "플레이어 상태 : 노말                         ";
		break;
	case PlayerState::Attacker:
		std::cout << "플레이어 상태 : 공격 !!";
		break;
	case PlayerState::Max:
		std::cout << "플레이어 상태 : Zzz                          ";
		break;
	}
}

void Player::ChangeState(PlayerState _State)
{
	if (_State != State)
	{
		switch (_State)
		{
		case PlayerState::Normal:
			NormalStart();
			break;
		case PlayerState::Attacker:
			AttackStart();
			break;
		case PlayerState::Max:
		default:
			break;
		}
	}
	State = _State;
}

void Player::StateUpdate()
{
	switch (State)
	{
	case PlayerState::Normal:
		return NormalUpdate();
	case PlayerState::Attacker:
		return AttackUpdate();
	case PlayerState::Max:
	default:
		break;
	}
}

void Player::Update()
{
	PlayerInfoPrint();

	StateUpdate();

	if (_kbhit())
	{
		do { Key = _getch(); }
		while (Key == 224);
	}

	int2 NextPos = PlayerPos;
	Sleep(PlayerSpeed); //플레이어 스피드
	Dir = Key;
	switch (Dir) {
	case LEFT:
		NextPos = PlayerPos;
		NextPos.X -= 1;
		MovePlayer(NextPos.X, NextPos.Y);
		break;
	case RIGHT:
		NextPos = PlayerPos;
		NextPos.X += 1;
		MovePlayer(NextPos.X, NextPos.Y);
		break;
	case UP:
		NextPos = PlayerPos;
		NextPos.Y -= 1;
		MovePlayer(NextPos.X, NextPos.Y);
		break;
	case DOWN:
		NextPos = PlayerPos;
		NextPos.Y += 1;
		MovePlayer(NextPos.X, NextPos.Y);
		break;
	}
}

void Player::NormalStart()
{
	
}

void Player::NormalUpdate()
{
	
}

const std::chrono::milliseconds Player::Attackker(6000);
void Player::AttackStart()
{
	AttackTime = std::chrono::steady_clock::now();
	AttackEndTime = AttackTime + Attackker;
}
void Player::AttackUpdate()
{
	auto CurrentTime = std::chrono::steady_clock::now();
	auto Check = CurrentTime - AttackTime;
	if (CurrentTime - AttackTime >= Attackker)
	{
		AttackTime = CurrentTime;
		ChangeState(PlayerState::Normal);
		return;
	}
	else
	{
		auto Now = std::chrono::steady_clock::now();
		auto RemainTime = std::chrono::duration_cast<std::chrono::seconds>(AttackEndTime - Now).count();

		Handle.Gotoxy(75, 47);
		std::cout << " 남은 시간 : " << RemainTime << " 초";
	}
	
	if (Dir == LEFT || Dir == RIGHT)
	{
		if (Dir == LEFT && LRReverse == true)
		{
			FlipHorizontally(PlayerArr1);
			FlipHorizontally(PlayerArr2);
			LRReverse = false;
		}
		if (Dir == RIGHT && LRReverse == false)
		{
			FlipHorizontally(PlayerArr1);
			FlipHorizontally(PlayerArr2);
			LRReverse = true;
		}
		if (CheckTime < 0.3)
		{
			DrawChar(PlayerPos.X, PlayerPos.Y, PlayerArr1, 12, 12);
		}
		if (CheckTime >= 0.3)
		{
			DrawChar(PlayerPos.X, PlayerPos.Y, PlayerArr2, 12, 12);
			start = clock();
		}
	}

	if (Dir == UP || Dir == DOWN)
	{
		if (Dir == UP && UDReverse == false)
		{
			FlipVertically(PlayerArr3);
			FlipVertically(PlayerArr4);
			UDReverse = true;
		}if (Dir == DOWN && UDReverse == true)
		{
			FlipVertically(PlayerArr3);
			FlipVertically(PlayerArr4);
			UDReverse = false;
		}
		if (CheckTime < 0.3)
		{
			DrawChar(PlayerPos.X, PlayerPos.Y, PlayerArr3, 12, 12);
		}
		if (CheckTime >= 0.3)
		{
			DrawChar(PlayerPos.X, PlayerPos.Y, PlayerArr4, 12, 12);
			start = clock();
		}
	}
}


void Player::MovePlayer(int _X, int _Y)
{
	if (PackManScreen::GetMainScreen().CanMove(_X, _Y))
	{
		DrawChar(PlayerPos.X, PlayerPos.Y, PlayerPreveArr);

		PlayerPos.X = _X;
		PlayerPos.Y = _Y;
	}
}

bool Player::MonsterCheck(int _X, int _Y)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (PlayerArr2[_Y + i][_X + j] == '5')
			{
				return true;
			}
			if (PlayerArr3[_Y + i][_X + j] == '5')
			{
				return true;
			}
			if (PlayerArr4[_Y + i][_X + j] == '5')
			{
				return true;
			}
		}
	}

	return false;
}

void Player::PlayerPrint()
{
	end = clock();
	CheckTime = double(end - start) / CLOCKS_PER_SEC;
	if (Dir == LEFT || Dir == RIGHT)
	{
		if (Dir == LEFT && LRReverse == true)
		{
			FlipHorizontally(PlayerArr1);
			FlipHorizontally(PlayerArr2);
			LRReverse = false;
		}
		if (Dir == RIGHT && LRReverse == false)
		{
			FlipHorizontally(PlayerArr1);
			FlipHorizontally(PlayerArr2);
			LRReverse = true;
		}
		if (CheckTime < 0.3)
		{
			DrawChar(PlayerPos.X, PlayerPos.Y, PlayerArr1);
		}
		if (CheckTime >= 0.3)
		{
			DrawChar(PlayerPos.X, PlayerPos.Y, PlayerArr2);
			start = clock();
		}
	}

	if (Dir == UP || Dir == DOWN)
	{
		if (Dir == UP && UDReverse == false)
		{
			FlipVertically(PlayerArr3);
			FlipVertically(PlayerArr4);
			UDReverse = true;
		}if (Dir == DOWN && UDReverse == true)
		{
			FlipVertically(PlayerArr3);
			FlipVertically(PlayerArr4);
			UDReverse = false;
		}
		if (CheckTime < 0.3)
		{
			DrawChar(PlayerPos.X, PlayerPos.Y, PlayerArr3);
		}
		if (CheckTime >= 0.3)
		{
			DrawChar(PlayerPos.X, PlayerPos.Y, PlayerArr4);
			start = clock();
		}
	}
}

void Player::DrawChar(short x, short y, const char c[][XSize], int _Font, int _Back)
{
	for (short i = 0; i < YSize; i++)
	{
		for (short j = 0; j < XSize - 1; j++)
		{
			COORD pos = { x + j, y + i};
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			Handle.TextColor(_Font, _Back);
			if (c[i][j] == '2')
			{
				std::cout << "■";
			}
			if (c[i][j] == '3')
			{
				Handle.TextColor(12, 14);
				std::cout << "◆";
			}
			if (c[i][j] == ' ')
			{
				Handle.TextColor(0, 0);
				std::cout << " ";
			}
		}
		Handle.TextColor(0, 0);
		std::cout << std::endl;
	}
}

void Player::PlayerReset()
{
	DrawChar(PlayerPos.X, PlayerPos.Y, PlayerPreveArr);
	PlayerPos = InitPlayerPos;
	
}