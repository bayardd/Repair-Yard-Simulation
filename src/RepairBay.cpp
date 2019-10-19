#include "RepairBay.h"

RepairBay::RepairBay(){
	counter = 0;
	std::vector<Vehicle*> Bays(3, nullptr);

}

//Returns True if full
bool RepairBay::bayFull(){
	return(Bays.size() == 3);

}

void RepairBay::addToRepair(Vehicle* toAdd){

	Bays.push_back(toAdd);
}

void RepairBay::calculateRepairTime(){

	

}