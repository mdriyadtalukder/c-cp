#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h = 0, c = 0, n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (v[i] == -1)
        {
            if (h == 0)
            {
                c++;
            }
            else
            {
                h--;
            }
        }
        else
        {
            h += v[i];
        }
    }
    cout << c << endl;
}