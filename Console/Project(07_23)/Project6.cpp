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

void TeacherBaseBall()
{
	srand(time(NULL));

	int number[10];
	int comNumber[3];
	int playerNumber[3];
	int dest, sour, temp;
	int ballCount;
	int strikeCount;

	for (size_t i = 0; i < 10; i++) // 초기화
	{
		number[i] = i;
	}
	for (size_t i = 0; i < 500; i++) // 섞고
	{
		dest = rand() % 10;
		sour = rand() % 10;

		temp = number[dest];
		number[dest] = number[sour];
		number[sour] = temp;
	}
	// 컴퓨터 숫자 받자.
	for (size_t i = 0; i < 3; i++)
	{
		comNumber[i] = number[i];
	}

	std::cout << "컴퓨터가 낸 숫자 :";
	for (size_t i = 0; i < 3; i++)
	{
		std::cout << comNumber[i] << " ";
	}
	std::cout << std::endl << std::endl;

	// 게임이 돌아가는 루프
	while (true)
	{
		std::cout << "0 ~ 9 까지 숫자를 입력해보시오☞ : " << std::endl;
		// 플레이어의 숫자를 3개 입력해라.
		for (size_t i = 0; i < 3; i++)
		{
			std::cout << i + 1 << "번째 숫자를 입력해라 ☞ ";
			std::cin >> playerNumber[i];
		}
		// 0으로 초기화.
		ballCount = 0;
		strikeCount = 0;

		//컴
		for (size_t i = 0; i < 3; i++)
		{
			//플
			for (size_t k = 0; k < 3; k++)
			{
				//컴퓨터 숫자와 내가 입력한 숫자가 같냐?
				if (comNumber[i] == playerNumber[k])
				{
					// 자리까지 같냐?
					if (i == k)
					{
						strikeCount++;
					}
					else
					{
						ballCount++;
					}
				}
			}
		}// end of for

		std::cout << ballCount << "볼" << strikeCount << "스트라잌" << std::endl;

		if (strikeCount == 3)
		{
			std::cout << "삼진 아웃" << std::endl;
			break;
		}
	}

}

int main()
{
	// 1. 구구단.
	//GoGoDan();

	// 2. 랜덤배열
	//RandArr();

	// 3. 숫자야구
	//BaseBallGame();

	// 선생님풀이
	TeacherBaseBall();

	return 0;
}