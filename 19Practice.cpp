#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<int> v;
    int c = 0;
    bool b = false;

    for (int i = 0; i < s.length(); i++)
    {
        if (b)
        {
            c = 0;
            b = false;
        }
        if (s[i] == '-')
        {
            c++;
        }
        if (c == 2)
        {
            v.push_back(c);
            b = true;
        }
        if (c == 1 && s[i] == '.')
        {
            v.push_back(c);
            b = true;
        }
        if (c == 0 && s[i] == '.')
        {

            v.push_back(c);
            b = true;
        }
    }

    for (int n : v)
    {
        cout << n;
    }
    cout << endl;
}