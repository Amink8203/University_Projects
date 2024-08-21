#ifndef _CONSTANTS_HPP
#define _CONSTANTS_HPP
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;


const int NUM_OF_WEEKS = 19;
const int ONE_WEEK_LATER = 1;
const int TWO_WEEKS_LATER = 2;
const int WIN = 3;
const int DRAW = 1;
const int INJURED = 3;
const int MAX_SELLS = 2;
const int MAX_YELLOW_CARDS_NUM = 3;
const int MAX_DF_NUM = 2;
const int COMPLETE_TEAM = 5;
const int EMPTY_TEAM = 0;
const int INIT_BUDGET = 2500;
const int PLAYER_WIN_POINTS = 5;
const int PLAYER_LOSE_NEG_POINTS = 1;
const int PLAYER_DRAW_POINTS = 1;
const int ZERO = 0 ;
const int OWN_GOAL_NEGATIVE_POINTS = 3;
const int MD_CLEAN_SHEET_POINTS = 1;
const int DF_CLEAN_SHEET_POINTS = 2;
const int GK_CLEAN_SHEET_POINTS = 5;
const int DF_GOALS_POINTS = 4;
const int MD_GOALS_POINTS = 3;
const int FW_GOALS_POINTS = 3;
const int DF_ASSISTS_POINTS = 3;
const int MD_ASSISTS_POINTS = 2;
const int FW_ASSISTS_POINTS = 1;
const int FW_NEGATIVE_POINTS = 1;
const int NOT_ENTERED = -1;
const float FULL = 10.0 ;
const float FLOAT_ZERO = 0.0 ;
const string LEAGUE_FILE_NAME = "data/premier_league.csv" ;
const string WEEK_FILE_NAME = "data/weeks_stats/week_" ;
const string BAD_REQ_WARNING = "Bad Request" ;
const string PERMISSION_DENIED_WARNING = "Permission Denied" ;
const string NOT_FOUND_WARNING = "Not Found" ;
const string EMPTY_WARNING = "Empty" ;
const string AVAILABILITY_WARNING = "This player is not available for next week" ;
const string ADMIN_USERNAME = "admin";
const string ADMIN_PASSWORD = "123456";
const string _GK = "gk";
const string _DF = "df";
const string _MD = "md";
const string _FW = "fw";
const string OK = "OK";
const string COMMAND_TYPE_1 = "GET" ;
const string COMMAND_TYPE_2 = "POST" ;
const string GF = " | GF: " ; 
const string GA = " | GA: " ;
const string OWN_GOAL = "OWN_GOAL" ;
const string FANTASY_TEAM = "fantasy_team: ";
const string GOALKEEPER = "Goalkeeper: ";
const string DEFENDER_1 = "Defender1: ";
const string DEFENDER_2 = "Defender2: ";
const string MIDIFIELDER = "Midfielder: ";
const string STRIKER = "Striker: ";
const string TOTAL_POINTS = "Total Points: ";
const string FORWARD = "Forward: ";
const string NO_CAPTAIN = "NONE";
const string TEAM_COST = "Team Cost: ";
const string CAPTAIN = " (CAPTAIN)";
const string OPEN_TRANSFER_WINDOW = "open_transfer_window" ;
const string CLOSE_TRANSFER_WINDOW = "close_transfer_window" ;
const string PASS_WEEK = "pass_week" ;
const string PLAYERS = "players";
const string SELL_PLAYER = "sell_player" ;
const string BUY_PLAYER = "buy_player" ;
const string SET_CAPTAIN = "set_captain" ;
const string LIST_OF_PLAYERS = "list of players" ;
const string LEAGUE_STANDING = "league standing" ;
const string TEAM_OF_THE_WEEK = "team of the week" ;
const string TOTW = "team_of_the_week";
const string WEEK_NUM = "week_num" ;
const string SQUAD = "squad" ;
const string FANTASY_TEAM_TYPE_2 = "fantasy_team" ;
const string USERS_RANKING = "users_ranking" ;
const string SHOW_BUDGET = "show_budget" ;
const string POINT = " | point: " ;
const string SIGNUP = "signup" ;
const string LOGIN = "login" ;
const string PASSWORD = "password";
const string USERNAME = "username" ;
const string REGISTER_ADMIN = "register_admin" ;
const string LOGOUT = "logout" ;
const string TEAM_NAME = ". team_name: " ;
const string TEAM_NAME_TYPE_2 = "team_name" ;
const string RANKS = "ranks" ;
const string LEAGUE_STANDINGS = "league_standings" ;
const string MATCHES_RESULT_LEAGUE = "matches_result_league" ;
const string PLAYER_NAME = "name" ;
const string NAME = ". name: " ;
const string NAME_TYPE_2 = "name" ;
const string ASSISTS = " | assists: " ;
const string CLEAN_SHEETS = " | clean sheets: " ;
const string ROLE = " | role: " ;
const string SCORE = " | score: " ;
const string SCORE_TYPE_2 = ": score: " ;
const string COST = " | cost: " ;
const string GOALS = " | goals: " ;
const string SPACE = " " ;
const string BAR = " | " ;
const string DOT = "." ;
const string NONE = "" ;
const string Q_MARK = "?";
const char SEMICOLON = ';' ;
const char COLON = ':' ;
const char COMMA = ',' ;
const char UNDERLINE = '_' ;
const char CHAR_SPACE = ' ' ;

enum POST
{
    GK = 1,
    DF,
    MD,
    FW
};

enum MATCH_STATUS
{
    _WIN_GAME,
    _DRAW_GAME,
    _LOSE_GAME
};

enum DEFENDER_POS
{
    LB = 1,
    LCB,
    RCB,
    RB
};

enum MIDIFIELDER_POS
{
    LCM = 5,
    CM,
    RCM
};

enum FORWARD_POS
{
    LW = 8,
    CF,
    RW
};

class BadRequest
{
public:
    void error() { cout << BAD_REQ_WARNING << endl; }
};

class PermissionDenied
{
public:
    void error() { cout << PERMISSION_DENIED_WARNING << endl; }
};

class NotFound
{
public:
    void error() { cout << NOT_FOUND_WARNING << endl; }
};

class Empty
{
public:
    void error() { cout << EMPTY_WARNING << endl; }
};

class NotAvailable
{
public:
    void error() { cout << AVAILABILITY_WARNING << endl; }
};

#endif