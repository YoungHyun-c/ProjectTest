#include "Monster_87.h"

void Monster_87::Attack() const
{
	std::cout << Name << "의 " << Weapon << "공격!" << std::endl;
}

void Monster_87::Move() const
{
	std::cout << Name << " 이(가) 피했습니다." << std::endl;
}