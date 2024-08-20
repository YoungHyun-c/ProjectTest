#pragma once

#include "Utill.h"
#include "AStartPathFinder.h"
#include "ConsoleGameObject.h"
#include "PackManScreen.h"

class Monster : public ConsoleGameObject
{
public:
	Monster();
	~Monster();
	Monster(int _FontColor, int _BackColor, int _X, int _Y)
		: FontColor(_FontColor), BackColor(_BackColor) , InitMonsterPos(_X, _Y)
	{
	}

	void MonsterPrint();

	inline void SetPos(const int2& _Value) override
	{
		MonsterPos = _Value;
	}

	inline int2 GetPos() const override
	{
		return MonsterPos;
	}

	void DrawChar(short _X, short _Y, const char C[YSize][XSize]);

	void MonsterPrevePrint(int _X, int _Y);

	void MonsterReset();

	void MonsterUpdate();
	void MoveMonster(int _X, int _Y);

	void FindMonsterToPlayer(Player* _Player);
	void MoveMonsterToPlayer();

private:
	/*char MonsterArr[5][6] = { " 222 ",
							  "23332",
							  "23432",
							  "22222",
							  "22 22" };*/

	char MonsterArr1[YSize][XSize] = 
							 {"444",
							  "454",
							  "4 4" };

	char MonsterArr2[YSize][XSize] =
							 {"444",
							  "454",
							  " 4 " };

	char MonsterPreveArr[YSize][XSize] =
							 {"   ",
							  "   ",
							  "   " };


	int FontColor = 0;
	int BackColor = 0;

	int MonsterSpeed = 100;
	int Dir = 0;

	double CheckTime;
	clock_t start = clock();
	clock_t end;

	class Utill Handle;

	int2 InitMonsterPos = { };
	int2 MonsterPos = {  };

	int IndexCount = 0;
	AStartPathFinder AStar;
	std::vector<int2> Path;
};

