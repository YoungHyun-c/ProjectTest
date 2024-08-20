#include "GameEngineRandom.h"


int GameEngineRandom::RandNum(int _Start, int _End)
{
	std::random_device Rd;
	std::mt19937 Gen(Rd());
	std::uniform_int_distribution<int> dist(_Start, _End);

	return dist(Gen);
}