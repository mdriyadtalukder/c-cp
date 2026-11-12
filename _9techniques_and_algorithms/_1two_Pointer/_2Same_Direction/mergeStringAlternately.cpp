#include <bits/stdc++.h>
using namespace std;
// optimal1
string mergeAlternately(string word1, string word2)
{
    string s;
    bool f = true;
    int m = word1.size(), n = word2.size();
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (f)
        {
            s += word1[i];
            i++;
        }
        else
        {
            s += word2[j];
            j++;
        }
        f = !f;
    }
    while (i < m)
    {
        s += word1[i];
        i++;
    }
    while (j < n)
    {
        s += word2[j];
        j++;
    }
    return s;
}
// optimal 2
string mergeAlternately(string word1, string word2)
{
    string result;
    int maxLen = max(word1.size(), word2.size());

    for (int i = 0; i < maxLen; i++)
    {
        // Add from word1 if characters remain
        if (i < word1.size())
        {
            result += word1[i];
        }
        // Add from word2 if characters remain
        if (i < word2.size())
        {
            result += word2[i];
        }
    }

    return result;
}