#include <bits/stdc++.h>
using namespace std;
vector<int> singleNumber(vector<int> &nums)
{
    // Step 1: XOR all numbers
    int xor_val = 0;
    for (int num : nums)
    {
        xor_val ^= num;
    }

    // Step 2: Find rightmost set bit
    // int diff = xor_val & (-xor_val);
    unsigned int diff = (unsigned int)xor_val & (-(unsigned int)xor_val);

    // Step 3: Separate into two groups and XOR
    vector<int> result(2, 0);
    for (int num : nums)
    {
        if ((num & diff) == 0)
        {
            result[0] ^= num; // Group 0
        }
        else
        {
            result[1] ^= num; // Group 1
        }
    }

    return result;
}
