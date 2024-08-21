#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int MAX(int m, int n)
{
    if (m >= n)
        return m;
    return n;
}
int MIN(int m, int n)
{
    if (m >= n)
        return n;
    return m;
}
void func(int arr[], int n, int prev_num = 0, int i = 0, int a = 0)
{
    if (i >= n)
    {
        return;
    }
    int jump;
    int prev = arr[i];
    if (i == 0)
    {
        //For special 0 condition.
        if(arr[i]==0){
            cout << 0;
            return;
        }
        jump = MAX(i, arr[i]);
        prev_num = arr[i];
        i += jump;
        a = 0;
    }
    else if (a == 0)
    {
        //For special 0 condition.
        if(prev_num==0 && arr[i]==0)
        {
            cout << 0;
            return;
        }
        jump = MIN(prev_num, arr[i]);
        prev_num = arr[i];
        i += jump;
        a = 1;
    }
    else if (a == 1)
    {
        //For special 0 condition.
        if(prev_num==0 && arr[i]==0)
        {
            cout << 0;
            return;
        }
        jump = MAX(prev_num, arr[i]);
        prev_num = arr[i];
        i += jump;
        a = 0;
    }
    // For not putting the ending space.
    if (i >= n)
        cout << prev;
    else
        cout << prev << ' ';
    func(arr, n, prev_num, i, a);
    return;
}
int main()
{
    int n;
    cin >> n;
    cin >> ws;
    int num[n];
    int i = 0;
    string line;
    string temp;
    getline(cin, line);
    stringstream str(line);
    while (getline(str, temp, ' ') && i < n)
    {
        num[i] = stoi(temp);
        i++;
    }
    func(num, n);
    return 0;
}