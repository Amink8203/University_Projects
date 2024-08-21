#ifndef _FORWARD_HPP
#define _FORWARD_HPP
#include "Player.hpp"
#include "Constants.hpp"

class Forward : public Player
{
private:
public:
    Forward(string player_name, string player_post, int _price)
        : Player(player_name, player_post, _price){};
    virtual void reset_weekly_points()
    {
        weekly_rating = 0;
        adding_ratings = 0;
        goals_num_this_week = 0;
        assists_num_this_week = 0;
        own_goals_this_week = 0;
        player_position_in_team = -1;
        in_squad = false;
    }
    virtual void calc_points(int match_status, int goale_khorde, vector<Player *> other_team_players);
    virtual void print();
    virtual Player *clone() { return new Forward(*this); }
};

#endif