// Modular Arithmetic for Division
/*
(A / B) % M ≠ (A % M / B % M)

(A / B) % M = (A × B^(-1)) % M

= ((A % M) × (B^(-1) % M)) % M

*/

#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
const int N = 1e6 + 10;

int fact[N];

// Fast exponentiation (binary exponentiation)
// Computes (a^b) % m in O(log b)
int binexp(int a, int b, int m)
{
    int result = 1;

    while (b > 0)
    {
        // If current bit of b is set, multiply result with a
        if (b & 1)
        {
            result = (result * 1LL * a) % m;
        }

        // square the base
        a = (a * 1LL * a) % m;

        // move to next bit
        b >>= 1;
    }

    return result;
}

/*
Problem:
There are N children and K toffees. K < N.
Count the number of ways to distribute toffees among N students
such that each student gets at most 1 toffee.

This is simply: nCk % M

Formula:
nCk = n! / ((n-k)! * k!)

We use modular inverse for division under modulo M = 1e9+7
(using Fermat's Little Theorem since M is prime)
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Precompute factorials modulo M
    fact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = (fact[i - 1] * 1LL * i) % M;
    }

    int q;
    cin >> q;

    while (q--)
    {
        int n, k;
        cin >> n >> k;

        // numerator = n!
        int ans = fact[n];

        // denominator = (n-k)! * k!
        int den = (fact[n - k] * 1LL * fact[k]) % M;

        // ans = n! * inverse(den) % M
        //ans = ans * binexp(den, M - 2, M);

        ans = (ans * 1LL * binexp(den, M - 2, M)) % M;

        cout << ans << "\n";
    }

    return 0;
}