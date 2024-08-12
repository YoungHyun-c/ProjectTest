#include "PackManScreen.h"

#define InterFrame 1000

void PackManScreen::Start()
{
	PackManSetList();
	GameSetList();
}

void PackManScreen::GameSetList()
{
	while (Done)
	{
		PackManStartScreen();
		int Num = PackManSetting();
		switch (Num)
		{
		case 0:
			std::cout << "�������� �̵��մϴ�.." << std::endl;
			Sleep(InterFrame);
			system("cls");
			PackManUpdate();
			Done = true;
			break;
		case 1:
			std::cout << "�����մϴ�..." << std::endl;
			Sleep(InterFrame);
			system("cls");
			Done = false;
			break;
		case 2:
			std::cout << "�ʱ�ȭ������ ���ư��ϴ�.." << std::endl;
			Sleep(InterFrame);
			system("cls");
			Done = true;
			break;
		default:
			break;
		}
	}
}

void PackManScreen::PackManStartScreen()
{
	Y = 3;
	Handle.Gotoxy(X, Y++);
	std::cout << "==========================================================" << std::endl;
	Handle.Gotoxy(X, Y++);
	std::cout << "||                                                      ||" << std::endl;
	Handle.Gotoxy(X, Y++);
	std::cout << "||                                                      ||" << std::endl;
	Handle.Gotoxy(X, Y++);
	std::cout << "||                                                      ||" << std::endl;
	Handle.Gotoxy(X, Y++);
	std::cout << "||                                                      ||" << std::endl;
	Handle.Gotoxy(X, Y++);
	std::cout << "||                                                      ||" << std::endl;
	Handle.Gotoxy(X, Y++);
	std::cout << "||                ���ӿ� ���Ű� ȯ���մϴ�.             ||" << std::endl;
	Handle.Gotoxy(X, Y++);
	std::cout << "||                                                      ||" << std::endl;
	Handle.Gotoxy(X, Y++);
	std::cout << "||                                                      ||" << std::endl;
	Handle.Gotoxy(X, Y++);
	std::cout << "||                                                      ||" << std::endl;
	Handle.Gotoxy(X, Y++);
	std::cout << "||                                                      ||" << std::endl;
	Handle.Gotoxy(X, Y++);
	std::cout << "||                                                      ||" << std::endl;
	Handle.Gotoxy(X, Y++);
	std::cout << "||                                                      ||" << std::endl;
	Handle.Gotoxy(X, Y++);
	std::cout << "||                                                      ||" << std::endl;
	Handle.Gotoxy(X, Y++);
	std::cout << "==========================================================" << std::endl;
}

void PackManScreen::PackManMapPrint()
{
	std::cout << "=======" << std::endl;
	std::cout << "==   ==" << std::endl;
	std::cout << "== = ==" << std::endl;
	std::cout << "== = ==" << std::endl;
}

void PackManScreen::PackManSetList()
{
	List.push_back("1. ������ �����Ѵ�.");
	List.push_back("2. �ʱ�ȭ������ ���ư���.");
	List.push_back("3. ������ �����Ѵ�.");
}

int PackManScreen::PackManSetting()
{
	return Handle.PrintScreen(X + 14, Y, List);
}


void PackManScreen::PackManUpdate()
{
	PackManMapPrint();
}

