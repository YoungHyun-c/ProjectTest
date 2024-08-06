#include "Archer_86.h"

Archer_86::Archer_86(const std::string& _Name, const int _Health, const int _Atk, const int _Def)
	: UnitProject_86(_Name, _Health, _Atk, _Def)
{
	Job = "아처";
	Weapon = new std::string("활");
}

Archer_86::~Archer_86()
{
}

void Archer_86::Attack() const
{
	std::cout << Name << "의 " << *Weapon << " 공격!" << std::endl;
}

//void Archer_86::TakeAttack(int _Damage)
//{
//	Health -= _Damage;
//	std::cout << Name << "가(이) " << _Damage << "만큼 피해를 입었습니다. 남은 체력 : " << Health << std::endl;
//}

void Archer_86::Move() const
{
	std::cout << Name << " 이(가) 바람처럼 움직입니다." << std::endl;
}
