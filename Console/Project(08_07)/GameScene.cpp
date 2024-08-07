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

#define InterFrame 2000

GameScene::~GameScene()
{
	if (nullptr != PlayerUnit)
	{
		delete PlayerUnit;
		PlayerUnit = nullptr;
	}
	if (nullptr != MonsterUnit)
	{
		delete MonsterUnit;
		MonsterUnit = nullptr;
	}
}

void GameScene::GameSet()
{
	srand(time(NULL));

	CreateCharacter();
	CreateMonster();

	Sleep(2000);
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
	if (MonsterUnit == nullptr)
	{
		MonsterUnit = new Monster_87("고붕이", "고블린", "몽둥이", 30, 50, 20);
		return;
	}

	Random_87 RandNum;
	int Rand = RandNum.RandNum(1, 5);
	int Exp;
	switch (Rand)
	{
	case 1:
		Exp = RandNum.RandNum(20, 50);
		MonsterUnit->SetLevel(2);
		MonsterUnit->SetMonster("고붕이", "고블린", "몽둥이", 100, 50, 40, 0.3f, Exp);
		break;
	case 2:
		Exp = RandNum.RandNum(40, 100);
		MonsterUnit->SetLevel(4);
		MonsterUnit->SetMonster("도붕이", "리자드맨", "나이프", 140, 60, 35, 0.4f, Exp);
		break;
	case 3:
		Exp = RandNum.RandNum(60, 120);
		MonsterUnit->SetLevel(5);
		MonsterUnit->SetMonster("버붕이", "버섯맨", "포자포자", 120, 70, 30, 0.2f, Exp);
		break;
	case 4:
		Exp = RandNum.RandNum(80, 150);
		MonsterUnit->SetLevel(8);
		MonsterUnit->SetMonster("좀붕이", "좀비맨", "깨물기", 200, 50, 60, 0.3f, Exp);
		break;
	case 5:
		Exp = RandNum.RandNum(200, 400);
		MonsterUnit->SetLevel(10);
		MonsterUnit->SetMonster("드붕이", "드래곤", "불꽃", 400, 90, 70, 0.5f, Exp);
		break;
	default:
		break;
	}
}

void GameScene::BattleInfoPrint(class UnitManager* _Player, class UnitManager* _Monster)
{
	std::cout << "===========================================================" << std::endl;
	std::cout << "플레이어 : " << PlayerUnit->GetName() << "  VS " << "   몬스터 : " << MonsterUnit->GetName() << std::endl;
	std::cout.width(5);
	std::cout << std::right <<"레벨     : " << PlayerUnit->GetLevel() << "               " << "레벨 : " << MonsterUnit->GetLevel() << std::endl;
	std::cout << "남은체력 : " << PlayerUnit->GetHp() << "         " << "남은체력 : " << MonsterUnit->GetHp() << std::endl;
	std::cout << std::right << "  공격력 : " << PlayerUnit->GetAtk() << "            " << "공격력 : " << MonsterUnit->GetAtk() << std::endl;
	std::cout << std::right << "  방어력 : " << PlayerUnit->GetDef() << "            " << "방어력 : " << MonsterUnit->GetDef() << std::endl;

	std::cout << "===========================================================" << std::endl;
}

void GameScene::BattleCheck()
{
	if (PlayerUnit == nullptr && MonsterUnit == nullptr)
	{
		return;
	}
	
	system("cls");
	std::cout << "	!!!!몬스터를 만났습니다!!!!" << std::endl;

	while (End)
	{
		int Number = 0;
		bool Attack = false;
		while (Number != 1 && Number != 2 && Number != 3)
		{
			system("cls");
			BattleInfoPrint(PlayerUnit, MonsterUnit);

			std::cout << "0.종료 1.계속 싸운다! 2. 회피한다. 3.도망간다. \n" << "숫자를 입력해주세요 : ";
			std::cin >> Number;
			if (Number == 0)
			{
				std::cout << "게임이 종료됩니다...." << std::endl;
				Sleep(InterFrame);
				End = false;
				break;
			}
			if (Number == 1)
			{
				std::cout << "	!!!!배틀이 시작됩니다!!!!" << std::endl;
				Sleep(InterFrame);
				Attack = true;
				break;
			}
			if (Number == 2)
			{
				std::cout << MonsterUnit->GetName() << "의 공격을 회피합니다!" << std::endl;
				Sleep(InterFrame);
				break;
			}
			if (Number == 3)
			{
				std::cout << "당신은 도망쳤습니다..." << std::endl;
				std::cout << "새로운 몬스터를 찾습니다..." << std::endl;
				Sleep(InterFrame);
				CreateMonster();
				break;
			}
			std::cout << "맞는 번호를 입력해주세요!" << std::endl;
			Sleep(InterFrame);
		}

		if (Attack == true)
		{
			BattleAttack();
		}

		Attack = false;
	}
}

void GameScene::BattleAttack()
{
	MonsterUnit->TakeAttack(PlayerUnit->GetAtk());
	Sleep(InterFrame);
	if (BattleEnd() == false)
	{
		return;
	}
	PlayerUnit->TakeAttack(MonsterUnit->GetAtk());
	Sleep(InterFrame);
	if (BattleEnd() == false)
	{
		return;
	}
	BattleInfoPrint(PlayerUnit, MonsterUnit);
	Sleep(InterFrame);
	system("cls");
}


bool GameScene::BattleEnd()
{
	if (PlayerUnit->GetHp() <= 0)
	{
		std::cout << "당신은 죽었습니다...." << std::endl;
		std::cout << "게임이 끝납니다...." << std::endl;
		Sleep(3000);
		exit(0);
		return false;
	}
	if (MonsterUnit->GetHp() <= 0)
	{
		std::cout << "몬스터를 잡았습니다!!!" << std::endl;
		std::cout << "Exp가 올라갑니다 : + " << MonsterUnit->GetExp() << std::endl;
		PlayerUnit->AddExp(MonsterUnit->GetExp());
		Sleep(3000);
		CreateMonster();
		return false;
	}

	return true;
}
