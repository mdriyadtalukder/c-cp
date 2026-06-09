#include <bits/stdc++.h>
using namespace std;
// TC=O(n*2^n); --n size array and tree

void getAllSubsets(vector<int> &nums, vector<int> &ans, int i, vector<vector<int>> &allSubsets)
{
    if (i == nums.size())
    {
        allSubsets.push_back(ans);
        return;
    }

    // include current element
    ans.push_back(nums[i]);
    getAllSubsets(nums, ans, i + 1, allSubsets);

    // backtrack (remove last element)
    ans.pop_back();

    // exclude current element
    getAllSubsets(nums, ans, i + 1, allSubsets);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> allSubsets;
    vector<int> ans;

    getAllSubsets(nums, ans, 0, allSubsets);

    return allSubsets;
}

int main()
{
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = subsets(nums);

    for (auto &subset : result)
    {
        cout << "[ ";
        for (int x : subset)
        {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}