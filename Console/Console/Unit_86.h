#pragma once

// virtual void Move()const = 0;
// ���������Լ� : �����ϰ� �������� ����.
// ���������Լ��� �����ϰ� �ִ� Ŭ������. �߻�Ŭ������� �Ҹ���.
// ���������� ������ �ִ�.
// Ư���Լ��� ������ �����ϰ� �����.

// ���������Լ��� �Ѱ� �̻��� �����Ѵٸ� �߻�Ŭ������� ��.
// �߻�Ŭ���� : �ν��Ͻ�ȭ ��ų �� ����. -> ��üȭ ��ų �� ����.
// �ٸ� Ŭ�������� ��ӹ޾ƾ� �ϴ� �⺻ �������̽��� �����ϴµ� ���.
// ������, �ڵ� ���뼺...
// Ư�� �Լ����� �ڽ�Ŭ������ ���� �����ǵ��� ������.
#include <iostream>
// �߻�Ŭ����
class Unit_86 abstract // ��ø� ���ִ°� �ִ�.
{
protected:
	std::string name;
	int health;

public:
	Unit_86(const std::string& _name, const int h);
	virtual ~Unit_86();

public:
	// ���� �����Լ�.
	virtual void Attack() const = 0;
	virtual void TakeDamage(int damage) = 0;
};

