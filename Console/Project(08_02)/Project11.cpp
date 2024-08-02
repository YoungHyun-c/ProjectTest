#include <iostream>
#include <Windows.h>
#include <random>
#include <algorithm>
#include <string>
#include <conio.h>

#pragma region 1.슬라이드
class int2
{
public:
	int X;
	int Y;

	int2(int _X, int _Y)
		: X(_X), Y(_Y)
	{
	}
};
class RandNum
{
public:
	int RandomNum(const int _Start, const int _End)
	{
		std::random_device Ren;
		std::mt19937 Mt(Ren());
		std::uniform_int_distribution<int> Dist(_Start, _End);

		return Dist(Mt);
	}
};

class SlideGame
{
public:
	SlideGame()
	{
	}

	static SlideGame& GetSlideScreen()
	{
		return MainScreen;
	}
	const int2 GetScreenSize()
	{
		return int2{ YScreenSize, XScreenSize };
	}

	bool IsScreenOver(const int2& _Pos) const;

	void Swap(int2 _CurPos, int2 _Pos);

	void const MadeSlide();
	void const PrintSlide();
	void const SetPlayerCharacter(int2 _Pos, std::string _Str);

	bool const WinSlide();

private:
	static const int XScreenSize = 6;
	static const int YScreenSize = 6;
	std::string Slide[YScreenSize][XScreenSize];

	static SlideGame MainScreen;
};

SlideGame SlideGame::MainScreen;

class Player
{
public:
	
	void Move(SlideGame& _Screen)
	{
		char Ch = _getch();


		int2 NextPos = PlayerPos;
		int2 CurPos = GetPos();

		switch (Ch)
		{
		case 'a':
		case 'A':
			NextPos.X -= 1;
			if (SlideGame::GetSlideScreen().IsScreenOver(NextPos) == false)
			{
				SlideGame::GetSlideScreen().Swap(CurPos, {PlayerPos.X -=1 , PlayerPos.Y});
			}
			break;
		case 'd':
		case 'D':
			NextPos.X += 1;
			if (SlideGame::GetSlideScreen().IsScreenOver(NextPos) == false)
			{
				SlideGame::GetSlideScreen().Swap(CurPos, { PlayerPos.X += 1 , PlayerPos.Y });
			}
			break;
		case 'w':
		case 'W':
			NextPos.Y -= 1;
			if (_Screen.GetSlideScreen().IsScreenOver(NextPos) == false)
			{
				_Screen.GetSlideScreen().Swap(CurPos, { PlayerPos.X , PlayerPos.Y -= 1 });
			}
			break;
		case 's':
		case 'S':
			NextPos.Y += 1;
			if (_Screen.GetSlideScreen().IsScreenOver(NextPos) == false)
			{
				_Screen.GetSlideScreen().Swap(CurPos, { PlayerPos.X, PlayerPos.Y += 1 });
			}
			break;
		default:
			break;
		}
		Sleep(InterFrame);
	}

	void SetPlayerPos(int2 _Pos)
	{
		PlayerPos.X = _Pos.X;
		PlayerPos.Y = _Pos.Y;
	}

	int2 GetPos()
	{
		return PlayerPos;
	}


private:
	int2 PlayerPos = { 0, 0 };
	static const int InterFrame = 100;
};
#pragma endregion


#pragma region 대전게임
class RandNumber
{
	const int RandomNum(const int _Start, const int _End)
	{
		std::random_device Ren;
		std::mt19937 Mt(Ren());
		std::uniform_int_distribution<int> Dist(_Start, _End);

		return Dist(Mt);
	}
};

class BattleGame
{
public:

private:

};

class Player
{
public:
	Player(int _Hp, int _Atk, int _Def)
		: pHp(_Hp), pAtk(_Atk), pDef(_Def)
	{
	}

private:
	int pHp = 0;
	int pAtk = 0;
	int pDef = 0;
};

class Monster
{
public:


private:
	int mHp = 0;
	int mAtk = 0;
	int mDef = 0;
};


#pragma endregion


int main()
{
	// 슬라이드 게임 클래스로 만들기
	/*{
		SlideGame::GetSlideScreen().MadeSlide();
		Player SPlayer;
		SPlayer.SetPlayerPos({ 4,4 });
		SlideGame::GetSlideScreen().SetPlayerCharacter(SPlayer.GetPos(), " ");
		while (true)
		{
			system("cls");

			SlideGame::GetSlideScreen().PrintSlide();
			if (true == SlideGame::GetSlideScreen().WinSlide())
			{
				break;
			}
			
			SPlayer.Move(SlideGame::GetSlideScreen());
		}
	}*/

	// 대전게임 클래스로 만들기
	{
		RandNumber Random;
		int PlayerHp, PlayerAtk, PlayerDef;
		//Player pPlayer(PlayerHp, PlayerAtk, PlayerDef);


	}



	return 0;
}





void SlideGame::Swap(int2 _CurPos, int2 _Pos)
{
	std::string Temp = Slide[_CurPos.Y][_CurPos.X];
	Slide[_CurPos.Y][_CurPos.X] = Slide[_Pos.Y][_Pos.X];
	Slide[_Pos.Y][_Pos.X] = Temp;
}
void const SlideGame::MadeSlide()
{
	for (int Y = 0; Y < YScreenSize; Y++)
	{
		for (int X = 0; X < XScreenSize; X++)
		{
			Slide[Y][X] = std::to_string((Y * 5) + X + 1);
		}
	}

	RandNum Rand;
	int X = 0, Y = 0;

	std::string Temp = "";

	for (int i = 0; i < 100; i++)
	{
		Y = Rand.RandomNum(0, YScreenSize - 1);
		X = Rand.RandomNum(0, XScreenSize - 1);
		Temp = Slide[Y][X];
		Slide[Y][X] = Slide[X][Y];
		Slide[X][Y] = Temp;
	}

}
void const SlideGame::PrintSlide()
{
	for (int Y = 0; Y < YScreenSize; Y++)
	{
		for (int X = 0; X < XScreenSize; X++)
		{
			std::cout.width(2);
			std::cout << std::right << Slide[Y][X] << " ";
		}
		std::cout << std::endl;
	}
}
void const SlideGame::SetPlayerCharacter(int2 _Pos, std::string _Str)
{
	if (true == IsScreenOver(_Pos))
	{
		return;
	}

	Slide[_Pos.Y][_Pos.X] = _Str;
}

bool SlideGame::IsScreenOver(const int2& _Pos) const 
{
	if (_Pos.X < 0)
	{
		return true;
	}

	if (_Pos.Y < 0)
	{
		return true;
	}

	if (_Pos.X >= XScreenSize)
	{
		return true;
	}

	if (_Pos.Y >= YScreenSize)
	{
		return true;
	}

	return false;
}

bool const SlideGame::WinSlide()
{
	for (int i = 0; i < XScreenSize - 1; i++)
	{
		if (Slide[0][i] != std::to_string(i + 1))
		{
			return false;
		}
	}
	std::cout << "당신이 이겼습니다!" << std::endl;
	return true;
}