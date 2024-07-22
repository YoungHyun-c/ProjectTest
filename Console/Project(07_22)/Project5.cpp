#include <iostream>
#include <time.h>
#include <Windows.h>
#include <string.h>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// 과제1. 복습

// 과제2. 가위바위보

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
		// 가위바위보, 남은게임 출력
		PrintSRP();
		
		// 컴퓨터 숫자 정하기
		int ComputerNum = ComputerRanNum();

		// 플레이어 숫자 정하기
		int PlayerNum = PlayerInputNum();

		Sleep(100);
		cout << "배팅 금액을 입력해주세요 : ";
		cin >> PlayerBatting;
		Sleep(100);
		PlayerBatting < LeastBatting || PlayerBatting > PlayerMoney ? ResetInput() : PlayerBatting;

		// 결과
		Result(ComputerNum, PlayerNum);

		// 플레이어 소지금액출력
		PrintPlayerMoney();
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

void PrintSRP()
{
	cout << "!!!!!가위바위보 게임!!!!!" << endl;
	cout << "남은 플레이 횟 수 : " << GameNum - GamePlayValue << endl;
	GamePlayValue++;
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

int ResetInput()
{
	printf("최소금액과 당신의 소지금 내에서 다시 입력해주세요 (%d원 ~ %d원) : ", LeastBatting, PlayerMoney);
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
		cout << "비겼습니다!" << endl;
		printf("배팅금액 X %d : %d + %d X %d \n", DrawBatting, PlayerMoney, PlayerBatting, DrawBatting);
		PlayerMoney += PlayerBatting * DrawBatting;
		break;
	case Lose:
		cout << "졌습니다!" << endl;
		printf("배팅금액 X %d : %d - %d X %d \n", LoseBatting, PlayerMoney, PlayerBatting, LoseBatting);
		PlayerMoney -= PlayerBatting * LoseBatting;
		break;
	case Win:
		cout << "이겼습니다." << endl;
		printf("배팅금액 X %d : %d + %d X %d \n", WinBatting, PlayerMoney, PlayerBatting, WinBatting);
		PlayerMoney += PlayerBatting * WinBatting;
		break;
	default:
		break;
	}
}

void PrintPlayerMoney()
{
	cout << "당신의 소지금 : " << PlayerMoney << "원" << endl;
}

string GameEnd()
{
	string End = "게임이 종료 되었습니다.";

	return End;
}