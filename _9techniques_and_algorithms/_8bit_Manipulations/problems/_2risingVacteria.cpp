#include <bits/stdc++.h>
using namespace std;
int countSetBits(int n) // ekta binary num te koita 1 ase
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}
int main()
{
    int n = 5;
    cout << countSetBits(n) << endl;
    return 0;
}