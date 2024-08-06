#include "Player_86.h"


Player_86::Player_86(const std::string& _name, const int h)
	: Unit_86(_name, h)
{

}

Player_86::~Player_86()
{
}

void Player_86::Attack() const
{
	std::cout << name << "ÀÇ °ø°Ý!" << std::endl;
}

void Player_86::TakeDamage(int damage)
{
	health -= damage;
	std::cout << health << std::endl;
}
