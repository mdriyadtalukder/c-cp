#include <bits/stdc++.h>
using namespace std;

// brute force
int removeElement(vector<int> &nums, int val)
{
    vector<int> v;

    for (int i : nums)
    {
        if (i != val)
        {
            v.push_back(i);
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        nums[i] = v[i];
    }

    return v.size();
}

// optimal
int removeElement(vector<int> &nums, int val)
{
    int k = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != val)
            nums[k++] = nums[i];
    }
    return k;
}

int main()
{
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;

    removeElement(nums, val);

    return 0;
}