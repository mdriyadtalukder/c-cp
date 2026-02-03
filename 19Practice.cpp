#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a, b, sum = 0, r = 0;
    cin >> n;
    while (n--)
    {
        cin >> a >> b;
        sum = (sum - abs(a)) + b;
        if (sum > r)
        {
            r = sum;
        }
    }
    cout << r << endl;
}