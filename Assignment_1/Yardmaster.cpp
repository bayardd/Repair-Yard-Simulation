#include "Yardmaster.h"

bool Yardmaster::checkVehicleCondition(Vehicle* vptr){
	int sumWorking = 0;
	int sumBroken = 0;

	for(auto itr = vptr->workingListBegin(); itr != vptr->workingListEnd(); itr++){

			/*std::cerr << "test" << std::endl;*/
			sumWorking += (*itr);
			/*std::cout <<  "Working parts sums: " << sumWorking << std::endl;*/
			
	}

	/*std::cout << "----------------------------------------------------------------------------------------------" << std::endl;*/

	for(auto itr = vptr->brokenListBegin(); itr != vptr->brokenListEnd(); itr++){
			/*std::cerr << "test 2" << std::endl;*/
			sumBroken += (*itr);
			/*std::cout << "Broken Parts Sums " << sumBroken << std::endl;*/
	}

	/*std::cout << "------------------------------------------------------------------------------------------------" << std::endl;
*/
	int TotalParts = sumWorking + sumBroken;

	return(sumBroken > (TotalParts * (.50)));

	return false;





}