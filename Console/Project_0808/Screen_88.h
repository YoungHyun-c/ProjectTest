#pragma once

#include <windows.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <vector>

class Screen_88
{
public:
	void Start();

	void MenuListSet();

	void ShopListSet();

	int PrintScreen();

	int KeyControl();

private:
	std::vector<std::string> List;

};

