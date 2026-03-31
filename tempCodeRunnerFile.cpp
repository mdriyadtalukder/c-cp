#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin >> x;
    while (x--)
    {
        int n, c = 0;
        cin >> n;
        vector<int> v(n + 1), v2(n + 1, 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
        };
        for (int i = 1; i <= n; i++)
        {
            if (v2[i] == -1)
            {
                break;
            }
            v2[v[i]] = -1;
            c++;
        }
        cout << c << endl;
    }
}