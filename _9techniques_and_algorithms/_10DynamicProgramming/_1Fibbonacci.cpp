// 0 1 1 2 3...pre 2 tar jog foll..er jnno ekt arrray create krbo jate sob value oitai store thke..recreate na krte hy..eitai DP.
#include <bits/stdc++.h>
using namespace std;
// top down--recursion with from top elem to dowm--recursion+cache
int fibon(int n, vector<int> &dp)
{
    // base case
    if (n == 0 || n == 1)
    {
        return n;
    }

    // already calculated result
    if (dp[n] != -1)
        return dp[n];

    return dp[n] = fibon(n - 1, dp) + fibon(n - 2, dp);
}

int fib(int n)
{
    vector<int> dp(n + 1, -1);
    return fibon(n, dp);

    // bottom up--loop--from bottom elem to up---build ans from smallest value
    // if (n == 0 || n == 1)
    //     return n;

    // vector<int> dp(n + 1, -1);
    // dp[0] = 0;
    // dp[1] = 1; // can't access it
    // for (int i = 2; i <= n; i++)
    // {
    //     dp[i] = dp[i - 1] + dp[i - 2];
    // }
    // return dp[n];

    /* speace optimization solution--when only pre state are needed
    if (n == 0 || n == 1)
    return n;
    int curr. prev = 1, prev2 = 0;
    for(int i = 2 i<=n;i++)
    {
    curr = prev+prev2;
    prev2 = prev;
    prev = curr;
    }
    return curr;
    */
}
/*
509. Fibonacci Number

Problem Statement:

The Fibonacci numbers are defined as:

F(0) = 0

F(1) = 1

For n > 1,

F(n) = F(n-1) + F(n-2)

Given an integer n,
return the nth Fibonacci number.

------------------------------------------------

Example 1:

Input:

n = 2

Output:

1

Explanation:

F(2) = F(1) + F(0)

     = 1 + 0

     = 1

------------------------------------------------

Example 2:

Input:

n = 4

Output:

3

Explanation:

F(4)

= F(3) + F(2)

= 2 + 1

= 3

------------------------------------------------

Example 3:

Input:

n = 6

Output:

8

Explanation:

Sequence:

0 1 1 2 3 5 8

------------------------------------------------

Constraints:

0 <= n <= 30

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

DP Idea:

Many Fibonacci values are calculated
multiple times in recursion.

Store each computed value in a DP array
so that every state is computed only once.

This technique is called Memoization.

When building answers from smaller states
using a loop, it is called Tabulation.

If only previous states are required,
store only those values instead of the
entire DP array (Space Optimization).
*/
// int fib(int n)
