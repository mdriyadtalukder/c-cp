#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while (tc--)
    {
        int n, k;
        cin >> n >> k;

        for (int i = 0; i < k; i++)
        {
            int x;
            cin >> x;
        }

        vector<pair<int, int>> v(n);

        for (int i = 0; i < n; i++)
        {
            int l;
            cin >> l;
            v[i] = {l, i};
        }

        sort(v.rbegin(), v.rend());

        vector<int> ops;

        for (int i = 0; i < n; i++)
        {
            for (; v[i].first < k + 1; v[i].first++)
            {
                ops.push_back(v[i].second);
            }
        }

        cout << ops.size() << "\n";

        for (auto &x : ops)
            cout << x + 1 << " ";

        cout << "\n";
    }
}