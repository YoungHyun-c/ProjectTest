#include <iostream>
#include <algorithm>
#include <random>
#include <string>


int main()
{
	std::string Bingo[25] = {};

	for (int i = 1; i <= 25; i++)
	{
		Bingo[i - 1] = i;
	}

	std::random_device Rd;
	std::mt19937 Gen(Rd());
	std::uniform_int_distribution<> Dist(0, 24);

	int Sour, Dest, Temp;
	for (int i = 0; i < 100; i++)
	{
		Dest = Dist(Gen);
		Sour = Dist(Gen);

		Temp = Bingo[Dest];
		Bingo[Dest] = Bingo[Sour];
		Bingo[Sour] = Temp;
	}

	for (int i = 0; i < 25; i++)
	{
		if (i / 5 != 0  && i % 5 == 0)
		{
			std::cout << std::endl;
		}
		std::cout << Bingo[i] << " " ;
	}


	return 0;
}