#pragma once
#include <iostream>
#include <vector>
#include "ConsoleGameMath.h"

#define ItemSize 2
#define ColSize 3

#define MonColX 40
#define MonColY 18

class GameEngineCollision
{
public:
	bool CheckCollision(int2 _Me , int2 _other) const {
		return (_Me.X < _other.X + ColSize &&
			_Me.X + ColSize > _other.X &&
			_Me.Y < _other.Y + ColSize &&
			_Me.Y + ColSize > _other.Y);
	}

	bool CheckMonsterCollision(int2 _Me, int2 _other) const {
			for (int dY = 0; dY < MonColY; dY++)
			{
				for (int dX = 0; dX < MonColX; dX++)
				{
					if (_Me.X + dX < _other.X + 3
						&& _Me.X + dX >= _other.X
						&& _Me.Y + dY < _other.Y + 3
						&& _Me.Y + dY >= _other.Y)
					{
						return true;
					}
				}
			}
			return false;
	}

	bool CheckItemCollision(int2 _Me, int2 _other) const {
		return (_Me.X < _other.X + ColSize &&
			_Me.X + ItemSize > _other.X &&
			_Me.Y < _other.Y + ColSize &&
			_Me.Y + ItemSize > _other.Y);
	}
};