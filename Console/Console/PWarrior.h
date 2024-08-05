#pragma once

#include "Unit.h"

class PWarrior : public Unit
{
public:
	PWarrior(const std::string& n, const int h);
	~PWarrior();

public:
	void Attack();
};

