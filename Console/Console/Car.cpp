#include "Car.h"

Car::Car(const std::string& _n)
	:Vehicle(_n)
{
	std::cout << "자식(car)생성자 호출" << std::endl;
}

Car::~Car()
{
	std::cout << "자식(car)소멸자 호출" << std::endl;
}

void Car::Move() const
{
	std::cout << name << "자식(car) 클래스의 자동차 함수 호출" << std::endl;
}
