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
		std::cout << "������ ������ �ּ��� (1.����, 2.�ü�, 3.������) : ";
		std::cin >> _Num;
		if (_Num <= 0 || _Num > CharacterNum)
		{
			std::cout << "�ٽ� �������ּ���" << std::endl;
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
	std::cout << "����� ĳ���Ͱ� ���� �Ǿ����ϴ�." << std::endl;
	PlayerUnit->PrintInfo();
}

void GameScene::CreateMonster()
{

	MonsterUnit = new Monster_87("�����", "���", "������", 30, 20, 20);
	MonsterUnit->PrintInfo();

}

void GameScene::BattleInfoPrint(class UnitManager* _Player, class UnitManager* _Monster)
{
	std::cout << "===========================================================" << std::endl;
	std::cout << "�÷��̾� : " << PlayerUnit->GetName() << "  VS " << "  ���� : " << MonsterUnit->GetName() << std::endl;
	std::cout.width(5);
	std::cout << "����ü�� : " << PlayerUnit->GetName() << "    " << "   ����ü�� : " << MonsterUnit->GetHp() << std::endl;
	std::cout << std::right << "  ���ݷ� : " << PlayerUnit->GetAtk() << "    " << "       ���ݷ� : " << MonsterUnit->GetAtk() << std::endl;
	std::cout << std::right << "  ���� : " << PlayerUnit->GetDef() << "    " << "       ���� : " << MonsterUnit->GetDef() << std::endl;

	std::cout << "===========================================================" << std::endl;
}

void GameScene::BattleCheck()
{
	if (PlayerUnit == nullptr && MonsterUnit == nullptr)
	{
		return;
	}

	std::cout << "	!!!!��Ʋ�� ���۵Ǿ����ϴ�!!!!" << std::endl;

	int Number = 0;
	while (Number != 1 && Number != 2 && Number != 3)
	{
		std::cout << "1.��� �ο��! 2. ȸ���Ѵ�. 3.��������. \n" << "���ڸ� �Է����ּ��� : ";
		std::cin >> Number;
		if (Number == 1)
		{
			break;
		}
		if (Number == 2)
		{
			std::cout << "ȸ��!" << std::endl;
		}
		if (Number == 3)
		{
			std::cout << "����� �����ƽ��ϴ�..." << std::endl;
			Sleep(2000);
			break;
		}
		std::cout << "�´� ��ȣ�� �Է����ּ���!" << std::endl;
	}


	BattleAttack();
}

void GameScene::BattleAttack()
{
	PlayerUnit->TakeAttack(MonsterUnit->GetAtk());
	std::cout << PlayerUnit->GetName() << "��(��) " << MonsterUnit->GetName() << "��(��) �����մϴ�!" << std::endl;
}


void GameScene::BattleEnd()
{

}
