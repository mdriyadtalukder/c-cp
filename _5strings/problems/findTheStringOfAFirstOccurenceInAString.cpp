#include <bits/stdc++.h>
using namespace std;
// Brute force

// string s = "na";
// string t = "apna collegena";

int strStr(string t, string s)
{
    int S = s.size();

    for (int i = 0; i < t.size(); i++)
    {
        if (t.substr(i, S) == s)
        {
            return i;
        }
    }
    return -1;
}

// optimal(KMP)

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
int strStr(string t, string s)
{

    vector<int> pi = prefix_function(s);

    int pos = -1;
    int i = 0, j = 0;

    while (i < t.size())
    {
        if (t[i] == s[j])
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

        if (j == s.size())
        {
            pos = i - s.size();
            break;
        }
    }
    return pos;
}