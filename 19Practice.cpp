#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, y, z, count = 0;
    bool b = true;
    map<string, int> m;
    cin >> x >> y >> z;
    m["x"] = x * 1;
    m["y"] = y * 2;
    m["z"] = z * 3;

    for (int i = 0; b; i++)
    {
        b = false;
        if (m["x"] > 0 && m["z"] > 2)
        {
            m["x"] -= 1;
            m["z"] -= 3;
            count++;
            b = true;
        }
        else if (m["x"] > 1 && (m["y"] > 1 && m["z"] == 0))
        {
            m["x"] -= 2;
            m["y"] -= 2;
            count++;
            b = true;
        }
        else if (m["x"] <= 1 && m["y"] > 3 && m["z"] == 0)
        {
            m["y"] -= 4;
            count++;
            b = true;
        }
    }
    cout << count;
}