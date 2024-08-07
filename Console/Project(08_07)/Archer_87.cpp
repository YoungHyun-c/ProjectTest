#include "Archer_87.h"


void Archer_87::Attack() const
{
	std::cout << Name << "의 " << Weapon << "공격!" << std::endl;
}

void Archer_87::Move() const
{
	std::cout << Name << " 이(가) 바람처럼 피해갑니다." << std::endl;
}
