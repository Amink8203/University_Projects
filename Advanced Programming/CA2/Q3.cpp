#include <bits/stdc++.h>
using namespace std;

const string cell_symbol[7][7] =
    {
        {"A1", "A2", "A3", "A4", "A5", "A6", "A7"},
        {"B1", "B2", "B3", "B4", "B5", "B6", "B7"},
        {"C1", "C2", "C3", "C4", "C5", "C6", "C7"},
        {"D1", "D2", "D3", "D4", "D5", "D6", "D7"},
        {"E1", "E2", "E3", "E4", "E5", "E6", "E7"},
        {"F1", "F2", "F3", "F4", "F5", "F6", "F7"},
        {"G1", "G2", "G3", "G4", "G5", "G6", "G7"},
};
const int possible_moves = 4;
const int row_double_jump[possible_moves] = {-2, 0, +2, 0};
const int col_double_jump[possible_moves] = {0, -2, 0, +2};
const int row_check[possible_moves] = {-1, 0, +1, 0};
const int col_check[possible_moves] = {0, -1, 0, +1};
const string where[possible_moves] = {" UP\n", " LEFT\n", " DOWN\n", " RIGHT\n"};

int num_of_N(vector<vector<char>> &board)
{
    int count = 0;
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
        {
            if (board[i][j] == 'N')
                count++;
        }
    return count;
}
void find_N(vector<vector<char>> &board, int m, int &row, int &col)
{
    int count = 0;
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
        {
            if (board[i][j] == 'N')
            {
                if (count == m)
                {
                    row = i;
                    col = j;
                    return;
                }
                count++;
            }
        }
}
bool find_soloution(vector<vector<char>> board, vector<string>& answer, int ans_index)
{
    if ((num_of_N(board) == 1) && board[3][3] == 'N')
        return true;
        int h=num_of_N(board);
    for (int m = 0; m < num_of_N(board); m++)
    {
        int row = 2, col = 2;
        find_N(board, m, row, col);
        for (int move_no = 0; move_no < possible_moves; move_no++)
        {
            int new_row = row + row_double_jump[move_no];
            int new_col = col + col_double_jump[move_no];
            int neighbor_row = row + row_check[move_no];
            int neighbor_col = col + col_check[move_no];
            if (new_col < 0 || new_col >= 7 || new_row < 0 || new_row >= 7)
                continue;
            if (board[neighbor_row][neighbor_col] != 'N')
                continue;
            if (board[new_row][new_col] != 'O')
                continue;
            board[row][col] = 'O';
            board[neighbor_row][neighbor_col] = 'O';
            board[new_row][new_col] = 'N';
            answer.push_back(cell_symbol[row][col]);
            answer.at(ans_index) += where[move_no];
            ans_index++;
            if(find_soloution(board,answer,ans_index))
            return true;
            board[row][col] = 'N';
            board[neighbor_row][neighbor_col] = 'N';
            board[new_row][new_col] = 'O';
            answer.pop_back();
            ans_index--;
        }
    }
    if(answer.size()==0){
    answer.push_back("Loser");
    return true;
    }
    return false;
}

int main()
{
    // for by value!
    vector<vector<char>> board(7, vector<char>(7));
    string line;
    vector<string> answer;
    int i = 0;
    while (getline(cin, line))
    {
        for (int j = 0; j < 7; j++)
            board[i][j] = line[j];
        i++;
    }
    find_soloution(board,answer,0);
    //Deleting the ending newline.
    (answer.at(answer.size()-1)).pop_back();
    for(auto x:answer)
    cout << x;
    return 0;
}