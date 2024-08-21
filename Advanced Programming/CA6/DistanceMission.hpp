#ifndef _DISTANCEMISSION_HPP
#define _DISTANCEMISSION_HPP
#include "Mission.hpp"


class DistanceMission : public Mission
{
private:
    int remaining_distance;

public:
    DistanceMission(int m_id, int s_time, int e_time, int _reward, int r_distance);
    virtual int get_mission_data() { return remaining_distance; };
    virtual bool is_mission_ended(Trip* trip);
    virtual Mission* handle_trip(Trip* trip);
    virtual Mission* clone() ;
};

#endif