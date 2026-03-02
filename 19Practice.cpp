#include <bits/stdc++.h>
using namespace std;
int main()
{
    string l = "level";
    unordered_map<char, int> m;
    for (int i = 0; i < l.length(); i++)
    {
        m[l[i]] += 1;
    }
    for (auto n : l)
    {
        if (m[n] == 1)
        {
            cout << n;
        }
    }
}