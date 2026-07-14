#include <bits/stdc++.h>
using namespace std;
int countSetBits(int n) // ekta binary num te koita 1 ase
{
    int count = 0;
    for (int i = 31; i >= 0; --i) // 10 er binary te koita set ase r koita unset ase ta count krbe
    {
        if ((n & (1 << i)) != 0)
        {
            count++;
        }
        // else
        // {
        //     unSetCount++;
        // }
    }
    return count;
}
int main()
{
    int n = 5;
    cout << countSetBits(n) << endl;
    return 0;
}