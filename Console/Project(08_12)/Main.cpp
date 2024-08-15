#include <windows.h>

#include <iostream>
#include <conio.h>

using namespace std;

#include "MainScreen.h"
#include "PackManScreen.h"
#include "Utill.h"

#include "Map.h"
#include "Player.h"
#include "Monster.h"
#include "Item.h"

#include <stdio.h>

#include "GameObjectManager.h"
#include "GameEnum.h"

int main() {

    system("mode con cols= 110 lines= 70 | title Á¦¸ñ¸í");
    //Utill Handle;
    //char Bullet = '*';
    //int XStart = 25;
    //int YStart = 12;
    //char Ch;
    ////Ch = _getch();
    //Handle.Gotoxy(XStart, YStart);
    //std::cout << Bullet << std::endl;
    //float time;
    //clock_t start, end;
    //start = clock();
    //while (true)
    //{
    //    int nSelect;
    //    end = clock();
    //    time = ((float)(end - start) / CLOCKS_PER_SEC);
    //    if (GetCursorPos(&MousePoint)) {
    //        float X = MousePoint.x / 1920.0f;
    //        float Y = MousePoint.y / 1080.0f;
    //        //cout << (MousePoint.x / 1920.0f) << "," << (MousePoint.y / 1080.0f) << "\n";
    //        //if (Ch == 'k')
    //        //{
    //        //    Handle.Gotoxy(XStart, YStart);
    //        //    //cout << X << ", " << Y << "\n";
    //        //}
    //        if (time >= 1.5)
    //        {
    //            XStart -= X * 0.01f;
    //            YStart -= Y * 0.01f;
    //            Handle.Gotoxy(XStart, YStart);
    //            std::cout << Bullet << std::endl;
    //            start = clock();
    //        }
    //    }
    //}

    {
        //Player Play;
        /*while (true)
        {
            Play.PlayerPrint();
            Play.PlayerMove();

            system("cls");
            Sleep(300);
        }*/
        /*Monster Mon = Monster(12, 12);
        Mon.MonsterPrint();*/

        //Monster Mon = Monster(9, 9); // ÆÄ¶û
        //Mon.MonsterPrint();

        //Monster Mon = Monster(13, 13); // º¸¶ó
        //Mon.MonsterPrint();

        //Monster Mon = Monster(14, 14); // ³ë¶û
        //Mon.MonsterPrint();
    }


    int2 ScreenSize = { 100, 40 };
    PackManScreen::GetMainScreen().SetScreenSize(ScreenSize);
    PackManScreen::GetMainScreen().VoidCursor();
    // PackManScreen::GetMainScreen().InitGame();

    GameObjectManager::CreateConsoleObject<Player>(ObjectOrder::Player);
    //GameObjectManager::CreateConsoleObject<Item>(ObjectOrder::Item);

    while (true)
    {
        while (Player::IsGameUpdate)
        {
            GameObjectManager::ConsoleAllObjectUpdate();
            GameObjectManager::ConsoleAllObjectRender();
            //GameObjectManager::ConsoleAllObjectRelease();
        }
        if (Player::IsGameUpdate == false)
        {
            char Ch = _getch();
            if (Ch == 'p')
            {
                Player::IsGameUpdate = true;
            }
        }
    }
  
    GameObjectManager::ConsoleAllObjectDelete();

    return 0;
}