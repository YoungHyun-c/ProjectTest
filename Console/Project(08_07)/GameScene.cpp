#include "GameScene.h"
#include <Windows.h>

#include "Warrior_87.h"
#include "Archer_87.h"
#include "Wizard_87.h"
#include "Monster_87.h"

#define Warrior 1
#define Archer 2
#define Wizard 3

#define CharacterNum 3

GameScene::~GameScene()
{
	if (nullptr != PlayerUnit)
	{
		delete PlayerUnit;
		PlayerUnit = nullptr;
	}
}

void GameScene::GameSet()
{
	CreateCharacter();
	CreateMonster();

	BattleCheck();
	

}

void GameScene::CreateCharacter()
{
	int _Num = 0;
	bool Select = true;

	while (Select)
	{
		std::cout << "직업을 선택해 주세요 (1.전사, 2.궁수, 3.마법사) : ";
		std::cin >> _Num;
		if (_Num <= 0 || _Num > CharacterNum)
		{
			std::cout << "다시 선택해주세요" << std::endl;
		}
		else
		{
			Select = false;
		}
	}
	switch (_Num)
	{
	case Warrior:
		PlayerUnit = new Warrior_87();
		break;
	case Archer:
		PlayerUnit = new Archer_87();
		break;
	case Wizard:
		PlayerUnit = new Wizard_87();
		break;
	default:
		break;
	}

	std::cout << "==============================" << std::endl;
	std::cout << "당신의 캐릭터가 선택 되었습니다." << std::endl;
	PlayerUnit->PrintInfo();
}

void GameScene::CreateMonster()
{

	MonsterUnit = new Monster_87("고붕이", "고블린", "몽둥이", 30, 20, 20);
	MonsterUnit->PrintInfo();

}

void GameScene::BattleInfoPrint(class UnitManager* _Player, class UnitManager* _Monster)
{
	std::cout << "===========================================================" << std::endl;
	std::cout << "플레이어 : " << PlayerUnit->GetName() << "  VS " << "  몬스터 : " << MonsterUnit->GetName() << std::endl;
	std::cout.width(5);
	std::cout << "남은체력 : " << PlayerUnit->GetName() << "    " << "   남은체력 : " << MonsterUnit->GetHp() << std::endl;
	std::cout << std::right << "  공격력 : " << PlayerUnit->GetAtk() << "    " << "       공격력 : " << MonsterUnit->GetAtk() << std::endl;
	std::cout << std::right << "  방어력 : " << PlayerUnit->GetDef() << "    " << "       방어력 : " << MonsterUnit->GetDef() << std::endl;

	std::cout << "===========================================================" << std::endl;
}

void GameScene::BattleCheck()
{
	if (PlayerUnit == nullptr && MonsterUnit == nullptr)
	{
		return;
	}

	std::cout << "	!!!!배틀이 시작되었습니다!!!!" << std::endl;

	int Number = 0;
	while (Number != 1 && Number != 2 && Number != 3)
	{
		std::cout << "1.계속 싸운다! 2. 회피한다. 3.도망간다. \n" << "숫자를 입력해주세요 : ";
		std::cin >> Number;
		if (Number == 1)
		{
			break;
		}
		if (Number == 2)
		{
			std::cout << "회피!" << std::endl;
		}
		if (Number == 3)
		{
			std::cout << "당신은 도망쳤습니다..." << std::endl;
			Sleep(2000);
			break;
		}
		std::cout << "맞는 번호를 입력해주세요!" << std::endl;
	}


	BattleAttack();
}

void GameScene::BattleAttack()
{
	PlayerUnit->TakeAttack(MonsterUnit->GetAtk());
	std::cout << PlayerUnit->GetName() << "가(이) " << MonsterUnit->GetName() << "을(를) 공격합니다!" << std::endl;
}


void GameScene::BattleEnd()
{

}
