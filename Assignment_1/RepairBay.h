#ifndef Included_RepairBay_H
#define Included_RepairBay_H

#include "Vehicle.h"

class RepairBay{

private:
	//Responsible for keeping track of time
	int counter;

	//Responsible for keeping track of size
	int size;

	//Vehicle to be added to repair bay
	Vehicle* toRepair;

public:

	RepairBay();

	//Add vehicle to repair bay
	bool bayFull();

	void addToRepair(Vehicle* toAdd);

	int getCounter()const {return counter;}
	void setCounter(const int toSet){counter = toSet;}

	void calculateRepairTime();

	Vehicle* getVehicle()const {return toRepair; }
	void decreaseTime(){counter = counter-1;}
	int getSize()const{return size;}
	void setSize(const int newSize){size = newSize;}
	// std::vector<Vehicle*>::iterator begin(){return Bays.begin();}
	// std::vector<Vehicle*>::iterator end(){return Bays.end();}

};














#endif
