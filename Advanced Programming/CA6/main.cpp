#include "Run.hpp"

int main()
{
    vector<Mission*> missions;
    vector<Driver*> drivers;
    while (true)
    {
        vector<string> input(1);
        input_command(input);
        string command = input[0];
        if (command == ADD_TIME_MISSION)
        {
            time_mission(missions,drivers,input);
        }

        else if (command == ADD_DISTANCE_MISSION)
        {
            distance_mission(missions,drivers,input);
        }

        else if (command == ADD_COUNT_MISSION)
        {
            count_mission(missions,drivers,input);
        }

        else if (command == ASSIGN_MISSION)
        {
            assign_mission(missions,drivers,input);
        }

        else if (command == RECORD_RIDE)
        {
            record_ride(missions,drivers,input);
        }

        else if (command == SHOW_MISSIONS_STATUS)
        {
            show_missions_status(missions, drivers, input);
        }
    }
    _delete(missions, drivers);
    return 0;
}