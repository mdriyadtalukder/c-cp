#include <bits/stdc++.h>
using namespace std;
// brute force
string longestCommonPrefix(vector<string> &strs)
{
    string ans = strs[0], l = "";
    for (int i = 1; i < strs.size(); i++)
    {
        string s = strs[i];
        for (int j = 0; j < ans.size(); j++)
        {
            if (ans[j] == s[j])
            {
                l.push_back(ans[j]);
            }
            else
            {
                ans = l;
                l = "";
            }
            if (!l.empty() && j == ans.size() - 1)
            {
                ans = l;
                l = "";
            }
        }
    }
    if (!l.empty())
    {
        ans = l;
        l = "";
    }
    return ans;
}

// optimal
string longestCommonPrefix(vector<string> &s)
{
    if (s.empty())
    {
        return "";
    }

    for (int i = 0; i < s[0].length(); i++)
    {
        char a = s[0][i];

        for (int j = 1; j < s.size(); j++)
        {
            if (i >= s[j].length() || s[j][i] != a)
            {
                return s[0].substr(0, i);
            }
        }
    }

    return s[0];
}

int main()
{
    vector<string> s = {"flower", "flow", "flight"};

    cout << longestCommonPrefix(s) << endl;

    return 0;
}