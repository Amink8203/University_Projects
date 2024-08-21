#ifndef _MISSION_HPP
#define _MISSION_HPP
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <memory>
#include <sstream>
#include "Trip.hpp"
#include "Constants.hpp"
using namespace std;

const int ONE_MINUTE = 60;

class Mission
{
protected:
    int mission_id;
    int start_time;
    int end_time;
    int end_mission;
    int reward;
    bool status;
    bool wrote_status;

public:
    Mission(int m_id, int s_time, int e_time, int _reward);
    int get_mission_id() const;
    int get_start_mission() const;
    int get_end_mission() const;
    int get_end_time() const;
    int get_reward() const;
    bool is_completed() const;
    bool has_written() const;
    void set_wrote_status();
    virtual int get_mission_data() = 0;
    virtual Mission* clone() = 0;
    virtual bool is_mission_ended(Trip* trip) = 0;
    virtual Mission* handle_trip(Trip* trip) = 0;
};


#endif