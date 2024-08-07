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
	std::cout << "===========================================================" << std::endl;
	std::cout << "�̸�   : " << Name << std::endl;
	std::cout << "����   : " << Level << std::endl;
	std::cout << "����   : " << Job << std::endl;
	std::cout << "����   : " << *Weapon << std::endl;
	std::cout << "ü��   : " << Hp << std::endl;
	std::cout << "���ݷ� : " << Atk << std::endl;
	std::cout << "���� : " << Def << std::endl;
	std::cout << "����EXP: " << Exp << std::endl;
	std::cout << "===========================================================" << std::endl;
}

void UnitManager::TakeAttack(int _Damage)
{
	int DefCal = static_cast<int>(DefPower * Def);
	if (_Damage - DefCal <= 0)
	{
		_Damage = 0;
		DefCal = 0;
	}
	Hp -= (_Damage - DefCal);
	if (Hp <= 0)
	{
		Hp = 0;
	}

	std::cout << "===========================================================" << std::endl;
	std::cout << Name << " ��(��)" << DefCal << "��ŭ ���ظ� ���ҽ��ϴ�." << std::endl;
	std::cout << Name << " ��(��)" << (_Damage - DefCal) << "�� ���ظ� �Ծ����ϴ�." << std::endl;
	std::cout << "���� ü�� : " << Hp << std::endl;
	std::cout << "===========================================================" << std::endl;
}

void UnitManager::AddExp(int _Exp)
{
	Exp += _Exp;
	if (MaxExp <= Exp)
	{
		int Divide = Exp / MaxExp;
		int Cal = Exp % MaxExp;
		Level += Divide;
		Exp = Cal;
		Atk += 10 * Divide;
		Def += 5 * Divide;
		MaxHp += 15 * Divide;
		Hp = MaxHp;
		MaxExp += 10;
		std::cout << "====================================" << std::endl;
		std::cout << Name << "�� ������ +" << Divide << " �ö����ϴ�!" << std::endl;
		std::cout << "Level : " << Level << std::endl;
		std::cout << "Atk : " << Atk << std::endl;
		std::cout << "Def : " << Def << std::endl;
		std::cout << "MaxHp : " << MaxHp << std::endl;
	}

	std::cout << "���� �������� ���� ����ġ : " << MaxExp - Exp << std::endl;
	std::cout << "====================================" << std::endl;
}