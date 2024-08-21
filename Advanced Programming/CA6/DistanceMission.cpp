#include "DistanceMission.hpp"

DistanceMission::DistanceMission(int m_id, int s_time, int e_time, int _reward, int r_distance)
    : Mission(m_id, s_time, e_time, _reward)
{
    remaining_distance = r_distance;
};

bool DistanceMission::is_mission_ended(Trip* trip)
{
    if (remaining_distance <= 0 && status == false)
    {
        end_mission = trip->get_end_trip();
        status = true;
        return true;
    }
    else
        return false;
};

Mission* DistanceMission::handle_trip(Trip* trip)
{
    if ((trip->get_start_trip() >= start_time) && (trip->get_end_trip() <= end_time))
    {
        int spent_distance = trip->get_distance();
        remaining_distance = remaining_distance - spent_distance;
    }
    if (is_mission_ended(trip))
    {
        return this;
    }
    return NULL;
};

Mission* DistanceMission::clone()
{
    return new DistanceMission(*this);
}