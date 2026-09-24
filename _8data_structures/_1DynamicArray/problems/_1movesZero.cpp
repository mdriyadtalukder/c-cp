#include <bits/stdc++.h>
using namespace std;

// brute force
void moveZeroes(vector<int> &nums)
{
    vector<int> v;
    int c = 0;
    for (int n : nums)
    {
        if (n != 0)
        {
            v.push_back(n);
            c++;
        };
    }
    for (int i = c; i < nums.size(); i++)
    {
        v.push_back(0);
    }
    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] = v[i];
    }
}

// optimal
void moveZeroes2(vector<int> &nums)
{
    for (int i = 0, j = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            j++;
        }
    }
}

int main()
{

    vector<int> nums = {1, 2, 3, 0, 5, 0, 6, 0, 2};
    moveZeroes(nums);

    return 0;
}