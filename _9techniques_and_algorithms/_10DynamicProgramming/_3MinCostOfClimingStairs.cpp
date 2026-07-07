
#include <bits/stdc++.h>
using namespace std;
// top down--recursion with from top elem to dowm
int ways(int n, vector<int> &cost, vector<int> &dp)
{
    if (n <= 1) // 0 or 1 no siri theke suru krte pari as 1 or 2 jump.. tai ja initial state...tai  hbe.. or leaft node 1 or 0 hy..
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
// proti ta siri er cost deoya ase..uporer siri te jete hole current siri er cost pay krte hbe then 1 or 2 jump dite pari..
// min cost ta ber krte hbe for n..
// topdown--n=4 theke niche jabo n theke 2 hbe 2 step nile r ek step nile 3..eivabe so on for all utill get 1 or 0 value..

/*
746. Min Cost Climbing Stairs

Problem Statement:

You are given an integer array cost,
where cost[i] is the cost of the ith stair.

After paying the cost,
you can climb either:

- 1 stair
- 2 stairs

You may start from:

- Step 0
- Step 1

Return the minimum cost
to reach the top of the floor.

The top is one step beyond
the last stair.

------------------------------------------------

Example 1:

Input:

cost = [10,15,20]

Output:

15

Explanation:

Start from step 1.

Pay 15.

Jump directly to the top.

Minimum cost = 15.

------------------------------------------------

Example 2:

Input:

cost =

[1,100,1,1,1,100,1,1,100,1]

Output:

6

Explanation:

One minimum-cost path is:

Step 0 (1)

↓

Step 2 (1)

↓

Step 3 (1)

↓

Step 4 (1)

↓

Step 6 (1)

↓

Step 7 (1)

↓

Top

Total Cost = 6

------------------------------------------------

Constraints:

2 <= cost.length <= 1000

0 <= cost[i] <= 999

------------------------------------------------

Approaches:

1. Simple Recursion
   Time  : O(2^N)
   Space : O(N)

2. Top-Down DP (Memoization)
   Time  : O(N)
   Space : O(N)

3. Bottom-Up DP (Tabulation)
   Time  : O(N)
   Space : O(N)

4. Space Optimized DP
   Time  : O(N)
   Space : O(1)

------------------------------------------------

DP State:

dp[i] = Minimum cost required
to reach step i.

Transition:

dp[i] = min(
    cost[i-1] + dp[i-1],
    cost[i-2] + dp[i-2]
)

Base Cases:

dp[0] = 0

dp[1] = 0

Answer:

dp[n]

where n = cost.size()
(the top of the staircase).
*/
// int minCostClimbingStairs(vector<int> &cost)
