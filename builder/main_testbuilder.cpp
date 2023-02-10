#include <iostream>
#include "AircraftConstructor.h"
#include "AircraftBuilder.h"
#include "HangGliderBuilder.h"
#include "PassengerPlane.h"
#include "Aircraft.h"


using namespace std;

void main() {
	try {
		AircraftBuilder* builder;		
		AircraftConstructor* constructor =
			new AircraftConstructor();	
		
		builder = new HangGliderBuilder();		
		constructor->Construct(builder);
		Aircraft* aircraft = builder->GetAircraft();
		aircraft->Show();		
		delete builder;

		builder = new PassengerPlane();
		constructor->Construct(builder);
		aircraft = builder->GetAircraft();
		aircraft->Show();

		delete builder;		
		delete constructor;		
	}
	catch (...) {
		cout << "Error" << endl;
	}
}