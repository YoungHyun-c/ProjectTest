
#include "Vehicle.h"



Vehicle::Vehicle(const std::string& _n)
{
	std::cout << "부모클래스 생성자 호출" << std::endl;
}

Vehicle::~Vehicle()
{
	std::cout << "부모클래스 소멸자 호출" << std::endl;
}

void Vehicle::Move() const
{
	std::cout << "부모 클래스 Move함수 호출" << std::endl;
}
