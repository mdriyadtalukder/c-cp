#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long x;
    cin >> x;
    while (x--)
    {
        long long n;
        cin >> n;
        if (n % 2 == 0)
        {
            cout << (n / 2) - 1 << endl;
        }
        else
        {
            cout << n / 2 << endl;
        }
    }
}