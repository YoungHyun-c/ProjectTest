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
	if (MonsterUnit == nullptr)
	{
		MonsterUnit = new Monster_87("�����", "���", "������", 30, 50, 20);
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
		MonsterUnit->SetMonster("�����", "���", "������", 100, 50, 40, 0.3f, Exp);
		break;
	case 2:
		Exp = RandNum.RandNum(40, 100);
		MonsterUnit->SetLevel(4);
		MonsterUnit->SetMonster("������", "���ڵ��", "������", 140, 60, 35, 0.4f, Exp);
		break;
	case 3:
		Exp = RandNum.RandNum(60, 120);
		MonsterUnit->SetLevel(5);
		MonsterUnit->SetMonster("������", "������", "��������", 120, 70, 30, 0.2f, Exp);
		break;
	case 4:
		Exp = RandNum.RandNum(80, 150);
		MonsterUnit->SetLevel(8);
		MonsterUnit->SetMonster("������", "�����", "������", 200, 50, 60, 0.3f, Exp);
		break;
	case 5:
		Exp = RandNum.RandNum(200, 400);
		MonsterUnit->SetLevel(10);
		MonsterUnit->SetMonster("�����", "�巡��", "�Ҳ�", 400, 90, 70, 0.5f, Exp);
		break;
	default:
		break;
	}
}

void GameScene::BattleInfoPrint(class UnitManager* _Player, class UnitManager* _Monster)
{
	std::cout << "===========================================================" << std::endl;
	std::cout << "�÷��̾� : " << PlayerUnit->GetName() << "  VS " << "   ���� : " << MonsterUnit->GetName() << std::endl;
	std::cout.width(5);
	std::cout << std::right <<"����     : " << PlayerUnit->GetLevel() << "               " << "���� : " << MonsterUnit->GetLevel() << std::endl;
	std::cout << "����ü�� : " << PlayerUnit->GetHp() << "         " << "����ü�� : " << MonsterUnit->GetHp() << std::endl;
	std::cout << std::right << "  ���ݷ� : " << PlayerUnit->GetAtk() << "            " << "���ݷ� : " << MonsterUnit->GetAtk() << std::endl;
	std::cout << std::right << "  ���� : " << PlayerUnit->GetDef() << "            " << "���� : " << MonsterUnit->GetDef() << std::endl;

	std::cout << "===========================================================" << std::endl;
}

void GameScene::BattleCheck()
{
	if (PlayerUnit == nullptr && MonsterUnit == nullptr)
	{
		return;
	}
	
	system("cls");
	std::cout << "	!!!!���͸� �������ϴ�!!!!" << std::endl;

	while (End)
	{
		int Number = 0;
		bool Attack = false;
		while (Number != 1 && Number != 2 && Number != 3)
		{
			system("cls");
			BattleInfoPrint(PlayerUnit, MonsterUnit);

			std::cout << "0.���� 1.��� �ο��! 2. ȸ���Ѵ�. 3.��������. \n" << "���ڸ� �Է����ּ��� : ";
			std::cin >> Number;
			if (Number == 0)
			{
				std::cout << "������ ����˴ϴ�...." << std::endl;
				Sleep(InterFrame);
				End = false;
				break;
			}
			if (Number == 1)
			{
				std::cout << "	!!!!��Ʋ�� ���۵˴ϴ�!!!!" << std::endl;
				Sleep(InterFrame);
				Attack = true;
				break;
			}
			if (Number == 2)
			{
				std::cout << MonsterUnit->GetName() << "�� ������ ȸ���մϴ�!" << std::endl;
				Sleep(InterFrame);
				break;
			}
			if (Number == 3)
			{
				std::cout << "����� �����ƽ��ϴ�..." << std::endl;
				std::cout << "���ο� ���͸� ã���ϴ�..." << std::endl;
				Sleep(InterFrame);
				CreateMonster();
				break;
			}
			std::cout << "�´� ��ȣ�� �Է����ּ���!" << std::endl;
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
		std::cout << "����� �׾����ϴ�...." << std::endl;
		std::cout << "������ �����ϴ�...." << std::endl;
		Sleep(3000);
		exit(0);
		return false;
	}
	if (MonsterUnit->GetHp() <= 0)
	{
		std::cout << "���͸� ��ҽ��ϴ�!!!" << std::endl;
		std::cout << "Exp�� �ö󰩴ϴ� : + " << MonsterUnit->GetExp() << std::endl;
		PlayerUnit->AddExp(MonsterUnit->GetExp());
		Sleep(3000);
		CreateMonster();
		return false;
	}

	return true;
}
