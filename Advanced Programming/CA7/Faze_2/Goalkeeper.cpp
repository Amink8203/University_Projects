#include "Goalkeeper.hpp"

void Goalkeeper::print()
{
    cout << NAME << name << ROLE << _GK << SCORE << fixed << setprecision(1) << get_average() << COST << price << CLEAN_SHEETS << clean_sheets << endl;
}

void Goalkeeper::calc_points(int match_status, int goale_khorde, vector<Player *> other_team_players)
{
    win_lose_draw_points(match_status);
    if (own_goals_this_week != ZERO)
    {
        adding_ratings -= OWN_GOAL_NEGATIVE_POINTS * own_goals_this_week;
    }
    if (goale_khorde == ZERO)
    {
        clean_sheets++;
        adding_ratings += GK_CLEAN_SHEET_POINTS;
    }
    else
    {
        adding_ratings -= goale_khorde;
    }
    calc_final_points();
}