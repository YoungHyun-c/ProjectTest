#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#include <Windows.h>
#include <conio.h>

struct int2
{
public:
	int X = 0;
	int Y = 0;

	int2(int _X, int _Y)
		: X(_X), Y(_Y)
	{
	}
};

struct SlideGame
{
private:
	SlideGame()
	{
	}
	static SlideGame MainScreen;

public:
	static SlideGame& GetMainScreen()
	{
		return MainScreen;
	}

public:
	static const int ScreenXSize = 5;
	static const int ScreenYSize = 5;
	std::string SaveString = "";

	static int2 GetScreenSize()
	{
		return int2(ScreenXSize, ScreenYSize);
	}

	void Swap(int2 _CurPos, int2 _Pos);
	void SlideMade();
	void SlidePrint();

	bool IsScreenOver(const int2& _Pos) const;
	void SetScreenCharacter(const int2& _Pos, std::string _Str);

private:
	std::string Slide[ScreenYSize][ScreenXSize] = {" "};
};

SlideGame SlideGame::MainScreen;

void SlideGame::SlideMade()
{
	for (size_t y = 0; y < ScreenYSize; y++)
	{
		for (size_t x = 0; x < ScreenXSize; x++)
		{
			Slide[y][x] = std::to_string((y * 5) + (x + 1));
		}
	}

	std::random_device Rd;
	std::mt19937 Gen(Rd());
	std::uniform_int_distribution<> Dist(0, 4);

	int Sour, Dest;
	std::string Temp;
	for (int i = 0; i < 100; i++)
	{
		Dest = Dist(Gen);
		Sour = Dist(Gen);

		Temp = Slide[Dest][Sour];
		Slide[Dest][Sour] = Slide[Sour][Dest];
		Slide[Sour][Dest] = Temp;
	}

	Slide[4][4] = " ";
}

void SlideGame::Swap(int2 _CurPos, int2 _Pos)
{
	std::string Temp;
	Temp = Slide[_CurPos.Y][_CurPos.X];

	Slide[_CurPos.Y][_CurPos.X] =  Slide[_Pos.Y][_Pos.X];
	Slide[_Pos.Y][_Pos.X] = Temp;
}

void SlideGame::SlidePrint()
{
	for (size_t y = 0; y < ScreenYSize; y++)
	{
		for (size_t x = 0; x < ScreenXSize; x++)
		{
			std::cout.width(2);
			std::cout << std::right << Slide[y][x] << " ";
		}
		std::cout << std::endl;
	}
}

bool SlideGame::IsScreenOver(const int2& _Pos) const
{
	if (0 > _Pos.X)
	{
		return true;
	}

	if (0 > _Pos.Y)
	{
		return true;
	}

	if (ScreenXSize <= _Pos.X)
	{
		return true;
	}

	if (ScreenYSize <= _Pos.Y)
	{
		return true;
	}

	return false;
}

void SlideGame::SetScreenCharacter(const int2& _Pos, std::string _Str)
{
	if (true == IsScreenOver(_Pos))
	{
		return;
	}

	Slide[_Pos.Y][_Pos.X] = _Str;
}

struct Player
{
public:
	Player()
	{
	}

	int2 GetPos() const
	{
		return Pos;
	}
	
	void SetPos(const int2& _Pos)
	{
		Pos = _Pos;
	}


	void Move(SlideGame& _Screen)
	{
		char Ch = _getch();
		int2 NextPos = { 0, 0 };
		int2 CurPos = GetPos();
		std::string PreStr = SlideGame::GetMainScreen().SaveString;
		
		switch (Ch)
		{
		case 'a':
		case 'A':
			NextPos = Pos;
			NextPos.X -= 1;
			if (false == SlideGame::GetMainScreen().IsScreenOver(NextPos))
			{
				SlideGame::GetMainScreen().Swap(CurPos, { Pos.X -= 1, Pos.Y });
			}
			break;
		case 'd':
		case 'D':
			NextPos = Pos;
			NextPos.X += 1;
			if (false == SlideGame::GetMainScreen().IsScreenOver(NextPos))
			{
				SlideGame::GetMainScreen().Swap(CurPos, { Pos.X += 1, Pos.Y });
			}
			break;
		case 'w':
		case 'W':
			NextPos = Pos;
			NextPos.Y -= 1;
			if (false == SlideGame::GetMainScreen().IsScreenOver(NextPos))
			{
				SlideGame::GetMainScreen().Swap(CurPos, { Pos.X, Pos.Y -= 1 });
			}
			break;
		case 's':
		case 'S':
			NextPos = Pos;
			NextPos.Y += 1;
			if (false == SlideGame::GetMainScreen().IsScreenOver(NextPos))
			{
				SlideGame::GetMainScreen().Swap(CurPos, { Pos.X, Pos.Y += 1 });
			}
			break;
		default:
			break;
		}

		Sleep(InterFrame);
	}

private:
	static const int InterFrame = 100;

	int2 Pos = int2(4, 4);
};

int main()
{
	Player GamePlayer;

	GamePlayer.SetPos({ 4, 4 });
	SlideGame::GetMainScreen().SlideMade();
	SlideGame::GetMainScreen().SetScreenCharacter(GamePlayer.GetPos(), " ");

	while (true)
	{
		system("cls");

		GamePlayer.GetPos();

		SlideGame::GetMainScreen().SlidePrint();
		GamePlayer.Move(SlideGame::GetMainScreen());
	}


	return 0;
}