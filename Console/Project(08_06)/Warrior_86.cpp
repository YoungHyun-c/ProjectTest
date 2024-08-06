#include "Warrior_86.h"

Warrior_86::Warrior_86(const std::string& _Name, const int _Health, const int _Atk, const int _Def)
	: UnitProject_86(_Name, _Health, _Atk, _Def)
{
	Job = "전사";
	Weapon = new std::string("검");
}

Warrior_86::~Warrior_86()
{

}

void Warrior_86::Attack() const
{
	std::cout << Name << "의 " << *Weapon << " 공격!" << std::endl;
}

//void Warrior_86::TakeAttack(int _Damage)
//{
//	Health -= _Damage;
//	std::cout << Name << "이(가) " << _Damage << "만큼 피해를 입었습니다.\n남은 체력 : " << Health << std::endl;
//}

void Warrior_86::Move() const
{
	std::cout << Name << " 이(가) 늠름하게 움직입니다." << std::endl;
}
