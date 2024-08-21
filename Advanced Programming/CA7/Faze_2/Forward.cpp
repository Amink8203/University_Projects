#include "Forward.hpp"

void Forward::print()
{
    cout << NAME << name << ROLE << _FW << SCORE << fixed << setprecision(1) << get_average() << COST << price << GOALS << goals_num_this_week << ASSISTS << assists_num_this_week << endl;
}

void Forward::calc_points(int match_status, int goale_khorde, vector<Player *> other_team_players)
{
    win_lose_draw_points(match_status);
    if (own_goals_this_week != ZERO)
    {
        adding_ratings -= OWN_GOAL_NEGATIVE_POINTS * own_goals_this_week;
    }
    if (goals_num_this_week != ZERO)
    {
        adding_ratings += FW_GOALS_POINTS * goals_num_this_week;
    }
    else
    {
        adding_ratings -= FW_NEGATIVE_POINTS;
    }
    if (assists_num_this_week != ZERO)
    {
        adding_ratings += FW_ASSISTS_POINTS * assists_num_this_week;
    }
    calc_final_points();
}