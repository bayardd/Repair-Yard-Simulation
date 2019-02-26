#ifndef TANK_H_INCLUDED
#define TANK_H_INCLUDED
#include <random>
#include <iostream>
#include "Vehicle.h"
#include <list>
#include<chrono>
#include <ctime>



class Tank : public Vehicle
{

private:
//	std::list<int> brokenParts;
//	std::list<int> workingParts;
//    std::list<int>::iterator itr;


public:
	Tank(int tankType, std::default_random_engine* gptr);
	~Tank(){std::cout <<"Destroyed tank type " << vehicleID <<  std::endl;}

	void display(std::ostream& outs);
};




#endif // TANK_H_INCLUDED
