/*
It means breaking a number into prime factors(num).

Example:

12 = 2 × 2 × 3
60 = 2 × 2 × 3 × 5
*/
// O(√n)--faster

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> prime_factors;

    for (int i = 2; i * i <= n; ++i)
    {
        while (n % i == 0)
        {
            prime_factors.push_back(i);
            n /= i;
        }
    }

    if (n > 1)
    {
        prime_factors.push_back(n);
    }

    for (int prime : prime_factors)
    {
        cout << prime << " ";
    }

    return 0;
}

/* fast version
Sieve:
O(N log log N)
Each factorization:
O(log n) ✔ (very fast)


#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;

vector<bool> isPrime(N, true);
vector<int> lp(N, 0), hp(N, 0);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Sieve
    for (int i = 2; i < N; ++i) {
        if (isPrime[i]) {
            lp[i] = hp[i] = i;

            for (int j = 2 * i; j < N; j += i) {
                isPrime[j] = false;
                hp[j] = i;

                if (lp[j] == 0) {
                    lp[j] = i;
                }
            }
        }
    }

    int num;
    cin >> num;

    unordered_map<int, int> prime_factors;

    while (num > 1) {
        int prime_factor = hp[num];

        while (num % prime_factor == 0) {
            num /= prime_factor;
            prime_factors[prime_factor]++;
        }
    }

    for (auto factor : prime_factors) {
        cout << factor.first << " " << factor.second << "\n";
    }
}*/