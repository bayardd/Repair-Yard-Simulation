#include "Scrapyard.h"

Scrapyard::Scrapyard(std::default_random_engine* gptr){

	Vehicle* vPtr = nullptr;
	std::uniform_int_distribution<int> randScrapVeh(1,6);

	Tank* tptr = nullptr;
	Wheeled* wptr = nullptr;
	Half_Track* trackptr = nullptr;


	for(int i = 0; i < 10; i++){

		int typeScrapVehicle = randScrapVeh(*gptr);

		if(typeScrapVehicle == 1){
                tptr = new Tank(1, gptr);
                vPtr = tptr;
                scrappedVehCollection.push_back(vPtr);
                
            }

            else if(typeScrapVehicle == 2){
                tptr = new Tank(2, gptr);
                vPtr = tptr;
                scrappedVehCollection.push_back(vPtr);
                
            }

            else if(typeScrapVehicle == 3){
                tptr = new Tank(3, gptr);
                vPtr = tptr;
                scrappedVehCollection.push_back(vPtr);
            }

            else if(typeScrapVehicle == 4){
                wptr = new Wheeled(1, gptr);
                vPtr = wptr;
                scrappedVehCollection.push_back(wptr);
               	
            }

            else if (typeScrapVehicle == 5){
                wptr = new Wheeled(2, gptr);
                vPtr = wptr;
                scrappedVehCollection.push_back(vPtr);
                
            }

            else if (typeScrapVehicle == 6){
                trackptr = new Half_Track(1, gptr);
                vPtr = trackptr;
                scrappedVehCollection.push_back(vPtr);
                
            }


	}

}



void Scrapyard::appendBrokenVeh(Vehicle* Vehicle){

	scrappedVehCollection.push_back(Vehicle);

	/*std::cout << "Added Vehicle to scrapyard: \n" << *(Vehicle) << std::endl;*/

}

void Scrapyard::display(){

	if(!scrappedVehCollection.empty()){

		vItr = scrappedVehCollection.begin();

		while(vItr != scrappedVehCollection.end()){
			std::cout << "Vehicle Name: " << (*vItr)->getName() << " Type " << (*vItr)->getID() << std::endl;
			vItr++;
		}

        std::cout << "--------------------------------------------" << std::endl;


	}
}