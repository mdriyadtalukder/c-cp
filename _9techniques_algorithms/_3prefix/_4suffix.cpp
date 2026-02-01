#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[6] = {2, 1, 4, 5, 66, 3};
    for (int i = 4; i >= 0; i--) // ar.length-2
    {
        a[i] = a[i] + a[i + 1];
    }
    for (int i : a)
    {
        cout << i << " ";
    }

    return 0;
}