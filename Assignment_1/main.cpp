#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include <random>
#include <ctime>
#include <list>
#include <iomanip>
#include "Vehicle.h"
#include "Tank.h"
#include "Half_Track.h"
#include "Wheeled.h"
#include "Scrapyard.h"
#include "Yardmaster.h"
#include "RepairBay.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

int menu();
void driver(Yardmaster* yardMaster, Scrapyard* scrapYard, std::list<Vehicle*>& vehicleCollection, int numDays, std::ofstream& myFile, std::default_random_engine* gptr, std::vector<RepairBay*>& repairBays);
void checkAndSend(Scrapyard* scrapYard, std::list<Vehicle*>& vehicleCollection, Yardmaster* yardMaster, std::queue<Vehicle*>& vehicleQueue);
void destroyAllVehicles(Scrapyard* scrapYard, std::list<Vehicle*>& vehicleCollection, Yardmaster* yardMaster);
void printVehicles(std::list<Vehicle*>& vehicleCollection, std::ofstream& myFile);
void displayRepairQueue(std::queue<Vehicle*>& vehicleQueue);
void fillRepairBay(std::queue<Vehicle*>& vehicleQueue, std::vector<RepairBay*>& repairBays);
void repairVehicles(std::vector<RepairBay*>& repairBays, Scrapyard* scrapYard, int Warehouse[]);
static bool throwAway(Vehicle* vehicle){delete vehicle; return true;}

int main(int argc,char* argv[]){

    std::ofstream myFile;
    myFile.open("VehicleInfo.txt");


	std::default_random_engine* gptr;
    gptr = new std::default_random_engine (time(NULL));

    //Why not make the yardmaster dynamic?
    Yardmaster* yardMaster = new Yardmaster("Billay", 23);

    //Repair Bay
    std::vector<RepairBay*> repairBays;
    RepairBay* Bay1 = new RepairBay();
    RepairBay* Bay2 = new RepairBay();
    RepairBay* Bay3 = new RepairBay();

    repairBays.push_back(Bay1);
    repairBays.push_back(Bay2);
    repairBays.push_back(Bay3);

    //List of Vehicle pointers
	std::list<Vehicle*> vehicles;

    //Scrapyard object
	Scrapyard* scrapyard = new Scrapyard(gptr);

	std::string snum = argv[1];
	int numDays = std::stoi(snum);

///Driver being passed one million things... Might be better to break this into segments...
	driver(yardMaster, scrapyard, vehicles, numDays, myFile, gptr, repairBays);



    //When done destroy all vehicles
    destroyAllVehicles(scrapyard, vehicles, yardMaster);
    myFile.close();




return 0;
}


/*int menu(){



	int selected = 0;

	std::cout << "Enter 1 to make damaged Tank type 1" << std::endl;
	std::cout << "Enter 2 to make damaged Tank type 2" << std::endl;
	std::cout << "Enter 3 to make damaged Tank type 3" << std::endl;
	std::cout << "Enter 4 to make damaged Wheeled type 1" << std::endl;
	std::cout << "Enter 5 to make damaged Wheeled type 2" << std::endl;
	std::cout << "Enter 6 to make damaged Half-Track type 1" << std::endl;
	std::cout << "Enter 7 to display vehicles" << std::endl;

	std::cout << "Enter the number: ";
	std::cin >> selected;
	std::cout << std::endl;


	while(selected < 0 || selected >8){
		std::cout << "Number is invalid, choose another number: ";
		std::cin >> selected;
        std::cout << std::endl;
	}

	return selected;
}*/


void driver(Yardmaster* yardMaster, Scrapyard* scrapYard, std::list<Vehicle*>& vehicleCollection, int numDays, std::ofstream& myFile, std::default_random_engine* gptr, std::vector<RepairBay*>& repairBays){

    //Declare vehicle and tank object pointers
    Vehicle* vptr = nullptr;
    Tank* tptr = nullptr;
    Half_Track* trackptr = nullptr;
    Wheeled* wptr = nullptr;

     //Queue to hold vehicles
    std::queue<Vehicle*> vehicleQueue;

    //Initialize Warehouse to 3 parts each
    int Warehouse[45];

    for(int i = 0; i<45; i++){
      Warehouse[i] = 3;

    }
    std::uniform_int_distribution<int> randVehicleGen(1,6);

    myFile << "This is the start of the Vehicle Repair Simulation  \n\n";
    myFile << "Listed below are the vehicles generated: \n\n ";

    //Main loop
    for(int i = 0; i<numDays; i++){

        int numToGenerate = randVehicleGen(*gptr);
        /*std::cerr <<  "Number per iteration: " << numToGenerate << std::endl;*/

        //Additional loop to generate random number of vehicles per time-stamp
        for(int i = 0; i < numToGenerate; i++){

    	   //Generate Random Vehicle Type
    	   int choice = randVehicleGen(*gptr);


    	   if(choice == 1){
                tptr = new Tank(1, gptr);
                vptr = tptr;
                vehicleCollection.push_back(vptr);
            }

            else if(choice == 2){
                tptr = new Tank(2, gptr);
                vptr = tptr;
                vehicleCollection.push_back(vptr);
            }

            else if(choice == 3){
                tptr = new Tank(3, gptr);
                vptr = tptr;
                vehicleCollection.push_back(vptr);
            }

            else if(choice == 4){
                wptr = new Wheeled(1, gptr);
                vptr = wptr;
                vehicleCollection.push_back(vptr);
            }

            else if (choice == 5){
                wptr = new Wheeled(2, gptr);
                vptr = wptr;
                vehicleCollection.push_back(vptr);
            }

            else if (choice == 6){
                trackptr = new Half_Track(1, gptr);
                vptr = trackptr;
                vehicleCollection.push_back(vptr);
            }

        }


    //Display vehicles that exist
     printVehicles(vehicleCollection, myFile);


    //Check vehicles and send them to scrapyard
    checkAndSend(scrapYard, vehicleCollection, yardMaster,vehicleQueue );
/*
    std::cout << "------------------------------------------------" << std::endl;*/
    std::cout << "Everything below belongs to the scrapyard" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;

    scrapYard->display();

    displayRepairQueue(vehicleQueue);

    std::cout << "------------------------------------------------" << std::endl;

    fillRepairBay(vehicleQueue, repairBays);

    repairVehicles(repairBays, scrapYard, Warehouse);
    }
}


    //Fill both scrapyard and repair bay with damaged vehicles
void checkAndSend(Scrapyard* scrapYard, std::list<Vehicle*>& vehicleCollection, Yardmaster* yardMaster, std::queue<Vehicle*>& vehicleQueue){


    std::list<Vehicle*>::iterator vItr;
    bool vehicleCondition = false;

     //iterate through all vehicles in the list
    vItr = vehicleCollection.begin();

    while(vItr != vehicleCollection.end()){

        //Return true if vehicle is going to scrap yard
        vehicleCondition = yardMaster->checkVehicleCondition((*vItr));
        //std::cerr << vehicleCondition << std::endl;

            //Send Vehicle Scrapyard
       if(vehicleCondition == 1){
            /*std::cerr << "Added Vehicle to Scrapyard" << std::endl;*/
            scrapYard->appendBrokenVeh((*vItr));
            /*std::cerr << "added Vehicle" << std::endl;*/
       }
            //Send vehicle to one of 3 repair bays
       else{

       /* std::cout << "Vehicle was added to repair queue" << std::endl;
        std::cout << **vItr;*/

        //Add Vehicle to Queue
        vehicleQueue.push((*vItr));

       /* std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;*/
       }


       vItr++;
    }

}

void destroyAllVehicles(Scrapyard* scrapYard, std::list<Vehicle*>& vehicleCollection, Yardmaster* yardMaster){

vehicleCollection.remove_if(throwAway);

}

void displayRepairQueue(std::queue<Vehicle*>& vehicleQueue){

    //Will be used to print queue
    Vehicle* vPtr = nullptr;
   /* std::cout << "QUEUE SIZE " <<queueSize;*/

    for(int i = 0; i<vehicleQueue.size(); i++){
        std::cout << "This vehicle is in the repair queue: " << *(vehicleQueue.front()) << std::endl;
        vPtr = vehicleQueue.front();
        vehicleQueue.pop();
        vehicleQueue.push(vPtr);
    }

}

void printVehicles(std::list<Vehicle*>& vehicleCollection, std::ofstream& myFile){

    std::list<Vehicle*>::iterator vItr;

    int i = 0;
    int collectionSize = vehicleCollection.size();


    if(!vehicleCollection.empty()){
        vItr = vehicleCollection.begin();

        std::cout << "This iteration added " << collectionSize << " Vehicles to be repaired " << std::endl << std::endl;
        while(vItr != vehicleCollection.end()){
            myFile << "displaying vehicle number " << i << " From Vehicle list" <<std::endl;
            std::cout << "displaying vehicle number " << i << " From Vehicle list" <<std::endl;
            std::cout << (**vItr);

            //Printing to terminal?
            /*myFile << (**vItr);*/
            vItr++;
            i++;

            }

            std::cout << std::endl;
            }

            else{ std::cout << "List is empty, cannot print " << std::endl << std::endl;}




}
/////////////////////////////////////////////////////////######################## MAKE SURE TO IMPLEMENT STATEMENT TO PREVENT GOOD VEHCICLES FROM BEING ADDED TO LSIT

//Removes vehicles from the vehicle queue and adds them to the repair bay
void fillRepairBay(std::queue<Vehicle*>& vehicleQueue, std::vector<RepairBay*>&  repairBays){
    Vehicle* vPtr = nullptr;
    int stop = 0;
    std::vector<RepairBay*>::iterator rItr;
    bool full = false;\
    rItr = repairBays.begin();
    int queueSize = vehicleQueue.size();

    if(!vehicleQueue.empty()){
      std::cout << "SIZE " << vehicleQueue.size() << std::endl;
        for(int i = 0; i<queueSize; i++){

            if(full != true){
              stop++;
              (*rItr) ->setSize(stop);

              full = (*rItr)->bayFull();
              // std::cout << "TESTING FULL " << full << std::endl;
              vPtr = vehicleQueue.front();

              (*rItr)->addToRepair(vPtr);
              (*rItr)->calculateRepairTime();
              std::cout << "The following vehicle have been added to the repair bays: " << std::endl;
              std::cout << "------------------------------------------------------------" << std::endl;
              std::cout << (*vPtr);

              vehicleQueue.pop();
              rItr++;
          }

        }

        std::cout << "EXITED" << std::endl;

        // int count = 0;
        // while(rItr != repairBays.end()){
        //   count++;
        //   std::cout << "TEST COUNT " << count << std::endl;
        //   rItr++;
        // }

    }

}

void repairVehicles(std::vector<RepairBay*>& repairBays, Scrapyard* scrapYard, int Warehouse[] ){
  Vehicle* vPtr = nullptr;
  std::vector<RepairBay*>::iterator itr;

  itr = repairBays.begin();
  auto times = repairBays.size();
  std::cout <<"SIZE HERE IS " << times << std::endl;

  while(!repairBays.empty()){
    std::cout << "-------------------------------------------------------------------" <<std::endl;
    vPtr = (*itr)-> getVehicle();
    std::cout << *vPtr;
    itr++;
  }





};
//Divide highest broken part # by 4, this will determine repair time. Each iteration of the loop decrement the time necessary to repair the part. RepairBay keeps track of the time counter
