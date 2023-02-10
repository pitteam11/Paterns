#pragma once
#include "AircraftBuilder.h"

class AircraftConstructor
{
public: 
	void Construct(AircraftBuilder* builder) {
		builder->BuildFrame();
		builder->BuildEngine();
		builder->BuildWheels();
		builder->BuildWings();
		builder->BuildDoors();
	}
};

