#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
// big A
int binExpBigA(int a, int b)
{
    // a = binExpBigA(2, 1024);
    a %= M; // important when a is big
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans * 1LL * a) % M;
        }
        a = (a * 1LL * a) % M;
        b >>= 1;
    }
    return ans;
}
// big M
//(O(log² b))
// long long int M2 = 1e18 + 7;
const long long M2 = 1000000000000000007LL;

int binMultiply(long long a, long long b)
{
    int ans = 0;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans + a) % M2;
        }
        a = (a + a) % M2;
        b >>= 1;
    }
    return ans;
}
int binExpBigM(long long a, long long b)
{
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = binMultiply(ans, a);
        }
        a = binMultiply(a, a);
        b >>= 1;
    }
    return ans;
}

int main()
{
    int a = 212312345, b = 1231231;
    cout << binExpBigA(a, b) << endl;
    cout << binExpBigM(34758, b) << endl;
    // cout << pow(a, b);
}

/* correct

#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
long long int M2 = (long long)1e18 + 7; // your way (forced cast)

// big A
int binExpBigA(int a, int b)
{
    a %= M;
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
            ans = (ans * 1LL * a) % M;

        a = (a * 1LL * a) % M;
        b >>= 1;
    }
    return ans;
}

// big multiply
long long binMultiply(long long a, long long b)
{
    long long ans = 0;
    a %= M2;

    while (b > 0)
    {
        if (b & 1)
            ans = (ans + a) % M2;

        a = (a + a) % M2;
        b >>= 1;
    }
    return ans;
}

// big M
long long binExpBigM(long long a, long long b)
{
    long long ans = 1;
    a %= M2;

    while (b > 0)
    {
        if (b & 1)
            ans = binMultiply(ans, a);

        a = binMultiply(a, a);
        b >>= 1;
    }
    return ans;
}

int main()
{
    int a = 212312345, b = 1231231;

    cout << binExpBigA(a, b) << endl;
    cout << binExpBigM(34758, b) << endl;
}

*/