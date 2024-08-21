#ifndef _MATCH_HPP
#define _MATCH_HPP
#include "Constants.hpp"
#include "indep_functions.hpp"

class Match
{
private:
    pair<string, int> team_1;
    pair<string, int> team_2;

public:
    Match(pair<string, int> result_1, pair<string, int> result_2) : team_1(result_1), team_2(result_2){};
    string get_team_1_name() { return team_1.first; }
    string get_team_2_name() { return team_2.first; }
    int get_goals_1() { return team_1.second; }
    int get_goals_2() { return team_2.second; }
};

#endif