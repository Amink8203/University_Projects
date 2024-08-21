#ifndef _PLAYER_HPP
#define _PLAYER_HPP
#include "Match.hpp"
#include "Constants.hpp"

class Player
{
protected:
    string name;
    string post;
    int total_matches_played;
    float total_ratings;
    float weekly_rating;
    bool in_squad;      
    int adding_ratings; 
    int yellow_cards_num;
    int goals_num_this_week;
    int assists_num_this_week;
    int own_goals_this_week;
    int all_goals;
    int all_assists;
    int price;
    int player_position_in_team; 
    vector<int> weeks_abandoned;

public:
    friend class Team;
    Player(string player_name, string player_post, int _price)
    {
        name = player_name;
        post = player_post;
        total_ratings = 0.0;
        weekly_rating = 0.0;
        total_matches_played = 0;
        yellow_cards_num = 0;
        adding_ratings = 0;
        goals_num_this_week = 0;
        assists_num_this_week = 0;
        all_assists = 0;
        all_goals = 0;
        own_goals_this_week = 0;
        player_position_in_team = -1; 
        price = _price;
        in_squad = false;
    }
    void set_name(string player_name) { name = player_name; }
    void set_post(string player_post) { post = player_post; }
    string get_post() { return post; }
    string get_name() { return name; }
    float get_weekly_point() { return weekly_rating; }
    int get_goals_num_this_week() { return goals_num_this_week; }
    void set_weeks_abandoned_cards(int &current_week);
    void set_weeks_abandoned_injury(int &current_week);
    bool is_abandoned(int &current_week);
    bool is_in_squad() { return in_squad; }
    float get_average();
    int get_price() { return price; }
    int get_adding_ratings() { return adding_ratings; }
    void calc_final_points();
    void set_players_played(vector<string> team_players_played, vector<string> players_scored_goals, vector<string> own_goals, vector<string> players_assists);
    void win_lose_draw_points(int match_status);
    virtual void reset_weekly_points() = 0;
    virtual void calc_points(int match_status, int goale_khorde, vector<Player *> other_team_players) = 0;
    virtual void print() = 0;
    virtual Player *clone() = 0;
};

#endif