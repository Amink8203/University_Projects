#include "TimeMission.hpp"

TimeMission::TimeMission(int m_id, int s_time, int e_time, int _reward, int r_time)
    : Mission(m_id, s_time, e_time, _reward)
{
    remaining_time = r_time * ONE_MINUTE;
};

bool TimeMission::is_mission_ended(Trip* trip)
{
    if (remaining_time <= 0 && status == false)
    {
        end_mission = trip->get_end_trip();
        status = true;
        return true;
    }
    else
        return false;
};

Mission* TimeMission::handle_trip(Trip* trip)
{
    if ((trip->get_start_trip() >= start_time) && (trip->get_end_trip() <= end_time))
    {
        int spent_time = trip->get_end_trip() - trip->get_start_trip();
        remaining_time = remaining_time - spent_time;
    }
    if (is_mission_ended(trip))
    {
        return this;
    }
    return NULL;
};

Mission* TimeMission::clone()
{
    return new TimeMission(*this);
}