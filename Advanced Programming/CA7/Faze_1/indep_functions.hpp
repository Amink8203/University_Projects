#ifndef _INDEP_FUNCTIONS_HPP
#define _INDEP_FUNCTIONS_HPP
#include "Constants.hpp"

pair<string, float> highest_rating(vector<pair<string, float>> players);
string sperate_player_name(vector<string> input);
string replace(string line);
void input_command(vector<string> &input, int &space_counter, string str);


#endif