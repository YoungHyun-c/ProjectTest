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
	std::cout << "ĳ������ �̸�   : " << Name << std::endl;
	std::cout << "ĳ������ ����   : " << Job << std::endl;
	std::cout << "ĳ������ ü��   : " << Health << std::endl;
	std::cout << "ĳ������ ���ݷ� : " << Atk << std::endl;
	std::cout << "ĳ������ ���� : " << Def << std::endl;
	std::cout << "==================================" << std::endl;
}

void UnitProject_86::TakeAttack(int _Damage)
{
	Health -= _Damage;
	std::cout << Name << " ��(��) " << _Damage << "��ŭ ���ظ� �Ծ����ϴ�.\n���� ü�� : " << Health << std::endl;
}