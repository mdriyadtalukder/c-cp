#include <bits/stdc++.h>
using namespace std;
// a b c d..a&b!=0 ,then a&b&c=0 so stop..
void solve()
{
    long long n;
    cin >> n;

    // long long x = n;
    // long long temp = n;

    // while (x > 0) {
    //     temp -= 1;
    //     x &= temp;
    // }

    // cout << temp << "\n";
    int c = 0;
    while (n > 0)
    { //(number of bits
        n >>= 1;
        c++;
    }
    int ans = (1 << (c - 1)) - 1;
    cout << ans << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}