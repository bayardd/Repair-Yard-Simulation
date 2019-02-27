#include "RepairBay.h"

RepairBay::RepairBay(){
	counter = 0;
	size = 0;
	toRepair = nullptr;
}

//Returns True if full
bool RepairBay::bayFull(){

	std::cout << "SIZE HEERE IS " << this->size << std::endl;
	return(size == 3);
}

void RepairBay::addToRepair(Vehicle* toAdd){
	//Check if this is valid.. might have address issues
	toRepair = toAdd;
}

void RepairBay::calculateRepairTime(){
	auto it = max_element(toRepair->brokenListBegin(), toRepair->brokenListEnd());
	counter = (*it)/4;
	std::cout << "MAX TIME " << counter<<std::endl;

}
