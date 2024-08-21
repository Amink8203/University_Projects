#include "Run.hpp"

void time_mission(vector<Mission*>& missions,vector<Driver*>& drivers, vector<string> input)
{
    if (add_is_incorrect(input))
            {
                cout << INVALID_ARGUMENTS << endl;
                return;
            }
            init_time_mission(missions, input);
}

void distance_mission(vector<Mission*>& missions,vector<Driver*>& drivers, vector<string> input)
{
    if (add_is_incorrect(input))
            {
                cout << INVALID_ARGUMENTS << endl;
                return;
            }
            init_distance_mission(missions, input);

}

void count_mission(vector<Mission*>& missions,vector<Driver*>& drivers, vector<string> input)
{
    if (add_is_incorrect(input))
            {
                cout << INVALID_ARGUMENTS << endl;
                return;
            }
            init_count_mission(missions, input);

}

void assign_mission(vector<Mission*>& missions,vector<Driver*>& drivers, vector<string> input)
{
    if (assign_is_incorrect(input))
            {
                cout << INVALID_ARGUMENTS << endl;
                return;
            }
            int _mission_id = stoi(input[1]);
            int _driver_id = stoi(input[2]);

            if (find_mission(missions, _mission_id) == NULL)
            {
                cout << MISSION_NOT_FOUND << endl;
                return;
            }
            handle_assign_mission(missions, drivers, _mission_id, _driver_id);

}

void record_ride(vector<Mission*>& missions,vector<Driver*>& drivers, vector<string> input)
{
    if (record_is_incorrect(input))
            {
                cout << INVALID_ARGUMENTS << endl;
                return;
            }
            int _start_trip = stoi(input[1]);
            int _end_trip = stoi(input[2]);
            int _driver_id = stoi(input[3]);
            int _distance = stoi(input[4]);
            handle_record_ride(missions, drivers, _start_trip, _end_trip, _driver_id, _distance);

}

void show_missions_status(vector<Mission*>& missions,vector<Driver*>& drivers, vector<string> input)
{
    if (show_is_incorrect(input))
            {
                cout << INVALID_ARGUMENTS << endl;
                return;
            }
            int _driver_id = stoi(input[1]);
            show_missions(missions, drivers, _driver_id);

}