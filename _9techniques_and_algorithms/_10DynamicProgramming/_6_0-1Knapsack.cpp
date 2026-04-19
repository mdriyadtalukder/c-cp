// weight and value er array ase and ekta fix weight er poli ba knapsack ase..like w=12..so max value guli diye 12kg vorte hbe poli te.
// 1st ta borte pari ba nao borte pari..eivbe tree hbe for all node(value)..(0,12)-1st ta nile hbe 10+(1,12)..like 10 is 1st value in array in 0 index
// 1 is 2nd index an 12 is poli weight..na dile hbe (1,12)..kisu jog be na..so on for all case
//it is taken and not token concept
#include <bits/stdc++.h>
using namespace std;

long rec(int i, int W, int n, vector<long> &v, vector<long> &w, vector<vector<long>> &dp)
{
    // base case
    if (i == n)
    {
        return 0;
    }

    // already computed
    if (dp[i][W] != -1)
    {
        return dp[i][W];
    }

    // not take
    long not_take = rec(i + 1, W, n, v, w, dp);

    // take
    long take = LONG_MIN;
    if (w[i] <= W)
    {
        take = v[i] + rec(i + 1, W - w[i], n, v, w, dp);
    }

    return dp[i][W] = max(take, not_take);
}

int main()
{
    // hardcoded values
    vector<long> v = {1, 2, 3, 4}; // values
    vector<long> w = {2, 3, 4, 5}; // weights
    int W = 5;                     // capacity
    int n = v.size();

    vector<vector<long>> dp(n, vector<long>(W + 1, -1));

    long ans = rec(0, W, n, v, w, dp);

    cout << ans << endl;

    return 0;

    /* bottom up
    vector<long> v = {1, 2, 3, 4};   // values
    vector<long> w = {2, 3, 4, 5};   // weights
    int W = 5;
    int n = v.size();

    vector<vector<long>> dp(n + 1, vector<long>(W + 1, 0));

    for (int i = n - 1; i >= 0; i--) {
        for (int cap = 0; cap <= W; cap++) {

            long not_take = dp[i + 1][cap];

            long take = LONG_MIN;
            if (w[i] <= cap) {
                take = v[i] + dp[i + 1][cap - w[i]];
            }

            dp[i][cap] = max(take, not_take);
        }
    }

    cout << dp[0][W] << endl;
    return 0;

    */
}
