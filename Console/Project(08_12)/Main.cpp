#include <windows.h>

#include <iostream>
#include <stdio.h>
#include <conio.h>

#include "PackManScreen.h"
#include "Utill.h"

#include "AStartPathFinder.h"


int main()
{
    system("mode con cols = 100 lines = 50 | title PackMan");
    // 프레임이 너무 느려 간단하게 바꾸기

    int2 ScreenSize = { 100, 50 };
    PackManScreen::GetMainScreen().SetScreenSize(ScreenSize);

    PackManScreen::GetMainScreen().Start();


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