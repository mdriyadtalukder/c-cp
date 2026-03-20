#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin >> x;
    while (x--)
    {
        int a, b, c, cn = 0;
        cin >> a >> b >> c;
        if (a + b >= 10 || a + c >= 10 || b + c >= 10)
        {
            cn++;
        }
        if (cn > 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}