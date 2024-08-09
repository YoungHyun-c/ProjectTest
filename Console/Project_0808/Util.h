#pragma once
#include <Windows.h>

#include <iostream>
#include <conio.h>
#include <vector>
#include <string>

// Ό³Έν :
class Util
{
public:
	// constructer destructer
	Util();
	~Util();

	// delete Function
	Util(const Util& _Other) = delete;
	Util(Util&& _Other) noexcept = delete;
	Util& operator = (const Util& _Other) = delete;
	Util& operator = (Util&& _Other) noexcept = delete;

	void Gotoxy(short _X, short _Y);

	int PrintScreen(int _X, int _Y, std::vector<std::string>& _List);

protected:
	int KeyControl();

private:

};

