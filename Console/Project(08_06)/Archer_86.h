#pragma once
#include "UnitProject_86.h"

class Archer_86 : public UnitProject_86
{
public:
	Archer_86(const std::string& _Name, const int _Health, const int _Atk, const int _Def);
	~Archer_86();


protected:
	void Attack() const override;
	//void TakeAttack(int _Damage) override;
	void Move() const override;

private:

};

