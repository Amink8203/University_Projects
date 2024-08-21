#include "Player.hpp"

float Player::get_average()
{
    if (total_matches_played != ZERO)
    {
        return total_ratings / (float)total_matches_played;
    }
    else
    {
        return ZERO_FLOAT;
    }
}

void Player::set_weeks_abandoned_cards(int& current_week)
{
    weeks_abandoned.clear();
    weeks_abandoned.push_back(current_week);
}

void Player::set_weeks_abandoned_injury(int& current_week)
{
    weeks_abandoned.clear();
    weeks_abandoned.push_back(current_week);
    weeks_abandoned.push_back(current_week + 1);
    weeks_abandoned.push_back(current_week + 2);
}

bool Player::is_abandoned(int& current_week)
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
