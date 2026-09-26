
#include <bits/stdc++.h>
using namespace std;

// brute force
set<vector<int>> s;

void getPerms(vector<int> &nums, int idx, vector<vector<int>> &ans)
{
    if (idx == nums.size())
    {
        if (s.find(nums) == s.end())
        {
            ans.push_back(nums);
            s.insert(nums);
        }
        return;
    }

    for (int i = idx; i < nums.size(); i++)
    {
        swap(nums[idx], nums[i]);
        getPerms(nums, idx + 1, ans);
        swap(nums[idx], nums[i]); // backtracking
    }
}

void nextPermutation(vector<int> &nums)
{
    vector<vector<int>> ans;

    getPerms(nums, 0, ans);

    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] == nums)
        {
            if (i == ans.size() - 1)
            {
                nums = ans[0];
            }
            else
            {
                nums = ans[i + 1];
            }
            break;
        }
    }
}

// optimal
void nextPermutation(vector<int> &nums)
{
    int n = nums.size();

    // 1. Find the gola_index
    int gola_index = -1;

    for (int i = n - 1; i > 0; i--)
    {
        if (nums[i] > nums[i - 1])
        {
            gola_index = i - 1;
            break;
        }
    }

    // 2. If gola exists
    if (gola_index != -1)
    {
        // 3. Find the number just greater than nums[gola_index]
        int swap_index = gola_index;

        for (int j = n - 1; j > gola_index; j--)
        {
            if (nums[j] > nums[gola_index])
            {
                swap_index = j;
                break;
            }
        }

        // 4. Swap gola with that number
        swap(nums[gola_index], nums[swap_index]);
    }

    // 5. Reverse the part after gola
    reverse(nums.begin() + gola_index + 1, nums.end()); // we want to reverse after gola_index index..so gola_index+1;
}

int main()
{

    vector<int> nums = {1, 1, 5};

    nextPermutation(nums);

    return 0;
}