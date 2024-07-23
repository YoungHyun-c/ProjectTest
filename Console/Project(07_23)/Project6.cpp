#include <iostream>
#include <Windows.h>


// 1��. �Է¹��� ������ ������ ���
void GoGoDan()
{
	//�Է�
	int InputNum;
	std::cout << "���� �Է����ּ��� : ";
	std::cin >> InputNum;
	int arr[10] = {};

	//ó��
	printf("%d �� : \n", InputNum);
	for (int i = 1; i < 10; i++)
	{
		arr[i - 1] = InputNum * i;
	}
	//���
	for (int i = 1; i < 10; i++)
	{
		printf("%d x %d  = %d\n", InputNum, i, arr[i - 1]);
	}
}

// 2��. �����迭 ���� �� ��.
void RandArr()
{
	srand(time(NULL));
	constexpr int YNum = 4;
	constexpr int XNum = 5;

	int RanArr[YNum][XNum] = { 0 };

	for (int i = 0; i < YNum; i++)
	{
		for (int j = 0; j < XNum; j++)
		{
			RanArr[i][j] = rand() % 100 + 1;
			std::cout << RanArr[i][j] << " ";
		}
		std::cout << '\n';
	}

	// ������ ���
	for (int i = 0; i < YNum; i++)
	{
		int XTotal = 0;
		for (int j = 0; j < XNum; j++)
		{
			XTotal += RanArr[i][j];
		}
		printf("%d ��° �� X �� : %d\n", i + 1, XTotal);
	}

	std::cout << std::endl;

	// ������ ���
	for (int i = 0; i < XNum; i++)
	{
		int YTotal = 0;
		for (int j = 0; j < YNum; j++)
		{
			YTotal += RanArr[j][i];
		}
		printf("%d ��° �� Y �� : %d\n", i + 1, YTotal);
	}
}

#include <algorithm>
#include <random>
#include <ctime>
// 3��. ���ھ߱�
// ���� �Լ� �����
void Shuffle_Array(int _Arr[], int _Num)
{
	unsigned Seed = 0;

	std::shuffle(_Arr, _Arr + _Num, std::default_random_engine(Seed));
}

int RandomNum(int _Arr[], int _Len)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(1, 10);
	int Num = dis(gen);
	
	for (int i = 0; i < _Len; i++)
	{
		while(Num == _Arr[i])
		{
			Num = dis(gen);
		}
	}

	return Num;
}

void BaseBallGame()
{
	// ���� ���
	/*int Com[3] = { 10, 20, 30 };
	int N = sizeof(Com) / sizeof(Com[0]);
	Shuffle_Array(Com, N);*/
	
	constexpr size_t BallNum = 3;
	size_t GameNum = 3;
	int Out = 0;
	for (int i = 1; i <= GameNum; i++)
	{
		printf("%d ��° ���� ! \n", i);
		int Com[3] = { 0 };
		std::cout << "��ǻ�� ��ȣ : ";
		for (size_t i = 0; i < 3; i++)
		{
			Com[i] = RandomNum(Com, 3);
			std::cout << Com[i] << " ";
		}
		std::cout << std::endl;

		bool GameStart = true;
		while (GameStart)
		{
			int Ball = 0, Strike = 0;
			int Player[BallNum] = {};
			for (size_t i = 0; i < BallNum; i++)
			{
				std::cout << i + 1 << "��° ��ȣ : ";
				std::cin >> Player[i];
				while (Player[i] > 10 || Player[i] < 1)
				{
					std::cout << "���� �� ���ڸ� �Է����ּ���. (1 ~ 10)\n";
					std::cout << i + 1 << "��° ��ȣ : ";
					std::cin >> Player[i];
				}
			}

			for (size_t i = 0; i < BallNum; i++)
			{
				for (size_t j = 0; j < BallNum; j++)
				{
					if (Com[i] == Player[j] && i == j)
					{
						Strike++;
					}
					else if (Com[i] == Player[j])
					{
						Ball++;
					}
				}
			}

			if (Strike == 3)
			{
				GameStart = false;
				Out++;
				std::cout << ("�¾ҽ��ϴ�~ �����մϴ�! \n");
			}

			printf("%d ��Ʈ����ũ , %d ��, %d �ƿ�\n", Strike, Ball, Out);
		}

		Sleep(3000);
		system("cls");
	}

	std::cout << "������ ����˴ϴ�...";
}

int main()
{
	// 1. ������.
	//GoGoDan();

	// 2. �����迭
	//RandArr();

	// 3. ���ھ߱�
	BaseBallGame();

	return 0;
}