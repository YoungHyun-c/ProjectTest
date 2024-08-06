#pragma once

#include <iostream>
#include <string>

// 부모 클래스
class Vehicle
{
protected:
	std::string name;

public:
	Vehicle(const std::string& _n);
	virtual ~Vehicle(); // 소멸자에서 virtual을 붙이는 이유가, 자식클래스의 소멸자도 불러야 되기 때문에.
	// virtual을 붙이지 않으면, 기본클래스의 소멸자만 호출이됨.
	// 자식에서 동적할당을 했었다면, 자식의 동적할당을 지워야하니 소멸자에 virtual을 붙이도록.

	// -> 소멸자에 Vritual
	// 다형성을 활용할 때 객체가 올바르게 소멸되도록 보장.
	// virtual을 쓰지 않으면 기본클래스의 소멸자만 호출되고,
	// 자식클래스의 소멸자는 회출되지 않는다.


	virtual void Move()const = 0;
	// virtual void Move()const abstract; // 위와 동일
	// 0을 붙이게 되면, 순수 가상함수.
	// 

};
