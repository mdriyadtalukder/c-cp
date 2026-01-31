#include <bits/stdc++.h>
using namespace std;
// tc=sc=O(n);
bool sorted(vector<int> v, int n)
{
    if (n == 0 || n == 1)
    {
        return true;
    }
    return v[n - 1] >= v[n - 2] && sorted(v, n - 1);
}
int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    cout << sorted(v, v.size());
}