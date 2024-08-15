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
	SetPos(PackManScreen::GetMainScreen().GetScreenSize().Half());

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

void Player::Update()
{
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
		if (false == PackManScreen::GetMainScreen().IsScreenOver(NextPos) && PackManScreen::GetMainScreen().GetScreenCharacter(NextPos) != '1')
		{
			Handle.TextColor(0, 0);
			DrawChar(PlayerPos.X, PlayerPos.Y, PlayerPreveArr);
			PlayerPos.X -= 1;
		}
		break;
	case RIGHT:
		NextPos = PlayerPos;
		NextPos.X += 1;
		if (false == PackManScreen::GetMainScreen().IsScreenOver(NextPos) && PackManScreen::GetMainScreen().GetScreenCharacter(NextPos) != '1')
		{
			Handle.TextColor(0, 0);
			DrawChar(PlayerPos.X, PlayerPos.Y, PlayerPreveArr);
			PlayerPos.X += 1;
		}
		break;
	case UP:
		NextPos = PlayerPos;
		NextPos.Y -= 1;
		if (false == PackManScreen::GetMainScreen().IsScreenOver(NextPos) && PackManScreen::GetMainScreen().GetScreenCharacter(NextPos) != '1')
		{
			Handle.TextColor(0, 0);
			DrawChar(PlayerPos.X, PlayerPos.Y, PlayerPreveArr);
			PlayerPos.Y -= 1;
		}
		break;
	case DOWN:
		NextPos = PlayerPos;
		NextPos.Y += 1;
		if (false == PackManScreen::GetMainScreen().IsScreenOver(NextPos) && PackManScreen::GetMainScreen().GetScreenCharacter(NextPos) != '1')
		{
			Handle.TextColor(0, 0);
			DrawChar(PlayerPos.X, PlayerPos.Y, PlayerPreveArr);
			PlayerPos.Y += 1;
		}
		break;
	case ESC:
		exit(0);
	}
}

void Player::PlayerPrint()
{
	end = clock();
	Test = double(end - start) / CLOCKS_PER_SEC;
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
		if (Test < 0.3)
		{
			DrawChar(PlayerPos.X, PlayerPos.Y, PlayerArr1);
		}
		if (Test >= 0.3)
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
		if (Test < 0.3)
		{
			DrawChar(PlayerPos.X, PlayerPos.Y, PlayerArr3);
		}
		if (Test >= 0.3)
		{
			DrawChar(PlayerPos.X, PlayerPos.Y, PlayerArr4);
			start = clock();
		}
	}
}

void Player::DrawChar(short x, short y, const char c[][6])
{
	short X = x;
	for (short i = 0; i < YSize; i++)
	{
		for (short j = 0; j < 5; j++)
		{
			COORD pos = { X + j, y + i };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			Handle.TextColor(14, 14);
			if (c[i][j] == '2')
			{
				std::cout << c[i][j];
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