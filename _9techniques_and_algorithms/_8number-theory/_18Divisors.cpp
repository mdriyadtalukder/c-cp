#include <bits/stdc++.h>
using namespace std;
// n ke kon kon i dara vag jai
int main()
{
    int n;
    cin >> n;

    int ct = 0;
    int sum = 0;
    // TC=O(n)
    // for (int i = 1; i <= n; ++i)
    // {
    //     if (n % i == 0)
    //     {
    //         cout << i << endl;

    //         ct++;     // tota divisors
    //         sum += i; // sum of divisors
    //     }
    // }

    // TC=O(√n)--faster
    for (int i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            cout << i << " " << n / i << endl;

            ct += 1;
            sum += i;

            if (n / i != i)
            {
                sum += n / i;
                ct += 1;
            }
        }
    }

    cout << ct << " " << sum << endl;
}

/* Sieve version--faster
tc=(nlogn)
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> divisors[N];

int main() {

    // Precompute divisors
    for (int i = 1; i < N; ++i) {
        for (int j = i; j < N; j += i) {
            divisors[j].push_back(i);
        }
    }

    // Print divisors for numbers 1 to 9
    for (int i = 1; i < 10; ++i) {
        for (int div : divisors[i]) {
            cout << div << " ";
        }
        cout << "\n";
    }
}
*/