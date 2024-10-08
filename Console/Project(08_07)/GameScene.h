#pragma once
#include <iostream>
#include <iomanip>

class GameScene
{
public:
	~GameScene();

	void GameSet();

	void CreateCharacter();
	void CreateMonster();

	void BattleInfoPrint(class UnitManager* _Player, class UnitManager* _Monster);
	void BattleCheck();
	void BattleAttack();
	bool BattleEnd();

private:
	class UnitManager* PlayerUnit;
	class UnitManager* MonsterUnit;
	bool End = true;
};