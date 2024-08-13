#include "Monster.h"


Monster::~Monster()
{
	if (UtillMan != nullptr)
	{
		delete UtillMan;
		UtillMan = nullptr;
	}
}


void Monster::MonsterPrint()
{
	UtillMan;
	while (true)
	{
		MonsterArr[4][2] = '2';
		MonsterArr[4][1] = ' ';
		MonsterArr[4][3] = ' ';

		system("cls");

		MonsterColor(FontColor, BackColor);

		Sleep(300);

		system("cls");
		MonsterArr[4][2] = ' ';
		MonsterArr[4][1] = '2';
		MonsterArr[4][3] = '2';

		MonsterColor(FontColor, BackColor);
		Sleep(300);
	}
}

void Monster::MonsterColor(int _Font, int _Back)
{

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			switch (MonsterArr[i][j])
			{
			case '2':
				UtillMan->TextColor(_Font, _Back);
				std::cout << "бс";
				break;
			case '3':
				UtillMan->TextColor(15, 15);
				std::cout << "бс";
				break;
			case '4':
				UtillMan->TextColor(0, 0);
				std::cout << "бс";
				break;
			default:
				UtillMan->TextColor(0, 0);
				std::cout << " ";
				break;
			}
		}
		UtillMan->TextColor(0, 0);
		std::cout << std::endl;
	}
}


/*{
	" 222 "
	"23332"
	"23432"
	"22222"
	"22 22"

	" 222 "
	"23432"

}*/
/*{
			MonsterArr[0][1] = '2';
			MonsterArr[0][2] = '2';
			MonsterArr[0][3] = '2';

			MonsterArr[1][0] = '2';
			MonsterArr[1][1] = '3';
			MonsterArr[1][2] = '3';
			MonsterArr[1][3] = '3';
			MonsterArr[1][4] = '2';

			MonsterArr[2][0] = '2';
			MonsterArr[2][1] = '3';
			MonsterArr[2][2] = '4';
			MonsterArr[2][3] = '3';
			MonsterArr[2][4] = '2';

			MonsterArr[3][0] = '2';
			MonsterArr[3][1] = '2';
			MonsterArr[3][2] = '2';
			MonsterArr[3][3] = '2';
			MonsterArr[3][4] = '2';

			MonsterArr[4][0] = '2';
			MonsterArr[4][1] = '2';
			MonsterArr[4][3] = '2';
			MonsterArr[4][4] = '2';
		}*/