#include <bits/stdc++.h>
using namespace std;
// every 0 er rage count kre then oi count*2-1  krbo..every zero er subarray zero like 000 ekhne 2 ta 00,2 ta 0 o 1 ta 000 subarray ase..
int main()
{
    vector<int> v = {1, 3, 0, 0, 2, 0, 0, 4};

    long long c = 0, r = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 0)
        {
            c++;
        }
        else
        {
            r += (c * (c + 1)) / 2; //(c*2)-1
            c = 0;
        }
    }

    // handle last zero segment (if array ends with 0)
    r += (c * (c + 1)) / 2;

    cout << r;

    return 0;
}