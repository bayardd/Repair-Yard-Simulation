#include "Wheeled.h"

Wheeled::Wheeled(int wheeledType, std::default_random_engine* gptr) : Vehicle("Wheeled"){

std::normal_distribution<double> distribution(5,2);

std::uniform_int_distribution<int> randPartGeneratorT1(31,40);
std::uniform_int_distribution<int> randPartGeneratorT2(36,45);


int brokenNumber = distribution(*gptr);

//We have 9 parts in each Wheeled Object
int numToGenerate = 10;

//Number of good parts after we deduct broken
int goodNumber = numToGenerate - brokenNumber;



name = "Wheeled";
if(wheeledType == 1){
   vehicleID = 1;

    int brokenLeft = brokenNumber;

    while(brokenLeft != 0){
        int brokenID = randPartGeneratorT1(*gptr);
        bool found = (std::find(brokenParts.begin(), brokenParts.end(), brokenID) != brokenParts.end());

        if(found == false){
            brokenParts.push_back(brokenID);
            brokenLeft--;

            //std::cerr << "Broken Part Generated: " << brokenID << std::endl;
        }
    }

    while(goodNumber != 0){
        int goodID = randPartGeneratorT1(*gptr);
        bool foundBroken = (std::find(brokenParts.begin(), brokenParts.end(), goodID) != brokenParts.end());
        bool foundGood = (std::find(workingParts.begin(), workingParts.end(), goodID) != workingParts.end());

        if(foundBroken == false && foundGood == false){
            goodNumber--;
            workingParts.push_back(goodID);

            //std::cerr << "Good Part Generated " << goodID << std::endl;
        }

    }

}

if(wheeledType == 2){
    vehicleID = 2;

    int brokenLeft = brokenNumber;

    while(brokenLeft != 0){
        int brokenID = randPartGeneratorT2(*gptr);
        bool found = (std::find(brokenParts.begin(), brokenParts.end(), brokenID) != brokenParts.end());

        if(found == false){
            brokenParts.push_back(brokenID);
            brokenLeft--;

            //std::cerr << "Broken Part Generated: " << brokenID << std::endl;
        }
    }

    while(goodNumber != 0){
        int goodID = randPartGeneratorT2(*gptr);
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

void Wheeled::display(std::ostream& outs){
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
