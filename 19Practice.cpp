#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, s1;
    cin >> s >> s1;
    for (char i : s)
    {
        i = tolower(i);
    }
    for (char i : s1)
    {
        i = tolower(i);
    }
    if (s > s1)
    {
        cout << 1 << endl;
    }
    if (s < s1)
    {
        cout << -1 << endl;
    }
    if (s == s1)
    {
        cout << 0 << endl;
    }
}