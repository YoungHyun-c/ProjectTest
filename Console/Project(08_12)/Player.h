#pragma once
#include "ConsoleGameObject.h"
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Utill.h"

#define XSize 6
#define YSize 5

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
	int2 PlayerPos = { 50, 30 };
	int2 PlayerSize;

	char PlayerArr1[YSize][XSize] =
	{
		 " 222 ",
		 "22222",
		 "222  ",
		 "22222",
		 " 222 "
	};

	char PlayerArr2[YSize][XSize] =
	{
		 " 2222",
		 "222  ",
		 "22   ",
		 "222  ",
		 " 2222"
	};

	char PlayerPreveArr[YSize][XSize] =
	{
		 "     ",
		 "     ",
		 "     ",
		 "     ",
		 "     "
	};

	void DrawChar(short x, short y, const char c[][6]);

	int Dir = RIGHT;
	int Key = -1;
	int Speed = 100;

	double Test;
	clock_t start = clock();
	clock_t end;

	class Utill Handle;
};

