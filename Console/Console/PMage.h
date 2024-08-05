#pragma once

#include "Unit.h"

class PMage : public Unit
{
public:
	PMage(const std::string& n, const int h);
	~PMage();

private:
	void Attack();
};

