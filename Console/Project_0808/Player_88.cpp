#include "Player_88.h"

#include "Util.h"



Player_88::Player_88()
{
}

Player_88::~Player_88()
{
}


void const Player_88::PlayerInfoPrint()
{

	std::cout << "=====�÷��̾� Status====" << std::endl;
	std::cout << "Hp : " << GetHp() << ", Mp : " << GetMp() << ", Atk : " << GetAtk() << ", Def : " << GetDef()
		<< ", AtkSpeed : " << GetAtkSpeed() << std::endl;
	std::cout << "���� ���� : " << GetWeapon() << std::endl;
	std::cout << "���� �� : " << std::endl;
	std::cout << "���� : " << GetHat() << ", ���� : " << GetArmor() << ", �Ź� : " << GetBoots() << std::endl;
	std::cout << "���� �ִ� ���� : " << std::endl;
	std::cout << "���� �ִ� �� : " << std::endl;
	std::cout << "�����ִ� ���� : " << std::endl;
}

void Player_88::PlayerListSet()
{
	List.push_back("1. �������� �����Ѵ�.");
	List.push_back("2. �������� �����Ѵ�.");
	List.push_back("3. �������� ����Ѵ�.");
	List.push_back("4. ������.");
}

int Player_88::PlayerActionList()
{
	return UManager->PrintScreen(1, Y, List);
}
