#include "Util.h"

#define Up 72
#define Down 80
#define Left 75
#define Right 77
#define Enter 13 

#define InterFrame 1000

Util::Util()
{

}

Util::~Util()
{

}

void Util::Gotoxy(short _X, short _Y)
{
	COORD Pos = { _X, _Y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int Util::PrintScreen(int _X, int _Y, std::vector<std::string>& _List)
{
	short X = _X;
	short Y = _Y;

	Util Cursor;
	Cursor.Gotoxy(X, Y);
	for (auto& Num : _List)
	{
		Cursor.Gotoxy(X + 2, Y++);
		std::cout << Num << std::endl;
	}
	Y = _Y;
	Cursor.Gotoxy(X, _Y);
	printf("=>");
	while (true)
	{
		int N = KeyControl();
		switch (N)
		{
		case Up:
			if (Y > _Y)
			{
				Cursor.Gotoxy(X, Y);
				printf("  ");
				Cursor.Gotoxy(X, --Y);
				printf("=>");
			}
			break;
		case Down:
			if (Y < _Y + _List.size() - 1)
			{
				Cursor.Gotoxy(X, Y);
				printf("  ");
				Cursor.Gotoxy(X, ++Y);
				printf("=>");
			}
			break;
		case Enter:
			Cursor.Gotoxy(0, _Y + _List.size());
			if (Y == _Y)
			{
				std::cout << "선택..." << std::endl;
				return 0;
			}
			if (Y == _Y + 1)
			{
				std::cout << "선택..." << std::endl;
				return 1;
			}
			if (Y == _Y + 2)
			{
				return 2;
			}
		}
	}
	return 0;
}


int Util::KeyControl()
{
	char Ch;

	Ch = _getch();

	switch (Ch)
	{
	case Up:
		return Up;
	case Down:
		return Down;
	case Right:
		return Right;
	case Left:
		return Left;
	case Enter:
		return Enter;
	default:
		return NULL;
		break;
	}
}
