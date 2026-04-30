// 1 o n dara just vag be oi shongkha ta..
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    bool is_prime = true;

    if (n < 2)
        is_prime = false;
//O(n)
    // for (int i = 2; i < n; ++i)
    // {
    //     if (n % i == 0)
    //     {
    //         is_prime = false;
    //         break;
    //     }
    // }
    //O(√n)--faster
    for (int i = 2; i*i <= n; ++i)
    {
        if (n % i == 0)
        {
            is_prime = false;
            break;
        }
    }

    cout << is_prime;
}