#include <bits/stdc++.h>
using namespace std;
set<vector<int>> s;
void getPermute(int i, vector<int> &nums, vector<vector<int>> &r)
{
    if (i == nums.size())
    {
        if (s.find(nums) == s.end())
        {
            r.push_back(nums);
            s.insert(nums);
        }
    }
    for (int idx = i; idx < nums.size(); idx++)
    {
        swap(nums[idx], nums[i]);
        getPermute(i + 1, nums, r);
        swap(nums[idx], nums[i]);
    }
}
vector<vector<int>> permuteUnique(vector<int> &nums)
{
    vector<vector<int>> r;
    getPermute(0, nums, r);
    return r;
}