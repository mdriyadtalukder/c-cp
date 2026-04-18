#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    cin >> x;
    while (x--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int max = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (max < v[i])
            {
                max = v[i];
            }
        }
        cout << max << endl;
    }
}