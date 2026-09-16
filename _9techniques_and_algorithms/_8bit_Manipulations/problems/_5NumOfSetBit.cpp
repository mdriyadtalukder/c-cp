#include <bits/stdc++.h>
using namespace std;
// num of 1 bits
int hammingWeight(int n)
{
    int setCount = 0;
    for (int i = 31; i >= 0; --i)
    {
        if ((n & (1 << i)) != 0)
        {
            setCount++;
        }
    }
    return setCount;
}
