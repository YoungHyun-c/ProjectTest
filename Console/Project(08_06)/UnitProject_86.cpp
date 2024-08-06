#include "UnitProject_86.h"


UnitProject_86::~UnitProject_86()
{
	if (Weapon != nullptr)
	{
		delete Weapon;
		Weapon = nullptr;
	}
}


void UnitProject_86::PrintInfo() const
{
	std::cout << "==================================" << std::endl;
	std::cout << "캐릭터의 이름   : " << Name << std::endl;
	std::cout << "캐릭터의 직업   : " << Job << std::endl;
	std::cout << "캐릭터의 체력   : " << Health << std::endl;
	std::cout << "캐릭터의 공격력 : " << Atk << std::endl;
	std::cout << "캐릭터의 방어력 : " << Def << std::endl;
	std::cout << "==================================" << std::endl;
}

void UnitProject_86::TakeAttack(int _Damage)
{
	Health -= _Damage;
	std::cout << Name << " 이(가) " << _Damage << "만큼 피해를 입었습니다.\n남은 체력 : " << Health << std::endl;
}