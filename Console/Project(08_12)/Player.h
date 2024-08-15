#pragma once
#include "ConsoleGameObject.h"
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Utill.h"

#define YSize 3
#define XSize 4

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define PAUSE 112
#define ESC 27

class Player : public ConsoleGameObject
{
public:
	Player();
	static bool IsGameUpdate;

	void Update() override;
	bool IsItemCheck();

	void PlayerPrint();

	const int2 GetPlayerSize()
	{
		return PlayerSize;
	}

private:
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

	int2 PlayerPos = { 50, 30 };
	int2 PlayerSize;

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

	void DrawChar(short x, short y, const char c[][XSize]);

	int Dir = RIGHT;
	int Key = -1;
	int Speed = 100;

	double Test;
	clock_t start = clock();
	clock_t end;

	class Utill Handle;

	bool LRReverse = true;
	bool UDReverse = true;

	void MovePlayer(int _X, int _Y);
};

