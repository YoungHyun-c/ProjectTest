#pragma once

#include <iostream>
#include <string>

class Player
{
public:

	void PlayerPrint();

	void PlayerMove();

private:
	char PlayerArr[5][5] = {' '};

};

