// weight and value er array ase and ekta fix weight er poli ba knapsack ase..like w=12..so max value guli diye 12kg vorte hbe poli te.
// 1st ta borte pari ba nao borte pari..eivbe tree hbe for all node(value)..(0,12)-1st ta nile hbe 10+(1,12)..like 10 is 1st value in array in 0 index
// 1 is 2nd index an 12 is poli weight..na dile hbe (1,12)..kisu jog be na..so on for all case
// it is taken and not token concept
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
}
/*speace optimized..its 1d
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<long> value = {1, 2, 3, 4};
    vector<long> weight = {2, 3, 4, 5};

    int W = 5;
    int n = value.size();

    vector<long> dp(W + 1, 0);

    for (int i = 0; i < n; i++)
    {
        // Traverse backwards
        for (int j = W; j >= weight[i]; j--)
        {
            dp[j] = max(dp[j], value[i] + dp[j - weight[i]]);
        }
    }

    cout << dp[W] << endl;

    return 0;
}

*/
/*
0/1 Knapsack Problem

Problem Statement:

You are given:

weight[i] = weight of the ith item

value[i] = value of the ith item

You are also given an integer W
representing the maximum capacity
of the knapsack.

Choose items such that:

• Total weight does not exceed W.

• Each item can be selected
  at most once.

Return the maximum total value
that can be obtained.

------------------------------------------------

Example 1:

Input:

value  = [1,2,3,4]

weight = [2,3,4,5]

W = 5

Output:

4

Explanation:

Possible selections:

Item 1 + Item 2

Weight = 2 + 3 = 5

Value = 1 + 2 = 3

Item 4

Weight = 5

Value = 4

Maximum value = 4

------------------------------------------------

Example 2:

Input:

value  = [60,100,120]

weight = [10,20,30]

W = 50

Output:

220

Explanation:

Choose items:

100 + 120

Weight = 20 + 30 = 50

Value = 220

------------------------------------------------

Constraints:

1 <= n <= 100

1 <= W <= 1000

1 <= weight[i] <= W

1 <= value[i] <= 1000

------------------------------------------------

Approaches:

1. Simple Recursion
   Time  : O(2^N)
   Space : O(N)

2. Top-Down DP (Memoization)
   Time  : O(N × W)
   Space : O(N × W)

3. Bottom-Up DP (Tabulation)
   Time  : O(N × W)
   Space : O(N × W)

4. Space Optimized DP
   Time  : O(N × W)
   Space : O(W)

------------------------------------------------

DP State:

dp[i][w]

=

Maximum value obtainable

using items from index i

with remaining capacity w.

------------------------------------------------

Transition:

Not Take:

dp[i+1][w]

Take:

value[i] +

dp[i+1][w-weight[i]]

Answer:

max(Take, Not Take)

------------------------------------------------

Base Case:

If no items remain,

return 0.

------------------------------------------------

Important:

This is called the

0/1 Knapsack Problem

because every item has only

two choices:

Take it once

OR

Do not take it.
*/