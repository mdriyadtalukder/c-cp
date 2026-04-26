#include <bits/stdc++.h>
using namespace std;

/*
Given array a of n integers. All integers
are present in even count except one.
Find that one integer which has odd count
in O(N) time complexity and O(1) space;

N < 10^5
a[i] < 10^5
*/

int main()
{
    vector<int> a = {1, 2, 3, 2, 1, 3, 3}; // example

    int xr = 0; // using XOR

    for (int i = 0; i < a.size(); i++)
    {
        xr ^= a[i];
    }

    cout << xr << endl; // element with odd count

    return 0;
}