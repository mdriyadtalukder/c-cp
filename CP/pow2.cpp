#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    unsigned long long result = 1; // to hold the power
    for (long long i = 0; i < n; i++)
    {
        result *= 6; // multiply directly, no modulo
    }

    long long lastTwo = result % 100; // take modulo 100 **after** computing full power
    if (lastTwo < 10)
        cout << '0'; // add leading zero if needed
    cout << lastTwo << endl;

    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

// Fast modular exponentiation: computes (base^exp) % mod
long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    long long n;
    cin >> n;

    long long lastTwo = modPow(6, n, 100); // base = 6, mod = 100
    // If lastTwo < 10, print leading 0
    if (lastTwo < 10) cout << '0';
    cout << lastTwo << endl;

    return 0;
}*/