#pragma once
#include "ConsoleGameMath.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <chrono>
#include "Utill.h"

//#define YSize 5
//#define XSize 6

#define YSize 3
#define XSize 4

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define PAUSE 112
#define ESC 27

#define ENTITYSIZE 3

// Ό³Έν :
class ConsoleGameObject
{
public:
	virtual inline void SetPos(const int2& _Value)
	{
		Pos = _Value;
	}

	virtual inline int2 GetPos() const
	{
		return Pos;
	}

	virtual bool MonsterCheck(int _X, int _Y)
	{
		return false;
	}

	bool IsDeath() const
	{
		return DeathValue;
	}

	void Death()
	{
		DeathValue = true;
	}

	bool IsUpdate()
	{
		return UpdateValue && false == IsDeath();
	}

	void On()
	{
		UpdateValue = true;
	}

	void Off()
	{
		UpdateValue = false;
	}

	virtual void Update();
	virtual void Render();

protected:
	int2 Pos;
	//char RenderChar = '2';
	char PreveRenderChar = ' ';

	/*char PlayerArr[YSize][XSize] =
	{
		 " 222 ",
		 "22222",
		 "222  ",
		 "22222",
		 " 222 "
	};

	char PlayerPreveArr[YSize][XSize] = 
	{
		 "     ",
		 "     ",
		 "     ",
		 "     ",
		 "     "
	};*/

	int MonsterCount = 3;

private:
	bool UpdateValue = true;
	bool DeathValue = false;

};

