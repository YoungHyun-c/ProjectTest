#pragma once
#include "ConsoleGameObject.h"

#define XSize 6
#define YSize 5

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

};

