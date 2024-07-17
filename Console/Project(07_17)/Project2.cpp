#include <iostream>
#include <time.h>

#include <Windows.h>
// 과제 1
// 0 흰 1검 2 초 3 하늘 4 적빨 5 연보 6 연노 7 흰 8 회색 9 파랑 10 연두 11 연파 12 빨 13 핑크 14노랑 15 흰
void TextColor(int Font, int BackGround)
{
	int Color = Font + BackGround * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}

void ChangeWhiteColor()
{
	int Color = 15 + 15 * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}
void ChangeRedColor()
{
	int Color = 4 + 4 * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}
void ChangeBlackColor()
{
	int Color = 0 + 0 * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}
void ChangeYellowColor()
{
	int Color = 14 + 14 * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}
void ChangeBlueColor()
{
	int Color = 9 + 9 * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}

void NemoPrint(int _Num = 1)
{
	for (int i = 0; i < _Num; i++)
	{
		std::cout << "■";
	}
}
void Gotoxy(short _X, short _Y)
{
	COORD Pos = { _X, _Y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	NemoPrint();
}

void BadgeDot()
{
	int x = 20;
	int y = 2; // 첫째줄
	ChangeRedColor();
	Gotoxy(x, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x, y);
	y++; // 2
	x = 6; Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x, y);
	x = 19; Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x, y);
	x = 35; Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);

	x = 5; y++; // 3
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); ChangeWhiteColor(); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	ChangeRedColor(); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x, y);
	x = 18; Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	x = 34; Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	ChangeWhiteColor(); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); ChangeRedColor(); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x, y);

	x = 5; y++; // 4
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); ChangeWhiteColor();  Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);  Gotoxy(x++, y); Gotoxy(x++, y);
	ChangeRedColor(); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); ChangeWhiteColor(); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);Gotoxy(x++, y);
	ChangeRedColor(); Gotoxy(x++, y); Gotoxy(x++, y);
	
	x = 5; y++; // 5
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); ChangeWhiteColor(); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	ChangeRedColor(); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	ChangeWhiteColor(); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); ChangeRedColor(); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	x = 5; y++; // 6
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	x = 6; y++; // 7
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); 
	x = 7; y++; // 8
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); 
	x = 7; y++; // 9
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); 

	x = 6; y++; // 10
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	x = 6; y++; // 11
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	x = 6; y++; // 12
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	x = 6; y++; // 13
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	x = 6; y++; // 14
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	x = 6; y++; // 15
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);

	x = 7; y++; // 16
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); 
	x = 8; y++; // 17
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); 

	x = 8; y++; // 18
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); 
	x = 9; y++; // 19
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	x = 2; Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	x = 44;  Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); 

	x = 10; y++; // 20
	Gotoxy(x++, y); Gotoxy(x++, y);  Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); 

	x = 1; Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	x = 43; Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	x = 11; y++; // 21
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);

	x = 1; Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	x = 43;  Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	x = 8; y++; // 22
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); ChangeBlackColor(); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); ChangeRedColor();
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	ChangeBlackColor(); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	ChangeRedColor();  Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	
	x = 2; Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);  Gotoxy(x++, y);
	x = 8; y++; // 23
	Gotoxy(x++, y); Gotoxy(x++, y);
	ChangeBlackColor(); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	ChangeRedColor(); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	ChangeBlackColor(); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	ChangeRedColor(); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);

	x = 3; Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); 
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	x = 8; y++; // 24
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);; Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	ChangeBlackColor(); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);	ChangeRedColor(); Gotoxy(x++, y); Gotoxy(x++, y);
	x = 6; ChangeBlackColor(); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	ChangeRedColor(); Gotoxy(x++, y);

	x = 8; y++; // 25
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);

	x = 9; y++; // 26
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	x = 7; y++; // 27
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);

	// 얼굴
	x = 20, y = 11;
	ChangeYellowColor();
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);

	x = 18; y = 12;
	ChangeYellowColor();
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	x = 17; y++;
	ChangeWhiteColor(); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	x = 20;
	ChangeYellowColor();
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	ChangeWhiteColor();
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);

	x = 16; y++;
	ChangeWhiteColor();
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);

	x = 14; y++;
	ChangeWhiteColor();
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	x = 14; y++;
	ChangeWhiteColor();
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	x = 14; y++;
	ChangeWhiteColor();
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);

	x = 16; y++;
	ChangeWhiteColor();
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	x = 16; y++;
	ChangeWhiteColor();
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);

	x = 18; y++;
	ChangeWhiteColor();
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); 

	x = 20; y++;
	ChangeWhiteColor();
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);


	// 눈
	x = 20; y = 15;
	ChangeRedColor();
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);
	x = 27;
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);

	x = 18; y = 16;
	ChangeRedColor();
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);

	x = 17; y = 17;
	ChangeRedColor();
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);

	// 눈동자
	x = 21; y = 18;
	ChangeBlackColor();
	Gotoxy(x, y);
	x = 28; y = 18;
	ChangeBlackColor();
	Gotoxy(x, y);

	// 입
	x = 24; y = 20;
	ChangeBlackColor();
	Gotoxy(x++, y); Gotoxy(x, y);


	// 넥타이
	x = 23; y = 22;
	ChangeBlueColor();
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);

	x = 22; y = 23;
	Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y); Gotoxy(x++, y);

	x = 21; y = 24;
	Gotoxy(x++, y); Gotoxy(x++, y); 
	x = 27; y = 24;
	Gotoxy(x++, y); Gotoxy(x++, y); 
}

void Project1()
{
	ChangeWhiteColor();
	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;

	BadgeDot();
}

// 과제 2
void Weapon()
{
	int RadomDivide = 30;
	int Rand = rand() % RadomDivide;
	int SwordDam = 200 + Rand, SwordPrice = 500;
	Rand = rand() % RadomDivide;
	int ExeDam = 300 + Rand, ExePrice = 700;
	Rand = rand() % RadomDivide;
	int ClubDam = 400 + Rand, ClubPrice = 1000;
	Rand = rand() % RadomDivide;
	int StaffDam = 800 + Rand, StaffPrice = 2000;
	Rand = rand() % RadomDivide;
	int BigSwordDam = 1000 + Rand, BigSwordPrice = 1500;

	printf("========================무기==============================================\n");
	printf("   종류		|	데미지	 |	 가격	|	특성		 |\n");
	printf("1. 검		|	%5d	 |	%5d원	| 빠르게 휘두를 수 있다. | \n", SwordDam, SwordPrice);
	printf("2. 도끼		|	%5d	 |	%5d원	| 찍기 공격이 가능하다.	 |\n", ExeDam, ExePrice);
	printf("3. 몽둥이	|	%5d	 |	%5d원	| 둔탁한 소리가 난다. 	 |\n", ClubDam,	 ClubPrice);
	printf("4. 대검		|	%5d	 |	%5d원	| 강한 공격을 할 수 있다.|\n", BigSwordDam, BigSwordPrice);
	printf("5. 지팡이	|	%5d	 |	%5d원	| 마법스킬을 배운다.	 |\n", StaffDam, StaffPrice);
}
void WeaponShieldDot()
{
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "|           ●●●●●●●       |                            |" << std::endl;
	std::cout << "|         ●●●      ●●     |       □■■■■■■■■■■■□        |" << std::endl;
	std::cout << "|        ●●●●  ●●●  ●●    |       ■■□□□□□□□□□■■        |" << std::endl;
	std::cout << "|         ●●●   ●● ●●     |       ■■□□□□□□□□□■■        |" << std::endl;
	std::cout << "|          ●●●●  ●●       |       ■■□□□□□□□□□■■        |" << std::endl;
	std::cout << "|           ●●            |        ■■□□□□□□□■■         |" << std::endl;
	std::cout << "|           ●●            |         ■■□□□□□■■          |" << std::endl;
	std::cout << "|           ●●            |          ■■■■■■■           |" << std::endl;
	std::cout << "|           ●●            |            ■■■             |" << std::endl;
	std::cout << "|           ●●            |             ■              |" << std::endl;
	std::cout << "|           ●●            |                            |" << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl;
}
void Armor()
{
	int RandomDivide = 9;
	int Rand = rand() % RandomDivide;
	int ShieldValue = 33 + Rand, ShieldPrice = 1500;
	Rand = rand() % RandomDivide;
	int ArmorShield = 125 + Rand, ArmorPrice = 700;
	Rand = rand() % RandomDivide;
	int BootsShield = 46 + Rand, BootsPrice = 1000;
	Rand = rand() % RandomDivide;
	int GloveShield = 71 + Rand, GlovePrice = 200;
	Rand = rand() % RandomDivide;
	int HelmetShield = 67 + Rand, HelmetPrice = 500;

	printf("========================방어구==============================================\n");
	printf("   종류		|	방어력 	 |	 가격	|	특성		 | \n");
	printf("1. 방패		|	 %4d	 |	%5d원	| 공격을 막을 수 있다.   |\n", ShieldValue, ShieldPrice);
	printf("2. 갑옷		|	 %4d	 |	%5d원	| 방어 능력이 띄어나다.  |\n", ArmorShield, ArmorPrice);
	printf("3. 부츠		|	 %4d	 |	%5d원	| 빠르게 움직일 수 있다. |\n", BootsShield, BootsPrice);
	printf("4. 장갑		|	 %4d	 |	%5d원	| 무기를 빠르게 휘두른다.|\n", GloveShield, GlovePrice);
	printf("5. 투구		|	 %4d	 |	%5d원	| 마법스킬이 강해진다.   |\n", HelmetShield, HelmetPrice);

}

void Project2()
{
	srand(time(NULL));
	Weapon();
	WeaponShieldDot();
	printf("\n");
	Armor();
}

// 과제 3
void Random(int _SValue, int _EValue)
{
	srand(time(NULL));
	int SubValue = _EValue - _SValue;
	int Random  = rand() % SubValue;
	int RandomResult = _SValue + Random;
	
	printf("%d ~ %d 까지의 랜덤 숫자 : %d \n", _SValue, _EValue, RandomResult);
}

void Project3()
{
	// 1
	// 1 ~ 5 랜덤
	{
		int SNum = 1, ENum = 5;
		Random(SNum, ENum);
	}
	// 6 ~ 19 랜덤
	{
		int SNum = 6, Enum = 19;
		Random(SNum, Enum);
	}
	// 23 ~ 189 랜덤
	{
		int SNum = 23, Enum = 189;
		printf("시작 숫자 : %d , 끝 숫자 : %d \n", SNum, Enum);
		
		Random(SNum, Enum);
	}


}


int main()
{
	// 과제 1
	//Project1();

	// 과제 2
	Project2();


	// 과제 3
	Project3();

	int a = 0;
}