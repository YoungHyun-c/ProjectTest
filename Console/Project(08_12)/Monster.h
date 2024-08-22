#pragma once

#include "Utill.h"
#include "AStartPathFinder.h"
#include "ConsoleGameObject.h"
#include "PackManScreen.h"
#include "Player.h"

#define ColStartX 14
#define ColStartY 8

enum class MonsterState
{
	Normal,
	Attack,
	Run,
	Max,
};


class Monster : public ConsoleGameObject
{
public:
	Monster();
	~Monster();
	Monster(int _FontColor, int _BackColor, int _X, int _Y)
		: FontColor(_FontColor), BackColor(_BackColor) , InitMonsterPos(_X, _Y)
	{
		MonsterColPos.X = _X - ColStartX;
		MonsterColPos.Y = _Y - ColStartY;
	}

	void MonsterPrint();
	void MonsterInfoPrint();

	inline void SetPos(const int2& _Value) override
	{
		MonsterPos = _Value;
	}
	inline void SetInitPos(const int2& _Value)
	{
		InitMonsterPos = _Value;
	}

	void SetColPos(const int2& _Value)
	{
		MonsterColPos.X = _Value.X - 16;
		MonsterColPos.Y = _Value.Y - 8;
	}

	inline int2 GetPos() const override
	{
		return MonsterPos;
	}

	inline int2 GetPrevePos() const
	{
		return PrevePos;
	}

	void DrawChar(short _X, short _Y, const char C[YSize][XSize]);

	void MonsterPrevePrint(int _X, int _Y);

	void MonsterReset();

	void Update() override;
	void MoveMonster(int _X, int _Y);

	void FindMonsterToPlayer(Player* _Player);
	void MoveMonsterToPlayer();

	void ChangeState(MonsterState _State);
	void StateUpdate();
	MonsterState GetState()
	{
		return State;
	}

	void MonsterColPrint();
	void MonsterColOff();

	void RecievepPlayer(Player* _pPlayer)
	{
		pPlayer = _pPlayer;
	}

protected:
	/*Normal,
	Attack,
	Run,*/

	void NormalStart();
	void NormalUpdate();

	void AttackStart();
	void AttackUpdate();

	void RunStart();
	void RunUpdate();

	void MaxUpdate();


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
	char MonsterColArr[18][41] =
							{
								"8888888888888888888888888888888888888888",
								"8888888888888888888888888888888888888888",
								"8888888888888888888888888888888888888888",
								"8888888888888888888888888888888888888888",
								"8888888888888888888888888888888888888888",
								"8888888888888888888888888888888888888888",
								"8888888888888888888888888888888888888888",
								"8888888888888888888888888888888888888888",
								"8888888888888888888888888888888888888888",
								"8888888888888888888888888888888888888888",
								"8888888888888888888888888888888888888888",
								"8888888888888888888888888888888888888888",
								"8888888888888888888888888888888888888888",
								"8888888888888888888888888888888888888888",
								"8888888888888888888888888888888888888888",
								"8888888888888888888888888888888888888888",
								"8888888888888888888888888888888888888888",
								"8888888888888888888888888888888888888888",
							};
	char MonsterColOffArr[18][41] =
	{
		"                                        ",
		"                                        ",
		"                                        ",
		"                                        ",
		"                                        ",
		"                                        ",
		"                                        ",
		"                                        ",
		"                                        ",
		"                                        ",
		"                                        ",
		"                                        ",
		"                                        ",
		"                                        ",
		"                                        ",
		"                                        ",
		"                                        ",
		"                                        ",
	};




	int FontColor = 0;
	int BackColor = 0;

	int Dir = 0;
	int Key = -1;

	double CheckTime;
	clock_t start = clock();
	clock_t end;
	std::chrono::steady_clock::time_point LastMonsterChaseTime;
	std::chrono::steady_clock::time_point LastMonsterFindTime;
	std::chrono::steady_clock::time_point LastMonsterMoveTime;
	static const std::chrono::milliseconds MoveChase;
	static const std::chrono::milliseconds MoveInterval;
	static const std::chrono::milliseconds Move;
	std::chrono::steady_clock::time_point RunTime;
	static const std::chrono::milliseconds Runner;

	class Utill Handle;

	int2 InitMonsterPos = { };
	int2 MonsterPos = {  };
	int2 PrevePos = { };
	int2 MonsterColPos = {};
	GameEngineCollision Col;

	int IndexCount = 0;
	AStartPathFinder AStar;
	std::vector<int2> Path;

	MonsterState State = MonsterState::Normal;

	Player* pPlayer;
};

