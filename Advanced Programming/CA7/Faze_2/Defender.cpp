#include "Defender.hpp"

void Defender::handle_defender_conditions(vector<Player *> other_team_players)
{
    if (player_position_in_team == LB)
    {
        int decreased_points = other_team_players[RB]->get_goals_num_this_week() + other_team_players[RW]->get_goals_num_this_week();
        adding_ratings -= decreased_points;
    }
    else if (player_position_in_team == RB)
    {
        int decreased_points = other_team_players[LB]->get_goals_num_this_week() + other_team_players[LW]->get_goals_num_this_week();
        adding_ratings -= decreased_points;
    }
    else
    {
        int decreased_points = other_team_players[CF]->get_goals_num_this_week() + other_team_players[LCB]->get_goals_num_this_week() + other_team_players[RCB]->get_goals_num_this_week();
        adding_ratings -= decreased_points;
    }
}

void Defender::print()
{
    cout << NAME << name << ROLE << _DF << SCORE << fixed << setprecision(1) << get_average() << COST << price << GOALS << goals_num_this_week << ASSISTS << assists_num_this_week << CLEAN_SHEETS << clean_sheets << endl;
}

void Defender::calc_points(int match_status, int goale_khorde, vector<Player *> other_team_players)
{
    win_lose_draw_points(match_status);
    if (own_goals_this_week != ZERO)
    {
        adding_ratings -= OWN_GOAL_NEGATIVE_POINTS * own_goals_this_week;
    }
    if (goale_khorde == ZERO)
    {
        clean_sheets++;
        adding_ratings += DF_CLEAN_SHEET_POINTS;
    }
    if (goals_num_this_week != ZERO)
    {
        adding_ratings += DF_GOALS_POINTS * goals_num_this_week;
    }
    if (assists_num_this_week != ZERO)
    {
        adding_ratings += DF_ASSISTS_POINTS * assists_num_this_week;
    }
    handle_defender_conditions(other_team_players);
    calc_final_points();
}