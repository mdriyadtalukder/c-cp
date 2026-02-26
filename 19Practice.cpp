#include <bits/stdc++.h>
using namespace std;
//Monotonic Stack
int main()
{
    vector<int> v = {100, 80, 60, 70, 60, 75, 85}, v2;

    for (int i = 0; i < v.size(); i++)
    {
        int n = 0;
        for (int j = i; j >=0; j--)
        {
            if (v[j] <= v[i])
            {
                n++;
            }
            else
            {
                break;
            }
        }
        v2.push_back(n);
    }

    for (int ii : v2)
    {
        cout << ii << " ";
    }
}