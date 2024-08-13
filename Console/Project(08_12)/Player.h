#pragma once

#include <iostream>
#include <string>
#include "ConsoleGameMath.h"

class Player
{
public:

	void PlayerPrint();

	void PlayerMove();

private:
	char PlayerArr[5][5] = {' '};

	int2 PlayerPos = { 5, 5 };
};

