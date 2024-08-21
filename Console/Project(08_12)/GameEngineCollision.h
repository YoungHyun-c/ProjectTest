#pragma once
#include <iostream>
#include <vector>
#include "ConsoleGameMath.h"

#define ItemSize 2
#define ColSize 3

class GameEngineCollision
{
public:
	bool CheckCollision(int2 _Me , int2 _other) const {
		return (_Me.X < _other.X + ColSize &&
			_Me.X + ColSize > _other.X &&
			_Me.Y < _other.Y + ColSize &&
			_Me.Y + ColSize > _other.Y);
	}

	bool CheckItemCollision(int2 _Me, int2 _other) const {
		return (_Me.X < _other.X + ColSize &&
			_Me.X + ItemSize > _other.X &&
			_Me.Y < _other.Y + ColSize &&
			_Me.Y + ItemSize > _other.Y);
	}
};