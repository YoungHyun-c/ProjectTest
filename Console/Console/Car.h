#pragma once

#include "Vehicle.h"

class Car : public Vehicle
{
public:
	Car(const std::string& _n);
	~Car();

	void Move() const override;



};

