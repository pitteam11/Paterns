#pragma once
#include <iostream>
#include <map>

using namespace std;

class Aircraft
{
	string aircraftType;
	map<string, string> parts;

public:
	Aircraft(string type) : aircraftType{ type } {}
	virtual ~Aircraft() {};


	bool CheckForPart(const string& key) {
		if (parts.find(key) != parts.end())
			return true;
		else
			return false;
	}

	void SetPart(const string& key, const string& value) {
		parts[key] = value;
	}

	string GetPart(const string& key) {
		if (CheckForPart(key))
			return parts[key];
		else
			return "no" + key;
	}

	void Show() {
		cout << "\n====================\n";
		cout << "Aircraft Type:" << aircraftType << endl;
		cout << "Frame:" << parts["frame"] << endl;
		cout << "Engine:" << parts["engine"] << endl;
		cout << "Wheels:" << parts["wheels"] << endl;
		cout << "Doors:" << parts["doors"] << endl;
		cout << "Wings:" << parts["wings"] << endl;
	}
};

