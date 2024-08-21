#include "Player.hpp"

void Player::calc_final_points()
{
    weekly_rating = 10 / (1 + exp(- adding_ratings / 6.0));
    weekly_rating = static_cast<float>(static_cast<int>(weekly_rating * FULL) / FULL);
    total_ratings += weekly_rating;
}

void Player::win_lose_draw_points(int match_status)
{
    if (match_status == _WIN_GAME)
    {
        adding_ratings += PLAYER_WIN_POINTS;
    }
    else if (match_status == _LOSE_GAME)
    {
        adding_ratings -= PLAYER_LOSE_NEG_POINTS;
    }
    else
    {
        adding_ratings += PLAYER_DRAW_POINTS;
    }
}

void Player::set_players_played(vector<string> team_players_played, vector<string> players_scored_goals, vector<string> own_goals, vector<string> players_assists)
{
    for (int i = 0; i < team_players_played.size(); i++)
    {
        if (name == team_players_played[i])
        {
            total_matches_played++;
            in_squad = true;
            player_position_in_team = i;
            break;
        }
    }
    if (!in_squad)
    {
        weekly_rating = ZERO;
        return;
    }
    for (int i = 0; i < players_scored_goals.size(); i++)
    {
        if (name == players_scored_goals[i])
        {
            goals_num_this_week++;
            all_goals++;
        }
    }
    for (int i = 0; i < players_assists.size(); i++)
    {
        if (name == players_assists[i])
        {
            assists_num_this_week++;
            all_assists++;
        }
    }
    for (int i = 0; i < own_goals.size(); i++)
    {
        if (name == own_goals[i])
        {
            own_goals_this_week++;
        }
    }
}

float Player::get_average()
{
    if (total_matches_played != ZERO)
    {
        float average_points = static_cast<float>(static_cast<int>((total_ratings / (float)total_matches_played) * FULL) / FULL);
        return average_points;
    }
    else
    {
        return FLOAT_ZERO;
    }
}

void Player::set_weeks_abandoned_cards(int &current_week)
{
    weeks_abandoned.clear();
    weeks_abandoned.push_back(current_week);
}

void Player::set_weeks_abandoned_injury(int &current_week)
{
    weeks_abandoned.clear();
    weeks_abandoned.push_back(current_week);
    weeks_abandoned.push_back(current_week + ONE_WEEK_LATER);
    weeks_abandoned.push_back(current_week + TWO_WEEKS_LATER);
}

bool Player::is_abandoned(int &current_week)
{
    for (int i = 0; i < weeks_abandoned.size(); i++)
    {
        if (current_week == weeks_abandoned[i])
        {
            return true;
        }
    }
    return false;
}
