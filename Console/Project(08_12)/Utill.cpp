#include "Utill.h"

#define Up 72
#define Down 80
#define Left 75
#define Right 77
#define Enter 13 

#define InterFrame 1000

Utill::Utill()
{

}

Utill::~Utill()
{

}

void Utill::Gotoxy(short _X, short _Y)
{
	COORD Pos = { _X, _Y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

// 0 �� 1�� 2 �� 3 �ϴ� 4 ���� 5 ���� 6 ���� 7 �� 8 ȸ�� 9 �Ķ� 10 ���� 11 ���� 12 �� 13 ��ũ 14��� 15 ��
void Utill::TextColor(int _Font, int _BackGround)
{
	int Color = _Font + _BackGround * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}

int Utill::PrintScreen(int _X, int _Y, std::vector<std::string>& _List)
{
	short X = _X;
	short Y = _Y;

	Utill Cursor;
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
			Cursor.Gotoxy(0, _Y + static_cast<short>(_List.size()));
			return Y - _Y;
		}
	}
	return 0;
}


int Utill::KeyControl()
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
