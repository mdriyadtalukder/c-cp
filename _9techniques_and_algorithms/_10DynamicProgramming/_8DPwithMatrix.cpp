// top left(1,1)or (0,0) theke koto possible vabe ekdm last sell e mane last e jete part..way-->hy right e jabo na hy bottom e
// je kono ek vabe jete hbe at a time right or bottom.. dot(.) ba hash(#) ase all cell e..hash gulai duka jbe na..
//(i,j+1) right jbo or (i+1,j) down(bottom) jbo for all case..eivabe tree hbe for all node

#include <bits/stdc++.h>
using namespace std;

int rec(int i, int j, int n, int m, vector<string> &matrix, vector<vector<int>> &dp)
{
    int mod = 1000000007;

    // out of bounds or blocked cell
    if (i >= n || j >= m || matrix[i][j] == '#')
    {
        return 0;
    }

    // destination reached
    if (i == n - 1 && j == m - 1)
    {
        return 1;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    // move right
    int right = rec(i, j + 1, n, m, matrix, dp) % mod;

    // move down
    int bottom = rec(i + 1, j, n, m, matrix, dp) % mod;

    return dp[i][j] = (right + bottom) % mod;
}

int main()
{
    vector<string> matrix = {
        "...",
        ".#.",
        "..."};

    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    cout << rec(0, 0, n, m, matrix, dp) << endl;

    return 0;
}
/* down
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> matrix = {
        "...",
        ".#.",
        "..."
    };

    int n = matrix.size();
    int m = matrix[0].size();
    int mod = 1000000007;

    vector<vector<int>> dp(n, vector<int>(m, 0));

    if (matrix[0][0] == '#') {
        cout << 0 << endl;
        return 0;
    }

    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '#') continue;

            if (i > 0)
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;

            if (j > 0)
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
        }
    }

    cout << dp[n - 1][m - 1] << endl;
    return 0;
}

*/

/* space optimizing
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> matrix = {
        "...",
        ".#.",
        "..."
    };

    int n = matrix.size();
    int m = matrix[0].size();
    int mod = 1000000007;

    // dp[j] = number of ways to reach current row, column j
    vector<int> dp(m, 0);

    // starting cell
    dp[0] = (matrix[0][0] == '.') ? 1 : 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            // if blocked → no ways
            if (matrix[i][j] == '#') {
                dp[j] = 0;
            }
            else if (j > 0) {
                // from left (dp[j-1]) + from top (dp[j])
                dp[j] = (dp[j] + dp[j - 1]) % mod;
            }
            // j == 0 case: only from top → dp[j] already holds it
        }
    }

    cout << dp[m - 1] << endl;

    return 0;
}

*/

/*
Grid Paths

Problem Statement:

You are given an n × m grid.

Each cell contains either:

'.'  -> Empty cell

'#'  -> Blocked cell

You start from the top-left cell
(0,0).

Your destination is the
bottom-right cell
(n-1,m-1).

You may move only:

• Right

or

• Down

You cannot move into
blocked cells.

Return the total number
of different paths from
source to destination.

Since the answer may be large,

return it modulo

1,000,000,007.

------------------------------------------------

Example 1:

Input:

grid =

...

.#.

...

Output:

2

Explanation:

Possible paths:

Right → Right → Down → Down

Down → Down → Right → Right

------------------------------------------------

Example 2:

Input:

grid =

...

###

...

Output:

0

Explanation:

Middle row is completely blocked.

No valid path exists.

------------------------------------------------

Constraints:

1 <= n,m <= 1000

grid[i][j] is either

'.'

or

'#'

------------------------------------------------

Approaches:

1. Simple Recursion
   Time  : O(2^(N+M))

2. Top-Down DP (Memoization)
   Time  : O(N × M)
   Space : O(N × M)

3. Bottom-Up DP (Tabulation)
   Time  : O(N × M)
   Space : O(N × M)

4. Space Optimized DP
   Time  : O(N × M)
   Space : O(M)

------------------------------------------------

DP State:

dp[i][j]

=

Number of ways to reach
the destination from cell (i,j).

------------------------------------------------

Transition:

dp[i][j]

=

dp[i][j+1]

+

dp[i+1][j]

(Right + Down)

------------------------------------------------

Base Cases:

Out of grid

or

Blocked cell

→ 0

Destination reached

→ 1

------------------------------------------------

Answer:

dp[0][0]

------------------------------------------------

Related Problems:

• LeetCode 63 - Unique Paths II

• CSES - Grid Paths
*/
// int solve(vector<string> matrix)
// {
// }