#include "Vehicle.h"

#ifndef YARDMASTER_H_INCLUDED
#define YARDMASTER_H_INCLUDED

class Yardmaster{
	
	private:

		//Were trying to be realistic right? Yardmaster is a person!!
		std::string name;
		int age;
		

	public:

		Yardmaster(std::string hisName, int hisAge): name(hisName), age(hisAge) {}

		//Returns true if vehicle is going to scrapyard
		bool checkVehicleCondition(Vehicle* vptr);
};

#endif