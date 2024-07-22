#include <iostream>
#include <time.h>
#include <Windows.h>
#include <string.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// 과제1. 복습

// 과제2. 가위바위보

#define Draw 1
#define Lose 2
#define Win 3

// 함수 개수 7개
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
		// 가위바위보, 남은게임 출력
		PrintSRP(GameNum, PlayValue);
		
		// 컴퓨터 숫자 정하기
		int ComputerNum = ComputerRanNum();

		// 플레이어 숫자 정하기
		int PlayerNum = PlayerInputNum();

		Sleep(100);
		cout << "배팅 금액을 입력해주세요 : ";
		int PlayerBatting;
		cin >> PlayerBatting;
		Sleep(100);
		PlayerBatting < LeastBatting || PlayerBatting > PlayerMoney ? PlayerBatting = BattingNum(LeastBatting, PlayerMoney) : PlayerBatting;

		// 결과
		PlayerMoney = Result(ComputerNum, PlayerNum, PlayerMoney, PlayerBatting);

		// 플레이어 소지금액출력
		PrintPlayerMoney(PlayerMoney);
		cout << "\n";
	}

	string Ending = GameEnd();
	cout << Ending;
}

int main()
{

	// 과제2.
	SRPGame();

	return 0;
}

void PrintSRP(int _GameNum, int _PlayValue)
{
	cout << "!!!!!가위바위보 게임!!!!!" << endl;
	cout << "남은 플레이 횟 수 : "<< _GameNum - _PlayValue << endl;
}

int ComputerRanNum()
{
	int _ComputerNum = rand() % 3 + 1;
	cout << "치트 : 컴퓨터가 낸 숫자 : " << _ComputerNum << endl;
	return _ComputerNum;
}

int PlayerInputNum()
{
	cout << "숫자를 선택해 주세요 (1.가위, 2.바위, 3.보) : ";
	int PlayerNumber;
	cin >> PlayerNumber;
	Draw <= PlayerNumber && PlayerNumber <= Win ? PlayerNumber : PlayerNumber = PlayerInputNum();

	return PlayerNumber;
}

int BattingNum(int _LeastBatting, int _PlayerMoney)
{
	printf("최소금액과 당신의 소지금 내에서 다시 입력해주세요 (%d원 ~ %d원) : ", _LeastBatting, _PlayerMoney);
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
		cout << "비겼습니다!" << endl;
		printf("배팅금액 X %d : %d + %d X %d \n", DrawBatting, _PlayerMoney, _PlayerBatting, DrawBatting);
		_PlayerMoney += _PlayerBatting * DrawBatting;
		break;
	case Lose:
		cout << "졌습니다!" << endl;
		printf("배팅금액 X %d : %d - %d X %d \n", LoseBatting, _PlayerMoney, _PlayerBatting, LoseBatting);
		_PlayerMoney -= _PlayerBatting * LoseBatting;
		break;
	case Win:
		cout << "이겼습니다." << endl;
		printf("배팅금액 X %d : %d + %d X %d \n", WinBatting, _PlayerMoney, _PlayerBatting, WinBatting);
		_PlayerMoney += _PlayerBatting * WinBatting;
		break;
	default:
		break;
	}

	return _PlayerMoney;
}

void PrintPlayerMoney(int _PlayerMoney)
{
	cout << "당신의 소지금 : " << _PlayerMoney << "원" << endl;
}

string GameEnd()
{
	string End = "게임이 종료 되었습니다.";

	return End;
}