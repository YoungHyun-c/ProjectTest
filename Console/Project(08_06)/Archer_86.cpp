#include "Archer_86.h"

Archer_86::Archer_86(const std::string& _Name, const int _Health, const int _Atk, const int _Def)
	: UnitProject_86(_Name, _Health, _Atk, _Def)
{
	Job = "��ó";
	Weapon = new std::string("Ȱ");
}

Archer_86::~Archer_86()
{
}

void Archer_86::Attack() const
{
	std::cout << Name << "�� " << *Weapon << " ����!" << std::endl;
}

//void Archer_86::TakeAttack(int _Damage)
//{
//	Health -= _Damage;
//	std::cout << Name << "��(��) " << _Damage << "��ŭ ���ظ� �Ծ����ϴ�. ���� ü�� : " << Health << std::endl;
//}

void Archer_86::Move() const
{
	std::cout << Name << " ��(��) �ٶ�ó�� �����Դϴ�." << std::endl;
}
