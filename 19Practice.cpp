#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    bool a = true;
    int n;
    map<char, int> m;

    cin >> n;
    cin.ignore();
    cin >> s;

    for (int i = 0; i < n; i++)
    {
        s[i] = tolower(s[i]);

        m[s[i]] += 1;
    }
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        if (m[ch] == 0)
        {
            a = false;
            break;
        }
    }
    if (a)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
