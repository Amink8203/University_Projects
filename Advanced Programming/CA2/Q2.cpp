#include <bits/stdc++.h>
using namespace std;

void simon(int i, int j, int n, int& count)
{
    if (n <= 0)
        return;
    if (i == n && j == n)
    {
        count++;
        return;
    }
    // Not going up the diognal.
    if (i <= n && j <= n && i >= 0 && j >= 0 && i == j)
        simon(i, j + 1, n, count);
    // Increasing column.
    if (i >= 0 && j >= 0 && i + 1 <= n && j <= n && i != j)
        simon(i + 1, j, n, count);
    // Increasing row.
    if (i >= 0 && j >= 0 && i <= n && j + 1 <= n && i != j)
        simon(i, j + 1, n, count);
}
int main()
{
    int n;
    cin >> n;
    int i = 0, j = 0, count = 0;
    simon(i, j, n, count);
    cout << count;
    return 0;
}