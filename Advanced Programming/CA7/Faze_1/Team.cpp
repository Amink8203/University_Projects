#include "Team.hpp"

void Team::player_get_red_card(int index, int& current_week)
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

void Team::update_player_rating(int index, float inc_points)
{
    team_players[index]->total_ratings += inc_points;
    team_players[index]->total_matches_played++;
    team_players[index]->weekly_rating += inc_points;
}

void Team::check_player_get_yellow_cards(int index, int& current_week)
{
    if (team_players[index]->yellow_cards_num == MAX_YELLOW_CARDS)
    {
        team_players[index]->set_weeks_abandoned_cards(current_week);
        team_players[index]->yellow_cards_num = ZERO;
    }
}