#include "CountMission.hpp"

CountMission::CountMission(int m_id, int s_time, int e_time, int _reward, int r_counts)
    : Mission(m_id, s_time, e_time, _reward)
{
    remaining_counts = r_counts;
}

bool CountMission::is_mission_ended(Trip* trip)
{
    if (remaining_counts <= 0 && status == false)
    {
        end_mission = trip->get_end_trip();
        status = true;
        return true;
    }
    else
        return false;
}

Mission* CountMission::handle_trip(Trip* trip)
{
    if ((trip->get_start_trip() >= start_time) && (trip->get_end_trip() <= end_time))
    {
        remaining_counts--;
    }
    if (is_mission_ended(trip))
    {
        return this;
    }
    return NULL;
};

Mission* CountMission::clone()
{
    return new CountMission(*this);
}