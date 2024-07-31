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
	std::cout << "���� ī��Ʈ : " << BingoCount << std::endl;
}

void BingoPan::BingoGame()
{
	while (true)
	{

		BingoPrint();

		std::cout << "��ȣ�� �Է����ּ��� : ";
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
			std::cout << "�ִ� ��ȣ�� �Է����ּ���!" << std::endl;
			Sleep(1000);
		}

		BingoCheck();

		system("cls");
		BingoPrint();

		if (BingoCount == 3)
		{
			std::cout << "\n ���� 3���� �Ϸ�Ǿ����ϴ�! \n !!!�����մϴ�!!!\n ������ ����˴ϴ�...";
			break;
		}

		//Sleep(1000);
		system("cls");
	}
}

void BingoPan::BingoCheck()
{
	BingoCount = 0;
	// x �� Ȯ��
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
	// y �� Ȯ��
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

	// �Ʒ� �밢�� Ȯ��
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

	// �� �밢�� Ȯ��
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