#include <iostream>
#include <algorithm>
#include <random>
#include <string>
#include <Windows.h>

struct BingoPan
{
	std::string Bingo[25] = {};

	int BingoCount = 0;

	void BingoMade();
	void BingoPrint();
	void BingoGame();

	void BingoCheck();
};

void BingoPan::BingoMade()
{
	for (int i = 1; i <= 25; i++)
	{
		Bingo[i - 1] = std::to_string(i);
	}

	std::random_device Rd;
	std::mt19937 Gen(Rd());
	std::uniform_int_distribution<> Dist(0, 24);

	int Sour, Dest;
	std::string Temp;
	for (int i = 0; i < 100; i++)
	{
		Dest = Dist(Gen);
		Sour = Dist(Gen);

		Temp = Bingo[Dest];
		Bingo[Dest] = Bingo[Sour];
		Bingo[Sour] = Temp;
	}
}

void BingoPan::BingoPrint()
{
	for (int i = 0; i < 25; i++)
	{
		if (i / 5 != 0  && i % 5 == 0)
		{
			std::cout << std::endl;
		}
		std::cout.width(2);
		std::cout << std::right << Bingo[i] << " " ;
	}

	std::cout << std::endl;
	std::cout << "빙고 카운트 : " << BingoCount << std::endl;
}

void BingoPan::BingoGame()
{
	while (true)
	{

		BingoPrint();

		std::cout << "번호를 입력해주세요 : ";
		int PlayerNum;
		std::cin >> PlayerNum;
		auto Found = std::find(std::begin(Bingo), std::end(Bingo), std::to_string(PlayerNum));
		if (Found != std::end(Bingo))
		{
			int Index = std::distance(Bingo, Found);
			Bingo[Index] = "*";
		}
		else
		{
			std::cout << "있는 번호를 입력해주세요!" << std::endl;
			Sleep(1000);
		}

		BingoCheck();

		system("cls");
		BingoPrint();

		if (BingoCount == 3)
		{
			std::cout << "\n 빙고 3개가 완료되었습니다! \n !!!축하합니다!!!\n 게임이 종료됩니다...";
			break;
		}

		//Sleep(1000);
		system("cls");
	}
}

void BingoPan::BingoCheck()
{
	BingoCount = 0;
	// x 축 확인
	for (int i = 0; i < 5; i++)
	{
		int Count = 0;
		for (int j = 0; j < 5; j++)
		{
			if (Bingo[(i * 5) + j] == "*")
			{
				Count++;
			}
		}
		if (Count == 5)
		{
			BingoCount++;
		}
	}
	// y 축 확인
	for (int i = 0; i < 5; i++)
	{
		int Count = 0;
		for (int j = 0; j < 5; j++)
		{
			if (Bingo[(j * 5) + i] == "*")
			{
				Count++;
			}
		}
		if (Count == 5)
		{
			BingoCount++;
		}
	}

	// 아래 대각선 확인
	int Count = 0;
	for (int i = 0; i < 5; i++)
	{
		if (Bingo[(i * 5) + i] == "*")
		{
			Count++;
		}
	}
	if (Count == 5)
	{
		BingoCount++;
	}

	// 위 대각선 확인
	Count = 0;
	for (int i = 5; i > 0; i--)
	{
		if (Bingo[(i * 4)] == "*")
		{
			Count++;
		}
	}
	if (Count == 5)
	{
		BingoCount++;
	}
}

int main()
{
	BingoPan Bingo;
	Bingo.BingoMade();	
	Bingo.BingoGame();


	return 0;
}