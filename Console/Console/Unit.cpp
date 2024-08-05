#include "Unit.h"

Unit::Unit()
{
}

Unit::Unit(const std::string& n, const int h)
	: name(n), health(h)
{
	std::cout << "부모 클래스 Unit 생성자 호출" << std::endl;
}

Unit::~Unit()
{
	std::cout << "부모 클래스 Unit 소멸자 호출" << std::endl;
}

void Unit::TakeDamage(const int damage)
{
	health -= damage;
	std::cout << name << "이(가) " << damage << "의 피해를 입었다. 남은 체력은 : " << health << " 입니다." << std::endl;

}
