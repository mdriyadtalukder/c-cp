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

/*
322. Coin Change

Problem Statement:

You are given an integer array coins,
where coins[i] represents the value
of the ith coin.

You have an unlimited number
of each type of coin.

Return the minimum number of coins
required to make up the given amount.

If it is impossible,
return -1.

------------------------------------------------

Example 1:

Input:

coins = [1,2,5]

amount = 11

Output:

3

Explanation:

11 = 5 + 5 + 1

Minimum coins = 3

------------------------------------------------

Example 2:

Input:

coins = [2]

amount = 3

Output:

-1

Explanation:

It is impossible to make
amount 3 using only coin 2.

------------------------------------------------

Example 3:

Input:

coins = [1]

amount = 0

Output:

0

Explanation:

No coins are needed.

------------------------------------------------

Constraints:

1 <= coins.length <= 12

1 <= coins[i] <= 2^31 - 1

0 <= amount <= 10^4

------------------------------------------------

Approaches:

1. Simple Recursion
   Time  : Exponential

2. Top-Down DP (Memoization)
   Time  : O(amount × number_of_coins)
   Space : O(amount)

3. Bottom-Up DP (Tabulation)
   Time  : O(amount × number_of_coins)
   Space : O(amount)

------------------------------------------------

DP State:

dp[x]

=

Minimum number of coins
needed to make amount x.

------------------------------------------------

Transition:

For every coin:

dp[x]

=

min(

dp[x],

1 + dp[x - coin]

)

------------------------------------------------

Base Cases:

amount == 0

Return 0.

amount < 0

Return Infinity
(Invalid path).

------------------------------------------------

Answer:

dp[amount]

If answer is Infinity,

return -1.

------------------------------------------------

Important:

Unlike 0/1 Knapsack,

each coin can be used

unlimited times.
*/