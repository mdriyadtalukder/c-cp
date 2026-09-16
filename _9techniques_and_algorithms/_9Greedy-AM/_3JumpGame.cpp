#include <bits/stdc++.h>
using namespace std;

// brute force (DP)
bool solve(vector<int> &nums, int i, vector<int> &dp)
{
    if (i == nums.size() - 1)
        return true;
    if (dp[i] != -1)
        return dp[i];
    for (int j = 1; j <= nums[i]; j++) // j=0 hbe na coz min jump 1 for a max jump
    {
        if (solve(nums, i + j, dp) == true)
            return dp[i] = true;
    }
    return dp[i] = false;
}
bool canJump(vector<int> &nums)
{
    vector<int> dp(nums.size() + 1, -1);
    return solve(nums, 0, dp);
}

// optimal(greedy)
bool canJump2(vector<int> &nums)
{
    int maxR = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > maxR)
            return false;
        maxR = max(maxR, i + nums[i]);
    }
    return true;
}

// main
int main()
{

    vector<int> nums = {2, 3, 1, 1, 4};

    cout << canJump(nums) << endl;

    return 0;
}