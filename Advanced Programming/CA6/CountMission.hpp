#ifndef _COUNTMISSION_HPP
#define _COUNTMISSION_HPP
#include "Mission.hpp"

class CountMission : public Mission
{
private:
    int remaining_counts;

public:
    CountMission(int m_id, int s_time, int e_time, int _reward, int r_counts);
    virtual int get_mission_data() { return remaining_counts; };
    virtual bool is_mission_ended(Trip* trip);
    virtual Mission* handle_trip(Trip* trip);
    virtual Mission* clone();
};

#endif