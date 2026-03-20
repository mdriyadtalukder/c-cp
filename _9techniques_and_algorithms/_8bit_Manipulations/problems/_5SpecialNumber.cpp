// n and k..k er binary form ber krb then 2 er jaigai n boshabo like n=3 so 101=1*3^2+0*3^1+1*3^0..eita positive hote hbe..
#include <bits/stdc++.h>
using namespace std;

long long mod = 1000000007;

string decimalToBinary(long long n)
{
    if (n == 0)
        return "0";

    string binary = "";
    while (n != 0)
    {
        int rem = n % 2;
        binary += to_string(rem);
        n /= 2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

long long binaryToDecimal(string binary, long long m)
{
    int n = binary.size();
    long long p = 1;
    long long decimal = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        if (binary[i] == '1')
        {
            decimal += p;
            decimal %= mod;
        }

        p *= m;
        p %= mod;
    }

    return decimal;
}

void solve()
{
    long long n, k;
    cin >> n >> k;

    string binary = decimalToBinary(k);
    long long ans = binaryToDecimal(binary, n);

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