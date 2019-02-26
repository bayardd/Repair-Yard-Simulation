# assignment_1: main.o tank.o
# 	g++ -o assignment_1 main.o 

# main.o: main.cpp Tank.h Vehicle.h
# 	g++ -c main.cpp

# tank.o: Tank.cpp Tank.h Vehicle.h
# 	g++ -c Tank.cpp


all: main.o tank.o half_track.o wheeled.o scrapyard.o yardmaster.o repairbay.o
	g++ -g -Wall -Wextra main.o Tank.o Half_Track.o Wheeled.o Scrapyard.o Yardmaster.o RepairBay.o -o prog1

main.o: main.cpp Vehicle.h
	g++ -g -Wall -Wextra -c main.cpp

tank.o: Tank.cpp Tank.h Vehicle.h
	g++ -g -Wall -Wextra -c Tank.cpp

half_track.o: Half_Track.cpp Half_Track.h Vehicle.h
	g++ -g -Wall -Wextra -c Half_Track.cpp

wheeled.o: Wheeled.cpp Wheeled.h Vehicle.h
	g++ -g -Wall -Wextra -c Wheeled.cpp

scrapyard.o: Scrapyard.cpp Scrapyard.h
	g++ -g -Wall -Wextra -c Scrapyard.cpp

yardmaster.o: Yardmaster.cpp Yardmaster.h
	g++ -g -Wall -Wextra -c Yardmaster.cpp

repairbay.o: RepairBay.cpp RepairBay.h
	g++ -g -Wall -Wextra -c RepairBay.cpp