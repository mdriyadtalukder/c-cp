#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    int k = 0,j=3;

    while (j--)
    {
       for (int i = 0; i < v.size(); i++)
    {
        if (i == 0)
        {
            k = v[i];
            v[i] = v[v.size() - 1];
        }
        else
        {
            int m = v[i];
            v[i] = k;
            k = m;
        }
    }
    }
    

    for (int k : v)
    {
        cout << k << endl;
    }
}