#include "Tank.h"



//Making Type 1,2, or 3 tank
Tank::Tank(int tankType, std::default_random_engine* gptr) : Vehicle("Tank"){

//Generate random number of parts between 1 and 11
    std::uniform_int_distribution<int> randPartGeneratorT1(1,11);
    std::uniform_int_distribution<int> randPartGeneratorT2(2,22);
    std::uniform_int_distribution<int> randPartGeneratorT3(3,33);


    //generate random number of broken parts
    std::normal_distribution<double> distribution(3,1);


//int numberParts = numPartsGenerator(*gptr);
//std::cout << "Attempting to make: " << numberParts << " Parts" << std::endl;

    //Number of broken parts to generate
    int brokenNumber = distribution(*gptr);

    //We have 11 unique parts to generate for Type 1,2,3
    int numToGenerate = 11;

    //Number of good parts after we deduct broken
    int goodNumber = numToGenerate - brokenNumber;

    name = "Tank";



if(tankType == 1){

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

if(tankType == 2){

    vehicleID = 2;

   int brokenLeft = brokenNumber;

    while(brokenLeft != 0){
        int brokenID = randPartGeneratorT2(*gptr);


        if(brokenID %2 == 0){
            bool found = (std::find(brokenParts.begin(), brokenParts.end(), brokenID) != brokenParts.end());

            if(found == false){
                brokenParts.push_back(brokenID);
                brokenLeft--;

                //std::cerr << "Broken Part Generated: " << brokenID << std::endl;
            }
        }
    }

    while(goodNumber != 0){
        int goodID = randPartGeneratorT2(*gptr);

        if(goodID %2 == 0){
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

if(tankType == 3){

    vehicleID = 3;

    name="Tank";

   int brokenLeft = brokenNumber;

    while(brokenLeft != 0){
        int brokenID = randPartGeneratorT3(*gptr);

        if(brokenID %3 == 0){
            bool found = (std::find(brokenParts.begin(), brokenParts.end(), brokenID) != brokenParts.end());

            if(found == false){
                brokenParts.push_back(brokenID);
                brokenLeft--;

                //std::cerr << "Broken Part Generated: " << brokenID << std::endl;
            }
        }
    }

    while(goodNumber != 0){
        int goodID = randPartGeneratorT3(*gptr);

        if(goodID %3 == 0){
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


void Tank::display(std::ostream& outs)  {

        //std::cout << "calling Tank display" << std::endl;
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
