
#include <bits/stdc++.h>
using namespace std;
// top down--recursion with from top elem to dowm
int count(int i, int n, vector<int> &dp)
{
    if (i == n) // leaf n hbe or n er theke boro..so n hhole return 1
        return 1;

    if (i > n) // leaf n er theke boro tai return 0
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
    // dp[n] = 1; //5 er 1 1 hbe-basecase
    // dp[n + 1] = 0; //6(n er theke boro) er ta 0 hbe-basecase
    // for (int i = n - 1 ;i >= 0; i--)
    //     dp[i] = dp[i + 1] + dp[i + 2]; //4 er ta 1+0=1,3 will be=1+1=2..so on..0 will be 8
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

// n=5 so nich theke 5th siri te uthte hbe..er jnno zero theke suru krbo..er jnno amra 1 step ba 2 step kre jete parbo in 5 no siri..
// like 1,1,1,1,1 or 2,2,1 or 2,1,1,1...emn kre koita possible result hbe eita ber krte hbe..
// tree banabo 0 hbe node then 1 step and 2 step will be left and right child then 1 er chil abr hbe 1step(1+1=2) and 2step(1+2=3)..so on until get 5 or 6..
// last e dekhbo kota possible(5) leap node hy..leaf node n or n er cheye boro value thkbe just
// amr bujar khetre node concept use krtese for describing
// last nodes 5 or 6 hbe..5 hole r check krbona

// uporer ta recursion silo..top down e every step er value store kre rakhbo..
//int climbStairs(int n)