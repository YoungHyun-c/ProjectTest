#include <iostream>
#include <random>
#include <algorithm>
#include <vector>

enum class CardNum
{
	Clover = 0,
	Spade = 1,
	Heart = 2,
	Diamond = 3,
};
// J = 11, Q = 12, K = 13

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


void CardGame()
{
	Cards Card;
	Card.CardDeclareNum();
	std::cout << "카드 : ";
	std::cout << std::endl;
	for (int j = 0; j < 4; j++)
	{
		for (int k = 0; k < 13; k++)
		{
			std::cout << Card.CardArr[j][k] << " ";
		}
		std::cout << std::endl;
	}

	std::random_device Rd;
	std::mt19937 gen(Rd());
	std::uniform_int_distribution<> dist(0, 3);
	int CardCheck[53] = {};
	for (int i = 1; i < 53; i++)
	{
		CardCheck[i] = i;
	}
	RandomNum(CardCheck, 0, 51);

	int PlayerMoney = 10000;
	int Index = 0;
	for (int i = 0; i < 2; i++)
	{
		int ChoiceCard = (CardCheck[Index] / 13);
		if (ChoiceCard == 4)
		{
			ChoiceCard = 3;
		}
		int CardNumber = ((CardCheck[Index] % 13));
		int PlayerBatting = 1000;
		//std::cout << "배팅 금액을 입력해주세요 : ";
		//std::cin >> PlayerBatting;

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
			Card.CardObject = "◇";
			break;
		default:
			break;
		}
		int CurCard = Card.CardArr[ChoiceCard][CardNumber];

		std::cout << "카드 뽑은 횟수 : "<< i + 1 << std::endl;
		std::cout << "초이스 : " << ChoiceCard << std::endl;
		std::cout << "넘버 : " << CardNumber << std::endl;
		std::cout << "컴퓨터 카드 : ";
		std::cout << Card.CardObject << " ." << CurCard << std::endl;

		Index++;
	}
}

int main()
{
	// 카드게임 만들기
	CardGame();

	return 0;
}


//std::cout << "플레이어 카드 : ";
//std::cout << Card.CardObject << " ." << Card.CardArr[ChoiceCard][CardNumber] << std::endl;
//PlayerNum = Card.CardArr[ChoiceCard][CardNumber];
//CardNumber++;
//Index += 2;
//
//if (PlayerNum > ComArr[0] || PlayerNum < ComArr[1])
//{
//	std::cout << "승리하셨습니다." << std::endl;
//	printf("소지금 %d + 배팅금액 %d X 3 당신의 소지금 : %d", PlayerMoney, PlayerBatting, PlayerMoney);
//}


	/*for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			
			std::cout << CheckCard[i][j];
		}
		std::cout << std::endl;
	}*/

	//Cards Card;
	//Card.CardDeclareNum();

	//std::cout << "카드 : ";
	//std::cout << std::endl;
	//for (int j = 0; j < 4; j++)
	//{
	//	for (int i = 0; i < 13; i++)
	//	{
	//		std::cout << Card.CardArr[j][i] << " ";
	//	}
	//	std::cout << std::endl;
	//}
