#include <bits/stdc++.h>
using namespace std;
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