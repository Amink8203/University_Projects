#ifndef _RUN_HPP
#define _RUN_HPP
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <memory>
#include "Constants.hpp"
#include "Trip.hpp"
#include "Mission.hpp"
#include "TimeMission.hpp"
#include "DistanceMission.hpp"
#include "CountMission.hpp"
#include "Driver.hpp"
#include "Functions.hpp"
using namespace std;

void time_mission(vector<Mission*>& missions,vector<Driver*>& drivers, vector<string> input);
void distance_mission(vector<Mission*>& missions,vector<Driver*>& drivers, vector<string> input);
void count_mission(vector<Mission*>& missions,vector<Driver*>& drivers, vector<string> input);
void assign_mission(vector<Mission*>& missions,vector<Driver*>& drivers, vector<string> input);
void record_ride(vector<Mission*>& missions,vector<Driver*>& drivers, vector<string> input);
void show_missions_status(vector<Mission*>& missions,vector<Driver*>& drivers, vector<string> input);


#endif