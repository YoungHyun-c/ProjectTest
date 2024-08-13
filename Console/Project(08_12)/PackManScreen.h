#pragma once

#include "ConsoleGameMath.h"
#include "Utill.h"

#define XScreen 101
#define YScreen 51

class PackManScreen
{
public:
	static PackManScreen& GetMainScreen()
	{
		return MainScreen;
	}
	PackManScreen();
	~PackManScreen();

	void Start();

	const int2 GetScreenSize()
	{
		return Size;
	}

	void SetScreenSize(int2 _Size);
	void ScreenClear();
	bool IsScreenOver(const int2& _Pos) const;
	void SetScreenCharacter(const int2& _Pos, wchar_t _ch);
	wchar_t GetScreenCharacter(const int2& _Pos) const;

	void ScreenPrint();

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

	static PackManScreen MainScreen;
	int2 Size;

	std::vector<std::vector<wchar_t>> ArrScreen;
};

