#ifndef _DRIVER_HPP
#define _DRIVER_HPP
#include "Mission.hpp"

class Driver
{
private:
    vector<Mission*> missions;
    int driver_id;

public:
    Driver(int d_id) : driver_id(d_id) {}
    ~Driver();
    int get_driver_id() { return driver_id; }
    void add_mission(Mission* mission) { missions.push_back(mission); }
    bool mission_is_available(int _mission_id);
    void trip_record(Trip* trip, vector<Mission*> &ended_missions);
    void sort_missions();
    void show_missions();
};


#endif