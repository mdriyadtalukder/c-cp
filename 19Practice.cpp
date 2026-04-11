#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin >> x;
    while (x--)
    {
        // 31415
        string s;
        cin >> s;
        int c = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if ((i == 0 && s[i] == '3') || (i == 1 && s[i] == '1') || (i == 2 && s[i] == '4') || (i == 3 && s[i] == '1') || (i == 4 && s[i] == '5'))
            {
                c++;
            }
            else
            {
                break;
            }
        }
        if (c == 5)
        {
            cout << s.length() << endl;
        }
        else
        {
            cout << c << endl;
        }
    }
}