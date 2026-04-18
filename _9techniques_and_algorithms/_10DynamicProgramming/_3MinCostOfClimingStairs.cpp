// proti ta siri er cost deoya ase..uporer siri te jete hole current siri er cost pay krte hbe then 1 or 2 jump dite pari..
// min cost ta ber krte hbe for n..
// topdown--n=4 theke niche jabo n theke 2 hbe 2 step nile r ek step nile 3..eivabe so on for all utill get 1 or 0 value..
#include <bits/stdc++.h>
using namespace std;
// top down--recursion with from top elem to dowm
int ways(int n, vector<int> &cost, vector<int> &dp)
{
    if (n <= 1)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = min(
               cost[n - 1] + ways(n - 1, cost, dp),
               cost[n - 2] + ways(n - 2, cost, dp));
}

int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    vector<int> dp(n + 1, -1);
    return ways(n, cost, dp);
    /*
    downup
    vector<int> dp(n + 1, -1);

    dp[0] = 0;
    dp[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = min(
            cost[i - 1] + dp[i - 1],
            cost[i - 2] + dp[i - 2]
        );
    }

    return dp[n];
    */

    /*
    speace optimizing
    int n = cost.size();

    int prev2 = 0,curr; // dp[i-2]
    int prev1 = 0; // dp[i-1]

    for (int i = 2; i <= n; i++)
    {
         curr = min(
            cost[i - 1] + prev1,
            cost[i - 2] + prev2
        );

        prev2 = prev1;
        prev1 = curr;
    }

    return curr;
}

    */
}
int main() {}