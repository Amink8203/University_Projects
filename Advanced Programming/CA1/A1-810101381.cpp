#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <fstream>
#define TRUE 1
using namespace std;
typedef struct diary_doc
{
    int pos_w;
    string Diary_Text;
    string date;
    string reverse_date;
    vector<string> replace_text;
} DIARY;
vector<string> token(string text, vector<string> diary, string delim)
{
    char *temp;
    char *Text = &text[0];
    char *Delimiter = &delim[0];
    temp = strtok(Text, Delimiter);
    while (temp != NULL)
    {
        diary.push_back(temp);
        temp = strtok(NULL, Delimiter);
    }
    return diary;
}
DIARY implemention_diaries(string Text, int Year, int Month, int Day)
{
    DIARY new_diary;
    new_diary.Diary_Text = Text;
    vector<string> main_diary;
    replace(Text.begin(), Text.end(), '\n', ' ');
    main_diary = token(Text, main_diary, " ");
    new_diary.replace_text = main_diary;
    return new_diary;
}
int finding_command(string text_line)
{
    vector<string> cmd;
    cmd = token(text_line, cmd, " ");
    if (cmd[0] == "start_day" || cmd[0] == "show_day" || cmd[0] == "show_the_longest_day" ||
        cmd[0] == "show_the_best_day" || cmd[0] == "show_the_best_day\n" || cmd[0] == "show_the_longest_day\n")
    {
        return 1;
    }
    return 0;
}

int main()
{
    vector<DIARY> diary_strc;
    vector<string> line;
    vector<string> p_word;
    string input;
    string f_input;
    ifstream fp;
    fp.open("positive-words.txt");
    int i = 0, j = 0, k = 0;
    if (fp.is_open())
    {
        while (getline(fp, f_input))
        {
            p_word.push_back(f_input);
            p_word[k] += "\n";
            k++;
        }
        fp.close();
        for (int h = 0; h < p_word.size(); h++)
        {
            (p_word.at(h)).pop_back();
        }
    }
    while (getline(cin, input))
    {
        line.push_back(input);
        line[i] += "\n";
        i++;
    }

    for (j; j < line.size(); j++)
    {
        vector<string> input_command;
        input_command = token(line[j], input_command, " ");
        if (input_command[0] == "start_day")
        {
            j++;
            DIARY new_day;
            vector<string> YMD;
            vector<string> Rep_Text;
            string start_date;
            string new_diary = "";
            string R_D;
            new_day.date = input_command[1];
            start_date = input_command[1];
            YMD = token(start_date, YMD, "/");

            YMD[2].pop_back();
            R_D += YMD[2];
            R_D += "/";
            R_D += YMD[1];
            R_D += "/";
            R_D += YMD[0];
            new_day.reverse_date = R_D;
            while ((finding_command(line[j]) == 0))
            {
                new_diary += line[j];
                j++;
                if (j == line.size())
                {
                    break;
                }
            }
            new_day.Diary_Text = new_diary;
            replace(new_diary.begin(), new_diary.end(), '\n', ' ');
            Rep_Text = token(new_diary, Rep_Text, " ");
            new_day.replace_text = Rep_Text;
            diary_strc.push_back(new_day);
            if (j == line.size())
            {
                break;
            }
            j--;
            continue;
        }
        if (input_command[0] == "show_day")
        {

            int m = 0;
            for (m; m < diary_strc.size(); m++)
            {
                if ((diary_strc.at(m)).date == input_command[1])
                    break;
            }

            cout << (diary_strc.at(m)).Diary_Text;
            if (j == line.size() - 1)
                break;
            else
                continue;
        }
        if (input_command[0] == "show_the_best_day\n" || input_command[0] == "show_the_best_day")
        {
            for (int d = 0; d < diary_strc.size(); d++)
            {
                int num = 0;
                if (d == diary_strc.size())
                    break;

                int cap = ((diary_strc.at(d)).replace_text).size();
                for (int e = 0; e < p_word.size(); e++)
                {
                    for (int v = 0; v < cap; v++)
                        if ((p_word.at(e)) == (((diary_strc.at(d)).replace_text)).at(v))
                        {
                            num++;
                        }
                }
                (diary_strc.at(d)).pos_w = num;
            }

            int max_pos;
            vector<int> date_index;
            string short_diary(24, '\0');
            max_pos = (diary_strc.at(0)).pos_w;
            for (int f = 0; f < diary_strc.size(); f++)
            {
                if (((diary_strc.at(f)).pos_w) > max_pos)
                {
                    max_pos = (diary_strc.at(f)).pos_w;
                }
            }
            for (int r = 0; r < diary_strc.size(); r++)
            {
                if (((diary_strc.at(r)).pos_w) == max_pos)
                {

                    date_index.push_back(r);
                }
            }
            int old_index;
            old_index = date_index.at(0);
            if (date_index.size() > 1)
            {
                for (int s = 1; s < date_index.size(); s++)
                {
                    if (((diary_strc.at(date_index.at(s))).reverse_date) < ((diary_strc.at(old_index)).reverse_date))
                    {
                        old_index = date_index.at(s);
                    }
                }
            }
            cout << (diary_strc.at(old_index)).date;
            if ((((diary_strc.at(old_index)).Diary_Text).length()) >= 20)
            {
                for (int t = 0; t < 20; t++)
                {
                    short_diary.at(t) = ((diary_strc.at(old_index)).Diary_Text).at(t);
                }
                short_diary.at(20) = '.';
                short_diary.at(21) = '.';
                short_diary.at(22) = '.';
                short_diary.at(23) = '\n';
                cout << short_diary;
            }
            else
                cout << (diary_strc.at(old_index)).Diary_Text;
            continue;
        }
        if (input_command[0] == "show_the_longest_day\n" || input_command[0] == "show_the_longest_day")
        {
            int max_char;
            string shorten_diary(24, '\0');
            vector<int> old;
            max_char = ((diary_strc.at(0)).Diary_Text).length();
            for (int n = 0; n < diary_strc.size(); n++)
            {
                if ((((diary_strc.at(n)).Diary_Text).length()) > max_char)
                {
                    max_char = ((diary_strc.at(n)).Diary_Text).length();
                }
            }
            // older.
            for (int n = 0; n < diary_strc.size(); n++)
            {
                if ((((diary_strc.at(n)).Diary_Text).length()) == max_char)
                {
                    old.push_back(n);
                }
            }
            int oldest = old.at(0);
            if ((old.size()) > 1)
            {
                for (int b = 1; b < old.size(); b++)
                {
                    if (((diary_strc.at(old.at(b))).reverse_date) < ((diary_strc.at(oldest)).reverse_date))
                    {
                        oldest = old.at(b);
                    }
                }
            }

            cout << (diary_strc.at(oldest)).date;
            if (max_char >= 20)
            {
                for (int a = 0; a < 20; a++)
                {
                    shorten_diary.at(a) = ((diary_strc.at(oldest)).Diary_Text).at(a);
                }
                shorten_diary.at(20) = '.';
                shorten_diary.at(21) = '.';
                shorten_diary.at(22) = '.';
                shorten_diary.at(23) = '\n';
                cout << shorten_diary;
            }
            else
                cout << (diary_strc.at(oldest)).Diary_Text;
        }
    }
    return 0;
}
