#include <bits/stdc++.h>
using namespace std;

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