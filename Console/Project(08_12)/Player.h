#pragma once
#include "ConsoleGameObject.h"
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Utill.h"


class Player : public ConsoleGameObject
{
public:
	Player();
	static bool IsGameUpdate;

	void Update() override;
	bool IsItemCheck();

	void PlayerPrint();

	int2 GetPlayerSize() const
	{
		return PlayerSize;
	}

	inline void SetPos(const int2& _Value) override
	{
		PlayerPos = _Value;
	}

	inline int2 GetPos() const override
	{
		return PlayerPos;
	}

	void SubLifeCount(int _Value = 1)
	{
		if (PlayerLifeCount > 0)
		{
			PlayerLifeCount -= _Value;
		}
	}

	int GetLifeCount()
	{
		return PlayerLifeCount;
	}

	void AddScore(int _Value)
	{
		PlayerScore += _Value;
	}


protected:
	void DrawChar(short x, short y, const char c[][XSize]);

	void MovePlayer(int _X, int _Y);

	void FlipHorizontally(char arr[YSize][XSize]) {
		for (int i = 0; i < YSize; i++) {
			for (int j = 0; j < (XSize - 1) / 2; j++) {
				std::swap(arr[i][j], arr[i][XSize - 2 - j]);
			}
		}
	}

	void FlipVertically(char arr[YSize][XSize]) {
		for (int i = 0; i < YSize / 2; i++) {
			for (int j = 0; j < XSize - 1; j++) {
				std::swap(arr[i][j], arr[YSize - 1 - i][j]);
			}
		}
	}

	void PlayerInfoPrint();
	bool MonsterCheck(int _X, int _Y) override;

private:
	/*char PlayerArr1[YSize][XSize] =
	{
		 " 222 ",
		 "22222",
		 "222  ",
		 "22222",
		 " 222 "
	};*/
	char PlayerArr1[YSize][XSize] =
	{
		 "222",
		 "22 ",
		 "222",
	};

	/*char PlayerArr2[YSize][XSize] =
	{
		 " 2222",
		 "222  ",
		 "22   ",
		 "222  ",
		 " 2222"
	};*/
	char PlayerArr2[YSize][XSize] =
	{
		 "223",
		 "2  ",
		 "223",
	};

	/*char PlayerArr3[YSize][XSize] =
	{
		 " 2 2 ",
		 "22 22",
		 "22222",
		 "22222",
		 " 222 "
	};*/

	char PlayerArr3[YSize][XSize] =
	{
		 "2 2",
		 "2 2",
		 "222"
	};

	char PlayerArr4[YSize][XSize] =
	{
		 "3 3",
		 "222",
		 "222"
	};

	/*char PlayerPreveArr[YSize][XSize] =
	{
		 "     ",
		 "     ",
		 "     ",
		 "     ",
		 "     "
	};*/
	char PlayerPreveArr[YSize][XSize] =
	{
		 "   ",
		 "   ",
		 "   ",
	};

	int Speed = 100;
	int Dir = RIGHT;
	int Key = -1;

	double CheckTime;
	clock_t start = clock();
	clock_t end;

	class Utill Handle;

	bool LRReverse = true;
	bool UDReverse = true;


	int2 PlayerPos = { 50, 30 };
	int2 PlayerSize = { XSize - 1, YSize };

	int PlayerScore = 0;
	int PlayerLifeCount = 3;
};

