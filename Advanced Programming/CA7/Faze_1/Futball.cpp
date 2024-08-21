#include "Futball.hpp"

pair<string, float> Futball::find_second_highest_df_rating(int week_num, string post, string name)
{
    vector<pair<string, float>> players;
    Week *week = weeks[week_num - 1];
    for (int i = 0; i < week->get_players_num(); i++)
    {
        for (int j = 0; j < teams.size(); j++)
        {
            for (int k = 0; k < teams[j]->get_team_size(); k++)
            {
                if ((teams[j]->get_player_name(k) == week->get_player_name(i)) && (teams[j]->get_player_name(k) != name) && (teams[j]->get_player_post(k) == post))
                {
                    players.push_back(week->get_player(i));
                }
            }
        }
    }
    return highest_rating(players);
}

void Futball::print_users_ranking(vector<User *> sorted_users)
{
    for (int i = 0; i < sorted_users.size(); i++)
    {
        float c = static_cast<float>(static_cast<int>(FULL * sorted_users[i]->get_points()) / FULL);
        cout << i + 1 << TEAM_NAME << sorted_users[i]->get_user_team_name()
             << POINT << fixed << setprecision(1) << c << endl;
    }
}

auto lambda_users_sort = [](User *u1, User *u2)
{
    if (u1->get_points() != u2->get_points())
    {
        return u1->get_points() > u2->get_points();
    }
    else
    {
        return u1->get_user_team_name() < u2->get_user_team_name();
    }
};

void Futball::show_users_ranking()
{
    vector<User *> sorted_users;
    if (users.size() == 0)
        throw Empty();

    for (int i = 0; i < users.size(); i++)
    {
        if (users[i]->is_complete())
            sorted_users.push_back(users[i]->clone());
    }
    if (sorted_users.size() == 0)
        throw Empty();

    sort(sorted_users.begin(), sorted_users.end(), lambda_users_sort);
    print_users_ranking(sorted_users);
}

bool Futball::user_sell_player(string player_name, int &user_number)
{
    return users[user_number]->sell_player(player_name);
}

bool Futball::user_buy_player(string player_name, int &user_number, int &current_week)
{
    for (int i = 0; i < teams.size(); i++)
    {
        for (int j = 0; j < teams[i]->get_team_size(); j++)
        {
            if (teams[i]->get_player_name(j) == player_name)
            {
                users[user_number]->buy_player(teams[i]->get_one_player(j), current_week);
                return true;
            }
        }
    }
    return false;
}

void Futball::reset_weekly_points(int &current_week)
{
    for (int i = 0; i < teams.size(); i++)
    {
        for (int j = 0; j < teams[i]->get_team_size(); j++)
        {
            teams[i]->reset_players_weekly_points(j);
        }
    }
}

void Futball::handle_buy_player(string player_name, int &user_number, bool &window_is_open, bool &user_is_logged_in, int &current_week)
{
    if (!user_is_logged_in)
    {
        throw PermissionDenied();
    }
    if (!window_is_open)
    {
        throw PermissionDenied();
    }
    if (users[user_number]->num_of_this_week_players() == COMPLETE_TEAM)
    {
        throw BadRequest();
    }
    if (!user_buy_player(player_name, user_number, current_week))
    {
        throw NotFound();
    }
    cout << OK << endl;
}

void Futball::handle_sell_player(string player_name, int &user_number, bool &window_is_open, bool &user_is_logged_in)
{
    if (!user_is_logged_in)
    {
        throw PermissionDenied();
    }
    if (!window_is_open)
    {
        throw PermissionDenied();
    }
    if (users[user_number]->num_of_this_week_players() == EMPTY_TEAM)
    {
        throw BadRequest();
    }
    if (users[user_number]->get_num_of_sells() == MAX_SELLS && users[user_number]->has_entered())
    {
        throw PermissionDenied();
    }
    if (!user_sell_player(player_name, user_number))
    {
        throw NotFound();
    }
    else if (users[user_number]->has_entered())
    {
        users[user_number]->inc_sells();
    }
    cout << OK << endl;
}

void Futball::update_fantasy_teams(int &current_week)
{
    if (users.size() == 0)
    {
        return;
    }
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i]->num_of_this_week_players() == COMPLETE_TEAM && !users[i]->has_entered())
        {
            users[i]->set_enter(current_week);
            users[i]->change_week();
            users[i]->reset_transfers();
            users[i]->calc_points();
        }
        else if (users[i]->num_of_this_week_players() != COMPLETE_TEAM && users[i]->has_entered())
        {
            users[i]->set_not_complete();
            users[i]->change_week();
            users[i]->reset_transfers();
        }
        else if (users[i]->num_of_this_week_players() == COMPLETE_TEAM && users[i]->has_entered())
        {
            users[i]->set_complete();
            users[i]->change_week();
            users[i]->reset_transfers();
            users[i]->calc_points();
        }
    }
}

void Futball::handle_get_squad(string user_team_name, bool &user_is_logged_in)
{
    if (!user_is_logged_in)
    {
        throw PermissionDenied();
    }
    bool found = false;
    User *wanted_user;
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i]->get_user_team_name() == user_team_name)
        {
            found = true;
            wanted_user = users[i];
            break;
        }
    }
    if (!found)
    {
        throw NotFound();
    }
    if (!wanted_user->is_complete() || !wanted_user->has_entered())
    {
        throw Empty();
    }
    float c = static_cast<float>(static_cast<int>(FULL * wanted_user->get_points()) / FULL);
    cout << FANTASY_TEAM << COLON << SPACE << wanted_user->get_user_team_name() << endl;
    cout << GOALKEEPER << wanted_user->get_player_post(_GK) << endl;
    cout << DEFENDER_1 << wanted_user->get_df(1) << endl;
    cout << DEFENDER_2 << wanted_user->get_df(2) << endl;
    cout << MIDIFIELDER << wanted_user->get_player_post(_MD) << endl;
    cout << STRIKER << wanted_user->get_player_post(_FW) << endl;
    cout << TOTAL_POINTS << fixed << setprecision(1) << c << endl;
}

void Futball::handle_transfer_window(bool open, bool &window_is_open, bool &admin_is_logged_in)
{
    if (!admin_is_logged_in)
    {
        throw PermissionDenied();
    }
    if (open)
    {
        window_is_open = true;
    }
    else
    {
        window_is_open = false;
    }
    cout << OK << endl;
}

void Futball::handle_logout(bool &admin_is_logged_in, bool &user_is_logged_in)
{
    if (!admin_is_logged_in && !user_is_logged_in)
    {
        throw PermissionDenied();
    }
    admin_is_logged_in = false;
    user_is_logged_in = false;
    cout << OK << endl;
}

void Futball::handle_admin_login(string username, string password, bool &admin_is_logged_in, bool &user_is_logged_in)
{
    if (admin_is_logged_in || user_is_logged_in)
    {
        throw BadRequest();
    }
    if (username != ADMIN_USERNAME || password != ADMIN_PASSWORD)
    {
        throw BadRequest();
    }
    admin_is_logged_in = true;
    cout << OK << endl;
}

void Futball::handle_login(string team_name, string password, int &user_number, bool &admin_is_logged_in, bool &user_is_logged_in)
{
    bool found = false;
    if (user_is_logged_in || admin_is_logged_in)
    {
        throw BadRequest();
    }
    for (int i = 0; i < users.size(); i++)
    {
        if (team_name == users[i]->get_user_team_name())
        {
            if (password != users[i]->get_password())
            {
                throw PermissionDenied();
            }
            found = true;
            user_is_logged_in = true;
            user_number = i;
            cout << OK << endl;
            break;
        }
    }
    if (!found)
    {
        throw NotFound();
    }
}

void Futball::handle_signup(string team_name, string password, int &user_number, bool &admin_is_logged_in, bool &user_is_logged_in)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (team_name == users[i]->get_user_team_name())
        {
            throw BadRequest();
        }
    }
    if (user_is_logged_in || admin_is_logged_in)
    {
        throw BadRequest();
    }
    users.push_back(new User(team_name, password));
    user_is_logged_in = true;
    admin_is_logged_in = false;
    user_number = users.size() - 1;
    cout << OK << endl;
}

void Futball::show_matches_result_league(int week_num, int &current_week)
{
    if (current_week == -1)
    {
        throw BadRequest();
    }
    if (week_num <= 0 || week_num > current_week + 1)
    {
        throw BadRequest();
    }
    Week *showing_week = weeks[week_num - 1];
    for (int i = 0; i < showing_week->get_weekly_matches_size(); i++)
    {
        Match *showing_match = showing_week->get_single_match(i);
        cout << showing_match->get_team_1_name() << SPACE << showing_match->get_goals_1() << BAR << showing_match->get_team_2_name() << SPACE << showing_match->get_goals_2() << endl;
    }
}

void Futball::print_league_standings(vector<Team *> sort_league_teams)
{
    cout << LEAGUE_STANDING << endl;
    for (int i = 0; i < sort_league_teams.size(); i++)
    {
        cout << i + 1 << DOT << SPACE << sort_league_teams[i]->get_name() << SCORE_TYPE_2
             << sort_league_teams[i]->get_point() << GF << sort_league_teams[i]->get_gf() << GA << sort_league_teams[i]->get_ga() << endl;
    }
}

auto lambda_league_sort = [](Team *t1, Team *t2)
{
    if (t1->get_point() != t2->get_point())
    {
        return t1->get_point() > t2->get_point();
    }
    else if (t1->get_gd() != t2->get_gd())
    {
        return t1->get_gd() > t2->get_gd();
    }
    else if (t1->get_gf() != t2->get_gf())
    {
        return t1->get_gf() > t2->get_gf();
    }
    else
    {
        return t1->get_name() < t2->get_name();
    }
};

void Futball::show_league_standings()
{
    vector<Team *> sort_league_teams;
    for (int i = 0; i < teams.size(); i++)
    {
        sort_league_teams.push_back(teams[i]->clone());
    }
    sort(sort_league_teams.begin(), sort_league_teams.end(), lambda_league_sort);
    print_league_standings(sort_league_teams);
}

auto lambda_ranked_sort = [](Player *p1, Player *p2)
{
    if (p1->get_average() != p2->get_average())
    {
        return p1->get_average() > p2->get_average();
    }
    else
    {
        return p1->get_name() < p2->get_name();
    }
};

void Futball::sort_posts(int i, string players_post, bool is_ranked)
{
    vector<Player *> post_players;
    for (int j = 0; j < teams[i]->get_team_size(); j++)
    {
        Player *temp_player = teams[i]->get_clone_player(j);
        if (temp_player->get_post() == players_post)
        {
            post_players.push_back(temp_player);
        }
    }
    if (is_ranked)
    {
        sort(post_players.begin(), post_players.end(), lambda_ranked_sort);
    }
    else
    {
        sort(post_players.begin(), post_players.end(), [](Player *p1, Player *p2)
             { return p1->get_name() < p2->get_name(); });
    }
    cout << LIST_OF_PLAYERS << endl;
    for (int k = 0; k < post_players.size(); k++)
    {
        float c = static_cast<float>(static_cast<int>(FULL * post_players[k]->get_average()) / FULL);
        cout << k + 1 << NAME << post_players[k]->get_name() << ROLE
             << post_players[k]->get_post() << SCORE_TYPE_1 << fixed << setprecision(1) << c << endl;
    }
}

void Futball::show_posts(string team_name, string players_post)
{
    bool found = false;
    for (int i = 0; i < teams.size(); i++)
    {
        if (teams[i]->get_name() == team_name)
        {
            found = true;
            sort_posts(i, players_post, false);
            break;
        }
    }
    if (!found)
    {
        throw NotFound();
    }
}

void Futball::sort_team(int i, bool is_ranked)
{
    vector<Player *> team_players = teams[i]->get_players();
    auto lambda_ranked_sort = [](Player *p1, Player *p2)
    {
        if (p1->get_average() != p2->get_average())
        {
            return p1->get_average() > p2->get_average();
        }
        else
        {
            return p1->get_name() < p2->get_name();
        }
    };
    if (is_ranked)
    {
        sort(team_players.begin(), team_players.end(), lambda_ranked_sort);
    }
    else
    {
        sort(team_players.begin(), team_players.end(), [](Player *p1, Player *p2)
             { return p1->get_name() < p2->get_name(); });
    }
    cout << LIST_OF_PLAYERS << endl;
    for (int k = 0; k < team_players.size(); k++)
    {
        float c = static_cast<float>(static_cast<int>(FULL * team_players[k]->get_average()) / FULL);
        cout << k + 1 << NAME << team_players[k]->get_name() << ROLE
             << team_players[k]->get_post() << SCORE_TYPE_1 << fixed << setprecision(1) << c << endl;
    }
}

void Futball::show_whole_team(string team_name)
{
    bool found = false;
    for (int i = 0; i < teams.size(); i++)
    {
        if (teams[i]->get_name() == team_name)
        {
            found = true;
            sort_team(i, false);
            break;
        }
    }

    if (!found)
    {
        throw NotFound();
    }
}

void Futball::show_ranked_posts(string team_name, string players_post)
{
    bool found = false;
    for (int i = 0; i < teams.size(); i++)
    {
        if (teams[i]->get_name() == team_name)
        {
            found = true;
            sort_posts(i, players_post, true);
            break;
        }
    }
    if (!found)
    {
        throw NotFound();
    }
}

void Futball::show_whole_ranked_team(string team_name)
{
    bool found = false;
    for (int i = 0; i < teams.size(); i++)
    {
        if (teams[i]->get_name() == team_name)
        {
            found = true;
            sort_team(i, true);
            break;
        }
    }

    if (!found)
    {
        throw NotFound();
    }
}

pair<string, float> Futball::find_highest_post_ratings(int week_num, string post)
{
    vector<pair<string, float>> players;
    Week *week = weeks[week_num - 1];
    for (int i = 0; i < week->get_players_num(); i++)
    {
        for (int j = 0; j < teams.size(); j++)
        {
            for (int k = 0; k < teams[j]->get_team_size(); k++)
            {
                if ((teams[j]->get_player_name(k) == week->get_player_name(i)) && (teams[j]->get_player_post(k) == post))
                {
                    players.push_back(week->get_player(i));
                }
            }
        }
    }
    return highest_rating(players);
}

void Futball::print_team_of_the_week(pair<string, float> gk, pair<string, float> df_1, pair<string, float> df_2, pair<string, float> md, pair<string, float> fw)
{
    cout << TEAM_OF_THE_WEEK << endl;
    cout << GOALKEEPER << gk.first << SCORE_TYPE_1 << gk.second << endl;
    if (df_1.first < df_2.first)
    {
        cout << DEFENDER_1 << df_1.first << SCORE_TYPE_1 << df_1.second << endl;
        cout << DEFENDER_2 << df_2.first << SCORE_TYPE_1 << df_2.second << endl;
    }
    else
    {
        cout << DEFENDER_1 << df_2.first << SCORE_TYPE_1 << df_2.second << endl;
        cout << DEFENDER_2 << df_1.first << SCORE_TYPE_1 << df_1.second << endl;
    }

    cout << MIDIFIELDER << md.first << SCORE_TYPE_1 << md.second << endl;
    cout << FORWARD << fw.first << SCORE_TYPE_1 << fw.second << endl;
}

void Futball::show_team_of_the_week(int week_num, int &current_week)
{
    if (current_week == NOT_ENTERED)
    {
        throw BadRequest();
    }
    if ((week_num > current_week + 1) || (week_num <= 0))
    {
        throw BadRequest();
    }
    pair<string, float> gk = find_highest_post_ratings(week_num, _GK);
    pair<string, float> df_1 = find_highest_post_ratings(week_num, _DF);
    pair<string, float> df_2 = find_second_highest_df_rating(week_num, _DF, df_1.first);
    pair<string, float> md = find_highest_post_ratings(week_num, _MD);
    pair<string, float> fw = find_highest_post_ratings(week_num, _FW);
    print_team_of_the_week(gk, df_1, df_2, md, fw);
}

void Futball::update_ratings(int &current_week)
{
    vector<pair<string, float>> player_ratings = weeks[current_week]->get_players();
    for (int k = 0; k < player_ratings.size(); k++)
    {
        for (int i = 0; i < teams.size(); i++)
        {
            for (int j = 0; j < teams[i]->get_team_size(); j++)
            {
                if (teams[i]->get_player_name(j) == player_ratings[k].first)
                {
                    teams[i]->update_player_rating(j, player_ratings[k].second);
                }
            }
        }
    }
}

void Futball::update_yellow_cards(int &current_week)
{
    vector<string> yellow_cards = weeks[current_week]->get_yellows();
    for (int k = 0; k < yellow_cards.size(); k++)
    {
        for (int i = 0; i < teams.size(); i++)
        {
            for (int j = 0; j < teams[i]->get_team_size(); j++)
            {
                if (teams[i]->get_player_name(j) == yellow_cards[k])
                {
                    teams[i]->inc_yellows(j);
                    teams[i]->check_player_get_yellow_cards(j, current_week);
                }
            }
        }
    }
}

void Futball::update_red_cards(int &current_week)
{
    vector<string> red_cards = weeks[current_week]->get_reds();
    for (int k = 0; k < red_cards.size(); k++)
    {
        for (int i = 0; i < teams.size(); i++)
        {
            for (int j = 0; j < teams[i]->get_team_size(); j++)
            {
                if (teams[i]->get_player_name(j) == red_cards[k])
                {
                    teams[i]->player_get_red_card(j, current_week);
                }
            }
        }
    }
}

void Futball::handle_injury(vector<string> injured_players, int &current_week)
{
    for (int k = 0; k < injured_players.size(); k++)
    {
        for (int i = 0; i < teams.size(); i++)
        {
            for (int j = 0; j < teams[i]->get_team_size(); j++)
            {
                if (teams[i]->get_player_name(j) == injured_players[k])
                {
                    teams[i]->player_injured(j, current_week);
                }
            }
        }
    }
}

void Futball::update_injuries(int &current_week)
{
    vector<string> injured_players = weeks[current_week]->get_injuries();
    handle_injury(injured_players, current_week);
}

void Futball::handle_win(string winner, string loser, int winner_goals, int loser_goals)
{
    for (int i = 0; i < teams.size(); i++)
    {
        if (teams[i]->get_name() == winner)
        {
            teams[i]->inc_gf(winner_goals);
            teams[i]->inc_ga(loser_goals);
            teams[i]->inc_points(WIN);
        }
        if (teams[i]->get_name() == loser)
        {
            teams[i]->inc_gf(loser_goals);
            teams[i]->inc_ga(winner_goals);
        }
    }
}

void Futball::handle_draw(string winner, string loser, int winner_goals, int loser_goals)
{
    for (int i = 0; i < teams.size(); i++)
    {
        if (teams[i]->get_name() == winner)
        {
            teams[i]->inc_gf(winner_goals);
            teams[i]->inc_ga(loser_goals);
            teams[i]->inc_points(DRAW);
        }
        if (teams[i]->get_name() == loser)
        {
            teams[i]->inc_gf(loser_goals);
            teams[i]->inc_ga(winner_goals);
            teams[i]->inc_points(DRAW);
        }
    }
}

void Futball::determine_result(string winner, string loser, int winner_goals, int loser_goals)
{
    if (winner_goals != loser_goals)
    {
        handle_win(winner, loser, winner_goals, loser_goals);
    }
    else
    {
        handle_draw(winner, loser, winner_goals, loser_goals);
    }
}

void Futball::update_teams(int &current_week)
{
    vector<Match *> matches = weeks[current_week]->get_matches();
    for (int i = 0; i < matches.size(); i++)
    {
        if (matches[i]->get_goals_1() >= matches[i]->get_goals_2())
        {
            determine_result(matches[i]->get_team_1_name(), matches[i]->get_team_2_name(), matches[i]->get_goals_1(), matches[i]->get_goals_2());
        }
        else
        {
            determine_result(matches[i]->get_team_2_name(), matches[i]->get_team_1_name(), matches[i]->get_goals_2(), matches[i]->get_goals_1());
        }
    }
}

void Futball::handle_pass_week(int &current_week, bool &admin_is_logged_in)
{
    if (!admin_is_logged_in)
    {
        throw PermissionDenied();
    }
    current_week++;
    reset_weekly_points(current_week);
    update_teams(current_week);
    update_injuries(current_week);
    update_red_cards(current_week);
    update_yellow_cards(current_week);
    update_ratings(current_week);
    update_fantasy_teams(current_week);
    cout << OK << endl;
}