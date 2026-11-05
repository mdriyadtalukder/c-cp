#include <bits/stdc++.h>
using namespace std;

// brute force
bool rotateString(string s, string goal)
{
    if (s == goal)
        return true;
    if (s.size() != goal.size())
        return false;
    for (int i = 1; i < s.size(); i++)
    {
        string l = s.substr(i) + s.substr(0, i);
        if (l == goal)
            return true;
    }
    return false;
}

// optimal (KMP)
vector<int> prefix_function(string s)
{
    int n = s.size();
    vector<int> pi(n, 0);

    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];

        while (j > 0 && s[i] != s[j])
        {
            j = pi[j - 1];
        }

        if (s[i] == s[j])
        {
            j++;
        }

        pi[i] = j;
    }

    return pi;
}

bool kmpContains(string s, string t)
{
    vector<int> pi = prefix_function(t);

    int i = 0, j = 0;

    while (i < s.size())
    {
        if (s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = pi[j - 1];
            }
            else
            {
                i++;
            }
        }

        if (j == t.size())
        {
            return true;
        }
    }

    return false;
}

bool rotateString(string s, string goal)
{
    if (s.size() != goal.size())
        return false;
    if (s.empty())
        return true;

    string text = s + s;

    return kmpContains(text, goal);
}
