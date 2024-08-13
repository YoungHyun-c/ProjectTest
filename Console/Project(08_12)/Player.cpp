#include "Player.h"

#include "Utill.h"

// 0 흰 1검 2 초 3 하늘 4 적빨 5 연보 6 연노 7 흰 8 회색 9 파랑 10 연두 11 연파 12 빨 13 핑크 14노랑 15 흰

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
					std::cout << "■";
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
					std::cout << "■";
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