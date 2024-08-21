#include "Team.hpp"

void Team::calc_players_points()
{
    int match_status;
    if (this_week_goals_scored > this_week_goals_recieved)
    {
        match_status = _WIN_GAME;
    }
    else if (this_week_goals_scored < this_week_goals_recieved)
    {
        match_status = _LOSE_GAME;
    }
    else
    {
        match_status = _DRAW_GAME;
    }
    vector<Player *> in_squad_players;
    for (int i = 0, j = 0; i < team_players.size(); i++)
    {
        if (team_players[i]->is_in_squad())
        {
            team_players[i]->calc_points(match_status, this_week_goals_recieved, other_team_players);
        }
    }
}

void Team::set_players_week(int goals_recieved, int goals_scored, vector<string> team_players_played, vector<string> players_scored_goals, vector<string> own_goals, vector<string> players_assists)
{
    other_team_players.clear();
    this_week_goals_recieved = goals_recieved;
    this_week_goals_scored = goals_scored;
    for (int i = 0; i < team_players.size(); i++)
    {
        team_players[i]->set_players_played(team_players_played, players_scored_goals, own_goals, players_assists);
    }
}

void Team::player_get_red_card(int index, int &current_week)
{
    team_players[index]->set_weeks_abandoned_cards(current_week);
    team_players[index]->yellow_cards_num = ZERO;
}

pair<string, float> Team::calculate_point_average(int index)
{
    float average = team_players[index]->total_ratings / team_players[index]->total_matches_played;
    string player_name = team_players[index]->name;
    return {player_name, average};
}

void Team::check_player_get_yellow_cards(int index, int &current_week)
{
    if (team_players[index]->yellow_cards_num == MAX_YELLOW_CARDS_NUM)
    {
        team_players[index]->set_weeks_abandoned_cards(current_week);
        team_players[index]->yellow_cards_num = ZERO;
    }
}