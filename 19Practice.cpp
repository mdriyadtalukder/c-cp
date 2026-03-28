#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long x;
    cin >> x;
    while (x--)
    {
        long long n, sum = 0;
        cin >> n;
        vector<long long> v(n);
        for (long long i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        for (long long i = 0; i < n; i++)
        {
            sum += v[i];
        }
        if (sum % 2 != 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}