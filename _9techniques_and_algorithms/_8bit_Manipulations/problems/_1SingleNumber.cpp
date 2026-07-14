#include <bits/stdc++.h>
using namespace std;
int singleNumber(vector<int> &nums)
{
    int result = 0;

    // XOR all elements; duplicates cancel out
    for (int num : nums)
    {
        result ^= num;
    }

    return result;
}
