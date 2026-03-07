#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 3, m = 3;

    int ar[n][m] = {{1, 2, 3}, {4, 1, 1}, {1, 1, 1}};
    int r1 = 1, c1 = 1, r2 = 2, c2 = 2;
    int sum = 0, left = 0, up = 0, leftUp = 0, ans = 0; // initially sob 0 thkbe..

    // row wise sum
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < m; j++) // j=1 coz ar[0][0] er value same thkbe..next index theke sum hy
        {
            ar[i][j] = ar[i][j] + ar[i][j - 1];
        }
    }

    // col wise sum of modified matrix
    for (int i = 0; i < m; i++)
    {
        for (int j = 1; j < n; j++) ////j=1 coz ar[0][0] er value same thkbe..next index theke sum hy
        {
            ar[j][i] += ar[j - 1][i];
        }
    }

    sum = ar[r2][c2];

    // 0 theke boro hote hbe na hy -1 index access krbe
    if (r1 > 0)
        up = ar[r1 - 1][c2];
    if (c1 > 0)
        left = ar[r2][c1 - 1];
    if (r1 > 0 && c1 > 0)
        leftUp = ar[r1 - 1][c1 - 1];
    ans = sum - up - left + leftUp;

    cout << ans;
}