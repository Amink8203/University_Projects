all: main.out

main.out: Trip.o Mission.o TimeMission.o DistanceMission.o CountMission.o Driver.o Functions.o Run.o main.o
	g++ --std=c++11 Trip.o Mission.o TimeMission.o DistanceMission.o CountMission.o Driver.o Functions.o Run.o main.o -o main

main.o: main.cpp Run.hpp
	g++ --std=c++11 -c main.cpp

Trip.o: Trip.cpp Constants.hpp Trip.hpp
	g++ --std=c++11 -c Trip.cpp

Mission.o: Mission.cpp Trip.hpp Constants.hpp Mission.hpp
	g++ --std=c++11 -c Mission.cpp

TimeMission.o: TimeMission.cpp Mission.hpp TimeMission.hpp
	g++ --std=c++11 -c TimeMission.cpp

DistanceMission.o: DistanceMission.cpp Mission.hpp TimeMission.hpp
	g++ --std=c++11 -c DistanceMission.cpp

CountMission.o: CountMission.cpp Mission.hpp CountMission.hpp
	g++ --std=c++11 -c CountMission.cpp

Driver.o: Driver.cpp Mission.hpp Driver.hpp
	g++ --std=c++11 -c Driver.cpp

Functions.o: Functions.cpp Mission.hpp Driver.hpp TimeMission.hpp DistanceMission.hpp CountMission.hpp Functions.hpp
	g++ --std=c++11 -c Functions.cpp

Run.o: Run.cpp Mission.hpp Driver.hpp TimeMission.hpp DistanceMission.hpp CountMission.hpp Functions.hpp Run.hpp
	g++ --std=c++11 -c Run.cpp

clean:
	rm *.o main