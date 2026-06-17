#include <bits/stdc++.h>
using namespace std;

/*

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount: // ager tar motoi just total koita combination hbe eita ber krbo
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

tree er end e 0 je koita hbe oi koita combination hbe..

We use ind + 2D DP because:
👉 “We must track both which coins are allowed and what amount is left.”

ind means which coins allow to use
ind = 0 → you can use [1, 2, 5]
ind = 1 → you can use [2, 5]
ind = 2 → you can use [5]

Case A: ind = 0 → allowed [1,2,5]
We can build:(for make 5)
1+1+1+1+1
2+1+1+1
2+2+1
5
Case B: ind=1->allowed(2,5)
We can build:(for make 5)
5
Case C: ind=2->allowed(5)
We can build:(for make 5)
5
*/

int func1(int ind, int amount, vector<int> &coins, vector<vector<int>> &dp)
{
    if (amount == 0)
        return 1;
    if (ind < 0)
        return 0;
    if (dp[ind][amount] != -1)
        return dp[ind][amount];

    int ways = 0;
    for (int coin_amount = 0; coin_amount <= amount; coin_amount += coins[ind])
    {
        ways += func1(ind - 1, amount - coin_amount, coins, dp);
    }

    return dp[ind][amount] = ways;
}

int change(int amount, vector<int> &coins)
{
    vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
    return func1(coins.size() - 1, amount, coins, dp);
}
