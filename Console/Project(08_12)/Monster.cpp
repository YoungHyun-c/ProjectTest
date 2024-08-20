#include "Monster.h"

Monster::~Monster()
{
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

//void Monster::MonsterColor(int _Font, int _Back, char M[YSize][XSize])
//{
//	for (int i = 0; i < YSize; i++)
//	{
//		for (int j = 0; j < XSize - 1; j++)
//		{
//			switch (M[i][j])
//			{
//			case '4':
//				Handle.TextColor(_Font, _Back);
//				std::cout << "бс";
//				break;
//			case '5':
//				Handle.TextColor(0, 0);
//				std::cout << "бс";
//				break;
//			default:
//				Handle.TextColor(0, 0);
//				std::cout << " ";
//				break;
//			}
//		}
//		Handle.TextColor(0, 0);
//		std::cout << std::endl;
//	}
//}
