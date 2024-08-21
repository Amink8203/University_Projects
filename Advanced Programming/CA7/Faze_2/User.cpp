#include "User.hpp"

void User::calc_captain_points(int index)
{
    int adding_ratings = last_week_fantasy_players[index]->get_adding_ratings();
    captain_point = 10 / (1 + exp(adding_ratings / 6.0));
    captain_point = static_cast<float>(static_cast<int>(captain_point * FULL) / FULL);
    points += captain_point;
}

float User::get_points()
{
    points = static_cast<float>(static_cast<int>(points * FULL) / FULL);
    return points;
}

int User::get_team_cost()
{
    int cost = 0;
    for (int i = 0; i < last_week_fantasy_players.size(); i++)
    {
        cost += last_week_fantasy_players[i]->get_price();
    }
    return cost;
}

void User::set_captain(string player_name)
{
    bool found = false;
    for (int i = 0; i < this_week_fantasy_players.size(); i++)
    {
        if (this_week_fantasy_players[i]->get_name() == player_name)
        {
            found = true;
            captain = this_week_fantasy_players[i]->get_name();
            captain_point = 0;
        }
    }
    if (!found)
    {
        throw NotFound();
    }
}

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

void User::buy_player(Player *new_player, int &current_week)
{
    if (post_is_available(new_player->get_post()))
    {
        if (new_player->get_post() == _DF)
        {
            if (get_num_of_dfs() == MAX_DF_NUM)
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
    if (new_player->get_price() > budget)
    {
        throw BadRequest();
    }
    this_week_fantasy_players.push_back(new_player);
    budget = budget - new_player->get_price();
}

bool User::sell_player(Player *player_name)
{
    bool found = false;
    for (int i = 0; i < this_week_fantasy_players.size(); i++)
    {
        if (this_week_fantasy_players[i]->get_name() == player_name->get_name())
        {
            found = true;
            if (player_name->get_name() == captain)
            {
                captain = NO_CAPTAIN;
                captain_point = ZERO;
            }
            this_week_fantasy_players.erase(this_week_fantasy_players.begin() + i);
            budget = budget + player_name->get_price();
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
        if (last_week_fantasy_players[i]->get_name() != captain)
        {
            points += last_week_fantasy_players[i]->get_weekly_point();
        }
        else
        {
            calc_captain_points(i);
        }
    }
}

void User::print_player(string post)
{
    for (int i = 0; i < last_week_fantasy_players.size(); i++)
    {
        if (last_week_fantasy_players[i]->get_post() == post)
        {
            if (last_week_fantasy_players[i]->get_name() == captain)
            {
                cout << last_week_fantasy_players[i]->get_name() << CAPTAIN << endl;
            }
            else
            {
                cout << last_week_fantasy_players[i]->get_name() << endl;
            }
        }
    }
}

void User::print_df(int df_num)
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
            if (dfs[0]->get_name() == captain)
                cout << dfs[0]->get_name() << CAPTAIN << endl;
            else
                cout << dfs[0]->get_name() << endl;
        }
        else
        {
            if (dfs[1]->get_name() == captain)
                cout << dfs[1]->get_name() << CAPTAIN << endl;
            else
                cout << dfs[1]->get_name() << endl;
        }
    }
    else
    {
        if (dfs[0]->get_name() < dfs[1]->get_name())
        {
            if (dfs[1]->get_name() == captain)
                cout << dfs[1]->get_name() << CAPTAIN << endl;
            else
                cout << dfs[1]->get_name() << endl;
        }
        else
        {
            if (dfs[0]->get_name() == captain)
                cout << dfs[0]->get_name() << CAPTAIN << endl;
            else
                cout << dfs[0]->get_name() << endl;
        }
    }
}