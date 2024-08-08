#pragma once

#include <Windows.h>
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

protected:

private:

};

