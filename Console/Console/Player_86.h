#pragma once
#include "Unit_86.h"

class Player_86 : public Unit_86
{
public:
	Player_86(const std::string& _name, const int h);
	~Player_86();

	void Attack() const override;
	void TakeDamage(int damage) override;
	// �ݵ�� ���������Լ��� �ڽ�Ŭ�������� ������ �ؾ��Ѵ�. ����.
};

