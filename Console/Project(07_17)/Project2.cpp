#include <iostream>
#include <time.h>

#include <Windows.h>
// ���� 1
// 0 �� 1�� 2 �� 3 �ϴ� 4 ���� 5 ���� 6 ���� 7 �� 8 ȸ�� 9 �Ķ� 10 ���� 11 ���� 12 �� 13 ��ũ 14��� 15 ��
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
		std::cout << "��";
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
	int y = 2; // ù°��
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

	// ��
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


	// ��
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

	// ������
	x = 21; y = 18;
	ChangeBlackColor();
	Gotoxy(x, y);
	x = 28; y = 18;
	ChangeBlackColor();
	Gotoxy(x, y);

	// ��
	x = 24; y = 20;
	ChangeBlackColor();
	Gotoxy(x++, y); Gotoxy(x, y);


	// ��Ÿ��
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
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;

	BadgeDot();
}

// ���� 2
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

	printf("========================����==============================================\n");
	printf("   ����		|	������	 |	 ����	|	Ư��		 |\n");
	printf("1. ��		|	%5d	 |	%5d��	| ������ �ֵθ� �� �ִ�. | \n", SwordDam, SwordPrice);
	printf("2. ����		|	%5d	 |	%5d��	| ��� ������ �����ϴ�.	 |\n", ExeDam, ExePrice);
	printf("3. ������	|	%5d	 |	%5d��	| ��Ź�� �Ҹ��� ����. 	 |\n", ClubDam,	 ClubPrice);
	printf("4. ���		|	%5d	 |	%5d��	| ���� ������ �� �� �ִ�.|\n", BigSwordDam, BigSwordPrice);
	printf("5. ������	|	%5d	 |	%5d��	| ������ų�� ����.	 |\n", StaffDam, StaffPrice);
}
void WeaponShieldDot()
{
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "|           �ܡܡܡܡܡܡ�       |                            |" << std::endl;
	std::cout << "|         �ܡܡ�      �ܡ�     |       ��������������        |" << std::endl;
	std::cout << "|        �ܡܡܡ�  �ܡܡ�  �ܡ�    |       ��������������        |" << std::endl;
	std::cout << "|         �ܡܡ�   �ܡ� �ܡ�     |       ��������������        |" << std::endl;
	std::cout << "|          �ܡܡܡ�  �ܡ�       |       ��������������        |" << std::endl;
	std::cout << "|           �ܡ�            |        ������������         |" << std::endl;
	std::cout << "|           �ܡ�            |         ����������          |" << std::endl;
	std::cout << "|           �ܡ�            |          ��������           |" << std::endl;
	std::cout << "|           �ܡ�            |            ����             |" << std::endl;
	std::cout << "|           �ܡ�            |             ��              |" << std::endl;
	std::cout << "|           �ܡ�            |                            |" << std::endl;
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

	printf("========================��==============================================\n");
	printf("   ����		|	���� 	 |	 ����	|	Ư��		 | \n");
	printf("1. ����		|	 %4d	 |	%5d��	| ������ ���� �� �ִ�.   |\n", ShieldValue, ShieldPrice);
	printf("2. ����		|	 %4d	 |	%5d��	| ��� �ɷ��� ����.  |\n", ArmorShield, ArmorPrice);
	printf("3. ����		|	 %4d	 |	%5d��	| ������ ������ �� �ִ�. |\n", BootsShield, BootsPrice);
	printf("4. �尩		|	 %4d	 |	%5d��	| ���⸦ ������ �ֵθ���.|\n", GloveShield, GlovePrice);
	printf("5. ����		|	 %4d	 |	%5d��	| ������ų�� ��������.   |\n", HelmetShield, HelmetPrice);

}

void Project2()
{
	srand(time(NULL));
	Weapon();
	WeaponShieldDot();
	printf("\n");
	Armor();
}

// ���� 3
void Random(int _SValue, int _EValue)
{
	srand(time(NULL));
	int SubValue = _EValue - _SValue;
	int Random  = rand() % SubValue;
	int RandomResult = _SValue + Random;
	
	printf("%d ~ %d ������ ���� ���� : %d \n", _SValue, _EValue, RandomResult);
}

void Project3()
{
	// 1
	// 1 ~ 5 ����
	{
		int SNum = 1, ENum = 5;
		Random(SNum, ENum);
	}
	// 6 ~ 19 ����
	{
		int SNum = 6, Enum = 19;
		Random(SNum, Enum);
	}
	// 23 ~ 189 ����
	{
		int SNum = 23, Enum = 189;
		printf("���� ���� : %d , �� ���� : %d \n", SNum, Enum);
		
		Random(SNum, Enum);
	}


}


int main()
{
	// ���� 1
	//Project1();

	// ���� 2
	Project2();


	// ���� 3
	Project3();

	int a = 0;
}