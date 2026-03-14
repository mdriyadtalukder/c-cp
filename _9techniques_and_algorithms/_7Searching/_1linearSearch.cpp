// it works for sorted and unsorted both array..
// TC=O(n);

// find index of a element
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int x;
    cin >> x;

    for (int i = 0; i < n; i++)
    {
        if (v[i] == x)
        {
            cout << i;
            return 0;
        }
    }

    cout << -1;
}