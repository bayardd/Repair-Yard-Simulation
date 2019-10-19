#include "Vehicle.h"
#include "Tank.h"
#include "Wheeled.h"
#include "Half_Track.h"
#ifndef SCRAPYARD_H_INCLUDED
#define SCRAPYARD_H_INCLUDED
 
//////////////////////////////// DONT FORGET TO INITIALIZE SCRAPYARD WITH A NUMBER OF VEHICLES 
class Scrapyard{
	
private:
	std::list<Vehicle*> scrappedVehCollection;
	std::list<Vehicle*>::iterator vItr;

public:
	//will need gptr later
	Scrapyard(std::default_random_engine* gptr);

	//Write Later
	/*~Scrapyard();*/

	void appendBrokenVeh(Vehicle* veh);

	void display();

};

#endif 
