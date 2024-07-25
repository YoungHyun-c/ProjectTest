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

	std::cout << "ī�� ���ӿ� ���Ű� ȯ���մϴ�~~~" << std::endl;
	for (int i = 0; i < 17 && 1 < CardLeft && 0 < PlayerMoney; i++)
	{
		std::cout << "���� ������ : " << PlayerMoney << std::endl;
		printf("���� �ݾ��� �Է����ּ��� (100 ~ %d) : ", PlayerMoney);
		std::cin >> PlayerBatting;
		while (PlayerBatting < 100 || PlayerBatting > PlayerMoney)
		{
			printf("�ּ� ���ñݾװ� ����� ������ ������ �ٽ� �Է��ϼ���! (100 ~ %d) : ", PlayerMoney);
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
				Card.CardObject = "��";
				break;
			case static_cast<int>(CardNum::Spade):
				Card.CardObject = "��";
				break;
			case static_cast<int>(CardNum::Heart):
				Card.CardObject = "��";
				break;
			case static_cast<int>(CardNum::Diamond):
				Card.CardObject = "��";
				break;
			default:
				break;
			}

			int CurCard = Card.CardArr[ChoiceCard][CardNumber];
			CardLeft--;

			if (CurIndex < 2)
			{
				WhoCard = "��ǻ�� ī�� : ";
				ComCard[CurIndex] = CurCard;
			}

			if (CurIndex == 2)
			{
				WhoCard = "�÷��̾� ī�� : ";
				PlayerCard = CurCard;
			}

			CardPrint(WhoCard, CurIndex, CurCard, Card);
			Index++;
		}

		std::sort(ComCard, ComCard + 2);
		printf("��ǻ�� ī�� : %d ~ %d, �÷��̾� ī�� : %d\n", ComCard[0], ComCard[1], PlayerCard);
		if (ComCard[0] < PlayerCard && PlayerCard < ComCard[1])
		{
			std::cout << "�¸��ϼ̽��ϴ�!!!" << std::endl;
			printf("������ : %d + %d X %d\n", PlayerMoney, PlayerBatting, WinBatting);
			PlayerMoney += PlayerBatting * WinBatting;
			std::cout << "����� ������ : " << PlayerMoney << std::endl;
		}
		else
		{
			std::cout << "�����ϴ�..." << std::endl;
			printf("������ : %d - %d X %d\n", PlayerMoney, PlayerBatting, LoseBatting);
			PlayerMoney -= (PlayerBatting * LoseBatting);
			std::cout << "����� ������ : " << PlayerMoney << std::endl;
		}

		if (PlayerMoney <= 0 || CardLeft <= 1)
		{
			std::cout << "������ �������ϴ�..." << std::endl;
			break;
		}

		Sleep(5000);
		std::system("Cls");

		std::cout << "���� ī�� : " << CardLeft << std::endl;
	}
}

int main()
{
	// ī����� �����
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