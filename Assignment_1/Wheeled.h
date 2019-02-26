#ifndef WHEELED_H_INCLUDED
#define WHEELED_H_INCLUDED
#include "Vehicle.h"

class Wheeled : public Vehicle{

public:
    Wheeled(int wheeledType, std::default_random_engine* gptr);

    ~Wheeled(){std::cout<< "Destroying Wheeled vehicle type " << vehicleID << std::endl;}

    void display(std::ostream& outs);



};



#endif // WHEELED_H_INCLUDED
