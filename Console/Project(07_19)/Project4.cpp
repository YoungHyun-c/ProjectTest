#include <iostream>
#include <Windows.h>
#include <time.h>

using std::cout;
using std::cin;
using std::endl;

// 1. 가위바위보 게임
void SRPGame()
{
	srand(time(NULL));

	int GameValue = 5;
	for (int i = 0; i < GameValue; i++)
	{
		int ComputerNum = rand() % 3 + 1;
		int PlayerNum;

		Sleep(300);
		cout << "!!!!가위 바위 보 게임!!!!" << endl;
		cout << "남은 게임 횟수 : " << GameValue - i << endl << endl;
		
		cout << "치트 (컴퓨터가 낸 수) : ";
		if(ComputerNum == 1)cout << ComputerNum <<".가위 " << endl;
		else if (ComputerNum == 2) cout << ComputerNum << ".바위 " << endl;
		else { cout << ComputerNum << ".보 " << endl; }
		
		cout << "숫자를 선택해 주세요 (1.가위, 2.바위, 3.보) : ";
		cin >> PlayerNum;
		Sleep(300);

		if (ComputerNum == PlayerNum)
		{
			cout << "비겼습니다!" << endl;
		}
		else if (ComputerNum == (PlayerNum % 3) + 1)
		{
			cout << "졌습니다!" << endl;
		}
		else
		{
			cout << "이겼습니다!" << endl;
		}

		cout << endl;
	}
	cout << "게임이 종료됩니다..." << endl;
}

// 2. 일수 출력기
void DayPrint()
{
	int PrintNum = 5;
	int PlayerValue;
	int DayNum;

	// if문
	{
		//for (int i = 0; i < PrintNum; i++)
		//{
		//	Sleep(200);
		//	cout << "남은 출력 수 : " << PrintNum - i << endl;
		//	cout << "일수 출력기 원하는 달을 선택하세요 (1월 ~ 12월) : ";
		//	cin >> PlayerValue;

		//	Sleep(100);
		//	//1, 3, 5, 7, 8, 10, 12
		//	cout << PlayerValue << "월 일 수 : ";
		//	if (PlayerValue == 1 || PlayerValue == 3 || PlayerValue == 5 || PlayerValue == 7 || PlayerValue == 8 || PlayerValue == 10 || PlayerValue == 12)
		//	{
		//		cout << 31 << endl;
		//	} // 2
		//	else if (PlayerValue == 2)
		//	{
		//		cout << 28 << endl;
		//	} // 4, 6, 9 ,11
		//	else if (PlayerValue == 4 || PlayerValue == 6 || PlayerValue == 9 || PlayerValue == 11)
		//	{
		//		cout << 30 << endl;
		//	}
		//	else
		//	{
		//		cout << "이 외의 달을 선택하셨습니다. 범위 내 입력해주세요" << endl;
		//	}

		//	cout << endl;
		//}
	}

	// switch문
	for (int i = 0; i < PrintNum; i++)
	{
		Sleep(200);
		cout << "남은 출력 수 : " << PrintNum - i << endl;
		cout << "일수 출력기 원하는 달을 선택하세요 (1월 ~ 12월) : ";
		cin >> PlayerValue;

		Sleep(100);
		cout << PlayerValue << "월 일 수 :";
		switch (PlayerValue)
		{
		case 1: //1, 5, 7, 8, 10, 12
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			DayNum = 31;
			cout << DayNum << endl;
			break;
		case 2: 
			DayNum = 28;
			cout << DayNum << endl;
			break;
		case 4: // 4, 6, 9 ,11
		case 6:
		case 9:
		case 11:
			DayNum = 30;
			cout << DayNum << endl;
			break;
		default:
			cout << "X" << '\n';
			cout << "이 외의 달을 선택하셨습니다.범위 내 입력해주세요!" << endl;
			break;
		}

		cout << '\n';
	}
}


// 3. 함수와 포인터를 활욯한 가위바위보
#define SICCOR 1
int A = SICCOR;
int* B = &A;
int** C = &B;

void* SRPFunction(int* _Siccor, int** _Rock, int*** _Paper)
{
	int GameValue = 5;
	for (int i = 0; i < GameValue; i++)
	{
		int ComputerNum = rand() % 3 + 1;
		int PlayerNum = A;

		Sleep(300);
		cout << "!!!!가위 바위 보 게임!!!!" << endl;
		cout << "남은 게임 횟수 : " << GameValue - i << endl << endl;

		cout << "치트 (컴퓨터가 낸 수) : ";
		if (ComputerNum == 1)cout << ComputerNum << ".가위 " << endl;
		else if (ComputerNum == 2) cout << ComputerNum << ".바위 " << endl;
		else { cout << ComputerNum << ".보 " << endl; }

		cout << "숫자를 선택해 주세요 (1.가위, 2.바위, 3.보) : ";
		cin >> PlayerNum;

		if (PlayerNum == 2)
		{
			//*B += 1;
			*_Rock += 1;
		}
		if (PlayerNum == 3)
		{
			//**C += 2;
			**_Paper += 2;
		}
		Sleep(300);

		if (ComputerNum == PlayerNum)
		{
			cout << "비겼습니다!" << endl;
		}
		else if (ComputerNum == (PlayerNum % 3) + 1)
		{
			cout << "졌습니다!" << endl;
		}
		else
		{
			cout << "이겼습니다!" << endl;
		}

		cout << endl;
	}
	cout << "게임이 종료됩니다..." << endl;



	return 0;
}

int main()
{
	// 1. 가위바위보 게임
	//SRPGame();

	// 2. 일수 출력기
	//DayPrint();

	// 3. 가위바위보 함수 포인터 활용
	SRPFunction(&A, &B, &C);

	return 0;
}