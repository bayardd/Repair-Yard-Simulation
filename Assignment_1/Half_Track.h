#ifndef HALF_TRACK_H_INCLUDED
#define HALF_TRACK_H_INCLUDED
#include "Vehicle.h"

class Half_Track : public Vehicle{

public:
    Half_Track(int trackType, std::default_random_engine* gptr);
    ~Half_Track();

    void display(std::ostream& outs);
	void writeFile(std::ofstream& writeFile);

};



#endif // HALF_TRACK_H_INCLUDED
