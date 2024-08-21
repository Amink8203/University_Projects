#ifndef _WEEK_HPP
#define _WEEK_HPP
#include "User.hpp"
#include "Constants.hpp"

class Week
{
private:
    vector<Match *> weekly_matches;
    vector<pair<string, float>> weekly_players;
    vector<string> injured_players;
    vector<string> yellow_cards;
    vector<string> red_cards;

public:
    void set_matches(vector<Match *> matches) { weekly_matches = matches; }
    void add_players_points(vector<pair<string, float>> players) { weekly_players.insert(weekly_players.end(), players.begin(), players.end()); }
    void add_injured_players(vector<string> injured) { injured_players.insert(injured_players.end(), injured.begin(), injured.end()); }
    void add_yellow_cards(vector<string> y_card) { yellow_cards.insert(yellow_cards.end(), y_card.begin(), y_card.end()); }
    void add_red_cards(vector<string> r_card) { red_cards.insert(red_cards.end(), r_card.begin(), r_card.end()); }
    int get_players_num() { return weekly_players.size(); }
    int get_weekly_matches_size() { return weekly_matches.size(); }
    Match *get_single_match(int index) { return weekly_matches[index]; }
    pair<string, float> get_player(int index) { return weekly_players[index]; }
    string get_player_name(int index) { return weekly_players[index].first; }
    vector<Match *> get_matches() { return weekly_matches; }
    vector<pair<string, float>> get_players() { return weekly_players; }
    vector<string> get_injuries() { return injured_players; }
    vector<string> get_yellows() { return yellow_cards; }
    vector<string> get_reds() { return red_cards; }
};

#endif