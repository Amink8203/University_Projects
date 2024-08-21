#include "User.hpp"

bool User::post_is_available(string player_post)
{
    for (int i = 0; i < this_week_fantasy_players.size(); i++)
    {
        if (this_week_fantasy_players[i]->get_post() == player_post)
        {
            return true;
        }
    }
    return false;
}

int User::get_num_of_dfs()
{
    int number = 0;
    for (int i = 0; i < this_week_fantasy_players.size(); i++)
    {
        if (this_week_fantasy_players[i]->get_post() == _DF)
        {
            number++;
        }
    }
    return number;
}

void User::buy_player(Player *new_player,int& current_week)
{
    if (post_is_available(new_player->get_post()))
    {
        if (new_player->get_post() == _DF)
        {
            if (get_num_of_dfs() == 2)
            {
                throw BadRequest();
            }
        }
        else
        {
            throw BadRequest();
        }
    }
    if (new_player->is_abandoned(current_week))
    {
        throw NotAvailable();
    }
    this_week_fantasy_players.push_back(new_player);
}

bool User::sell_player(string player_name)
{
    bool found = false;
    for (int i = 0; i < this_week_fantasy_players.size(); i++)
    {
        if (this_week_fantasy_players[i]->get_name() == player_name)
        {
            found = true;
            this_week_fantasy_players.erase(this_week_fantasy_players.begin() + i);
            break;
        }
    }
    if (!found)
    {
        return false;
    }
    return true;
}

void User::calc_points()
{
    for (int i = 0; i < last_week_fantasy_players.size(); i++)
    {
        points += last_week_fantasy_players[i]->get_weekly_point();
    }
}

string User::get_player_post(string post)
{
    for (int i = 0; i < last_week_fantasy_players.size(); i++)
    {
        if (last_week_fantasy_players[i]->get_post() == post)
        {
            return last_week_fantasy_players[i]->get_name();
        }
    }
    return NONE;
}

string User::get_df(int df_num)
{
    vector<Player *> dfs;
    for (int i = 0; i < last_week_fantasy_players.size(); i++)
    {
        if (last_week_fantasy_players[i]->get_post() == _DF)
        {
            dfs.push_back(last_week_fantasy_players[i]);
        }
    }
    if (df_num == 1)
    {
        if (dfs[0]->get_name() < dfs[1]->get_name())
        {
            return dfs[0]->get_name();
        }
        else
        {
            return dfs[1]->get_name();
        }
    }
    else
    {
        if (dfs[0]->get_name() < dfs[1]->get_name())
        {
            return dfs[1]->get_name();
        }
        else
        {
            return dfs[0]->get_name();
        }
    }
    return NONE;
}