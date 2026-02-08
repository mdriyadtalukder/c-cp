#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v(4);
    int c = 0;
    for (int i = 0; i < 4; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            if (v[i] == v[j] && v[i] > 0)
            {
                v[j] = -1;
                c++;
            }
        }
    }
    cout << c << endl;
}