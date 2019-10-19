#include <iostream>
#include <string>
#include <list>
#include <random>
#include <algorithm>
#ifndef Included_Vehicle_H
#define Included_Vehicle_H

class Vehicle
{

protected:
    int vehicleID;
    std::string name;
    std::list<int> brokenParts;
	std::list<int> workingParts;
    std::list<int>::iterator itr;


public:
    //Construct a non specialized vehicle
    Vehicle(std::string vehName){name = vehName;};

    //Vehicle is abstract class, cannot instantiate
    virtual ~Vehicle(){};

    //Every vehicle needs its own display function
    virtual void display(std::ostream& outs){ std::cout << "Vehicle Name: " << name << " ";}

    std::list<int>::iterator workingListBegin() { return workingParts.begin(); }
    std::list<int>::iterator workingListEnd() { return workingParts.end(); }
    std::list<int>::iterator brokenListBegin(){ return brokenParts.begin();}
    std::list<int>::iterator brokenListEnd(){ return brokenParts.end();}
    

    void setID(const int ID){vehicleID = ID;}
    int getID()const {return vehicleID;}
    void setName(const std::string Name){name = Name;}
    std::string getName() const {return name;}

};

inline
std::ostream& operator<< ( std::ostream& outs, Vehicle &prt )
{
    prt.display( outs );

    return outs;
}

#endif
