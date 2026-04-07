#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    cin >> x;
    while (x--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        if (n > 1)
        {
            for (int i = 0; i < n; i++)
            {
                v[i] = k;
            }
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum += v[i];
            }
            if ((sum + 1) % 2 == 0)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
        else
        {
            cout << "YES" << endl;
        }
    }
}