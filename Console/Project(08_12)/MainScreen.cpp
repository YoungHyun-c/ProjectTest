#include "MainScreen.h"

#define InterFrame 1000

//void MainScreen::Start()
//{
//	PackMan.PackManSetList();
//	StartPackMan();
//}
//
//void MainScreen::StartPackMan()
//{
//	while (Done)
//	{
//		PackMan.PackManStartScreen();
//		int Num = PackMan.PackManSetting();
//		switch (Num)
//		{
//		case 0:
//			std::cout << "�������� �̵��մϴ�.." << std::endl;
//			Sleep(InterFrame);
//			system("cls");
//			PackMan.PackManUpdate();
//			Done = true;
//			break;
//		case 1:
//			std::cout << "�ʱ�ȭ������ ���ư��ϴ�.." << std::endl;
//			Sleep(InterFrame);
//			system("cls");
//			Done = true;
//			break;
//		case 2:
//			std::cout << "�����մϴ�..." << std::endl;
//			Sleep(InterFrame);
//			system("cls");
//			Done = false;
//			break;
//		default:
//			break;
//		}
//	}
//}