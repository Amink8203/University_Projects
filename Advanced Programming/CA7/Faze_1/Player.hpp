#ifndef _PLAYER_HPP
#define _PLAYER_HPP
#include "Match.hpp"
#include "Constants.hpp"

class Player
{
private:
    string name;
    string post;
    float average;
    int total_matches_played;
    float total_ratings;
    float weekly_rating;
    int yellow_cards_num;
    vector<int> weeks_abandoned;

public:
    friend class Team;
    Player(string player_name, string player_post)
    {
        name = player_name;
        post = player_post;
        total_ratings = 0.0;
        weekly_rating = 0.0;
        total_matches_played = 0;
        yellow_cards_num = 0;
        average = 0.0;
    }
    void set_name(string player_name) { name = player_name; }
    void set_post(string player_post) { post = player_post; }
    string get_post() { return post; }
    string get_name() { return name; }
    float get_weekly_point() { return weekly_rating; }
    void set_weeks_abandoned_cards(int& current_week);
    void set_weeks_abandoned_injury(int& current_week);
    bool is_abandoned(int& current_week);
    float get_average();
    Player *clone() { return new Player(*this); }
};

#endif