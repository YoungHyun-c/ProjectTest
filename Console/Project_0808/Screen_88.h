#pragma once

#include <windows.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <vector>

#define ScreenX 4
#define ScreenY 1


class Screen_88
{
public:
	void Start();

	void MenuListSet();

	int PrintScreen();

private:
	std::vector<std::string> List;
	class Util* ComManager;

	int X = ScreenX;
	int Y = ScreenY;
};

