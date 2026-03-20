// n size array and k ase..ami k>=1 er element niye niye er xor ber krbo and maximum ta ans hbe ..

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;

    if (k == 1)
    {
        cout << n << "\n";
        return 0;
    }

    long long ans = 1;

    while (ans < n)
    {
        ans *= 2;
        ans += 1;
    }

    cout << ans << "\n";

    return 0;
}