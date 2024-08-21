#include "Run.hpp"

void run(Futball &fantasy_futball)
{
    string str;
    bool window_is_open = true;
    bool admin_is_logged_in = false;
    bool user_is_logged_in = false;
    int user_number = NOT_ENTERED;
    int current_week = NOT_ENTERED;
    while (getline(cin, str))
    {
        try
        {
            vector<string> input(1);
            int space_counter = 0;
            input_command(input, space_counter, str);
            if (input.size() >= 2 && input[0] == COMMAND_TYPE_1)
            {
                if (input.size() >= 3 && input[1] == TOTW && input[2] == Q_MARK)
                {
                    if (input.size() == 5)
                    {
                        if (input[3] == WEEK_NUM && space_counter == 4)
                        {
                            fantasy_futball.show_team_of_the_week(stoi(input[4]), current_week);
                        }
                        else
                        {
                            throw BadRequest();
                        }
                    }
                    else if (space_counter == 2)
                    {
                        fantasy_futball.show_team_of_the_week(current_week + 1, current_week);
                    }
                    else
                    {
                        throw BadRequest();
                    }
                }
                else if (input.size() >= 4 && input[1] == PLAYERS && input[2] == Q_MARK && input[3] == TEAM_NAME_TYPE_2)
                {
                    if (input.size() == 5 && space_counter == 4)
                    {
                        fantasy_futball.show_whole_team(replace(input[4]));
                    }
                    else if (input.size() == 6 && space_counter == 5)
                    {
                        if (input[5] == _GK || input[5] == _DF || input[5] == _MD || input[5] == _FW)
                        {
                            fantasy_futball.show_posts(replace(input[4]), input[5]);
                        }

                        else if (input[5] == RANKS)
                        {
                            fantasy_futball.show_whole_ranked_team(replace(input[4]));
                        }
                        else
                        {
                            throw BadRequest();
                        }
                    }
                    else if (input.size() == 7 && space_counter == 6)
                    {
                        if ((input[5] == _GK || input[5] == _DF || input[5] == _MD || input[5] == _FW) && (input[6] == RANKS))
                        {
                            fantasy_futball.show_ranked_posts(replace(input[4]), input[5]);
                        }
                        else
                        {
                            throw BadRequest();
                        }
                    }
                    else
                    {
                        throw BadRequest();
                    }
                }
                else if (input[1] == LEAGUE_STANDINGS && space_counter == 1)
                {
                    fantasy_futball.show_league_standings();
                }
                else if (input.size() >= 3 && input[1] == MATCHES_RESULT_LEAGUE && input[2] == Q_MARK)
                {
                    if (input.size() == 3 && space_counter == 2)
                    {
                        fantasy_futball.show_matches_result_league(current_week + 1, current_week);
                    }
                    else if (input.size() == 5 && input[3] == WEEK_NUM && space_counter == 4)
                    {
                        fantasy_futball.show_matches_result_league(stoi(input[4]), current_week);
                    }
                    else
                    {
                        throw BadRequest();
                    }
                }
                else if ( input[1] == SQUAD && input[2] == Q_MARK)
                {
                    if (input.size() == 3 && space_counter == 2)
                    {
                        if (!user_is_logged_in)
                        {
                            throw PermissionDenied();
                        }
                        fantasy_futball.handle_get_squad(fantasy_futball.get_user_team_name(user_number), user_is_logged_in);
                    }
                    else if (input.size() == 5 && input[1] == SQUAD && input[2] == Q_MARK && input[3] == FANTASY_TEAM_TYPE_2 && space_counter == 4)
                    {
                        if (!user_is_logged_in)
                        {
                            throw PermissionDenied();
                        }
                        fantasy_futball.handle_get_squad(input[4], user_is_logged_in);
                    }
                    else
                    {
                        throw BadRequest();
                    }
                }
                else if (input[1] == USERS_RANKING && space_counter == 1)
                {
                    fantasy_futball.show_users_ranking();
                }
                else if (input[1] == SHOW_BUDGET && space_counter == 1)
                {
                    fantasy_futball.show_budget(user_is_logged_in, user_number);
                }
                else
                {
                    throw NotFound();
                }
            }
            else if (input.size() >= 2 && input[0] == COMMAND_TYPE_2)
            {
                if (input.size() == 7 && input[1] == SIGNUP && input[2] == Q_MARK && input[3] == TEAM_NAME_TYPE_2 && input[5] == PASSWORD && space_counter == 6)
                {
                    fantasy_futball.handle_signup(input[4], input[6], user_number, admin_is_logged_in, user_is_logged_in);
                }
                else if (input.size() == 7 && input[1] == LOGIN && input[2] == Q_MARK && input[3] == TEAM_NAME_TYPE_2 && input[5] == PASSWORD && space_counter == 6)
                {
                    fantasy_futball.handle_login(input[4], input[6], user_number, admin_is_logged_in, user_is_logged_in);
                }
                else if (input.size() == 7 && input[1] == REGISTER_ADMIN && input[2] == Q_MARK && input[3] == USERNAME && input[5] == PASSWORD && space_counter == 6)
                {
                    fantasy_futball.handle_admin_login(input[4], input[6], admin_is_logged_in, user_is_logged_in);
                }
                else if (input.size() == 2 && input[1] == LOGOUT && space_counter == 1)
                {
                    fantasy_futball.handle_logout(admin_is_logged_in, user_is_logged_in);
                }
                else if (input.size() == 2 && input[1] == OPEN_TRANSFER_WINDOW && space_counter == 1)
                {
                    fantasy_futball.handle_transfer_window(true, window_is_open, admin_is_logged_in);
                }
                else if (input.size() == 2 && input[1] == CLOSE_TRANSFER_WINDOW && space_counter == 1)
                {
                    fantasy_futball.handle_transfer_window(false, window_is_open, admin_is_logged_in);
                }
                else if (input.size() == 2 && input[1] == PASS_WEEK && space_counter == 1)
                {
                    if (!admin_is_logged_in)
                    {
                        throw PermissionDenied();
                    }
                    fantasy_futball.handle_pass_week(current_week, admin_is_logged_in);
                }
                else if (input.size() >= 5 && input[1] == SELL_PLAYER && input[2] == Q_MARK && input[3] == PLAYER_NAME && space_counter >= 4)
                {
                    string player_name = sperate_player_name(input);
                    fantasy_futball.handle_sell_player(player_name, user_number, window_is_open, user_is_logged_in);
                }
                else if (input.size() >= 5 && input[1] == BUY_PLAYER && input[2] == Q_MARK && input[3] == PLAYER_NAME && space_counter >= 4)
                {
                    string player_name = sperate_player_name(input);
                    fantasy_futball.handle_buy_player(player_name, user_number, window_is_open, user_is_logged_in, current_week);
                }
                else if (input.size() >= 5 && input[1] == SET_CAPTAIN && input[2] == Q_MARK && input[3] == PLAYER_NAME && space_counter >= 4)
                {
                    string player_name = sperate_player_name(input);
                    fantasy_futball.handle_set_captain(player_name, user_number, user_is_logged_in);
                }
                else
                {
                    throw NotFound();
                }
            }
            else
            {
                throw BadRequest();
            }
        }
        catch (BadRequest &ex)
        {
            ex.error();
            continue;
        }
        catch (PermissionDenied &ex)
        {
            ex.error();
            continue;
        }
        catch (NotFound &ex)
        {
            ex.error();
            continue;
        }
        catch (Empty &ex)
        {
            ex.error();
            continue;
        }
        catch (NotAvailable &ex)
        {
            ex.error();
            continue;
        }
    }
}