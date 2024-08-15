#pragma once
#include "ConsoleGameMath.h"

//#define YSize 5
//#define XSize 6

// Ό³Έν :
class ConsoleGameObject
{
public:
	virtual inline void SetPos(const int2& _Value)
	{
		Pos = _Value;
	}

	inline int2 GetPos() const
	{
		return Pos;
	}

	bool IsDeath()
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

private:
	bool UpdateValue = true;
	bool DeathValue = false;

};

