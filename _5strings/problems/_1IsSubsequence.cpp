#include <bits/stdc++.h>
using namespace std;
// brute force
bool isSubsequence(string s, string t)
{

    if (s.empty())
        return true;

    int j = 0;

    for (int i = 0; i < s.size(); i++)
    {
        for (int k = j; k < t.size(); k++)
        {
            if (s[i] == t[k])
            {
                j = k + 1;
                break;
            }
        }

        if (j == 0 || (i > 0 && j <= 0))
            return false;
    }

    return true;
}
//optimal
bool isSubsequence(string s, string t)
{
    if (s.size() == 0)
        return true;
    int j = 0;
    for (int i = 0; i < t.size(); i++)
    {
        if (t[i] == s[j])
        {
            j++;
            if (j == s.size())
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    string a = "abc", b = "ahbgdc";
    string s = isSubsequence(a, b) == true ? "true" : "false";
    cout << s;
}