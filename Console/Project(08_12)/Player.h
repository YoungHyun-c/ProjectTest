#pragma once
#include "ConsoleGameObject.h"

class Player : public ConsoleGameObject
{
public:
	Player();
	static bool IsGameUpdate;

	void Update() override;
	bool IsItemCheck();

	void PlayerPrint();


private:
	char PlayerArr[5][5] = {' '};

	int2 PlayerPos;
};

