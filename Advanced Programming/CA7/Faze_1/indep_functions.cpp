#include "indep_functions.hpp"

pair<string, float> highest_rating(vector<pair<string, float>> players)
{
    vector<pair<string, float>> temp;
    pair<string, float> max = players[0];
    for (int i = 0; i < players.size(); i++)
    {
        if (players[i].second > max.second)
        {
            max = players[i];
        }
    }
    for (int i = 0; i < players.size(); i++)
    {
        if (players[i].second == max.second)
        {
            temp.push_back(players[i]);
        }
    }
    pair<string, float> wanted_player = temp[0];
    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i].first < wanted_player.first)
        {
            wanted_player = temp[i];
        }
    }
    return wanted_player;
}

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

