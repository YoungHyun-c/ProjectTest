#include "Player.h"

#include <conio.h>
#include <Windows.h>
#include "PackManScreen.h"
#include "GameObjectManager.h"
#include "GameEnum.h"
#include "Item.h"

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

	Handle.Gotoxy(45, 47);
	std::cout << "Score : " << PlayerScore;
}

void Player::Update()
{
	PlayerInfoPrint();

	if (_kbhit())
	{
		Key = _getch();
		do { Key = _getch(); } while (Key == 224);
	}

	int2 NextPos = PlayerPos;
	Sleep(Speed); //플레이어 스피드
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
	case PAUSE:
		IsGameUpdate = false;
	case ESC:
		exit(0);
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

	/*if (MonsterCheck(_X, _Y))
	{
		PlayerLifeCount -= 1;

		char ch = _getch();
	}*/
}

bool Player::MonsterCheck(int _X, int _Y)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (PlayerArr2[_Y + i][_X + j] == '4')
			{
				return true;
			}
			if (PlayerArr3[_Y + i][_X + j] == '4')
			{
				return true;
			}
			if (PlayerArr4[_Y + i][_X + j] == '4')
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

void Player::DrawChar(short x, short y, const char c[][XSize])
{
	for (short i = 0; i < YSize; i++)
	{
		for (short j = 0; j < XSize - 1; j++)
		{
			COORD pos = { x + j, y + i};
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			Handle.TextColor(14, 14);
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