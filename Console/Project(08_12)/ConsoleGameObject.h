#pragma once
#include "ConsoleGameMath.h"

// ���� :
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
	wchar_t RenderChar = L'��';
	wchar_t PreveRenderChar = L' ';

	char PlayerArr[5][5] = { ' ' };

private:
	bool UpdateValue = true;
	bool DeathValue = false;

};

