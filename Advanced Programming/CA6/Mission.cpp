#include "Mission.hpp"

Mission::Mission(int m_id, int s_time, int e_time, int _reward)
        : mission_id(m_id), start_time(s_time), end_time(e_time), reward(_reward)
    {
        end_mission = -1;
        status = false;
        wrote_status = false;
    };

int Mission::get_mission_id() const { return mission_id; };
int Mission::get_start_mission() const { return start_time; };
int Mission::get_end_mission() const { return end_mission; };
int Mission::get_end_time() const { return end_time; };
int Mission::get_reward() const { return reward; };
bool Mission::is_completed() const { return status; };
bool Mission::has_written() const { return wrote_status; };
void Mission::set_wrote_status() { wrote_status = true; };