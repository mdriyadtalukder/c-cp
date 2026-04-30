#include <bits/stdc++.h>
using namespace std;
//Sieve algo
//array te nums thkbe..konta prime or not ta blbe..
//tc=O(N*log(logN))
const int N = 1e7 + 10;
vector<bool> isPrime(N, true);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < N; ++i)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j < N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    int q;
    cin >> q;

    while (q--)
    {
        int num;
        cin >> num;

        if (isPrime[num])
        {
            cout << "prime\n";
        }
        else
        {
            cout << "not prime\n";
        }
    }
}