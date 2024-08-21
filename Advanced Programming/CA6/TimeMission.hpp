#ifndef _TIMEMISSION_HPP
#define _TIMEMISSION_HPP
#include "Mission.hpp"


class TimeMission : public Mission
{
private:
    int remaining_time;

public:
    TimeMission(int m_id, int s_time, int e_time, int _reward, int r_time);
    int get_remaining_time() const { return remaining_time; };
    virtual int get_mission_data() { return remaining_time; };
    virtual bool is_mission_ended(Trip* trip);
    virtual Mission* handle_trip(Trip* trip);
    virtual Mission* clone();
};




#endif