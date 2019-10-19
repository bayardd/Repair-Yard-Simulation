#include "Half_Track.h"

Half_Track::Half_Track(int trackType, std::default_random_engine* gptr) : Vehicle("Half_Track"){


std::normal_distribution<double> distribution(5,2);

int brokenNumber = distribution(*gptr);

//We have 9 parts in each Wheeled Object
int numToGenerate = 15;

//Number of good parts after we deduct broken
int goodNumber = numToGenerate - brokenNumber;


std::uniform_int_distribution<int> randPartGenerator(1,40);

name = "Half-Track";


    if(trackType == 1){
        vehicleID = 1;

    int brokenLeft = brokenNumber;

    while(brokenLeft != 0){
        int brokenID = randPartGenerator(*gptr);

         if((brokenID >= 1 && brokenID<= 5) || (brokenID >= 31 && brokenID<= 40 )){
            bool found = (std::find(brokenParts.begin(), brokenParts.end(), brokenID) != brokenParts.end());

            if(found == false){
                brokenParts.push_back(brokenID);
                brokenLeft--;

                //std::cerr << "Broken Part Generated: " << brokenID << std::endl;
            }
        }
    }
    while(goodNumber != 0){
        int goodID = randPartGenerator(*gptr);

         if((goodID >= 1 && goodID<= 5) || (goodID >= 31 && goodID<= 40 )){
            bool foundBroken = (std::find(brokenParts.begin(), brokenParts.end(), goodID) != brokenParts.end());
            bool foundGood = (std::find(workingParts.begin(), workingParts.end(), goodID) != workingParts.end());

            if(foundBroken == false && foundGood == false){
                goodNumber--;
                workingParts.push_back(goodID);

                //std::cerr << "Good Part Generated " << goodID << std::endl;
            }

        }
    }

    }
}






Half_Track::~Half_Track(){
    std::cout << "destroying Half-Track Vehicle" << std::endl;
}

void Half_Track::display(std::ostream& outs){
    Vehicle::display(outs);
        outs << "Type: " << vehicleID << std::endl << std::endl;

        if(!brokenParts.empty()){
            outs << "Broken Part ID's: ";

            itr = brokenParts.begin();

            while(itr != brokenParts.end()){
                outs << (*itr) << " ";
                itr++;
            }
        }

        else{
            outs << "There were no damaged parts produced";
        }

        outs << std::endl << std::endl;
}
