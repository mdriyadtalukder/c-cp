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
        int max = INT_MIN;
        vector<int> v(n);

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        while (v.size() > 1)
        {
            vector<int> v2;

            for (int j = 0; j < (int)v.size() - 1; j++)
            {
                v2.push_back(v[j] ^ v[v.size() - 1]);
                
            }

            v = v2;
        }

        cout << v[0] << endl;
    }
}