// common sub sequnce koita ta ber krbo 2 ta string er..
// tree te ekbar i barbe r ekbar j  barbe..jdi i and j soman hy tahole oi word jog hbe and i and j both 1 kre barbe.
// like i and j soman so 2tai barlo then both is different so then i barle..after increasing i we see now i and j are same..so abr i and j barbe ek kore
// out of index holei stop hbe sob.
// s=aze and t=aeb ...so common subsequence ae..so result-2
// task---> s=aze and t=aeb ...so common subsequence ae..task how print ae?

// longest palindromic subsequence is same as it just s k reverse kre oi 2 tai compare kre result dim.
//

#include <bits/stdc++.h>
using namespace std;

int rec(int i, int j, string &text1, string &text2, vector<vector<int>> &dp)
{
    // base case
    if (i >= text1.size() || j >= text2.size())
    {
        return 0;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;

    // if characters match
    if (text1[i] == text2[j])
    {
        ans = 1 + rec(i + 1, j + 1, text1, text2, dp);
    }
    else
    {
        ans = max(
            rec(i + 1, j, text1, text2, dp),
            rec(i, j + 1, text1, text2, dp));
    }

    return dp[i][j] = ans;
}

int main()
{
    string text1 = "abcde";
    string text2 = "ace";

    int n = text1.size();
    int m = text2.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    cout << rec(0, 0, text1, text2, dp) << endl;
    /*
        // bottom up
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (text1[i] == text2[j])
                {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        cout << dp[0][0];

        */

    // space optimized
    // vector<int> prev(m + 1, 0), curr(m + 1, 0);

    // for (int i = n - 1; i >= 0; i--)
    // {
    //     for (int j = m - 1; j >= 0; j--)
    //     {
    //         if (text1[i] == text2[j])
    //         {
    //             curr[j] = 1 + prev[j + 1];
    //         }
    //         else
    //         {
    //             curr[j] = max(prev[j], curr[j + 1]);
    //         }
    //     }
    //     prev = curr;
    // }

    // cout << prev[0];

    return 0;
}

/*
Explanation:

Suppose:

text1 = "abcde"
text2 = "ace"

We compare one character from each string.

If both characters are same:
Take that character into the answer.
Move both pointers forward.

Example:
a == a
Answer = 1 + LCS("bcde","ce")

If characters are different:
We have two choices:
1. Skip character from text1.
2. Skip character from text2.

Take whichever gives the larger answer.

Example:

text1 = abcde
         ^
text2 = ace
         ^

b != c

Option 1:
Skip 'b'
LCS("cde","ce")

Option 2:
Skip 'c'
LCS("bcde","e")

Take maximum.

Tree Idea:

          (i,j)
         /     \
   skip i     skip j
     /           \
(i+1,j)      (i,j+1)

If characters match:

      (i,j)
         |
   1 + (i+1,j+1)

Memoization stores every (i,j) answer so repeated states
are computed only once.

Time Complexity:
O(N × M)

Space Complexity:
O(N × M)

----------------------------------------------------

How to print the actual LCS?

After building the Bottom-Up DP table:

Start from (0,0)

while(i<n && j<m)
{
    if(text1[i]==text2[j])
    {
        cout<<text1[i];
        i++;
        j++;
    }
    else if(dp[i+1][j] >= dp[i][j+1])
        i++;
    else
        j++;
}

Example:

text1 = abcde
text2 = ace

Output:
ace

----------------------------------------------------

Longest Palindromic Subsequence (LPS)

LPS is solved using exactly the same algorithm.

Steps:
1. Reverse the string.
2. Find LCS(original, reversed).

Example:

s = "bbbab"

reverse = "babbb"

LCS = "bbbb"

Answer = 4
*/