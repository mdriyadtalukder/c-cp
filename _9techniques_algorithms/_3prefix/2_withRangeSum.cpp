#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[6] = {0, 1, 2, 3, 4, 5};
    for (int i = 1; i < 6; i++)
    {
        a[i] = a[i] + a[i - 1];
    }
    int l = 1, r = 5, sum;
    sum = a[r] + a[l - 1];
    cout << sum;

    return 0;
}