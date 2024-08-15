#pragma once

#include "ConsoleGameMath.h"
#include "Utill.h"

#define XScreen 101
#define YScreen 50

struct stRect
{
	int nWidht;
	int nHeight;
};
struct stConsole
{
	HANDLE hConsole;
	stRect rtConsole;
	HANDLE hBuffer[2];

	int nCurBuffer;

	stConsole()
		: hConsole(nullptr), hBuffer{ nullptr, }, nCurBuffer(0)
	{}
};

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
	void SetScreenCharacter(const int2& _Pos, char _Ch);
	void SetScreenCharacter(const int2& _Pos, char _Ch[][6]);
	char GetScreenCharacter(const int2& _Pos) const;
	void InitGame(bool bInitConsole = true);

	void ScreenPrint();
	void VoidCursor();

	bool CanMove(int _X, int _Y);

private:
	void PackManStartScreen();
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

	char MapArr[YScreen][XScreen] =
	{	"111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
		"100000000000000000000000000000000000000000000011110000000000000000000000000000000000000000000000001",
		"100000000011111111111100000011111111111100000011110000000111111111000000000001111111111000000000001",
		"100000000011111111111100000011111111111100000011110000000111111111000000000001111111111000000000001",
		"100000000011111111111100000011111111111100000011110000000111111111000000000001111111111000000000001",
		"100000000000000000000000000000000000000000000011110000000000000000000000000000000000000000000000001",
		"100000000011111111111100000000000000000000000011110000000000000000000000000000000000000000000000001",
		"100000000011111111111100000000000000000000000000000000000000000000000000000000000111111111100000001",
		"100000000000000000000000000000000000111111111111111111111111100000011100000000000111111111100000001",
		"100000000000000000000000011100000000111111111111111111111111100000011100000000000000000000000000001",
		"100000000000000000000000011100000000111111111111111111111111100000011100000000000000000000000000001",
		"111111111111000000000000011100000000000000000011111000000000000000011100000000000000000011111111111",
		"111111111111000000000000011100000000000000000011111000000000000000011100000000000000000011111111111",
		"111111111111000000000000011111111111110000000011111000000001111111111100000011111100000011111111111",
		"111111111111000000000000011111111111110000000011111000000001111111111100000011111100000011111111111",
		"111111111111000000000000011100000000000000000000000000000000000000011100000011111100000011111111111",
		"100000000000000000000000011100000000000000000000000000000000000000011100000000000000000000000000001",
		"100000000000000000000000011100000000000000000000000000000000000000011100000000000000000000000000001",
		"100000000000000000000000011111111111111111111111111111111111111111111100000000000000000000000000001",
		"100000000000000000000000000111111111111111111111111111111111111111100000000000000000000000000000001",
		"100000000000111111111000000000000000000000000000000000000000000000000000000000000000000001111110001",
		"100000000000111111111000000000000000000000000000000000000000000000000000000111111111000001111110001",
		"100000000000111111111000000000000000000000000000000000000000000000000000000111111111000001111110001",
		"100000000000000000000000000000000000000111111111111111111110000000000000000111111111000001111110001",
		"100000000000000000000000000000000000000111111111111111111110000000000000000111111111000000000000001",
		"100000000000000000000000000000000000000111111111111111111110000000000000000111111111000000000000001",
		"100000011111111111111000000000000000000111111111111111111110000000000000000111111111000000000000001",
		"100000011111111111111000000000000000000000000000000000000000000000000000000111111111000000000000001",
		"100000000000000000111000000000000000000000000000000000000000000000000000000111111111000000000000001",
		"100000000000000000111000000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000111000000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000111000000000000000000000000000000000000000000000000000000000000000000111111000001",
		"100000000000000000111000000000000000000000000000000000000000000000000000000000000000000111111000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000000000000000111111000001",
		"100000001111111111111111111111111111111000000000000000000000111111111111111110000000000000000000001",
		"100000001111111111111111111111111111111000000000000000000000111111111111111110000000000000000000001",
		"100000001111111111111111111111111111111000000000000000000000111111111111111110000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
		"111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
	};

private:
	char chBuf[256] = { 0 , };
	COORD coord{ 0, 0 };
	DWORD dw = 0;
};

