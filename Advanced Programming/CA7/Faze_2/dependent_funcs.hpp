#ifndef _DEPENDENT_FUNCS_HPP
#define _DEPENDENT_FUNCS_HPP
#include "Futball.hpp"
#include "Constants.hpp"

vector<string> seperate_by_delim(string line, char delim);
void set_players(vector<Player *> &players, vector<string> names, int post);
void set_goalkeepers(vector<Player *> &players, vector<string> names, int post);
void set_defenders(vector<Player *> &players, vector<string> names, int post);
void set_midfielders(vector<Player *> &players, vector<string> names, int post);
void set_forwards(vector<Player *> &players, vector<string> names, int post);
void set_teams(vector<string> league_input, vector<Team *> &new_teams);
void get_league_input(vector<string> &league_input);
void get_week(int week_number, vector<string> &week_input);
Match *add_match(string teams, string results, string goals_with_assists, string team_1, string team_2);
Week *assign_week(vector<string> week_input);
void set_weeks(vector<Week *> &new_weeks);
void create_futball_fantasy(Futball &futball_fantasy);

#endif