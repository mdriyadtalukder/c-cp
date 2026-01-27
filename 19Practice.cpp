#include <bits/stdc++.h>
using namespace std;
int f(int x)
{
    int sum = 1;
    while (x != 0)
    {
        int d = x % 10;
        if (d != 0)
            sum *= d;
        x = x / 10;
    }
    return sum;
}
int g(int x)
{
    while (x > 9)
    {
        x = f(x);
    }
    return x;
}
int main()
{
    const int max = 1000000;
    static int ar[10][max + 1]; // only int use stack..Stack → small shelf (limited space)Data segment → warehouse(huge space) .
    for (int i = 1; i <= max; i++)
    {
        int gx = g(i);
        for (int k = 1; k <= 9; k++)
        {
            ar[k][i] = ar[k][i - 1]; // copy previous counts
        }
        ar[gx][i]++; // increment current gx count
    }
    int n;
    cin >> n;
    while (n--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        cout << ar[k][r] - ar[k][l - 1] << endl;
    }
}
// for k=1..9: pref[k][i]=pref[k][i-1]  // carry previous counts
// pref[g(i)][i]++                      // add current number

// for k=1..9: pref[k][i] = pref[k][i-1]  // copy previous counts
// pref[g(x)][i]++            // increment count for current number
