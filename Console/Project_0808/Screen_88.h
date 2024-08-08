#pragma once

#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <vector>

class Screen_88
{
public:

	void ListSet();

	void PrintScreen();

	void CheckPoint();

private:
	std::vector<std::string> List;
};

