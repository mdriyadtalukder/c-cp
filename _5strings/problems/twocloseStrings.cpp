#include <bits/stdc++.h>
using namespace std;
// brute force
bool closeStrings(string word1, string word2)
{
    if (word1.size() != word2.size())
        return false;
    map<char, int> m, m2;
    vector<int> v, v2;
    string s, s2;
    for (int i = 0; i < word1.size(); i++)
    {
        m[word1[i]]++;
        m2[word2[i]]++;
        if (s.find(word1[i]) == string::npos)
            s += word1[i];
        if (s2.find(word2[i]) == string::npos)
            s2 += word2[i];
    }
    for (auto &i : m)
    {
        v.push_back(i.second);
    }
    for (auto &j : m2)
    {
        v2.push_back(j.second);
    }
    sort(v.begin(), v.end());
    sort(v2.begin(), v2.end());
    sort(s.begin(), s.end());
    sort(s2.begin(), s2.end());
    return v == v2 && s == s2;
}

// optimal
bool closeStrings(string word1, string word2)
{
    if (word1.length() != word2.length())
        return false;

    vector<int> freq1(26, 0);
    vector<int> freq2(26, 0);

    // Count character frequencies
    for (char c : word1)
        freq1[c - 'a']++;

    for (char c : word2)
        freq2[c - 'a']++;

    // Check both strings have the same set of characters
    for (int i = 0; i < 26; i++)
    {
        if ((freq1[i] == 0) != (freq2[i] == 0))
            return false;
    }

    // Sort frequency arrays and compare
    sort(freq1.begin(), freq1.end());
    sort(freq2.begin(), freq2.end());

    return freq1 == freq2;
}