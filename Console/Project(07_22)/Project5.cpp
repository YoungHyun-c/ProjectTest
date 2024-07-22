#include <iostream>
#include <time.h>
#include <Windows.h>
#include <string.h>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// ����1. ����

// ����2. ����������

int PlayerMoney = 10000;
int PlayerBatting = 0;
const int LeastBatting = 1000;

const int DrawBatting = 5;
const int LoseBatting = 7;
const int WinBatting = 3;
const int GameNum = 5;
int GamePlayValue = 0;

#define Draw 1
#define Lose 2
#define Win 3

void PrintSRP();
int ComputerRanNum();
int PlayerInputNum();
int ResetInput();
void Result(int _ComputerNum, int _PlayerNum);
void PrintPlayerMoney();
string GameEnd();

void SRPGame()
{
	srand(time(NULL));

	for (; GamePlayValue < GameNum && 0 < PlayerMoney;)
	{
		// ����������, �������� ���
		PrintSRP();
		
		// ��ǻ�� ���� ���ϱ�
		int ComputerNum = ComputerRanNum();

		// �÷��̾� ���� ���ϱ�
		int PlayerNum = PlayerInputNum();

		Sleep(100);
		cout << "���� �ݾ��� �Է����ּ��� : ";
		cin >> PlayerBatting;
		Sleep(100);
		PlayerBatting < LeastBatting || PlayerBatting > PlayerMoney ? ResetInput() : PlayerBatting;

		// ���
		Result(ComputerNum, PlayerNum);

		// �÷��̾� �����ݾ����
		PrintPlayerMoney();
		cout << "\n";
	}

	string Ending = GameEnd();
	cout << Ending;
}


int main()
{

	// ����2.
	SRPGame();

	return 0;
}

void PrintSRP()
{
	cout << "!!!!!���������� ����!!!!!" << endl;
	cout << "���� �÷��� Ƚ �� : " << GameNum - GamePlayValue << endl;
	GamePlayValue++;
}

int ComputerRanNum()
{
	int _ComputerNum = rand() % 3 + 1;
	cout << "ġƮ : ��ǻ�Ͱ� �� ���� : " << _ComputerNum << endl;
	return _ComputerNum;
}
int PlayerInputNum()
{
	cout << "���ڸ� ������ �ּ��� (1.����, 2.����, 3.��) : ";
	int PlayerNumber;
	cin >> PlayerNumber;
	Draw <= PlayerNumber && PlayerNumber <= Win ? PlayerNumber : PlayerNumber = PlayerInputNum();

	return PlayerNumber;
}

int ResetInput()
{
	printf("�ּұݾװ� ����� ������ ������ �ٽ� �Է����ּ��� (%d�� ~ %d��) : ", LeastBatting, PlayerMoney);
	cin >> PlayerBatting;
	PlayerBatting < LeastBatting || PlayerBatting > PlayerMoney ? ResetInput() : PlayerBatting;

	return PlayerBatting;
}

void Result(int _ComputerNum, int _PlayerNum)
{
	int Result = (_ComputerNum == _PlayerNum) ? 1 : (_ComputerNum == (_PlayerNum % 3) + 1) ? 2 : 3;

	switch (Result)
	{
	case Draw:
		cout << "�����ϴ�!" << endl;
		printf("���ñݾ� X %d : %d + %d X %d \n", DrawBatting, PlayerMoney, PlayerBatting, DrawBatting);
		PlayerMoney += PlayerBatting * DrawBatting;
		break;
	case Lose:
		cout << "�����ϴ�!" << endl;
		printf("���ñݾ� X %d : %d - %d X %d \n", LoseBatting, PlayerMoney, PlayerBatting, LoseBatting);
		PlayerMoney -= PlayerBatting * LoseBatting;
		break;
	case Win:
		cout << "�̰���ϴ�." << endl;
		printf("���ñݾ� X %d : %d + %d X %d \n", WinBatting, PlayerMoney, PlayerBatting, WinBatting);
		PlayerMoney += PlayerBatting * WinBatting;
		break;
	default:
		break;
	}
}

void PrintPlayerMoney()
{
	cout << "����� ������ : " << PlayerMoney << "��" << endl;
}

string GameEnd()
{
	string End = "������ ���� �Ǿ����ϴ�.";

	return End;
}