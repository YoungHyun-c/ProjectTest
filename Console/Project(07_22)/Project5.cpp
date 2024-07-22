#include <iostream>
#include <time.h>
#include <Windows.h>
#include <string.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// ����1. ����

// ����2. ����������

#define Draw 1
#define Lose 2
#define Win 3

// �Լ� ���� 7��
void PrintSRP(int GameNum, int _PlayValue); // 1
int ComputerRanNum(); // 2
int PlayerInputNum(); // 3
int BattingNum(int _LeastBatting, int _PlayerMoney); // 4
int Result(int _ComputerNum, int _PlayerNum, int _PlayerMoney, int _PlayerBatting); // 5
void PrintPlayerMoney(int _PlayerMoney); // 6
string GameEnd(); //7

void SRPGame()
{
	srand(time(NULL));
	
	const int GameNum = 5;
	int PlayerMoney = 10000;
	const int LeastBatting = 1000;

	for (int PlayValue = 0; PlayValue < GameNum && 0 < PlayerMoney; PlayValue++)
	{
		// ����������, �������� ���
		PrintSRP(GameNum, PlayValue);
		
		// ��ǻ�� ���� ���ϱ�
		int ComputerNum = ComputerRanNum();

		// �÷��̾� ���� ���ϱ�
		int PlayerNum = PlayerInputNum();

		Sleep(100);
		cout << "���� �ݾ��� �Է����ּ��� : ";
		int PlayerBatting;
		cin >> PlayerBatting;
		Sleep(100);
		PlayerBatting < LeastBatting || PlayerBatting > PlayerMoney ? PlayerBatting = BattingNum(LeastBatting, PlayerMoney) : PlayerBatting;

		// ���
		PlayerMoney = Result(ComputerNum, PlayerNum, PlayerMoney, PlayerBatting);

		// �÷��̾� �����ݾ����
		PrintPlayerMoney(PlayerMoney);
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

void PrintSRP(int _GameNum, int _PlayValue)
{
	cout << "!!!!!���������� ����!!!!!" << endl;
	cout << "���� �÷��� Ƚ �� : "<< _GameNum - _PlayValue << endl;
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

int BattingNum(int _LeastBatting, int _PlayerMoney)
{
	printf("�ּұݾװ� ����� ������ ������ �ٽ� �Է����ּ��� (%d�� ~ %d��) : ", _LeastBatting, _PlayerMoney);
	int PlayerBatting = 0;
	cin >> PlayerBatting;
	PlayerBatting < _LeastBatting || PlayerBatting > _PlayerMoney ? PlayerBatting = BattingNum(_LeastBatting, _PlayerMoney) : PlayerBatting;

	return PlayerBatting;
}

int Result(int _ComputerNum, int _PlayerNum, int _PlayerMoney, int _PlayerBatting)
{
	const int DrawBatting = 5;
	const int LoseBatting = 7;
	const int WinBatting = 3;

	int Result = (_ComputerNum == _PlayerNum) ? 1 : (_ComputerNum == (_PlayerNum % 3) + 1) ? 2 : 3;

	switch (Result)
	{
	case Draw:
		cout << "�����ϴ�!" << endl;
		printf("���ñݾ� X %d : %d + %d X %d \n", DrawBatting, _PlayerMoney, _PlayerBatting, DrawBatting);
		_PlayerMoney += _PlayerBatting * DrawBatting;
		break;
	case Lose:
		cout << "�����ϴ�!" << endl;
		printf("���ñݾ� X %d : %d - %d X %d \n", LoseBatting, _PlayerMoney, _PlayerBatting, LoseBatting);
		_PlayerMoney -= _PlayerBatting * LoseBatting;
		break;
	case Win:
		cout << "�̰���ϴ�." << endl;
		printf("���ñݾ� X %d : %d + %d X %d \n", WinBatting, _PlayerMoney, _PlayerBatting, WinBatting);
		_PlayerMoney += _PlayerBatting * WinBatting;
		break;
	default:
		break;
	}

	return _PlayerMoney;
}

void PrintPlayerMoney(int _PlayerMoney)
{
	cout << "����� ������ : " << _PlayerMoney << "��" << endl;
}

string GameEnd()
{
	string End = "������ ���� �Ǿ����ϴ�.";

	return End;
}