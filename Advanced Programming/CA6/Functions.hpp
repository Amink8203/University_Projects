#ifndef _FUNCTIONS_HPP
#define _FUNCTIONS_HPP
#include "Mission.hpp"
#include "Driver.hpp"
#include "TimeMission.hpp"
#include "DistanceMission.hpp"
#include "CountMission.hpp"

Mission* find_mission(vector<Mission*> &missions, int _mission_id);
void input_command(vector<string> &input);
bool time_is_wrong(vector<Mission*> &missions, vector<string> input);
void init_time_mission(vector<Mission*> &missions, vector<string> input);
bool distance_is_wrong(vector<Mission*> &missions, vector<string> input);
void init_distance_mission(vector<Mission*> &missions, vector<string> input);
bool count_is_wrong(vector<Mission*> &missions, vector<string> input);
void init_count_mission(vector<Mission*> &missions, vector<string> input);
Driver* find_driver(vector<Driver*> &drivers, int _driver_id);
void add_new_driver(vector<Mission*> &missions, vector<Driver*> &drivers, int _mission_id, int _driver_id);
bool driver_is_available(vector<Driver*> &drivers, int _driver_id);
void add_mission_to_driver(vector<Mission*> &missions, vector<Driver*> &drivers, int _mission_id, int _driver_id);
void set_new_driver(vector<Mission*> &missions, vector<Driver*> &drivers, int _mission_id, int _driver_id);
void set_mission(vector<Mission*> &missions, vector<Driver*> &drivers, int _mission_id, int _driver_id);
void handle_assign_mission(vector<Mission*> &missions, vector<Driver*> &drivers, int _mission_id, int _driver_id);
void show_record(vector<Mission*> &ended_missions, int _driver_id);
void handle_record_ride(vector<Mission*> &missions, vector<Driver*> &drivers, int _start_trip, int _end_trip, int _driver_id, int _distance);
void show_missions(vector<Mission*>& missions, vector<Driver*>& drivers, int _driver_id);
bool add_is_incorrect(vector<string> input);
bool record_is_incorrect(vector<string> input);
bool assign_is_incorrect(vector<string> input);
bool show_is_incorrect(vector<string> input);
void _delete(vector<Mission*> missions, vector<Driver*> drivers);


#endif