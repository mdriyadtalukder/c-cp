#include <bits/stdc++.h>
using namespace std;
bool isDouble(string s)
{
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int x;
    cin >> x;

    while (x--)
    {
        string s;
        cin >> s;
        string sl = s, sl2 = s, sl3 = s;
        int k = 0, k2 = 0;
        for (int i = 1; i < s.size(); i++)
        {
            if (sl[i] == sl[i - 1])
            {
                k = i;
            }
        }
        reverse(sl.begin() + k, sl.end());
        for (int i = 1; i < s.size(); i++)
        {
            if (sl2[i] == sl2[i - 1])
            {
                k2 = i - 1;
            }
        }
        int temp = sl2[k], temp2 = sl2[k + 1];
        sl2[k] = temp2;
        sl2[k + 1] = temp;
        if (sl3[k] == 'b')
        {
            sl3[k] = 'a';
        }
        else
        {
            sl3[k] = 'b';
        }
        if (isDouble(sl) || isDouble(sl2) || isDouble(sl3))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}