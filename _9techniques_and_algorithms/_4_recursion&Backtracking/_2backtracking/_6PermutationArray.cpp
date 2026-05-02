#include <bits/stdc++.h>
using namespace std;
// TC=O(n!*n)
void getPerms(vector<int> &nums, int idx, vector<vector<int>> &ans)
{
    if (idx == nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for (int i = idx; i < nums.size(); i++)
    {
        swap(nums[idx], nums[i]);
        getPerms(nums, idx + 1, ans);
        swap(nums[idx], nums[i]); // backtracking
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    getPerms(nums, 0, ans);
    return ans;
}

int main()
{
    vector<int> v = {1, 2, 3};
    vector<vector<int>> r = permute(v);

    for (auto i : r)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}