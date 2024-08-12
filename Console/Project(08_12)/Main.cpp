#include <windows.h>

#include <iostream>
#include <conio.h>

using namespace std;

#include "Utill.h"

#include "MainScreen.h"

int main() {
    //POINT MousePoint;
    //std::cout << fixed;
    //std::cout.precision(1);

    system("mode con cols= 210 lines= 100 | title Á¦¸ñ¸í");
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
        MainScreen GameScreen;
        GameScreen.Start();

    }
    return 0;
}
