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
        set_goalkeepers(players , names , post);
    }
    else if (post == DF)
    {
        set_defenders(players , names , post);
    }
    else if (post == MD)
    {
        set_midfielders(players , names , post);
    }

    else if (post == FW)
    {
        set_forwards(players , names , post);
    }
}

void set_goalkeepers(vector<Player *> &players, vector<string> names, int post)
{
    for (int k = 0; k < names.size(); k++)
    {
        vector<string> name_price = seperate_by_delim(names[k], COLON);
        string name = name_price[0];
        name_price[1].pop_back();
        int price = stoi(name_price[1]);
        players.push_back(new Goalkeeper(name, _GK, price));
    }
}

void set_defenders(vector<Player *> &players, vector<string> names, int post)
{
    for (int k = 0; k < names.size(); k++)
    {
        vector<string> name_price = seperate_by_delim(names[k], COLON);
        string name = name_price[0];
        name_price[1].pop_back();
        int price = stoi(name_price[1]);
        players.push_back(new Defender(name, _DF, price));
    }
}

void set_midfielders(vector<Player *> &players, vector<string> names, int post)
{
    for (int k = 0; k < names.size(); k++)
    {
        vector<string> name_price = seperate_by_delim(names[k], COLON);
        string name = name_price[0];
        name_price[1].pop_back();
        int price = stoi(name_price[1]);
        players.push_back(new Midifielder(name, _MD, price));
    }
}

void set_forwards(vector<Player *> &players, vector<string> names, int post)
{
    for (int k = 0; k < names.size(); k++)
    {
        vector<string> name_price = seperate_by_delim(names[k], COLON);
        string name = name_price[0];
        name_price[1].pop_back();
        int price = stoi(name_price[1]);
        players.push_back(new Forward(name, _FW, price));
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

Match *add_match(string teams, string results, string goals_with_assists, string team_1, string team_2)
{
    vector<string> two_teams = seperate_by_delim(teams, COLON);
    vector<string> two_results = seperate_by_delim(results, COLON);
    vector<string> team_1_players = seperate_by_delim(team_1, SEMICOLON);
    vector<string> team_2_players = seperate_by_delim(team_2, SEMICOLON);
    vector<string> players_scored_goals;
    vector<string> own_goals;
    vector<string> players_assists;
    vector<string> temp_goals_and_assists = seperate_by_delim(goals_with_assists, SEMICOLON);
    for (int i = 0; i < temp_goals_and_assists.size(); i++)
    {
        vector<string> temp = seperate_by_delim(temp_goals_and_assists[i], COLON);
        if (temp[1] == OWN_GOAL)
        {
            own_goals.push_back(temp[0]);
        }
        else
        {
            players_scored_goals.push_back(temp[0]);
            players_assists.push_back(temp[1]);
        }
    }
    return new Match({two_teams[0], stoi(two_results[0])}, {two_teams[1], stoi(two_results[1])}, team_1_players, team_2_players, players_scored_goals, own_goals, players_assists);
}

Week *assign_week(vector<string> week_input)
{
    Week *new_week = new Week;
    vector<Match *> new_matches;
    for (int i = 0; i < week_input.size(); i++)
    {
        vector<string> elements = seperate_by_delim(week_input[i], COMMA);
        new_matches.push_back(add_match(elements[0], elements[1], elements[5], elements[6], elements[7]));
        vector<string> injured_players = seperate_by_delim(elements[2], SEMICOLON);
        vector<string> yellow_cards = seperate_by_delim(elements[3], SEMICOLON);
        vector<string> red_cards = seperate_by_delim(elements[4], SEMICOLON);
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