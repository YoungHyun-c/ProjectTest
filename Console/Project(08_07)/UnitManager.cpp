#include "UnitManager.h"

UnitManager::UnitManager(const std::string& _Name, int _Hp, int _Atk, int _Def)
	: Name(_Name), Hp(_Hp), Atk(_Atk), Def(_Def)
{
	MaxHp = _Hp;
}

UnitManager::~UnitManager()
{
	if (Weapon != nullptr)
	{
		delete Weapon;
		Weapon = nullptr;
	}
}

void UnitManager::PrintInfo()
{
	std::cout << "==================================" << std::endl;
	std::cout << "이름   : " << Name << std::endl;
	std::cout << "레벨   : " << Level << std::endl;
	std::cout << "직업   : " << Job << std::endl;
	std::cout << "무기   : " << *Weapon << std::endl;
	std::cout << "체력   : " << Hp << std::endl;
	std::cout << "공격력 : " << Atk << std::endl;
	std::cout << "방어력 : " << Def << std::endl;
	std::cout << "현재EXP: " << Exp << std::endl;
	std::cout << "==================================" << std::endl;
}

void UnitManager::TakeAttack(int _Damage)
{
	int DefCal = static_cast<int>(DefPower * Def);
	Hp -= (_Damage - DefCal);

	std::cout << Name << " 이(가)" << DefCal << "만큼 피해를 덜 받았습니다." << std::endl;
	std::cout << Name << " 이(가)" << _Damage << "의 피해를 입었습니다." << std::endl;
	std::cout << "남은 체력 : " << Hp << std::endl;
}