#ifndef _DEFENDER_HPP
#define _DEFENDER_HPP
#include "Player.hpp"
#include "Constants.hpp"

class Defender : public Player
{
private:
    int clean_sheets;

public:
    Defender(string player_name, string player_post, int _price)
        : Player(player_name, player_post, _price)
    {
        clean_sheets = 0;
    };
    virtual void reset_weekly_points()
    {
        weekly_rating = 0.0;
        adding_ratings = 1;
        goals_num_this_week = 0;
        assists_num_this_week = 0;
        own_goals_this_week = 0;
        player_position_in_team = -1;
        in_squad = false;
    }
    void handle_defender_conditions(vector<Player *> other_team_players);
    virtual void calc_points(int match_status, int goale_khorde, vector<Player *> other_team_players);
    virtual void print();
    virtual Player *clone() { return new Defender(*this); }
};

#endif