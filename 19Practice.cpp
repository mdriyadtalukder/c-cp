#include <bits/stdc++.h>
using namespace std;

int main()
{

    int x;
    cin >> x;
    while (x--)
    {
        int n, c, c1 = 0;
        cin >> n >> c;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        for (int i = 1; i < n; i++)
        {
            if (v[i - 1] > v[i])
            {
                c1++;
            }
        }

        if (c > c1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}