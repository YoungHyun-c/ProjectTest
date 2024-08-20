#pragma once
#include <iostream>

class int2
{
public:
	inline int2()
	{

	}

	inline int2(int _X, int _Y) : X(_X), Y(_Y)
	{

	}

	static const int2 Left;
	static const int2 Right;
	static const int2 Up;
	static const int2 Down;
	static const int2 Zero;


	int X = 0;
	int Y = 0;

	struct HashFunction {
		size_t operator()(const int2& pos) const {
			return std::hash<int>()(pos.X) ^ std::hash<int>()(pos.Y);
		}
	};

public:
	inline int2 Half() const
	{
		return { X / 2, Y / 2 };
	}

	bool Check(const int2& _Other) const
	{
		return X == _Other.X && Y == _Other.Y;
	}

	bool operator==(const int2& _Other) const
	{
		return X == _Other.X && Y == _Other.Y;
	}
};
