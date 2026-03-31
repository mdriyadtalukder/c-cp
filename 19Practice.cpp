#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin >> x;
    while (x--)
    {
        int y, z;
        string a, b, c;
        cin >> y >> a >> z >> b >> c;

        for (int i = 0; i < c.length(); i++)
        {
            if (c[i] == 'D')
            {
                a.push_back(b[i]);
            }
            else
            {
                a.insert(0, string(1, b[i]));
            }
        }
        cout << a << endl;
    }
}