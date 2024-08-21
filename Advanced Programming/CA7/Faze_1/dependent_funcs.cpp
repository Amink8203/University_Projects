#include "dependent_funcs.hpp"

vector<string> seperate_by_delim(string line, char delim)
{
    int i = 0;
    istringstream str(line);
    vector<string> temp(1);
    while (getline(str, temp.at(i), delim))
    {
        temp.push_back(SPACE);
        i++;
    }
    temp.pop_back();
    return temp;
}

void set_players(vector<Player *> &players, vector<string> names, int post)
{
    if (post == GK)
    {
        for (int k = 0; k < names.size(); k++)
        {
            players.push_back(new Player(names[k], _GK));
        }
    }
    else if (post == DF)
    {
        for (int k = 0; k < names.size(); k++)
        {
            players.push_back(new Player(names[k], _DF));
        }
    }
    else if (post == MD)
    {
        for (int k = 0; k < names.size(); k++)
        {
            players.push_back(new Player(names[k], _MD));
        }
    }

    else if (post == FW)
    {
        for (int k = 0; k < names.size(); k++)
        {
            players.push_back(new Player(names[k], _FW));
        }
    }
}

void set_teams(vector<string> league_input, vector<Team *> &new_teams)
{
    for (int i = 0; i < league_input.size(); i++)
    {
        vector<string> elements = seperate_by_delim(league_input[i], COMMA);
        Team *new_team = new Team(elements[0]);
        for (int j = 1; j < elements.size(); j++)
        {
            vector<Player *> players;
            vector<string> names = seperate_by_delim(elements[j], SEMICOLON);
            set_players(players, names, j);
            new_team->set_players(players);
        }
        new_teams.push_back(new_team);
    }
}

void get_league_input(vector<string> &league_input)
{
    ifstream league_file(LEAGUE_FILE_NAME);
    string line;
    getline(league_file, line);
    while (getline(league_file, line))
    {
        if (!line.empty() && line.back() == '\r')
            line.pop_back();
        league_input.push_back(line);
    }
}

void get_week(int week_number, vector<string> &week_input)
{
    string week_num = to_string(week_number);
    string filename = WEEK_FILE_NAME + week_num + ".csv";
    ifstream file(filename);
    string line;
    getline(file, line);
    while (getline(file, line))
    {
        if (!line.empty() && line.back() == '\r')
            line.pop_back();
        week_input.push_back(line);
    }
}

Match *add_match(string teams, string results)
{
    vector<string> two_teams = seperate_by_delim(teams, COLON);
    vector<string> two_results = seperate_by_delim(results, COLON);
    return new Match({two_teams[0], stoi(two_results[0])}, {two_teams[1], stoi(two_results[1])});
}

void assign_weekly_points(string players, vector<pair<string, float>> &weekly_players)
{
    vector<string> elements = seperate_by_delim(players, SEMICOLON);
    for (int i = 0; i < elements.size(); i++)
    {
        vector<string> temp = seperate_by_delim(elements[i], COLON);
        weekly_players.push_back({temp[0], stof(temp[1])});
    }
}

Week *assign_week(vector<string> week_input)
{
    Week *new_week = new Week;
    vector<Match *> new_matches;
    for (int i = 0; i < week_input.size(); i++)
    {
        vector<string> elements = seperate_by_delim(week_input[i], COMMA);
        new_matches.push_back(add_match(elements[0], elements[1]));
        vector<string> injured_players = seperate_by_delim(elements[2], SEMICOLON);
        vector<string> yellow_cards = seperate_by_delim(elements[3], SEMICOLON);
        vector<string> red_cards = seperate_by_delim(elements[4], SEMICOLON);
        vector<pair<string, float>> weekly_players;
        assign_weekly_points(elements[5], weekly_players);
        new_week->add_players_points(weekly_players);
        new_week->add_injured_players(injured_players);
        new_week->add_yellow_cards(yellow_cards);
        new_week->add_red_cards(red_cards);
    }
    new_week->set_matches(new_matches);
    return new_week;
}

void set_weeks(vector<Week *> &new_weeks)
{
    for (int i = 1; i <= NUM_OF_WEEKS; i++)
    {
        vector<Match *> new_matches;
        vector<string> week_input;
        get_week(i, week_input);
        new_weeks.push_back(assign_week(week_input));
    }
}

void create_futball_fantasy(Futball &futball_fantasy)
{
    vector<string> league_input;
    vector<Team *> new_teams;
    vector<Week *> new_weeks;
    get_league_input(league_input);
    set_teams(league_input, new_teams);
    futball_fantasy.set_teams(new_teams);
    set_weeks(new_weeks);
    futball_fantasy.set_weeks(new_weeks);
}