#include "Player_88.h"

Player_88::Player_88()
{
}

Player_88::~Player_88()
{
}



void const Player_88::PlayerInfoPrint()
{
	std::cout << "=====플레이어 Status====" << std::endl;
	std::cout << "Hp : " << GetHp() << " Mp : " << GetMp() << " Atk : " << GetAtk() << " Def : " << GetDef()
		<< " AtkSpeed : " << GetAtkSpeed() << std::endl;
	std::cout << "현재 무기 : " << GetWeapon();
	std::cout << "갖고 있는 무기 : ";
	std::cout << "현재 방어구 : ";
	std::cout << "모자 : " << " 갑옷 : " << " 신발 : ";
	std::cout << "갖고 있는 방어구 : ";
	std::cout << "갖고있는 물약 : ";
}