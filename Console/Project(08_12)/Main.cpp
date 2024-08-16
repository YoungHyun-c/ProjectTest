#include <windows.h>

#include <iostream>
#include <stdio.h>
#include <conio.h>

#include "PackManScreen.h"
#include "Utill.h"

#include "Map.h"
#include "Player.h"
#include "Monster.h"
#include "Item.h"

int main()
{
    system("mode con cols = 100 lines = 50 | title PackMan");
    // 프레임이 너무 느려 간단하게 바꾸기

    int2 ScreenSize = { 100, 50 };
    PackManScreen::GetMainScreen().SetScreenSize(ScreenSize);

    PackManScreen::GetMainScreen().Start();


    {
        /*Monster Mon = Monster(12, 12);
        Mon.MonsterPrint();*/

        //Monster Mon = Monster(9, 9); // 파랑
        //Mon.MonsterPrint();

        //Monster Mon = Monster(13, 13); // 보라
        //Mon.MonsterPrint();

        //Monster Mon = Monster(14, 14); // 노랑
        //Mon.MonsterPrint();
    }

    // 만들었던 프레임 워크 이거로 안할꺼임
    {
        //int2 ScreenSize = { 100, 50 };
        //PackManScreen::GetMainScreen().SetScreenSize(ScreenSize);
        //PackManScreen::GetMainScreen().VoidCursor();

        //GameObjectManager::CreateConsoleObject<Player>(ObjectOrder::Player);
        //while (true)
        //{
        //    while (Player::IsGameUpdate)
        //    {
        //        GameObjectManager::ConsoleAllObjectUpdate();
        //        GameObjectManager::ConsoleAllObjectRender();
        //        //GameObjectManager::ConsoleAllObjectRelease();
        //    }
        //    if (Player::IsGameUpdate == false)
        //    {
        //        char Ch = _getch();
        //        if (Ch == 'p')
        //        {
        //            Player::IsGameUpdate = true;
        //        }
        //    }
        //}
        //GameObjectManager::ConsoleAllObjectDelete();
    }

    return 0;
}


// 바깥에서 시간
// clock_t start = clock();
 //void Player::PlayerPrint(clock_t _Start)
    //{*/
    //    /*clock_t current = clock() - _Start;
    //    int sec;
    //    sec = current / CLOCKS_PER_SEC;
    //    if (sec < 0.5)
    //    {
    //        DrawChar(PlayerPos.X, PlayerPos.Y , PlayerArr1);
    //    }
    //    if (1 < sec)
    //    {
    //        DrawChar(PlayerPos.X, PlayerPos.Y, PlayerArr2);
    //        sec = 0;
    //    }*/
    //}