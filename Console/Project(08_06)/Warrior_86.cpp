#include "Warrior_86.h"

Warrior_86::Warrior_86(const std::string& _Name, const int _Health, const int _Atk, const int _Def)
	: UnitProject_86(_Name, _Health, _Atk, _Def)
{
	Job = "����";
	Weapon = new std::string("��");
}

Warrior_86::~Warrior_86()
{

}

void Warrior_86::Attack() const
{
	std::cout << Name << "�� " << *Weapon << " ����!" << std::endl;
}

//void Warrior_86::TakeAttack(int _Damage)
//{
//	Health -= _Damage;
//	std::cout << Name << "��(��) " << _Damage << "��ŭ ���ظ� �Ծ����ϴ�.\n���� ü�� : " << Health << std::endl;
//}

void Warrior_86::Move() const
{
	std::cout << Name << " ��(��) �Ƹ��ϰ� �����Դϴ�." << std::endl;
}
