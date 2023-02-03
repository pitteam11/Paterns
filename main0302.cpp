#include <iostream>
#include "PCFactory/PCFactory.h"

using namespace std;


class IMarker abstract {
public:
	string color;
};

class RedMarker : public IMarker {
public:
	RedMarker() {
		color = "red";
	}
};

class BlueMarker : public IMarker {
public:
	BlueMarker() {
		color = "blue";
	}
};

class IMarkerFactory abstract {
public:
	virtual IMarker* create() = 0;
};

class BlueMarkerFacrory : public IMarkerFactory {
public:
	IMarker* create() override {
		return new BlueMarker();
	}
};

class RedMarkerFacrory : public IMarkerFactory {
public:
	IMarker* create() override {
		return new RedMarker();
	}
};

void main() {
	cout << "Test absract factory\n";
	//test_PCFactory();
	IMarkerFactory* factory = new BlueMarkerFacrory();
	IMarker *marker = factory->create();
	delete factory;
	factory = new RedMarkerFacrory();
	IMarker* marker2 = factory->create();
	delete factory;

	cout << marker->color << " " << marker2->color << endl;

	delete marker;
	delete marker2;
}