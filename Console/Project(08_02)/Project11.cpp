#include <iostream>
#include <Windows.h>
#include <random>
#include <algorithm>
#include <string>
#include <conio.h>

#pragma region 1.�����̵�
class int2
{
public:
	int X;
	int Y;

	int2(int _X, int _Y)
		: X(_X), Y(_Y)
	{
	}
};
class RandNum
{
public:
	int RandomNum(const int _Start, const int _End)
	{
		std::random_device Ren;
		std::mt19937 Mt(Ren());
		std::uniform_int_distribution<int> Dist(_Start, _End);

		return Dist(Mt);
	}
};

class SlideGame
{
public:
	SlideGame()
	{
	}

	static SlideGame& GetSlideScreen()
	{
		return MainScreen;
	}
	const int2 GetScreenSize()
	{
		return int2{ YScreenSize, XScreenSize };
	}

	bool IsScreenOver(const int2& _Pos) const;

	void Swap(int2 _CurPos, int2 _Pos);

	void const MadeSlide();
	void const PrintSlide();
	void const SetPlayerCharacter(int2 _Pos, std::string _Str);

	bool const WinSlide();

private:
	static const int XScreenSize = 6;
	static const int YScreenSize = 6;
	std::string Slide[YScreenSize][XScreenSize];

	static SlideGame MainScreen;
};

SlideGame SlideGame::MainScreen;

class Player
{
public:
	
	void Move(SlideGame& _Screen)
	{
		char Ch = _getch();


		int2 NextPos = PlayerPos;
		int2 CurPos = GetPos();

		switch (Ch)
		{
		case 'a':
		case 'A':
			NextPos.X -= 1;
			if (SlideGame::GetSlideScreen().IsScreenOver(NextPos) == false)
			{
				SlideGame::GetSlideScreen().Swap(CurPos, {PlayerPos.X -=1 , PlayerPos.Y});
			}
			break;
		case 'd':
		case 'D':
			NextPos.X += 1;
			if (SlideGame::GetSlideScreen().IsScreenOver(NextPos) == false)
			{
				SlideGame::GetSlideScreen().Swap(CurPos, { PlayerPos.X += 1 , PlayerPos.Y });
			}
			break;
		case 'w':
		case 'W':
			NextPos.Y -= 1;
			if (_Screen.GetSlideScreen().IsScreenOver(NextPos) == false)
			{
				_Screen.GetSlideScreen().Swap(CurPos, { PlayerPos.X , PlayerPos.Y -= 1 });
			}
			break;
		case 's':
		case 'S':
			NextPos.Y += 1;
			if (_Screen.GetSlideScreen().IsScreenOver(NextPos) == false)
			{
				_Screen.GetSlideScreen().Swap(CurPos, { PlayerPos.X, PlayerPos.Y += 1 });
			}
			break;
		default:
			break;
		}
		Sleep(InterFrame);
	}

	void SetPlayerPos(int2 _Pos)
	{
		PlayerPos.X = _Pos.X;
		PlayerPos.Y = _Pos.Y;
	}

	int2 GetPos()
	{
		return PlayerPos;
	}


private:
	int2 PlayerPos = { 0, 0 };
	static const int InterFrame = 100;
};
#pragma endregion


#pragma region ��������
class RandomNumber
{
public:
	const int RandomNum(const int& _Start, const int& _End)
	{
		std::random_device Ren;
		std::mt19937 Mt(Ren());
		std::uniform_int_distribution<int> Dist(_Start, _End);

		return Dist(Mt);
	}
};


class BattlePlayer;
class BattleMonster;
class BattleGame
{
public:
	
	void BattleCheck(class BattlePlayer* _Player, class BattleMonster* _Monster);
	void BattleInfoPrint(class BattlePlayer* _Player, class BattleMonster* _Monster);
	void BattleAtk(std::string _AttackerName, int _AttackerPower, std::string _ReceiveName, int& _ReceiveHp, int _ReceiveDef)
	{
		std::cout << _AttackerName << "��(��) " << _ReceiveName <<"��(��)�����մϴ�!" << std::endl;
		//std::cout << _ReceiveName << "(��)��" << _ReceiveHp << " - " << _AttackerPower - static_cast<int>(0.6f * _ReceiveDef) << std::endl;
		printf("%s(��)�� %d ��ŭ ���ݹ޽��ϴ�!\n", _ReceiveName.c_str() , _AttackerPower - static_cast<int>(0.6f * _ReceiveDef));
		_ReceiveHp -= _AttackerPower - static_cast<int>(0.6f * _ReceiveDef);
		if (_ReceiveHp <= 0) _ReceiveHp = 0;
		std::cout << _ReceiveName << "�� ����ü�� : " << _ReceiveHp << std::endl;
	}

	void BattleAtk(class BattlePlayer* _PAttacker, class BattleMonster* _MReceive);
	void BattleAtk(class BattleMonster* _MAttacker, class BattlePlayer* _PReceive);


	bool BattleEnd(class BattlePlayer* _Player, class BattleMonster* _Monster);

private:
	int Count = 1;
	int CalcDam = 0;
};

class BattlePlayer
{
public:
	BattlePlayer()
	{
	}

	void SetPlayerHp(int _Hp)
	{
		if (_Hp <= 0)
		{
			pHp = 0;
			return;
		}
		pHp = _Hp;
	}
	const int GetPlayerHp()
	{
		return pHp;
	}
	void SetPlayerAtk(int _Atk)
	{
		pAtk = _Atk;
	}
	const int GetPlayerAtk()
	{
		return pAtk;
	}
	void SetPlayerDef(int _Def)
	{
		pDef = _Def;
	}
	const int GetPlayerDef()
	{
		return pDef;
	}


	void SetPlayerName(std::string _Name)
	{
		PlayerName = _Name;
	}

	const std::string& GetPlayerName()
	{
		return PlayerName;
	}

private:
	int pHp = 0;
	int pAtk = 0;
	int pDef = 0;
	std::string PlayerName = "";
};

class BattleMonster
{
public:
	BattleMonster(std::string _Name, int _Hp, int _Atk, int _Def)
		: MonsterName(_Name), mHp(_Hp), mAtk(_Atk), mDef(_Def)
	{
	}

	void SetMonsterHp(int _Hp)
	{
		if (_Hp <= 0)
		{
			mHp = 0;
			return;
		}
		mHp = _Hp;
	}
	const int GetMonsterHp()
	{
		return mHp;
	}
	void SetMonsterAtk(int _Atk)
	{
		mAtk = _Atk;
	}
	const int GetMonsterAtk()
	{
		return mAtk;
	}

	void SetMonsterDef(int _Def)
	{
		mDef = _Def;
	}
	const int GetMonsterDef()
	{
		return mDef;
	}

	void SetMonsterName(std::string _name)
	{
		MonsterName = _name;
	}

	const std::string& GetMonsterName()
	{
		return MonsterName;
	}

private:
	int mHp = 0;
	int mAtk = 0;
	int mDef = 0;
	std::string MonsterName = "";
};


#pragma endregion


int main()
{
	// �����̵� ���� Ŭ������ �����
	/*{
		SlideGame::GetSlideScreen().MadeSlide();
		Player* SPlayer = new Player();
		SPlayer->SetPlayerPos({ 4,4 });
		SlideGame::GetSlideScreen().SetPlayerCharacter(SPlayer->GetPos(), " ");
		while (true)
		{
			system("cls");

			SlideGame::GetSlideScreen().PrintSlide();
			if (true == SlideGame::GetSlideScreen().WinSlide())
			{
				break;
			}
			
			SPlayer->Move(SlideGame::GetSlideScreen());
		}

		delete SPlayer;
		SPlayer = nullptr;
	}*/

	// �������� Ŭ������ �����
	{
		RandomNumber Random;

		int PlayerHp;
		BattlePlayer* pPlayer = new BattlePlayer();
		pPlayer->SetPlayerName("����");
		pPlayer->SetPlayerHp(Random.RandomNum(500, 1200));
		PlayerHp = pPlayer->GetPlayerHp();
		pPlayer->SetPlayerAtk(Random.RandomNum(100, 300));
		pPlayer->SetPlayerDef(Random.RandomNum(100, 150));

		int MonsterHp, MonsterAtk, MonsterDef;
		MonsterHp = Random.RandomNum(500, 1000);
		MonsterAtk = Random.RandomNum(100, 300);
		MonsterDef = Random.RandomNum(100, 150);
		BattleMonster* pMonster = new BattleMonster("�����", MonsterHp, MonsterAtk, MonsterDef);

		BattleGame BattlePnM;
		BattlePnM.BattleCheck(pPlayer, pMonster);
	}



	return 0;
}





void SlideGame::Swap(int2 _CurPos, int2 _Pos)
{
	std::string Temp = Slide[_CurPos.Y][_CurPos.X];
	Slide[_CurPos.Y][_CurPos.X] = Slide[_Pos.Y][_Pos.X];
	Slide[_Pos.Y][_Pos.X] = Temp;
}
void const SlideGame::MadeSlide()
{
	for (int Y = 0; Y < YScreenSize; Y++)
	{
		for (int X = 0; X < XScreenSize; X++)
		{
			Slide[Y][X] = std::to_string((Y * 5) + X + 1);
		}
	}

	RandNum Rand;
	int X = 0, Y = 0;

	std::string Temp = "";

	for (int i = 0; i < 100; i++)
	{
		Y = Rand.RandomNum(0, YScreenSize - 1);
		X = Rand.RandomNum(0, XScreenSize - 1);
		Temp = Slide[Y][X];
		Slide[Y][X] = Slide[X][Y];
		Slide[X][Y] = Temp;
	}

}
void const SlideGame::PrintSlide()
{
	for (int Y = 0; Y < YScreenSize; Y++)
	{
		for (int X = 0; X < XScreenSize; X++)
		{
			std::cout.width(2);
			std::cout << std::right << Slide[Y][X] << " ";
		}
		std::cout << std::endl;
	}
}
void const SlideGame::SetPlayerCharacter(int2 _Pos, std::string _Str)
{
	if (true == IsScreenOver(_Pos))
	{
		return;
	}

	Slide[_Pos.Y][_Pos.X] = _Str;
}
bool SlideGame::IsScreenOver(const int2& _Pos) const 
{
	if (_Pos.X < 0)
	{
		return true;
	}

	if (_Pos.Y < 0)
	{
		return true;
	}

	if (_Pos.X >= XScreenSize)
	{
		return true;
	}

	if (_Pos.Y >= YScreenSize)
	{
		return true;
	}

	return false;
}
bool const SlideGame::WinSlide()
{
	for (int i = 0; i < XScreenSize - 1; i++)
	{
		if (Slide[0][i] != std::to_string(i + 1))
		{
			return false;
		}
	}
	std::cout << "����� �̰���ϴ�!" << std::endl;
	return true;
}


void BattleGame::BattleInfoPrint(class BattlePlayer* _Player, class BattleMonster* _Monster)
{
	if (_Player != nullptr && _Monster != nullptr)
	{
		std::cout << "===========================================================" << std::endl;
		std::cout << "�÷��̾� : " << _Player->GetPlayerName() << "  VS " << "  ���� : " << _Monster->GetMonsterName() << std::endl;
		std::cout.width(5);
		std::cout << "����ü�� : " << _Player->GetPlayerHp() << "    " << "  ����ü�� : " << _Monster->GetMonsterHp() << std::endl;
		std::cout << std::right << "  ���ݷ� : " << _Player->GetPlayerAtk() << "    " << "    ���ݷ� : " << _Monster->GetMonsterAtk() << std::endl;
		std::cout << std::right << "  ���� : " << _Player->GetPlayerDef() << "    " << "    ���� : " << _Monster->GetMonsterDef() << std::endl;

		std::cout << "===========================================================" << std::endl;
	}
}

bool BattleGame::BattleEnd(class BattlePlayer* _Player, class BattleMonster* _Monster)
{
	if (_Player->GetPlayerHp() <= 0)
	{
		BattleInfoPrint(_Player, _Monster);
		std::cout << "�÷��̾ �����ϴ�..." << std::endl;
		std::cout << "������ �������ϴ�...";
		return false;
	}
	if (_Monster->GetMonsterHp() <= 0)
	{
		BattleInfoPrint(_Player, _Monster);
		std::cout << "�����մϴ�! �÷��̾ �̰���ϴ�!!!" << std::endl;
		std::cout << "������ �������ϴ�...";
		return false;
	}

	return true;
}

void BattleGame::BattleCheck(class BattlePlayer* _Player, class BattleMonster* _Monster)
{
	if (_Player == nullptr && _Monster == nullptr)
	{
		return;
	}

	int PlayerHp = _Player->GetPlayerHp();
	int MonsterHp = _Monster->GetMonsterHp();

	std::cout << "	!!!!��Ʋ�� ���۵Ǿ����ϴ�!!!!" << std::endl;
	while (true)
	{

		BattleInfoPrint(_Player, _Monster);

		std::cout << Count++ << "�� ° ���Դϴ�." << std::endl;

		int Number = 0;
		while (Number != 1 && Number != 2)
		{
			std::cout << "1.��� �ο��! 2. ����������.\n" << "���ڸ� �Է����ּ��� : ";
			std::cin >> Number;
			if (Number == 1)
			{
				break;
			}
			if (Number == 2)
			{
				std::cout << "�ο� ������ ������ �������ϴ�...";

				Sleep(2000);
				exit(0);
			}

			std::cout << "�´� ��ȣ�� �Է����ּ���!" << std::endl;
		}

		std::cout << std::endl;

		// Ŭ������ ��ü�� �ȹް��Ҷ�.
		//BattleAtk(_Player->GetPlayerName(), _Player->GetPlayerAtk(), _Monster->GetMonsterName(), MonsterHp, _Monster->GetMonsterDef());
		//_Monster->SetMonsterHp(MonsterHp);

		BattleAtk(_Player, _Monster);
		if (BattleEnd(_Player, _Monster) == false)
		{
			break;
		}
		BattleAtk(_Monster, _Player);
		if (BattleEnd(_Player, _Monster) == false)
		{
			break;
		}

		BattleInfoPrint(_Player, _Monster);

		Sleep(3000);
		system("cls");
	}
}

void BattleGame::BattleAtk(class BattlePlayer* _PAttacker, class BattleMonster* _MReceive)
{
	CalcDam = _PAttacker->GetPlayerAtk() - static_cast<int>(0.6f * _MReceive->GetMonsterDef());
	std::cout << _PAttacker->GetPlayerName() << "��(��) " << _MReceive->GetMonsterName() << "��(��) �����մϴ�!" << std::endl;
	printf("%s(��)�� %d ��ŭ ���ݹ޽��ϴ�! \n", _MReceive->GetMonsterName().c_str(), CalcDam);
	_MReceive->SetMonsterHp(_MReceive->GetMonsterHp() - CalcDam);
	std::cout << _MReceive->GetMonsterName() << "�� ���� ü�� : " << _MReceive->GetMonsterHp() << std::endl;
	std::cout << std::endl;
	Sleep(2000);
}
void BattleGame::BattleAtk(class BattleMonster* _MAttacker, class BattlePlayer* _PReceive)
{
	CalcDam = _MAttacker->GetMonsterAtk() - static_cast<int>(0.6f * _PReceive->GetPlayerDef());
	std::cout << _MAttacker->GetMonsterName() << "��(��) " << _PReceive->GetPlayerName() << "��(��) �����մϴ�!" << std::endl;
	printf("%s(��)�� %d ��ŭ ���ݹ޽��ϴ�! \n", _PReceive->GetPlayerName().c_str(), CalcDam);
	_PReceive->SetPlayerHp(_PReceive->GetPlayerHp() - CalcDam);
	std::cout << _PReceive->GetPlayerName() << "�� ���� ü�� : " << _PReceive->GetPlayerHp() << std::endl;
	std::cout << std::endl;
	Sleep(2000);
}