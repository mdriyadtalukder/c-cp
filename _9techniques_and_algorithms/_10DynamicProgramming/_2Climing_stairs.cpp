// n=5 so nich theke 5th siri te uthte hbe..er jnno zero theke suru krbo j 1 step nibo then 2 step..abr each node same krbo.
// last e dekhbo kota possible leap node hy..
// amr bujar khetre node concept use krtese for describing
// last nodes 5 or 6 hbe..5 hole r check krbona

// uporer ta recursion silo..top down e every step er value store kre rakhbo..
#include <bits/stdc++.h>
using namespace std;
// top down--recursion with from top elem to dowm
int count(int i, int n, vector<int> &dp)
{
    if (i == n)
        return 1;

    if (i > n)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    return dp[i] = count(i + 1, n, dp) + count(i + 2, n, dp); // for 1,2,3     return dp[i] = count(i + 1, n, dp) + count(i + 2, n, dp)+count(i + 3, n, dp);
}
int climbStairs(int n)
{
    vector<int> dp(n + 2, -1);
    return count(0, n, dp);

    // Bottom up
    // vector<int>dp(n+2,-1);
    // dp[n] = 1;
    // dp[n + 1] = 0;
    // for (int i = n - 1 ;i >= 0; i--)
    //     dp[i] = dp[i + 1] + dp[i + 2];
    // return dp[0]

    /*
    //space optimization
    int curr, next = 1, next2 = 0;
    for(int i = n - 1 i >= 0 ;i--)
    {
    curr = next+next2;
    next2 = next;
    next = curr;
    }
    return curr;

        */
}