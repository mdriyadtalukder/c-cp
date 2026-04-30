#include <bits/stdc++.h>
using namespace std;
//ekta num er height and lowest prime num using Sieve algo.
const int N = 1e7 + 10;

vector<bool> isPrime(N, true);
vector<int> lp(N, 0), hp(N, 0); // lowest prime, highest prime

int main()
{
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i < N; ++i)
    {
        if (isPrime[i])
        {
            lp[i] = hp[i] = i;

            for (int j = 2 * i; j < N; j += i)
            {
                isPrime[j] = false;
                hp[j] = i;

                if (lp[j] == 0)
                {
                    lp[j] = i;
                }
            }
        }
    }

    // sample print
    for (int i = 1; i < 100; ++i)
    {
        cout << i << " -> LP: " << lp[i] << ", HP: " << hp[i] << "\n";
    }
}