#include <bits/stdc++.h>
using namespace std;
long long modPow(long long a, long long b, long long mod)
{
    long long result = 1;
    while (b > 0)
    {
        if (b & 1)
            result = (result * a) % mod;

        a = (a * a) % mod;
        b >>= 1;
    }
    return result;
}
int main()
{
    int x;
    cin >> x;
    while (x--)
    {
        long long n, i = 1;
        cin >> n;
        while (modPow(i, n, n) != 0)
        {
            i++;
        }
        cout << i << endl;
    }
}

/*#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n = 12;
    long long i = 1;

    while (pow(i, n) % n != 0)
    {
        i++;
    }
    cout << i;
}*/