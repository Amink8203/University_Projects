#ifndef _TEAM_HPP
#define _TEAM_HPP
#include "Player.hpp"
#include "Goalkeeper.hpp"
#include "Defender.hpp"
#include "Midifielder.hpp"
#include "Forward.hpp"
#include "Constants.hpp"

class Team
{
private:
    string name;
    int gf;
    int ga;
    int point;
    int this_week_goals_scored;
    int this_week_goals_recieved;
    vector<Player *> team_players;
    vector<Player *> other_team_players;

public:
    Team(string team_name)
    {
        name = team_name;
        gf = 0;
        ga = 0;
        this_week_goals_recieved = 0;
        this_week_goals_scored = 0;
        point = 0;
    }
    string get_name() { return name; }
    int get_gf() { return gf; }
    int get_ga() { return ga; }
    int get_gd() { return gf - ga; }
    int get_point() { return point; }
    int get_team_size() { return team_players.size(); }
    Player *get_one_player(int index) { return team_players[index]; }
    Player *get_clone_player(int index) { return team_players[index]->clone(); }
    vector<Player *> get_players() { return team_players; }
    vector<Player*> get_other_team_players() { return other_team_players; }
    string get_player_name(int index) { return team_players[index]->name; }
    string get_player_post(int index) { return team_players[index]->post; }
    pair<string, float> calculate_point_average(int index);
    void set_other_team_players(vector<Player *> other_team) { other_team_players = other_team; }
    void set_players_week(int goals_recieved, int goals_scored, vector<string> team_players_played, vector<string> players_scored_goals, vector<string> own_goals, vector<string> players_assists);
    void player_injured(int index, int &current_week) { team_players[index]->set_weeks_abandoned_injury(current_week); }
    void check_player_get_yellow_cards(int index, int &current_week);
    void player_get_red_card(int index, int &current_week);
    void inc_gf(int inc) { gf += inc; }
    void inc_ga(int inc) { ga += inc; }
    void inc_points(int inc) { point += inc; }
    void inc_yellows(int index) { team_players[index]->yellow_cards_num++; }
    void set_players(vector<Player *> players) { team_players.insert(team_players.end(), players.begin(), players.end()); }
    void reset_players_weekly_points(int index) { team_players[index]->reset_weekly_points(); }
    void calc_players_points();
    bool player_is_abandoned(int index, int &current_week) { return team_players[index]->is_abandoned(current_week); }
    Team *clone() { return new Team(*this); }
};

#endif