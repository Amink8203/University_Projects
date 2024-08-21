#include <iostream>
#include <string>
#include <algorithm>
#define upper 32
using namespace std;
string to_upper(string &line, int i = 0)
{
    if (line[i] == '\n')
        return line;
    if (line[i] >= 'a' && line[i] <= 'z')
        line[i] -= upper;
    to_upper(line, i + 1);
    return line;
}
int main()
{
    string line;
    while (getline(cin, line))
    {
        line.push_back('\n');
        cout << to_upper(line, 0);
    }
    return 0;
}