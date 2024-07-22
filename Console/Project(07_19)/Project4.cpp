#include <iostream>
#include <Windows.h>
#include <time.h>

using std::cout;
using std::cin;
using std::endl;

// 1. ���������� ����
void SRPGame()
{
	srand(time(NULL));

	int GameValue = 5;
	for (int i = 0; i < GameValue; i++)
	{
		int ComputerNum = rand() % 3 + 1;
		int PlayerNum;

		Sleep(300);
		cout << "!!!!���� ���� �� ����!!!!" << endl;
		cout << "���� ���� Ƚ�� : " << GameValue - i << endl << endl;
		
		cout << "ġƮ (��ǻ�Ͱ� �� ��) : ";
		if(ComputerNum == 1)cout << ComputerNum <<".���� " << endl;
		else if (ComputerNum == 2) cout << ComputerNum << ".���� " << endl;
		else { cout << ComputerNum << ".�� " << endl; }
		
		cout << "���ڸ� ������ �ּ��� (1.����, 2.����, 3.��) : ";
		cin >> PlayerNum;
		Sleep(300);

		if (ComputerNum == PlayerNum)
		{
			cout << "�����ϴ�!" << endl;
		}
		else if (ComputerNum == (PlayerNum % 3) + 1)
		{
			cout << "�����ϴ�!" << endl;
		}
		else
		{
			cout << "�̰���ϴ�!" << endl;
		}

		cout << endl;
	}
	cout << "������ ����˴ϴ�..." << endl;
}

// 2. �ϼ� ��±�
void DayPrint()
{
	int PrintNum = 5;
	int PlayerValue;
	int DayNum;

	// if��
	{
		//for (int i = 0; i < PrintNum; i++)
		//{
		//	Sleep(200);
		//	cout << "���� ��� �� : " << PrintNum - i << endl;
		//	cout << "�ϼ� ��±� ���ϴ� ���� �����ϼ��� (1�� ~ 12��) : ";
		//	cin >> PlayerValue;

		//	Sleep(100);
		//	//1, 3, 5, 7, 8, 10, 12
		//	cout << PlayerValue << "�� �� �� : ";
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
		//		cout << "�� ���� ���� �����ϼ̽��ϴ�. ���� �� �Է����ּ���" << endl;
		//	}

		//	cout << endl;
		//}
	}

	// switch��
	for (int i = 0; i < PrintNum; i++)
	{
		Sleep(200);
		cout << "���� ��� �� : " << PrintNum - i << endl;
		cout << "�ϼ� ��±� ���ϴ� ���� �����ϼ��� (1�� ~ 12��) : ";
		cin >> PlayerValue;

		Sleep(100);
		cout << PlayerValue << "�� �� �� :";
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
			cout << "�� ���� ���� �����ϼ̽��ϴ�.���� �� �Է����ּ���!" << endl;
			break;
		}

		cout << '\n';
	}
}


// 3. �Լ��� �����͸� Ȱ�G�� ����������
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
		cout << "!!!!���� ���� �� ����!!!!" << endl;
		cout << "���� ���� Ƚ�� : " << GameValue - i << endl << endl;

		cout << "ġƮ (��ǻ�Ͱ� �� ��) : ";
		if (ComputerNum == 1)cout << ComputerNum << ".���� " << endl;
		else if (ComputerNum == 2) cout << ComputerNum << ".���� " << endl;
		else { cout << ComputerNum << ".�� " << endl; }

		cout << "���ڸ� ������ �ּ��� (1.����, 2.����, 3.��) : ";
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
			cout << "�����ϴ�!" << endl;
		}
		else if (ComputerNum == (PlayerNum % 3) + 1)
		{
			cout << "�����ϴ�!" << endl;
		}
		else
		{
			cout << "�̰���ϴ�!" << endl;
		}

		cout << endl;
	}
	cout << "������ ����˴ϴ�..." << endl;



	return 0;
}

int main()
{
	// 1. ���������� ����
	//SRPGame();

	// 2. �ϼ� ��±�
	//DayPrint();

	// 3. ���������� �Լ� ������ Ȱ��
	SRPFunction(&A, &B, &C);

	return 0;
}