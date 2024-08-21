#include "Driver.hpp"


Driver::~Driver()
{
    for(int i=0; i<missions.size(); i++)
    {
        delete missions[i];
    }
}

void Driver::trip_record(Trip* trip, vector<Mission*> &ended_missions)
{
    for (int i = 0; i < missions.size(); i++)
    {
        Mission* current_mission = missions[i]->handle_trip(trip);
        if (current_mission != NULL)
        {
            ended_missions.push_back(current_mission);
        }
    }
}

bool Driver::mission_is_available(int _mission_id)
{
    for (int i = 0; i < missions.size(); i++)
    {
        if (missions[i]->get_mission_id() == _mission_id)
        {
            return true;
        }
    }
    return false;
}

void Driver::sort_missions()
{
    sort(missions.begin(), missions.end(), [](Mission* m1, Mission* m2)
         { return m1->get_start_mission() < m2->get_start_mission(); });
};

void Driver::show_missions()
{
    cout << "missions status for driver " << driver_id << ":" << endl;
    for (int i = 0; i < missions.size(); i++)
    {
        cout << "mission " << missions[i]->get_mission_id() << ":" << endl;
        cout << "start timestamp: " << missions[i]->get_start_mission() << endl;
        cout << "end timestamp: " << missions[i]->get_end_mission() << endl;
        cout << "reward: " << missions[i]->get_reward() << endl;
        if (i == missions.size() - 1)
        {
            if (missions[i]->is_completed())
            {
                cout << "status: completed" << endl;
                return;
            }
            else
            {
                cout << "status: ongoing" << endl;
                return;
            }
        }
        if (missions[i]->is_completed())
        {
            cout << "status: completed" << endl << endl;
        }
        else
        {
            cout << "status: ongoing" << endl << endl;
        }
    }
};