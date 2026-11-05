#include <bits/stdc++.h>
using namespace std;

// brute force
bool isAnagram(string s, string t)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

// optimal1
bool isAnagram(string s, string t)
{
    unordered_map<char, int> m, m2;
    for (int i = 0; i < s.size(); i++)
    {
        m[s[i]]++;
    }
    for (int i = 0; i < t.size(); i++)
    {
        m2[t[i]]++;
    }
    return m == m2;
}
// more optimal2
bool isAnagram(string s, string t)
{
    if (s.size() != t.size())
        return false;

    vector<int> count(26, 0);

    // Increment for s, decrement for t
    for (int i = 0; i < s.size(); i++)
    {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }

    // Check if all counts are zero
    for (int c : count)
    {
        if (c != 0)
            return false;
    }

    return true;
}