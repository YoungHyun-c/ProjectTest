#include "Wizard_86.h"

Wizard_86::Wizard_86(const std::string& _Name, const int _Health, const int _Atk, const int _Def)
	: UnitProject_86(_Name, _Health, _Atk, _Def)
{
	Job = "������";
	Weapon = new std::string("������");
}

Wizard_86::~Wizard_86()
{
}

void Wizard_86::Attack() const
{
	std::cout << Name << "�� " << *Weapon <<"�� ��ų ����!" << std::endl;
}

//void Wizard_86::TakeAttack(int _Damage)
//{
//	Health -= _Damage;
//	std::cout << Name << "��(��) " << _Damage << "��ŭ ���ظ� �Ծ����ϴ�.\n���� ü�� : " << Health << std::endl;
//}

void Wizard_86::Move() const
{
	std::cout << Name << " ��(��) ���İ��� �����Դϴ�." << std::endl;
}
