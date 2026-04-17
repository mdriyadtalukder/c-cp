// 0 1 1 2 3...pre 2 tar jog foll..er jnno ekt arrray create krbo jate sob value oitai store thke..recreate na krte hy..eitai DP.
#include <bits/stdc++.h>
using namespace std;
// top down--recursion with from top elem to dowm
int fibon(int n, vector<int> &dp)
{
    // base case
    if (n <= 1)
        return n;

    // already calculated result
    if (dp[n] != -1)
        return dp[n];

    return dp[n] = fibon(n - 1, dp) + fibon(n - 2, dp);
}

int fib(int n)
{
    vector<int> dp(n + 1, -1);
    return fibon(n, dp);

    // bottom up--loop--from bottom elem to up
    // if (n <= 1)
    //     return n;
    // vector<int> dp(n + 1, -1);
    // dp[0] = 0;
    // dp[1] = 1; // can't access it
    // for (int i = 2; i <= n; i++)
    // {
    //     dp[i] = dp[i - 1] + dp[i - 2];
    // }
    // return dp[n];

    /* speace optimization solution
    if(n <= 1)
    return n;
    int curr prev = 1, prev2 = 0;
    for(int i = 2 i<=n;i++)
    {
    curr = prev+prev2;
    prev2 = prev;
    prev = curr;
    }
    return curr;
    */
}