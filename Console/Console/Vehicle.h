#pragma once

#include <iostream>
#include <string>

// �θ� Ŭ����
class Vehicle
{
protected:
	std::string name;

public:
	Vehicle(const std::string& _n);
	virtual ~Vehicle(); // �Ҹ��ڿ��� virtual�� ���̴� ������, �ڽ�Ŭ������ �Ҹ��ڵ� �ҷ��� �Ǳ� ������.
	// virtual�� ������ ������, �⺻Ŭ������ �Ҹ��ڸ� ȣ���̵�.
	// �ڽĿ��� �����Ҵ��� �߾��ٸ�, �ڽ��� �����Ҵ��� �������ϴ� �Ҹ��ڿ� virtual�� ���̵���.

	// -> �Ҹ��ڿ� Vritual
	// �������� Ȱ���� �� ��ü�� �ùٸ��� �Ҹ�ǵ��� ����.
	// virtual�� ���� ������ �⺻Ŭ������ �Ҹ��ڸ� ȣ��ǰ�,
	// �ڽ�Ŭ������ �Ҹ��ڴ� ȸ����� �ʴ´�.


	virtual void Move()const = 0;
	// virtual void Move()const abstract; // ���� ����
	// 0�� ���̰� �Ǹ�, ���� �����Լ�.
	// 

};
