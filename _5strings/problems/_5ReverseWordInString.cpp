#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s = "the sky is blue", l = "", r = "";
    vector<string> v;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            if (!l.empty())
            {
                v.push_back(l);
                l = "";
            }
            else
            {
                continue;
            }
        }
        else
        {
            l += s[i];
        }
    }
    if (!l.empty())
    {
        v.push_back(l);
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)

    {
        if (i == v.size() - 1)
        {
            r += v[i];
        }
        else
        {
            r += v[i] + " ";
        }
    }
    cout << r;
}