#pragma once

#include "Utill.h"
#include "ConsoleGameMath.h"

#define XScreen 101
#define YScreen 51

class PackManScreen
{
public:
	void Start();

	const int2 GetScreenSize()
	{
		return int2{ YScreenSize, XScreenSize };
	}

	bool IsScreenOver(const int2& _Pos) const;

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

private:
	static const int XScreenSize = XScreen;
	static const int YScreenSize = YScreen;

};

