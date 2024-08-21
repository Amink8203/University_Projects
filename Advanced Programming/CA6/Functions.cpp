#include "Functions.hpp"

Mission* find_mission(vector<Mission*> &missions, int _mission_id)
{
    for (int i = 0; i < missions.size(); i++)
    {
        if (missions[i]->get_mission_id() == _mission_id)
        {
            return missions[i];
        }
    }
    return NULL;
};

void input_command(vector<string> &input)
{
    int j = 0;
    string str;
    getline(cin, str);
    istringstream line(str);
    while (line >> input.at(j))
    {
        input.push_back(" ");
        j++;
    }
    input.pop_back();
};

bool time_is_wrong(vector<Mission*> &missions, vector<string> input)
{
    int _mission_id = stoi(input[1]);
    int _start_time = stoi(input[2]);
    int _end_time = stoi(input[3]);
    int _remaining_time = stoi(input[4]);
    int _reward = stoi(input[5]);
    if ((_start_time > _end_time) || (_remaining_time < 0) || (_reward < 0))
    {
        cout << INVALID_ARGUMENTS << endl;
        return true;
    }
    if (find_mission(missions, _mission_id) != NULL)
    {
        cout << DUPLICATE_MISSION_ID << endl;
        return true;
    }
    return false;
};

void init_time_mission(vector<Mission*> &missions, vector<string> input)
{
    if (time_is_wrong(missions, input))
    {
        return;
    }
    int _mission_id = stoi(input[1]);
    int _start_time = stoi(input[2]);
    int _end_time = stoi(input[3]);
    int _remaining_time = stoi(input[4]);
    int _reward = stoi(input[5]);
    TimeMission* time_mission = new TimeMission(_mission_id, _start_time, _end_time, _reward, _remaining_time);
    missions.push_back(time_mission);
    cout << OK << endl;
};

bool distance_is_wrong(vector<Mission*> &missions, vector<string> input)
{
    int _mission_id = stoi(input[1]);
    int _start_time = stoi(input[2]);
    int _end_time = stoi(input[3]);
    int _remaining_distance = stoi(input[4]);
    int _reward = stoi(input[5]);
    if ((_start_time > _end_time) || (_remaining_distance < 0) || (_reward < 0))
    {
        cout << INVALID_ARGUMENTS << endl;
        return true;
    }
    if (find_mission(missions, _mission_id) != NULL)
    {
        cout << DUPLICATE_MISSION_ID << endl;
        return true;
    }
    return false;
};

void init_distance_mission(vector<Mission*> &missions, vector<string> input)
{
    if (distance_is_wrong(missions, input))
    {
        return;
    }
    int _mission_id = stoi(input[1]);
    int _start_time = stoi(input[2]);
    int _end_time = stoi(input[3]);
    int _remaining_distance = stoi(input[4]);
    int _reward = stoi(input[5]);
    DistanceMission* distance_mission = new DistanceMission(_mission_id, _start_time, _end_time, _reward, _remaining_distance);
    missions.push_back(distance_mission);
    cout << OK << endl;
};

bool count_is_wrong(vector<Mission*> &missions, vector<string> input)
{
    int _mission_id = stoi(input[1]);
    int _start_time = stoi(input[2]);
    int _end_time = stoi(input[3]);
    int _remaining_counts = stoi(input[4]);
    int _reward = stoi(input[5]);
    if ((_start_time > _end_time) || (_remaining_counts < 0) || (_reward < 0))
    {
        cout << INVALID_ARGUMENTS << endl;
        return true;
    }
    if (find_mission(missions, _mission_id) != NULL)
    {
        cout << DUPLICATE_MISSION_ID << endl;
        return true;
    }
    return false;
};

void init_count_mission(vector<Mission*> &missions, vector<string> input)
{
    if (count_is_wrong(missions, input))
    {
        return;
    }
    int _mission_id = stoi(input[1]);
    int _start_time = stoi(input[2]);
    int _end_time = stoi(input[3]);
    int _remaining_count = stoi(input[4]);
    int _reward = stoi(input[5]);
    CountMission* count_mission = new CountMission(_mission_id, _start_time, _end_time, _reward, _remaining_count);
    missions.push_back(count_mission);
    cout << OK << endl;
};

Driver* find_driver(vector<Driver*> &drivers, int _driver_id)
{
    for (int j = 0; j < drivers.size(); j++)
    {
        if (drivers[j]->get_driver_id() == _driver_id)
        {
            return drivers[j];
        }
    }
    return NULL;
}

void add_new_driver(vector<Mission*> &missions, vector<Driver*> &drivers, int _mission_id, int _driver_id)
{
    Mission* current_mission = find_mission(missions, _mission_id);
    Mission* new_mission(current_mission->clone());
    Driver* new_driver = new Driver(_driver_id);
    new_driver->add_mission(new_mission);
    drivers.push_back(new_driver);
}

bool driver_is_available(vector<Driver*> &drivers, int _driver_id)
{
    for (int j = 0; j < drivers.size(); j++)
    {
        if (drivers[j]->get_driver_id() == _driver_id)
        {
            return true;
        }
    }
    return false;
};

void add_mission_to_driver(vector<Mission*> &missions, vector<Driver*> &drivers, int _mission_id, int _driver_id)
{
    Mission* current_mission = find_mission(missions, _mission_id);
    Mission* new_mission(current_mission->clone());
    Driver* new_driver = find_driver(drivers, _driver_id);
    new_driver->add_mission(new_mission);
}

void set_new_driver(vector<Mission*> &missions, vector<Driver*> &drivers, int _mission_id, int _driver_id)
{
    add_new_driver(missions, drivers, _mission_id, _driver_id);
};
void set_mission(vector<Mission*> &missions, vector<Driver*> &drivers, int _mission_id, int _driver_id)
{
    add_mission_to_driver(missions, drivers, _mission_id, _driver_id);
};

void handle_assign_mission(vector<Mission*> &missions, vector<Driver*> &drivers, int _mission_id, int _driver_id)
{
    if (!driver_is_available(drivers, _driver_id))
    {
        set_new_driver(missions, drivers, _mission_id, _driver_id);
        cout << OK << endl;
        return;
    }
    else
    {
        for (int j = 0; j < drivers.size(); j++)
        {
            if (drivers[j]->get_driver_id() == _driver_id)
            {
                if (drivers[j]->mission_is_available(_mission_id))
                {
                    cout << "DUPLICATE_DRIVER_MISSION" << endl;
                    return;
                }
                else
                {
                    set_mission(missions, drivers, _mission_id, _driver_id);
                    cout << "OK" << endl;
                    return;
                }
            }
        }
    }
};

void show_record(vector<Mission*> &ended_missions, int _driver_id)
{
    int enter_count = -1;
    sort(ended_missions.begin(), ended_missions.end(), [](Mission* m1, Mission* m2)
         { return m1->get_start_mission() < m2->get_start_mission(); });
    cout << "completed missions for driver " << _driver_id << ":" << endl;
    for (int i = 0; i < ended_missions.size(); i++)
    {
        if (ended_missions[i] != NULL && !ended_missions[i]->has_written())
        {
            enter_count++;
        }
    }
    for (int i = 0; i < ended_missions.size(); i++)
    {
        if (ended_missions[i] != NULL && !ended_missions[i]->has_written())
        {
            cout << "mission: " << ended_missions[i]->get_mission_id() << endl;
            cout << "start timestamp: " << ended_missions[i]->get_start_mission() << endl;
            cout << "end timestamp: " << ended_missions[i]->get_end_mission() << endl;
            cout << "reward: " << ended_missions[i]->get_reward() << endl;
            ended_missions[i]->set_wrote_status();
            if(enter_count > 0)
            {
                cout << endl;
                enter_count--;
            }
        }
    }
};

void handle_record_ride(vector<Mission*> &missions, vector<Driver*> &drivers, int _start_trip, int _end_trip, int _driver_id, int _distance)
{
    vector<Mission*> ended_missions;
    Trip* new_trip = new Trip(_driver_id, _start_trip, _end_trip, _distance);
    Driver* driver = find_driver(drivers, _driver_id);
    driver->trip_record(new_trip, ended_missions);
    show_record(ended_missions, _driver_id);
};

void show_missions(vector<Mission*>& missions, vector<Driver*>& drivers, int _driver_id)
{
    Driver* driver = find_driver(drivers, _driver_id);
    driver->sort_missions();
    driver->show_missions();
};

void _delete(vector<Mission*> missions, vector<Driver*> drivers)
{
    for(Mission*& mission : missions)
    delete mission;
    for(Driver*& driver : drivers)
    delete driver;
}

bool add_is_incorrect(vector<string> input) { return input.size() != 6; };
bool record_is_incorrect(vector<string> input) { return input.size() != 5 || stoi(input[2]) < stoi(input[1]); };
bool assign_is_incorrect(vector<string> input) { return input.size() != 3; };
bool show_is_incorrect(vector<string> input) { return input.size() != 2; };