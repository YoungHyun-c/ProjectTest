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
	std::cout << "�̸�   : " << Name << std::endl;
	std::cout << "����   : " << Level << std::endl;
	std::cout << "����   : " << Job << std::endl;
	std::cout << "����   : " << *Weapon << std::endl;
	std::cout << "ü��   : " << Hp << std::endl;
	std::cout << "���ݷ� : " << Atk << std::endl;
	std::cout << "���� : " << Def << std::endl;
	std::cout << "����EXP: " << Exp << std::endl;
	std::cout << "==================================" << std::endl;
}

void UnitManager::TakeAttack(int _Damage)
{
	int DefCal = static_cast<int>(DefPower * Def);
	Hp -= (_Damage - DefCal);

	std::cout << Name << " ��(��)" << DefCal << "��ŭ ���ظ� �� �޾ҽ��ϴ�." << std::endl;
	std::cout << Name << " ��(��)" << _Damage << "�� ���ظ� �Ծ����ϴ�." << std::endl;
	std::cout << "���� ü�� : " << Hp << std::endl;
}