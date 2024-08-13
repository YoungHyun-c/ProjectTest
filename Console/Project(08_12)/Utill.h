#pragma once
#include <Windows.h>

#include <iostream>
#include <conio.h>
#include <vector>
#include <string>

// Ό³Έν :
class Utill
{
public:
	// constructer destructer
	Utill();
	~Utill();

	// delete Function
	Utill(const Utill& _Other) = delete;
	Utill(Utill&& _Other) noexcept = delete;
	Utill& operator = (const Utill& _Other) = delete;
	Utill& operator = (Utill&& _Other) noexcept = delete;

	void Gotoxy(short _X, short _Y);

	void TextColor(int _Font, int _BackGround);

	int PrintScreen(int _X, int _Y, std::vector<std::string>& _List);

protected:
	int KeyControl();

private:

};

