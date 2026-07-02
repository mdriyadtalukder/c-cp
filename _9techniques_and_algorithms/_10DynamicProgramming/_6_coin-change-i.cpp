#include <bits/stdc++.h>
using namespace std;

int func(int amount, vector<int> &coins, vector<int> &dp)
{
    if (amount == 0)
        return 0;
    if (amount < 0)
        return 1e9; // infinity case

    if (dp[amount] != -1)
        return dp[amount];

    int ans = 1e9;

    for (int coin : coins)
    {
        if (amount - coin >= 0)
        {
            ans = min(ans, func(amount - coin, coins, dp) + 1); // amount theke 1,2,5 minus krbo then abr 1,2,5 theke 1,2,5 minus krbo ..eivbe tree create hbe.amount 0 j level e 1st hbe oitai level e ans like 3.
        }
    }

    return dp[amount] = ans;
}

int coinChange(vector<int> coins, int amount)
{
    vector<int> dp(amount + 1, -1);

    int ans = func(amount, coins, dp);

    return (ans >= 1e9) ? -1 : ans;
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    cout << coinChange(coins, amount) << endl;

    return 0;
}

//    cout << coinChange(coins, amount) << endl;
/*
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1...min koita coins lagbe total

                               11
                   /            |            \
                 10             9             6
              /  |  \        /  |  \       /  |  \
             9   8   5      8   7   4     5   4   1
           / | \  /|\  \
          8  7  4 7 6 3 0

level=3=ans

*/