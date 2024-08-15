#include "Player.h"
#include "Utill.h"

#include <conio.h>
#include <Windows.h>
#include "PackManScreen.h"
#include "GameObjectManager.h"
#include "GameEnum.h"
#include "Item.h"

Player::Player()
{
	SetPos(PackManScreen::GetMainScreen().GetScreenSize().Half());
	RenderChar = 'A';
	PreveRenderChar = '0';
}

bool Player::IsGameUpdate = true;

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
	//IsItemCheck();

	if (0 == _kbhit())
	{
		return;
	}

	//if (true == KeyCheck())
	//{

	//}

	char Ch;

	int2 NextPos = PlayerPos;

	do { Ch = _getch();  Dir = Ch; } while (Ch == 224);
	switch (Ch) {
	case LEFT:
		NextPos = Pos;
		NextPos.X -= 1;
		if (false == PackManScreen::GetMainScreen().IsScreenOver(NextPos) && PackManScreen::GetMainScreen().GetScreenCharacter(NextPos) != '1')
		{
			PackManScreen::GetMainScreen().SetScreenCharacter(Pos, PreveRenderChar);
			Pos.X -= 1;
		}
		break;
	case RIGHT:
		NextPos = Pos;
		NextPos.X += 1;
		if (false == PackManScreen::GetMainScreen().IsScreenOver(NextPos) && PackManScreen::GetMainScreen().GetScreenCharacter(NextPos) != '1')
		{
			PackManScreen::GetMainScreen().SetScreenCharacter(Pos, PreveRenderChar);
			Pos.X += 1;
		}
		break;
	case UP:
		NextPos = Pos;
		NextPos.Y -= 1;
		if (false == PackManScreen::GetMainScreen().IsScreenOver(NextPos) && PackManScreen::GetMainScreen().GetScreenCharacter(NextPos) != '1')
		{
			PackManScreen::GetMainScreen().SetScreenCharacter(Pos, PreveRenderChar);
			Pos.Y -= 1;
		}
		break;
	case DOWN:
		NextPos = Pos;
		NextPos.Y += 1;
		if (false == PackManScreen::GetMainScreen().IsScreenOver(NextPos) && PackManScreen::GetMainScreen().GetScreenCharacter(NextPos) != '1')
		{
			PackManScreen::GetMainScreen().SetScreenCharacter(Pos, PreveRenderChar);
			Pos.Y += 1;
		}
		break;
	case PAUSE:
		IsGameUpdate = false;
		//Pause();
		break;
	case ESC:
		exit(0);
	}
	
	// Ch = 0;

	//if (0 != GetAsyncKeyState('A') || 0 != GetAsyncKeyState('a'))
	//{

	//}

	//IsItemCheck();
}


// 0 �� 1�� 2 �� 3 �ϴ� 4 ���� 5 ���� 6 ���� 7 �� 8 ȸ�� 9 �Ķ� 10 ���� 11 ���� 12 �� 13 ��ũ 14��� 15 ��
void Player::PlayerPrint()
{
	Utill UtillMan;
	while (true)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				PlayerArr[i][j] = ' ';
			}
		}
		system("cls");

		{
			PlayerArr[0][1] = '1';
			PlayerArr[0][2] = '1';
			PlayerArr[0][3] = '1';

			PlayerArr[1][0] = '1';
			PlayerArr[1][1] = '1';
			PlayerArr[1][2] = '1';
			PlayerArr[1][3] = '1';
			PlayerArr[1][4] = '1';

			PlayerArr[2][0] = '1';
			PlayerArr[2][1] = '1';
			PlayerArr[2][2] = '1';

			PlayerArr[3][0] = '1';
			PlayerArr[3][1] = '1';
			PlayerArr[3][2] = '1';
			PlayerArr[3][3] = '1';
			PlayerArr[3][4] = '1';

			PlayerArr[4][1] = '1';
			PlayerArr[4][2] = '1';
			PlayerArr[4][3] = '1';
		}

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (PlayerArr[i][j] == '1')
				{
					UtillMan.TextColor(14, 14);
					std::cout << "��";
				}
				else
				{
					std::cout << PlayerArr[i][j];
				}
				UtillMan.TextColor(0, 0);
			}
			std::cout << std::endl;
		}

		Sleep(300);
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				PlayerArr[i][j] = ' ';
			}
		}

		system("cls");

		{
			PlayerArr[0][1] = '1';
			PlayerArr[0][2] = '1';
			PlayerArr[0][3] = '1';
			PlayerArr[0][4] = '1';

			PlayerArr[1][0] = '1';
			PlayerArr[1][1] = '1';
			PlayerArr[1][2] = '1';

			PlayerArr[2][0] = '1';
			PlayerArr[2][1] = '1';

			PlayerArr[3][0] = '1';
			PlayerArr[3][1] = '1';
			PlayerArr[3][2] = '1';

			PlayerArr[4][1] = '1';
			PlayerArr[4][2] = '1';
			PlayerArr[4][3] = '1';
			PlayerArr[4][4] = '1';
		}

		//{

		//		" 000 "
		//		"00000"
		//		"000   "
		//		"00000"
		//		" 000 "

		//		" 0000"
		//		"000  "
		//		"0    "
		//		"000  "
		//		" 0000"

		//}
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (PlayerArr[i][j] == '1')
				{
					UtillMan.TextColor(14, 14);
					std::cout << "��";
				}
				else
				{
					std::cout << PlayerArr[i][j];
				}
				UtillMan.TextColor(0, 0);
			}
			std::cout << std::endl;
		}

		Sleep(300);
	}
}


//{
//	{
//		PlayerArr[0][2] = '1';
//		PlayerArr[0][3] = '1';
//		PlayerArr[0][4] = '1';
//
//		PlayerArr[1][1] = '1';
//		PlayerArr[1][2] = '1';
//		PlayerArr[1][3] = '1';
//		PlayerArr[1][4] = '1';
//		PlayerArr[1][5] = '1';
//		PlayerArr[1][6] = '1';
//
//		PlayerArr[2][0] = '1';
//		PlayerArr[2][1] = '1';
//		PlayerArr[2][2] = '1';
//		PlayerArr[2][3] = '1';
//
//		PlayerArr[3][1] = '1';
//		PlayerArr[3][2] = '1';
//		PlayerArr[3][3] = '1';
//		PlayerArr[3][4] = '1';
//		PlayerArr[3][5] = '1';
//		PlayerArr[3][6] = '1';
//
//		PlayerArr[4][2] = '1';
//		PlayerArr[4][3] = '1';
//		PlayerArr[4][4] = '1';
//	}
//
//	{
//		PlayerArr[0][3] = '1';
//		PlayerArr[0][4] = '1';
//		PlayerArr[0][5] = '1';
//		PlayerArr[0][6] = '1';
//
//		PlayerArr[1][1] = '1';
//		PlayerArr[1][2] = '1';
//		PlayerArr[1][3] = '1';
//		PlayerArr[1][4] = '1';
//
//		PlayerArr[2][0] = '1';
//		PlayerArr[2][1] = '1';
//		PlayerArr[2][2] = '1';
//
//		PlayerArr[3][1] = '1';
//		PlayerArr[3][2] = '1';
//		PlayerArr[3][3] = '1';
//		PlayerArr[3][4] = '1';
//
//		PlayerArr[4][3] = '1';
//		PlayerArr[4][4] = '1';
//		PlayerArr[4][5] = '1';
//		PlayerArr[4][6] = '1';
//	}
//}

