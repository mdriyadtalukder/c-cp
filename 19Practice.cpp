#include <bits/stdc++.h>
using namespace std;

long long mod = 1e9 + 7;

long long power(long long a, long long b)
{
    long long res = 1;

    while (b > 0)
    {
        if (b % 2)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }

    return res;
}

int main()
{
    long long b;
    cin >> b;

    long long ans = power(5, b);

    // Print last 2 digits, always 2 characters
    cout << setw(2) << setfill('0') << ans << endl;

    return 0;
}