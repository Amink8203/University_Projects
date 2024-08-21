#ifndef _GOALKEEPER_HPP
#define _GOALKEEPER_HPP
#include "Player.hpp"
#include "Constants.hpp"

class Goalkeeper : public Player
{
private:
    int clean_sheets;

public:
    Goalkeeper(string player_name, string player_post, int _price)
        : Player(player_name, player_post, _price)
    {
        clean_sheets = 0;
    };
    virtual void reset_weekly_points()
    {
        weekly_rating = 0.0;
        adding_ratings = 3;
        goals_num_this_week = 0;
        assists_num_this_week = 0;
        own_goals_this_week = 0;
        player_position_in_team = -1;
        in_squad = false;
    }
    virtual void calc_points(int match_status, int goale_khorde, vector<Player *> other_team_players);
    virtual void print();
    virtual Player *clone() { return new Goalkeeper(*this); }
};

#endif