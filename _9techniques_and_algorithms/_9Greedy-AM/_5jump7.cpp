#include <bits/stdc++.h>
using namespace std;

// brute force
bool solve(int i, string s, int minJump, int maxJump, vector<int> &dp)
{
    if (i == s.size() - 1)
        return true;

    if (dp[i] != -1)
        return dp[i];

    for (int jump = minJump; jump <= maxJump; jump++)
    {
        int j = i + jump;

        if (j >= s.size())
            break;

        if (s[j] == '0')
        {
            if (solve(j, s, minJump, maxJump, dp) == true)
                return dp[i] = true;
        }
    }

    return dp[i] = false;
}

bool canReach(string s, int minJump, int maxJump)
{
    vector<int> dp(s.size() + 1, -1);

    return solve(0, s, minJump, maxJump, dp);
}

// optimal (dp+sliding window)->referred greedy
bool canReach2(string s, int minJump, int maxJump)
{
    vector<int> t(s.size(), 0);

    int c = 0;
    t[0] = 1;

    for (int j = 1; j < s.size(); j++)
    {
        if (j - minJump >= 0)
            c += t[j - minJump];

        if (j - maxJump - 1 >= 0)
            c -= t[j - maxJump - 1]; //-1 for decrease sliding window

        if (c > 0 && s[j] == '0')
            t[j] = 1;
    }

    return t[s.size() - 1] > 0;
}
int main()
{
    string s = "011010";
    int minJump = 2;
    int maxJump = 3;

    bool result = canReach(s, minJump, maxJump);

    if (result)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}