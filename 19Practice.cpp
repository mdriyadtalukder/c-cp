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
        string s;
        cin >> s;
        stack<char> st;
        for (auto &l : s)
        {
            l = tolower(l);
        }
        int m = 0, e = 0, o = 0, w = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'm')
            {
                m++;
            }
            if (s[i] == 'e')
            {
                e++;
            }
            if (s[i] == 'o')
            {
                o++;
            }
            if (s[i] == 'w')
            {
                w++;
            }
        }
        if (m > 0 && e > 0 && o > 0 && w > 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (!st.empty())
                {
                    if ((st.top() == 'm' && (s[i] == 'm' || s[i] == 'e')) || (st.top() == 'e' && (s[i] == 'e' || s[i] == 'o')) || (st.top() == 'o' && (s[i] == 'o' || s[i] == 'w')) || (st.top() == 'w' && (s[i] == 'w')))
                    {
                        b = false;
                    }
                    else
                    {
                        b = true;
                        break;
                    }
                }
                st.push(s[i]);
            }
        }
        else
        {
            b = true;
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