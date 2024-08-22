#pragma once
#include "ConsoleGameObject.h"
#include "GameObjectManager.h"

enum class PlayerState
{
	Normal,
	Attacker,
	Max,
};

class Player : public ConsoleGameObject
{
public:
	Player();
	static bool IsGameUpdate;

	void Update() override;
	bool IsItemCheck();

	void PlayerPrint();

	int2 GetPlayerSize() const
	{
		return PlayerSize;
	}

	inline void SetPos(const int2& _Value) override
	{
		PlayerPos = _Value;
	}

	inline void SetInitPos(const int2& _Value)
	{
		InitPlayerPos = _Value;
	}

	inline int2 GetPos() const override
	{
		return PlayerPos;
	}

	inline int2 GetInitialPos()
	{
		return InitPlayerPos;
	}

	void SubLifeCount(int _Value = 1)
	{
		if (PlayerLifeCount > 0)
		{
			PlayerLifeCount -= _Value;
		}
	}
	void SetLifeCount(int _Value)
	{
		PlayerLifeCount = _Value;
	}

	int GetLifeCount()
	{
		return PlayerLifeCount;
	}

	void AddScore(int _Value)
	{
		PlayerScore += _Value;
	}

	void AddSpeed(int _Value)
	{
		if (PlayerSpeed + _Value < 10)
		{
			PlayerSpeed = 10;
			return;
		}
		PlayerSpeed += _Value;
		if (PlayerSpeed >= 150)
		{
			PlayerSpeed = 150;
			return;
		}
	}

	void SetSpeed(int _Value)
	{
		PlayerSpeed = _Value;
	}

	void PlayerReset();

	void ChangeState(PlayerState _State);
	void StateUpdate();

	PlayerState GetState()
	{
		return State;
	}

protected:
	void DrawChar(short x, short y, const char c[][XSize], int _Font = 14, int _Back = 14);

	void MovePlayer(int _X, int _Y);

	void FlipHorizontally(char arr[YSize][XSize]) {
		for (int i = 0; i < YSize; i++) {
			for (int j = 0; j < (XSize - 1) / 2; j++) {
				std::swap(arr[i][j], arr[i][XSize - 2 - j]);
			}
		}
	}

	void FlipVertically(char arr[YSize][XSize]) {
		for (int i = 0; i < YSize / 2; i++) {
			for (int j = 0; j < XSize - 1; j++) {
				std::swap(arr[i][j], arr[YSize - 1 - i][j]);
			}
		}
	}

	void PlayerInfoPrint();
	bool MonsterCheck(int _X, int _Y) override;


	void NormalStart();
	void NormalUpdate();

	void AttackStart();
	void AttackUpdate();


private:
	char PlayerArr1[YSize][XSize] =
	{
		 "222",
		 "22 ",
		 "222",
	};
	char PlayerArr2[YSize][XSize] =
	{
		 "223",
		 "2  ",
		 "223",
	};


	char PlayerArr3[YSize][XSize] =
	{
		 "2 2",
		 "2 2",
		 "222"
	};

	char PlayerArr4[YSize][XSize] =
	{
		 "3 3",
		 "222",
		 "222"
	};

	char PlayerPreveArr[YSize][XSize] =
	{
		 "   ",
		 "   ",
		 "   ",
	};

	int PlayerSpeed = 100;
	int Dir = RIGHT;
	int Key = -1;

	double CheckTime;
	clock_t Check = clock();
	clock_t start = clock();
	clock_t end;
	std::chrono::steady_clock::time_point AttackTime;
	std::chrono::steady_clock::time_point AttackEndTime;
	static const std::chrono::milliseconds Attackker;

	class Utill Handle;

	bool LRReverse = true;
	bool UDReverse = true;

	int2 InitPlayerPos = { 50, 40 };
	int2 PlayerPos = InitPlayerPos;
	int2 PlayerSize = { XSize - 1, YSize };

	int PlayerScore = 0;
	int PlayerLifeCount = 3;

	PlayerState State = PlayerState::Normal;
};

