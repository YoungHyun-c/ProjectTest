#include "Player_88.h"

Player_88::Player_88()
{
}

Player_88::~Player_88()
{
}



void const Player_88::PlayerInfoPrint()
{
	std::cout << "=====�÷��̾� Status====" << std::endl;
	std::cout << "Hp : " << GetHp() << " Mp : " << GetMp() << " Atk : " << GetAtk() << " Def : " << GetDef()
		<< " AtkSpeed : " << GetAtkSpeed() << std::endl;
	std::cout << "���� ���� : " << GetWeapon();
	std::cout << "���� �ִ� ���� : ";
	std::cout << "���� �� : ";
	std::cout << "���� : " << " ���� : " << " �Ź� : ";
	std::cout << "���� �ִ� �� : ";
	std::cout << "�����ִ� ���� : ";
}