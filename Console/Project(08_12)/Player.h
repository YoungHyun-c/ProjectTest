#pragma once
#include "ConsoleGameObject.h"

class Player : public ConsoleGameObject
{
public:
	static bool IsGameUpdate;

	void Update() override;
	bool IsItemCheck();

	void PlayerPrint();
	void PlayerMove();

private:
	char PlayerArr[5][5] = {' '};

	int2 PlayerPos = { 5, 5 };
};

