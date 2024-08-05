#pragma once // ���������� �ߺ� ���Ǹ� �����ִ� ��.

#ifndef UNIT_H // �ѹ� �����ϵǰ�, ������ �Ǵ� ����, �� ���Խ�Ű�� �ʴ´�. �������� ���.
#define UNIT_H

#include <iostream>
// ���� �θ� Ŭ����
class Unit
{
protected:
	std::string name;
	int health;

public:
	Unit();
	Unit(const std::string& n, const int h);
	~Unit();

public:
	void TakeDamage(const int damage);

};


#endif // UNIT_H
