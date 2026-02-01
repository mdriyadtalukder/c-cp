#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, l, r, l2, r2, sum = 0;
    cin >> n >> m;
    int ar[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ar[i][j];
        }
    }
    cin >> l >> r >> l2 >> r2;

    for (int i = l; i <= l2; i++)
    {
        for (int j = r; j <= r2; j++)
        {
            sum += ar[i][j];
        }
    }
    cout << sum;
}