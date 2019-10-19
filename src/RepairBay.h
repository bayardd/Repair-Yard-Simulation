#ifndef Included_RepairBay_H
#define Included_RepairBay_H

#include "Vehicle.h"
#include <vector>

class RepairBay{

private:
	int counter;
	std::vector<Vehicle*> Bays;
	std::vector<Vehicle*>::iterator bItr;

public:

	RepairBay();

	//Add vehicle to repair bay
	bool bayFull();

	void addToRepair(Vehicle* toAdd);

	int getCounter()const {return counter;}
	void setCounter(const int toSet){counter = toSet;}
	void calculateRepairTime();

	int getSize()const{return Bays.size();}
	std::vector<Vehicle*>::iterator begin(){return Bays.begin();}
	std::vector<Vehicle*>::iterator end(){return Bays.end();}

};














#endif