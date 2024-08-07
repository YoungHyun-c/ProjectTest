#include "Random_87.h"

int Random_87::RandNum(int _Start, int _End)
{
	std::random_device Rd;
	std::mt19937 Gen(Rd());
	std::uniform_int_distribution<int> dist(_Start, _End);

	return dist(Gen);
}