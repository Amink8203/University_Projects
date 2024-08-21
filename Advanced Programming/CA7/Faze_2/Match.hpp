#ifndef _MATCH_HPP
#define _MATCH_HPP
#include "Constants.hpp"
#include "indep_functions.hpp"

class Match
{
private:
    pair<string, int> team_1;
    pair<string, int> team_2;
    vector<string> team_1_players;
    vector<string> team_2_players;
    vector<string> players_scored_goals;
    vector<string> own_goals;
    vector<string> players_assists;

public:
    Match(pair<string, int> result_1, pair<string, int> result_2, vector<string> _team_1, vector<string> _team_2, vector<string> goals, vector<string> _own_goals, vector<string> _players_assists)
        : team_1(result_1), team_2(result_2), team_1_players(_team_1), team_2_players(_team_2), players_scored_goals(goals), own_goals(_own_goals), players_assists(_players_assists){};
    string get_team_1_name() { return team_1.first; }
    string get_team_2_name() { return team_2.first; }
    int get_goals_1() { return team_1.second; }
    int get_goals_2() { return team_2.second; }
    vector<string> get_team_1_players() { return team_1_players; }
    vector<string> get_team_2_players() { return team_2_players; }
    vector<string> get_players_scored_goals() { return players_scored_goals; }
    vector<string> get_own_goals() { return own_goals; }
    vector<string> get_players_assists() { return players_assists; }
};

#endif