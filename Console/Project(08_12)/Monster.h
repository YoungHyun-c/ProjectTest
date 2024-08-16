#pragma once

#include "Utill.h"
#include "ConsoleGameObject.h"

class Monster : public ConsoleGameObject
{
public:
	Monster();
	~Monster();
	Monster(int _FontColor, int _BackColor, int _X, int _Y)
		: FontColor(_FontColor), BackColor(_BackColor) , MonsterPos(_X, _Y)
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
	//void MonsterColor(int _Font, int _Back, char M[YSize][XSize]);

	//void MonsterMove();

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


	int FontColor = 0;
	int BackColor = 0;

	int Speed = 100;
	int Dir = RIGHT;

	double CheckTime;
	clock_t start = clock();
	clock_t end;

	class Utill Handle;

	int2 MonsterPos = {  };
};

