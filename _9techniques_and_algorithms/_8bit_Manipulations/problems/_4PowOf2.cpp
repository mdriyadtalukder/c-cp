#include <bits/stdc++.h>
using namespace std;
//n negative num ba 0 hole false hbe..
bool isPowerOfTwo(int n)
{
    if (n <= 0)
        return false;

    if (n & (n - 1))
    {
        return false;
    }

    return true;
}