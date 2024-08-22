#pragma once
#include <iostream>
#include <Windows.h>
#include <random>
#include <chrono>
#include <thread>
#include <map>

#include "ConsoleGameMath.h"
#include "GameEngineRandom.h"
#include "Utill.h"

#include "GameEngineCollision.h"
#include "GameObjectManager.h"
#include "Player.h"
#include "Monster.h"
#include "Item.h"

#include "AStartPathFinder.h"

#define XScreen 101
#define YScreen 50
#define MaxStage 3;

class PackManScreen
{
public:
	static PackManScreen& GetMainScreen()
	{
		return MainScreen;
	}
	void SetScreenSize(int2 _Size);
	const int2 GetScreenSize()
	{
		return Size;
	}
public:
	PackManScreen();
	~PackManScreen();

	void VoidCursor();
	void InitGame(bool bInitConsole = true);
	void Start();

	bool CanMove(int _X, int _Y) const;
	bool IsScreenOver(const int2& _Pos) const;
	void SetScreenCharacter(const int2& _Pos, char _Ch[][6]);
	char GetScreenCharacter(const int2& _Pos) const;

	void ScreenPrint();
	void ScreenClear();

	bool CheckMonsterCol();
	bool CheckTest(const int2& _Pos);
	bool CheckCollision();

private:
	int PackManSetting();
	void PackManTitleScreen();
	void PackManSetList();
	void PackManUpdate();
	void PackManInfo();

	void GameSetList();
	void GameInfoPrint();
	void GameProcess();
	void StageProcess();
	void StageClear();
	bool Stage1Clear();

	void ItemMade();

private:
	bool Done = true;
	std::vector<std::string> List;

	int X = 14;
	int Y = 0;

	class Utill Handle;

private:
	static PackManScreen MainScreen;
	static const int XScreenSize = XScreen;
	static const int YScreenSize = YScreen;
	static const int MaxStageNum = MaxStage;

	std::vector<std::vector<wchar_t>> ArrScreen;
	int2 Size;

	char MapArr[MaxStageNum][YScreenSize][XScreenSize] = {
	{
		"111111111111111111111111111111111111111111111111111111111111111111111111111111",
		"100000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000001",
		"111111111111111111111111111111111111111111111111111111111111111111111111111111",
	},
	{
		"111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
		"100000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
		"111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
	},
	{	"111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
		"100000000000000000000000000000000000000000000011110000000000000001111111100000000001111111110000001",
		"100000000000000000000000000000000000000000000011110000000000000001111111100000000001111111110000001",
		"100000000000000000000000000000000000000000000011110000000000000000000000000000000000000000000000001",
		"100000011111110000000011111111110000000011111111111111100000000000000000000000000000000000000000001",
		"100000011111110000000011111111110000000000000000000000000000000000000000000000000000000000000000001",
		"100000011111110000000000000000000000000000000000000000000000000000000000000111111100000011111000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000111111100000011111000001",
		"100000000000000000000000000000000000000001111111111110000000000000000000000111111100000000000000001",
		"100000000000000000000000111111111111111111111111111111111111111111111000000000000000000000000000001",
		"100000000000000000000000111111111111111111111111111111111111111111111000000000000000000000000000001",
		"111111111111000000000000111111111111111111111111111111111111111111111000000000000000000011111100001",
		"111111111111000000000000111111111111111111111111111111111111111111111000000000000000000011111100001",
		"111111111111000000000000000000000000000001111111111110000000000000000000000011111100000011111100001",
		"111111111111000000000000000000000000000000000000000000000000000000000000000011111100000011111100001",
		"111111111111000000000000000000000000000000000000000000000000000000000000000011111100000011111100001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000011111111111110000000000000000001111111111110000000000000000000000000000001",
		"100000000000000000000000011111111111110000000000000000001111111111110000001110000000111000000000001",
		"100000001111111111000000011000000000000000000000000000000000000000110000001110000000000000000000001",
		"100000001111111111000000011000000000000000000000000000000000000000110000001110000000000000000000001",
		"100000001111111111000000011000000000000000000000000000000000000000110000001110000000000000000000001",
		"100000001111111111000000011000000000000000000000000000000000000000110000001110000001000001111111111",
		"100000001111111111000000011000000000000000000000000000000000000000110000001110000001000001111111111",
		"100000001111111111000000011000000000000000000000000000000000000000110000001110000001000001111111111",
		"100000001111111111000000011111111111111111111111111111111111111111110000001110000001000001111111111",
		"100000001111111111000000000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
		"111000000000000000000000000001111111111111111111111111111111111100000000000000000011111110000000001",
		"111110000000000111110000000001111111111111111111111111111111111100000000000000000011111110000000001",
		"111110000000000111110000000000000000000000011111100000000000000000000000000000000011100000000000001",
		"100000000000000000000000000000000000000000011111100000000000000000000000000000000011100000000000001",
		"100000000000000000000000000000000000000000011111100000000000000000000000000000000011100000000000001",
		"100000000000000000000000000000000000000000011111100000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000111000000000000000000001",
		"100000000001111111110000000000000000000000000000000000000000000000000000000111000000000000000000001",
		"100000000001111111110000000000000000111000000000000000000000000000000000000111000000000000000000001",
		"100000000001111111110000000000000000111000000000000000000000000000111111111111111111111111100000001",
		"100000011111111111111111000000000000000000000000000000000000000000111111111111111111111111100000001",
		"100000011111111111111111000000000000000000000000000000000000000000111111111111111111111111100000001",
		"100000000000000000000000000000000000000000000000000000000000000000111111111111111111111111100000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000001111111111111111111111111111000000000000000000000000000000000000001",
		"100000000000000000000000000000001111111111111111111111111111000000000000000000000000000000000000001",
		"111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
	},
	};

private:
	int Stage = 0;

	// 메모리 쓴 것
	class Player* PlayMan;
	char Key;
	
	std::vector<class Monster*> MonsterList;
	int MonsterCount = 3;
	GameEngineCollision Col;
	int IndexCount = 0;

	std::vector<class Item*> Items;
	int ItemCount = 22;
};

