#include <iostream>
#include <Windows.h>


// 1번. 입력받은 숫자의 구구단 출력
void GoGoDan()
{
	//입력
	int InputNum;
	std::cout << "단을 입력해주세요 : ";
	std::cin >> InputNum;
	int arr[10] = {};

	//처리
	printf("%d 단 : \n", InputNum);
	for (int i = 1; i < 10; i++)
	{
		arr[i - 1] = InputNum * i;
	}
	//결과
	for (int i = 1; i < 10; i++)
	{
		printf("%d x %d  = %d\n", InputNum, i, arr[i - 1]);
	}
}

// 2번. 랜덤배열 생성 및 합.
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

	// 가로합 출력
	for (int i = 0; i < YNum; i++)
	{
		int XTotal = 0;
		for (int j = 0; j < XNum; j++)
		{
			XTotal += RanArr[i][j];
		}
		printf("%d 번째 줄 X 합 : %d\n", i + 1, XTotal);
	}

	std::cout << std::endl;

	// 세로합 출력
	for (int i = 0; i < XNum; i++)
	{
		int YTotal = 0;
		for (int j = 0; j < YNum; j++)
		{
			YTotal += RanArr[j][i];
		}
		printf("%d 번째 줄 Y 합 : %d\n", i + 1, YTotal);
	}
}

#include <algorithm>
#include <random>
#include <ctime>
// 3번. 숫자야구
// 셔플 함수 만들기
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
	// 셔플 사용
	/*int Com[3] = { 10, 20, 30 };
	int N = sizeof(Com) / sizeof(Com[0]);
	Shuffle_Array(Com, N);*/
	
	constexpr size_t BallNum = 3;
	size_t GameNum = 3;
	int Out = 0;
	for (int i = 1; i <= GameNum; i++)
	{
		printf("%d 번째 게임 ! \n", i);
		int Com[3] = { 0 };
		std::cout << "컴퓨터 번호 : ";
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
				std::cout << i + 1 << "번째 번호 : ";
				std::cin >> Player[i];
				while (Player[i] > 10 || Player[i] < 1)
				{
					std::cout << "범위 내 숫자를 입력해주세요. (1 ~ 10)\n";
					std::cout << i + 1 << "번째 번호 : ";
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
				std::cout << ("맞았습니다~ 축하합니다! \n");
			}

			printf("%d 스트라이크 , %d 볼, %d 아웃\n", Strike, Ball, Out);
		}

		Sleep(3000);
		system("cls");
	}

	std::cout << "게임이 종료됩니다...";
}

int main()
{
	// 1. 구구단.
	//GoGoDan();

	// 2. 랜덤배열
	//RandArr();

	// 3. 숫자야구
	BaseBallGame();

	return 0;
}