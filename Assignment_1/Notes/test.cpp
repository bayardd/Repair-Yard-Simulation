#include <iostream>
#include <chrono>
#include <random>

int main(){
std::default_random_engine* gptr;
    gptr = new std::default_random_engine (time(NULL));
std::normal_distribution<double> distribution(2,5);

	std::cout << distribution(*gptr);
/*

for(int i =0; i<10; i++){
	std::cout << distribution(*gptr);
}

*/

	return 0;
}