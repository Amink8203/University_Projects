#include "indep_functions.hpp"

string sperate_player_name(vector<string> input)
{
    string player_name;
    for (int i = 4; i < input.size(); i++)
    {
        player_name += input[i];
        if (i != input.size() - 1)
            player_name += SPACE;
    }
    return player_name;
}

string replace(string line)
{
    string temp;
    for (int i = 0; i < line.size(); i++)
    {
        if (line[i] == UNDERLINE)
        {
            temp += SPACE;
        }
        else
        {
            temp += line[i];
        }
    }
    return temp;
}

void input_command(vector<string> &input, int &space_counter, string str)
{
    int j = 0;
    istringstream line(str);
    while (line >> input.at(j))
    {
        input.push_back(SPACE);
        j++;
    }
    input.pop_back();
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == CHAR_SPACE)
        {
            space_counter++;
        }
    }
}

