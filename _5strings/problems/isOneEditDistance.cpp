#include <bits/stdc++.h>
using namespace std;
// brute force (DP)
int solve(int i, int j, string &s, string &t, vector<vector<int>> &dp)
{
    // Base cases
    if (i == 0)
        return j;
    if (j == 0)
        return i;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i - 1] == t[j - 1])
    {
        return dp[i][j] = solve(i - 1, j - 1, s, t, dp);
    }
    else
    {
        int replace = solve(i - 1, j - 1, s, t, dp);
        int remove = solve(i - 1, j, s, t, dp);
        int insert = solve(i, j - 1, s, t, dp);

        return dp[i][j] = 1 + min({replace, remove, insert});
    }
}

bool isOneEditDistance(string s, string t)
{
    int m = s.size(), n = t.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    return solve(m, n, s, t, dp) == 1;
}

//optimal
bool isOneEditDistance2(string s, string t)
{
    int sLen = s.length(), tLen = t.length();
    // Ensure s is the shorter or equal-length string
    if (sLen > tLen)
    {
        return isOneEditDistance2(t, s);
    }

    // Length difference > 1 means more than one edit needed
    if (tLen - sLen > 1)
    {
        return false;
    }

    // Find the first mismatch
    for (int i = 0; i < sLen; i++)
    {
        if (s[i] != t[i])
        {
            if (sLen == tLen)
            {
                // Replace case: rest of strings must match
                return s.substr(i + 1) == t.substr(i + 1);
            }
            else
            {
                // Insert/delete case: skip char in t, rest must match
                return s.substr(i) == t.substr(i + 1); // this logic for both(delete and insert)
            }
        }
    }

    // No mismatch found; one edit only if t has one extra char at the end
    return sLen != tLen;
}