#include "Midifielder.hpp"

void Midifielder::print()
{
    cout << NAME << name << ROLE << _MD << SCORE << fixed << setprecision(1) << get_average() << COST << price << GOALS << goals_num_this_week << ASSISTS << assists_num_this_week << CLEAN_SHEETS << clean_sheets << endl;
}

void Midifielder::handle_midifielder_conditions(vector<Player *> other_team_players)
{
    int decreased_points = other_team_players[LCM]->get_goals_num_this_week() + other_team_players[CM]->get_goals_num_this_week() + other_team_players[RCM]->get_goals_num_this_week();
    adding_ratings -= decreased_points;
}

void Midifielder::calc_points(int match_status, int goale_khorde, vector<Player *> other_team_players)
{
    win_lose_draw_points(match_status);
    if (own_goals_this_week != ZERO)
    {
        adding_ratings -= OWN_GOAL_NEGATIVE_POINTS * own_goals_this_week;
    }
    if (goale_khorde == ZERO)
    {
        clean_sheets++;
        adding_ratings += MD_CLEAN_SHEET_POINTS;
    }
    if (goals_num_this_week != ZERO)
    {
        adding_ratings += MD_GOALS_POINTS * goals_num_this_week;
    }
    if (assists_num_this_week != ZERO)
    {
        adding_ratings += MD_ASSISTS_POINTS * assists_num_this_week;
    }
    handle_midifielder_conditions(other_team_players);
    calc_final_points();
}