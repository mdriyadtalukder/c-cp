#include <bits/stdc++.h>
using namespace std;
// brute force
int lengthOfLastWord(string s)
{

    int c = 0;
    string st;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == ' ' && c == 0)
            continue;
        else if (s[i] == ' ' && c > 0)
            break;
        else
        {
            st.push_back(s[i]);
            c++;
        };
    }
    return st.size();
}

// optimal
int lengthOfLastWord2(string s)
{

    int c = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == ' ' && c == 0)
            continue;
        else if (s[i] == ' ' && c > 0)
            break;
        else
            c++;
    }
    return c;
}