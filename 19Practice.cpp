#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin >> x;
    while (x--)
    {
        int n;
        bool b = false;
        cin >> n;
        string s, s2;
        cin >> s >> s2;
        for (int i = 0; i < n; i++)
        {
            if ((s[i] == 'G' && s2[i] == 'B') || (s[i] == 'B' && s2[i] == 'G') || s[i] == s2[i])
            {
                b = false;
            }
            else
            {
                b = true;
                break;
            }
        }
        if (b)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
}