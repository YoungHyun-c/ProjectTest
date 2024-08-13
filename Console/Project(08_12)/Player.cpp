#include "Player.h"

#include "Utill.h"

void Player::PlayerMove()
{
	
	if (0 == _kbhit())
	{
		Sleep(1000);
		return;
	}

	char Ch = _getch();
	int2 NextPos = PlayerPos;

	switch (Ch)
	{
	case 'a':
	case 'A':
		NextPos.X -= 1;
		PlayerPos.X -= 1;
		break;
	case 'd':
	case 'D':
		NextPos.X += 1;
		PlayerPos.X += 1;
		break;
	case 'w':
	case 'W':
		NextPos.Y -= 1;
		PlayerPos.Y -= 1;
		break;
	case 's':
	case 'S':
		NextPos.Y += 1;
		PlayerPos.Y += 1;
		break;
	default:
		break;
	}
}


// 0 Èò 1°Ë 2 ÃÊ 3 ÇÏ´Ã 4 Àû»¡ 5 ¿¬º¸ 6 ¿¬³ë 7 Èò 8 È¸»ö 9 ÆÄ¶û 10 ¿¬µÎ 11 ¿¬ÆÄ 12 »¡ 13 ÇÎÅ© 14³ë¶û 15 Èò
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
					std::cout << "¡á";
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
					std::cout << "¡á";
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