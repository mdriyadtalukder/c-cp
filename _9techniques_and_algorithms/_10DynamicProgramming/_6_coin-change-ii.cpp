#include <bits/stdc++.h>
using namespace std;


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
//int change(int amount, vector<int> &coins)
/*

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount: // ager tar motoi just total koita combination hbe eita ber krbo
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1


We use ind + 2D DP because:
👉 “We must track both which coins are allowed and what amount is left.”

ind = 0 → [1]
ind = 1 → [1,2]
ind = 2 → [1,2,5]

🧠 Example (if coins = [1,2,5], amount = 5)

          0   1   2   3   4   5
        -------------------------
1       | -1  -1  -1  -1  -1  -1
2       | -1  -1  -1  -1  -1  -1
5       | -1  -1  -1  -1  -1  -1
*/
