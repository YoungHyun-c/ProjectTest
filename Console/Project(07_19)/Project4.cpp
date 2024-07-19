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
	int PlayerDay;

	for (int i = 0; i < PrintNum; i++)
	{
		Sleep(200);
		cout << "���� ��� �� : " << PrintNum - i << endl;
		cout << "�ϼ� ��±� ���ϴ� ���� �����ϼ��� (1�� ~ 12��) : ";
		cin >> PlayerDay;

		Sleep(100);
		//1, 5, 7, 8, 10, 12
		cout << PlayerDay << "�� �� �� : ";
		if (PlayerDay == 1 || PlayerDay == 3 || PlayerDay == 5 || PlayerDay == 7 || PlayerDay == 8 || PlayerDay == 10 || PlayerDay == 12)
		{
			cout << 31 << endl;
		} // 2
		else if (PlayerDay == 2)
		{
			cout << 28 << endl;
		} // 4, 6, 9 ,11
		else if (PlayerDay == 4 || PlayerDay == 6 || PlayerDay == 9 || PlayerDay == 11)
		{
			cout << 30 << endl;
		}
		else
		{
			cout << "�� ���� ���� �����ϼ̽��ϴ�. ���� �� �Է����ּ���" << endl;
		}

		cout << endl;

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
			*B += 1;
		}
		if (PlayerNum == 3)
		{
			**C += 2;
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