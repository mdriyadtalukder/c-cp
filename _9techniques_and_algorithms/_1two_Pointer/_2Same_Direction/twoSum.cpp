#include <bits/stdc++.h>
using namespace std;
// brute force

vector<int> twoSum(vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {};
}

// optimal
vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++)
    {
        int complement = target - nums[i];

        // Check if complement was seen before
        if (map.count(complement))
        {
            return {map[complement], i};
        }

        // Store current value and its index
        map[nums[i]] = i;
    }

    return {};
}
