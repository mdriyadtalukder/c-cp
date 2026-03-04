#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    int a, b, x, y;
    a = (k * l) / nl;
    b = c * d;
    x = p / np;
    y = min(a, b);
    cout << min(x, y) / n << endl;
}