#include <iostream>
#include <random>
#include <algorithm>
#include <windows.h>

enum class CardNum
{
	Clover = 0,
	Spade = 1,
	Heart = 2,
	Diamond = 3,
};

struct Cards
{
	int CardValue = 52;
	int CardArr[4][13] = { };

	std::string CardObject = " ";

	void CardDeclareNum();
};

void RandomNum(int _Arr[], int _RandFrist = 0, int _RandEnd = 12)
{
	std::random_device Rd;
	std::mt19937 gen(Rd());
	std::uniform_int_distribution<> dist(_RandFrist, _RandEnd);
	int Dest, Sour, Temp;
	for (int i = 0; i < 100; i++)
	{
		Dest = dist(gen);
		Sour = dist(gen);

		Temp = _Arr[Dest];
		_Arr[Dest] = _Arr[Sour];
		_Arr[Sour] = Temp;
	}
}

void Cards::CardDeclareNum()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j < 14; j++)
		{
			CardArr[i][j - 1] = j;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		RandomNum(CardArr[i]);
	}
}

void CardPrint(std::string _WhoCard, int _CurIndex, int _Num, Cards _Card);


void CardGame()
{
	Cards Card;
	Card.CardDeclareNum();

	int CardCheck[53] = {};
	for (int i = 0; i < 52; i++)
	{
		CardCheck[i] = i;
	}
	RandomNum(CardCheck, 0, 51);
	int CardLeft = Card.CardValue;

	int PlayerMoney = 10000;
	int Index = 0;
	int PlayerBatting = 100;
	int WinBatting = 3;
	int LoseBatting = 2;
	std::string WhoCard = "";

	std::cout << "카드 게임에 오신걸 환영합니다~~~" << std::endl;
	for (int i = 0; i < 17 && 1 < CardLeft && 0 < PlayerMoney; i++)
	{
		std::cout << "남은 소지금 : " << PlayerMoney << std::endl;
		printf("배팅 금액을 입력해주세요 (100 ~ %d) : ", PlayerMoney);
		std::cin >> PlayerBatting;
		while (PlayerBatting < 100 || PlayerBatting > PlayerMoney)
		{
			printf("최소 배팅금액과 당신의 소지금 내에서 다시 입력하세요! (100 ~ %d) : ", PlayerMoney);
			std::cin >> PlayerBatting;
		}
		int ComCard[2] = {};
		int PlayerCard = 0;

		for (int CurIndex = 0; CurIndex < 3; CurIndex++)
		{
			int ChoiceCard = (CardCheck[Index] / 13);
			int CardNumber = ((CardCheck[Index] % 13));
			switch (ChoiceCard)
			{
			case static_cast<int>(CardNum::Clover):
				Card.CardObject = "♧";
				break;
			case static_cast<int>(CardNum::Spade):
				Card.CardObject = "♤";
				break;
			case static_cast<int>(CardNum::Heart):
				Card.CardObject = "♡";
				break;
			case static_cast<int>(CardNum::Diamond):
				Card.CardObject = "◆";
				break;
			default:
				break;
			}

			int CurCard = Card.CardArr[ChoiceCard][CardNumber];
			CardLeft--;

			if (CurIndex < 2)
			{
				WhoCard = "컴퓨터 카드 : ";
				ComCard[CurIndex] = CurCard;
			}

			if (CurIndex == 2)
			{
				WhoCard = "플레이어 카드 : ";
				PlayerCard = CurCard;
			}

			CardPrint(WhoCard, CurIndex, CurCard, Card);
			Index++;
		}

		std::sort(ComCard, ComCard + 2);
		printf("컴퓨터 카드 : %d ~ %d, 플레이어 카드 : %d\n", ComCard[0], ComCard[1], PlayerCard);
		if (ComCard[0] < PlayerCard && PlayerCard < ComCard[1])
		{
			std::cout << "승리하셨습니다!!!" << std::endl;
			printf("소지금 : %d + %d X %d\n", PlayerMoney, PlayerBatting, WinBatting);
			PlayerMoney += PlayerBatting * WinBatting;
			std::cout << "당신의 소지금 : " << PlayerMoney << std::endl;
		}
		else
		{
			std::cout << "졌습니다..." << std::endl;
			printf("소지금 : %d - %d X %d\n", PlayerMoney, PlayerBatting, LoseBatting);
			PlayerMoney -= (PlayerBatting * LoseBatting);
			std::cout << "당신의 소지금 : " << PlayerMoney << std::endl;
		}

		if (PlayerMoney <= 0 || CardLeft <= 1)
		{
			std::cout << "게임이 끝났습니다..." << std::endl;
			break;
		}

		Sleep(5000);
		std::system("Cls");

		std::cout << "남은 카드 : " << CardLeft << std::endl;
	}
}

int main()
{
	// 카드게임 만들기
	CardGame();

	return 0;
}

void CardPrint(std::string _WhoCard, int _CurIndex, int _CurCard, Cards _Card)
{
	if (_CurCard <= 10)
	{
		std::cout << _WhoCard;
		std::cout << _Card.CardObject << " ." << _CurCard << std::endl;
	}
	else if (_CurCard > 10)
	{
		// J = 11, Q = 12, K = 13
		std::cout << _WhoCard;
		std::string JQK = "";
		switch (_CurCard)
		{
		case 11:
			JQK = "J";
			break;
		case 12:
			JQK = "Q";
			break;
		case 13:
			JQK = "K";
			break;
		default:
			break;
		}
		std::cout << _Card.CardObject << " . " << JQK << std::endl;
	}
}