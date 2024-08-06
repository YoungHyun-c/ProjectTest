#include "Wizard_86.h"

Wizard_86::Wizard_86(const std::string& _Name, const int _Health, const int _Atk, const int _Def)
	: UnitProject_86(_Name, _Health, _Atk, _Def)
{
	Job = "마법사";
	Weapon = new std::string("지팡이");
}

Wizard_86::~Wizard_86()
{
}

void Wizard_86::Attack() const
{
	std::cout << Name << "의 " << *Weapon <<"로 스킬 공격!" << std::endl;
}

//void Wizard_86::TakeAttack(int _Damage)
//{
//	Health -= _Damage;
//	std::cout << Name << "이(가) " << _Damage << "만큼 피해를 입었습니다.\n남은 체력 : " << Health << std::endl;
//}

void Wizard_86::Move() const
{
	std::cout << Name << " 이(가) 순식간에 움직입니다." << std::endl;
}
