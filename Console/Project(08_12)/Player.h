#pragma once
#include "ConsoleGameObject.h"
#include <Windows.h>

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
	int2 PlayerPos;
	int2 PlayerSize;

	/*char PlayerArr[YSize][XSize] =
	{
		 " 111 ",
		 "11111",
		 "111  ",
		 "11111",
		 " 111 "
	};*/

	int Key = -1;

	bool KeyCheck()
	{
		return 0 != GetAsyncKeyState(Key);
	}


	int Dir = RIGHT;
};

