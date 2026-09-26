#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findMissingRanges(vector<int> &nums, int lower, int upper)
{
    vector<vector<int>> result;
    int n = nums.size();

    if (n == 0)
    {
        result.push_back({lower, upper});
        return result;
    }

    // Gap before the first element
    if (lower < nums[0])
    {
        result.push_back({lower, nums[0] - 1});
    }

    // Gaps between consecutive elements
    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i + 1] - nums[i] > 1)
        {
            result.push_back({nums[i] + 1, nums[i + 1] - 1});
        }
    }

    // Gap after the last element
    if (nums[n - 1] < upper)
    {
        result.push_back({nums[n - 1] + 1, upper});
    }

    return result;
}

int main()
{

    vector<int> nums = {0, 1, 3, 50, 75};
    int lower = 0;
    int upper = 99;

    findMissingRanges(nums, lower, upper);

    return 0;
}