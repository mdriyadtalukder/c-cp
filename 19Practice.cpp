#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 0100101;
    vector<int> v(7);
    while (n != 0)
    {
        v.push_back(n % 10);
        n = n / 10;
    }
    reverse(v.begin(), v.end());
    for (int i : v)
    {
        cout << i << " ";
    }
}