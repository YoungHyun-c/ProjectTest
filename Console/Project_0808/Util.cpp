#include "Util.h"

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

