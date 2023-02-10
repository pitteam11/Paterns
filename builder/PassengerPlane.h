#pragma once
#include "AircraftBuilder.h"

class PassengerPlane :public AircraftBuilder
{
public:
	PassengerPlane() {
		aircraft = new Aircraft("Boing 737");
	}

	void BuildFrame() override {
		aircraft->SetPart("fram", "Boing 737");
	};
	void BuildEngine() override {
		aircraft->SetPart("engine", "4 8W");
	};
	void BuildWheels() override {
		aircraft->SetPart("wheels", "16");
	};
	void BuildDoors() override {
		aircraft->SetPart("doors", "6");
	}
	void BuildWings() override {
		aircraft->SetPart("wings", "2");
	}
};


