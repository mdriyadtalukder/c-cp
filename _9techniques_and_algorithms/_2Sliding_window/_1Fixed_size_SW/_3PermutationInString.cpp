#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2)
{
    vector<int> b(26, 0), s(26, 0);

    if (s2.size() < s1.size())
        return false;

    // frequency of pattern s1
    for (char c : s1)
    {
        b[c - 'a']++;
    }

    int k = s1.size();

    // first window
    for (int i = 0; i < k; i++)
    {
        s[s2[i] - 'a']++;
    }

    if (b == s)
        return true;

    // sliding window
    for (int i = k; i < s2.size(); i++)
    {
        s[s2[i] - 'a']++;
        s[s2[i - k] - 'a']--;

        if (b == s)
            return true;
    }

    return false;
}

int main()
{

    string s1 = "ab";
    string s2 = "eidbaooo";

    if (checkInclusion(s1, s2))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}