#pragma once

#include "Utill.h"

class Monster
{
public:
	Monster();
	~Monster();
	Monster(int _FontColor, int _BackColor)
		: FontColor(_FontColor), BackColor(_BackColor)
	{
	}

	void MonsterPrint();

	void MonsterColor(int _Font, int _Back);

	//void MonsterMove();

private:
	char MonsterArr[5][6] = { " 222 ",
							  "23332",
							  "23432",
							  "22222",
							  "22 22" };

	int FontColor = 0;
	int BackColor = 0;

	Utill* UtillMan;
};

