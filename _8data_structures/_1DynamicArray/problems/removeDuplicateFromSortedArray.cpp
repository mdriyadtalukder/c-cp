
#include <bits/stdc++.h>
using namespace std;

// brute force
int removeDuplicates(vector<int> &nums)
{
    map<int, int> m;

    for (auto &n : nums)
    {
        m[n]++;
    }

    int j = 0;

    for (auto &i : m)
    {
        while (i.second > 2)
        {
            i.second--;
        }
    }

    for (auto &i : m)
    {
        while (i.second > 0)
        {
            nums[j++] = i.first;
            i.second--;
        }
    }

    return j;
}

// optimal
int removeDuplicates(vector<int> &nums)
{
    if (nums.size() <= 2)
        return nums.size();

    // First two elements are always valid
    int writePos = 2;

    for (int i = 2; i < nums.size(); i++)
    {
        // Compare with element two positions back in result
        if (nums[i] != nums[writePos - 2])
        {
            nums[writePos] = nums[i];
            writePos++;
        }
    }

    return writePos;
}
int main()
{

    vector<int> nums = {1, 1, 1, 2, 2, 3};

    removeDuplicates(nums);

    return 0;
}