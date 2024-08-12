#pragma once

#include "Utill.h"

#define XScreenSize
#define YScreenSize

class PackManScreen
{
public:
	void Start();

private:
	void PackManStartScreen();
	void PackManMapPrint();
	void PackManSetList();
	int PackManSetting();
	void PackManUpdate();

	void GameSetList();

private:
	bool Done = true;

	std::vector<std::string> List;

	int X = 14;
	int Y = 0;

	class Utill Handle;
};

