#ifndef _USER_HPP
#define _USER_HPP
#include "Team.hpp"
#include "Constants.hpp"


class User
{
private:
    string user_team_name;
    string password;
    vector<Player *> this_week_fantasy_players;
    vector<Player *> last_week_fantasy_players;
    string captain;
    float captain_point;
    float points;
    int week_entered;
    bool team_is_complete;
    bool team_has_entered;
    int num_of_sells;
    int budget;

public:
    User(string username, string _pass) : user_team_name(username), password(_pass)
    {
        week_entered = -1;
        team_is_complete = false;
        team_has_entered = false;
        num_of_sells = 0;
        points = 0.0;
        captain_point = -1.0;
        captain = NO_CAPTAIN;
        budget = INIT_BUDGET;
    }
    string get_user_team_name() { return user_team_name; }
    string get_password() { return password; }
    void print_df(int df_num);
    void print_player(string post);
    string get_captain_name() { return captain; }
    void change_week() { last_week_fantasy_players = this_week_fantasy_players; }
    bool is_complete() { return team_is_complete; }
    bool has_entered() { return team_has_entered; }
    void set_enter(int &current_week)
    {
        team_has_entered = true;
        team_is_complete = true;
        week_entered = current_week;
    }
    void set_complete() { team_is_complete = true; }
    void set_not_complete() { team_is_complete = false; }
    void calc_points();
    void calc_captain_points(int index);
    void reset_transfers()
    {
        num_of_sells = 0;
    }
    int num_of_last_week_players() { return last_week_fantasy_players.size(); }
    int num_of_this_week_players() { return this_week_fantasy_players.size(); }
    float get_points();
    int get_week_entered() { return week_entered; }
    int get_num_of_sells() { return num_of_sells; }
    int get_num_of_dfs();
    bool post_is_available(string player_post);
    bool sell_player(Player *player_name);
    void buy_player(Player *new_player, int &current_week);
    void inc_sells() { num_of_sells++; }
    void set_captain(string player_name);
    void print_budget() { cout << budget << endl; }
    int get_budget() { return budget; }
    int get_team_cost();
    User *clone() { return new User(*this); }
};


#endif