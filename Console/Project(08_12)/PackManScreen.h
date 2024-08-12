#pragma once

#include "Utill.h"

#define XScreenSize
#define YScreenSize

class PackManScreen
{
public:
	
	void PackManStartScreen();

	void PackManMapPrint();

	void PackManSetList();

	int PackManSetting();

	void PackManUpdate();

private:
	std::vector<std::string> List;

	int X = 14;
	int Y = 0;

	class Utill Handle;
};

