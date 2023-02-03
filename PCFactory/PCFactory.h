#pragma once

#include <iostream>
using namespace std;

class Box {
public:
	string name = "Hihg tower black";
};

class Processor {
public:
	string name = "Intel i3 7300";
};

class MainBoard {
public:
	string name;
	int price;
	int memory;
};

class MCI : public MainBoard {
public:
	MCI() {
		name = "MCI 8080";
		price = 10000;
		memory = 6;
	}
};

class Hdd {
};

class Memory {
};

class PC {
	Box* box;
	Processor* processor;
	MainBoard* mainboard;
	Hdd* hdd;
	Memory* memory;
public:
	PC() {
		box = NULL;
		processor = NULL;
		mainboard = NULL;
		hdd = NULL;
		memory = NULL;
	}

	virtual ~PC() {
		if (box)
			delete box;
		if (processor)
			delete processor;
		if (mainboard)
			delete mainboard;
		if (hdd)
			delete hdd;
		if (memory)
			delete memory;
	}

	Box* getBox() {
		return box;
	}

	void setBox(Box* pVal) {
		box = pVal;
	}

	Processor* getProcessor() {
		return processor;
	}

	void setProcessor(Processor* pVal) {
		processor = pVal;
	}

	MainBoard* getMainBoard() {
		return mainboard;
	}

	void setMainBoard(MainBoard* pVal) {
		mainboard = pVal;
	}

};

class IPCFactory {
public:
	virtual Box* CreateBox() = 0;
	virtual Processor* CreateProcessor() = 0;
	virtual MainBoard* CreateMainBoard() = 0;
	virtual Hdd* CreateHdd() = 0;
	virtual Memory* CreateMemory() = 0;
};

class WorkPCFactory : public IPCFactory {
public:
	Box* CreateBox() override {
		return new Box();
	}
	Processor* CreateProcessor() override {
		return new Processor();
	}
	MainBoard* CreateMainBoard() override {
		return new MCI();
	}
	Hdd* CreateHdd() override {
		return new Hdd();
	}
	Memory* CreateMemory() override {
		return new Memory();
	}
};


class HomePCFactory : public IPCFactory {
public:
	Box* CreateBox() override {
		return new Box();
	}
	Processor* CreateProcessor() override {
		return new Processor();
	}
	MainBoard* CreateMainBoard() override {
		return new MainBoard();
	}
	Hdd* CreateHdd() override {
		return new Hdd();
	}
	Memory* CreateMemory() override {
		return new Memory();
	}
};

class PCConfigurator {
	IPCFactory* pcFactory;
public:
	PCConfigurator() {
		pcFactory = NULL;
	}

	virtual ~PCConfigurator() {
		if (pcFactory)
			delete pcFactory;
	}

	IPCFactory* getPCFactory() {
		return pcFactory;
	}

	void setPCFactory(IPCFactory* pVal) {
		pcFactory = pVal;
	}

	void Configure(PC* pc)
	{
		pc->setBox(pcFactory->CreateBox());
		pc->setMainBoard(pcFactory->CreateMainBoard());
		//pc->SetHdd(pcFactory->CreateHdd());
		//pc->SetMemory(pcFactory->CreateMemory());
		pc->setProcessor(pcFactory->CreateProcessor());
	}
};

void test_PCFactory() {
	PCConfigurator config;
	config.setPCFactory(new HomePCFactory());
	PC* pc = new PC();
	config.Configure(pc);
	cout << pc->getBox()->name << " " << pc->getProcessor()->name << endl;

	PC* pc2 = new PC();
	config.setPCFactory(new WorkPCFactory());
	config.Configure(pc2);
	cout << pc2->getBox()->name << " " << pc2->getProcessor()->name << endl;
	cout << pc2->getMainBoard()->name << " " << pc2->getMainBoard()->price << endl;


	delete pc;
	delete pc2;
}
