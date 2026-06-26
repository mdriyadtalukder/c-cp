#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[6] = {5, 3, 2, 6, 3, 1};
    int sum = 0, total = 0, suffix;
    for (int i : a)
    {
        total += i;
    }
    for (int i = 0; i < 6; i++)
    {
        sum += a[i];
        suffix = total - sum;
        if (suffix - a[i] == sum - a[i])
        {
            cout << "True";
            // return true;
        }
    }

    return 0;
}