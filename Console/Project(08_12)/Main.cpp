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

//struct stRect
//{
//    int nWidht;
//    int nHeight;
//};
//struct stConsole
//{
//    HANDLE hConsole;
//    stRect rtConsole;
//    HANDLE hBuffer[2];
//
//    int nCurBuffer;
//
//    stConsole()
//        : hConsole(nullptr), hBuffer{ nullptr, }, nCurBuffer(0)
//    {}
//};
//
//stConsole Console;
//void InitGame(bool bInitConsole = true);
//void BufferFlip();
//void ClearScreen();
//void DestroyGame();

int main() {

    system("mode con cols= 110 lines= 70 | title 제목명");
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

        //Monster Mon = Monster(9, 9); // 파랑
        //Mon.MonsterPrint();

        //Monster Mon = Monster(13, 13); // 보라
        //Mon.MonsterPrint();

        //Monster Mon = Monster(14, 14); // 노랑
        //Mon.MonsterPrint();
    }


    int2 ScreenSize = { 100, 40 };
    PackManScreen::GetMainScreen().SetScreenSize(ScreenSize);
    PackManScreen::GetMainScreen().VoidCursor();
    PackManScreen::GetMainScreen().InitGame();

    GameObjectManager::CreateConsoleObject<Player>(ObjectOrder::Player);
    //GameObjectManager::CreateConsoleObject<Item>(ObjectOrder::Item);

    //InitGame();
    //char chBuf[256] = { 0 , };
    //COORD coord{ 0, 0 };
    //DWORD dw = 0;

    //while (true)
    //{
    //    memset(chBuf, 0, sizeof(chBuf));
    //    int nLen = sprintf_s(chBuf, sizeof(chBuf), "Test");
    //    SetConsoleCursorPosition(Console.hBuffer[Console.nCurBuffer], coord);
    //    WriteFile(Console.hBuffer[Console.nCurBuffer], chBuf, nLen, &dw, NULL);

    //    ClearScreen();
    //    BufferFlip();
    //    Sleep(1);
    //}

    //DestroyGame();

    while (true)
    {
        while (Player::IsGameUpdate)
        {

            GameObjectManager::ConsoleAllObjectUpdate();
            GameObjectManager::ConsoleAllObjectRender();
            GameObjectManager::ConsoleAllObjectRelease();
            Sleep(500);
        }
        if (Player::IsGameUpdate == false)
        {
            char Ch = _getch();
            if (Ch == 'q')
            {
                Player::IsGameUpdate = true;
            }
        }
    }
  
    GameObjectManager::ConsoleAllObjectDelete();

    return 0;
}

//void InitGame(bool bInitConsole)
//{
//    if (bInitConsole)
//    {
//        Console.hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//
//        Console.nCurBuffer = 0;
//
//
//        CONSOLE_CURSOR_INFO ConsoleCursor{ 1, FALSE };
//        CONSOLE_SCREEN_BUFFER_INFO ConsoleInfo{ 0 , };
//        GetConsoleScreenBufferInfo(Console.hConsole, &ConsoleInfo);
//        ConsoleInfo.dwSize.X = 100;
//        ConsoleInfo.dwSize.Y = 40;
//
//        Console.rtConsole.nWidht = ConsoleInfo.srWindow.Right - ConsoleInfo.srWindow.Left;
//        Console.rtConsole.nHeight = ConsoleInfo.srWindow.Bottom - ConsoleInfo.srWindow.Top;
//
//        Console.hBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
//        SetConsoleScreenBufferSize(Console.hBuffer[0], ConsoleInfo.dwSize);
//        SetConsoleWindowInfo(Console.hBuffer[0], TRUE, &ConsoleInfo.srWindow);
//        SetConsoleCursorInfo(Console.hBuffer[0], &ConsoleCursor);
//
//        Console.hBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
//        SetConsoleScreenBufferSize(Console.hBuffer[1], ConsoleInfo.dwSize);
//        SetConsoleWindowInfo(Console.hBuffer[1], TRUE, &ConsoleInfo.srWindow);
//        SetConsoleCursorInfo(Console.hBuffer[1], &ConsoleCursor);
//    }
//}

//void DestroyGame()
//{
//    if (Console.hBuffer[0] = nullptr)
//    {
//        CloseHandle(Console.hBuffer[0]);
//    }
//
//    if (Console.hBuffer[1] != nullptr)
//    {
//        CloseHandle(Console.hBuffer[1]);
//    }
//}
//
//void ClearScreen()
//{
//    COORD Pos{ 0, };
//    DWORD dwWritten = 0;
//    unsigned Size = Console.rtConsole.nWidht * Console.rtConsole.nHeight;
//
//    FillConsoleOutputCharacter(Console.hConsole, ' ', Size, Pos, &dwWritten);
//    SetConsoleCursorPosition(Console.hConsole, Pos);
//}
//
//void BufferFlip()
//{
//    // 화면 버퍼 설정
//    SetConsoleActiveScreenBuffer(Console.hBuffer[Console.nCurBuffer]);
//    // 화면 버퍼 인덱스를 교체
//    Console.nCurBuffer = Console.nCurBuffer ? 0 : 1;
//}