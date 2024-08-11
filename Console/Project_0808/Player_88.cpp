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

	std::cout << "=====플레이어 Status====" << std::endl;
	std::cout << "Hp : " << GetHp() << ", Mp : " << GetMp() << ", Atk : " << GetAtk() << ", Def : " << GetDef()
		<< ", AtkSpeed : " << GetAtkSpeed() << std::endl;
	std::cout << "현재 무기 : " << GetWeapon() << std::endl;
	std::cout << "현재 방어구 : " << std::endl;
	std::cout << "모자 : " << GetHat() << ", 갑옷 : " << GetArmor() << ", 신발 : " << GetBoots() << std::endl;
	std::cout << "갖고 있는 무기 : " << std::endl;
	std::cout << "갖고 있는 방어구 : " << std::endl;
	std::cout << "갖고있는 물약 : " << std::endl;
}

void Player_88::PlayerListSet()
{
	List.push_back("1. 아이템을 장착한다.");
	List.push_back("2. 아이템을 해제한다.");
	List.push_back("3. 아이템을 사용한다.");
	List.push_back("4. 나간다.");
}

int Player_88::PlayerActionList()
{
	return UManager->PrintScreen(1, Y, List);
}
