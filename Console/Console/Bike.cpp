#include "Bike.h"

Bike::Bike(const std::string& _n)
	: Vehicle(_n)
{
	std::cout << "�ڽ�(Bike)������ ȣ��" << std::endl;
}

Bike::~Bike()
{
	std::cout << "�ڽ�(Bike)�Ҹ��� ȣ��" << std::endl;
}

void Bike::Move() const
{
	std::cout << name << "�� �ڽ�Ŭ���� ������� �Լ� ȣ��" << std::endl;
}
