#ifndef _FUTBALL_HPP
#define _FUTBALL_HPP
#include "Week.hpp"
#include "Constants.hpp"

class Futball
{
private:
    vector<Team *> teams;
    vector<Week *> weeks;
    vector<User *> users;

public:
    void set_teams(vector<Team *> team) { teams = team; }
    void set_weeks(vector<Week *> week) { weeks = week; }
    string get_user_team_name(int index) { return users[index]->get_user_team_name(); }
    void handle_pass_week(int &current_week, bool &admin_is_logged_in);
    void update_teams(int &current_week);
    void handle_win(string winner, string loser, int winner_goals, int loser_goals);
    void handle_draw(string winner, string loser, int winner_goals, int loser_goals);
    void determine_result(string winner, string loser, int winner_goals, int loser_goals);
    void update_injuries(int &current_week);
    void handle_injury(vector<string> injured_players, int &current_week);
    void update_yellow_cards(int &current_week);
    void update_red_cards(int &current_week);
    void update_ratings(int &current_week);
    void get_other_team_players(vector<string> players_played, Team *current_team, string other_team_name);
    void reset_weekly_points(int &current_week);
    void update_fantasy_teams(int &current_week);
    void show_team_of_the_week(int week_num, int &current_week);
    void show_whole_team(string team_name);
    void sort_team(int i, bool is_ranked);
    void show_posts(string team_name, string players_post);
    void sort_posts(int i, string players_post, bool is_ranked);
    void show_whole_ranked_team(string team_name);
    void show_ranked_posts(string team_name, string players_post);
    void show_league_standings();
    pair<string, float> highest_rating(vector<Player *> players);
    pair<string, float> find_highest_post_ratings(int week_num, string post);
    pair<string, float> find_second_highest_df_rating(int week_num, string post, string name);
    void print_league_standings(vector<Team *> sort_league_teams);
    void show_matches_result_league(int week_num, int &current_week);
    void handle_signup(string team_name, string password, int &user_number, bool &admin_is_logged_in, bool &user_is_logged_in);
    void handle_login(string team_name, string password, int &user_number, bool &admin_is_logged_in, bool &user_is_logged_in);
    void handle_admin_login(string username, string password, bool &admin_is_logged_in, bool &user_is_logged_in);
    void handle_logout(bool &admin_is_logged_in, bool &user_is_logged_in);
    void handle_get_squad(string user_team_name, bool &user_is_logged_in);
    void handle_sell_player(string player_name, int &user_number, bool &window_is_open, bool &user_is_logged_in);
    void handle_buy_player(string player_name, int &user_number, bool &window_is_open, bool &user_is_logged_in, int &current_week);
    void handle_set_captain(string player_name, int &user_number, bool &user_is_logged_in);
    bool user_buy_player(string player_name, int &user_number, int &current_week);
    bool user_sell_player(string player_name, int &user_number);
    void show_users_ranking();
    void show_budget(bool user_is_logged_in, int user_number);
    void print_users_ranking(vector<User *> sorted_users);
    void handle_transfer_window(bool open, bool &window_is_open, bool &admin_is_logged_in);
};

#endif