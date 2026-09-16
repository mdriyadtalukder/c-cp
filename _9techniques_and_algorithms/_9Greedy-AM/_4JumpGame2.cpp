#include <bits/stdc++.h>
using namespace std;

// brute force (DP)
int solve(vector<int> &nums, int i, vector<int> &dp)
{
    if (i == nums.size() - 1)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int ans = INT_MAX;
    for (int j = 1; j <= nums[i] && i + j < nums.size(); j++) // j=0 hbe na coz min jump 1 for a max jump
    {
        if (solve(nums, i + j, dp) != INT_MAX)
            ans = min(ans, solve(nums, i + j, dp) + 1); // 1 add hyse coz eita total jumps = 1 + remaining jumps
    }
    return dp[i] = ans;
}
int Jump(vector<int> &nums)
{
    vector<int> dp(nums.size() + 1, -1);
    return solve(nums, 0, dp);
}

// optimal(greedy)
bool Jump2(vector<int> &nums)
{
    int n = nums.size();

    int jumps = 0;
    int l = 0;
    int r = 0;

    while (r < n - 1)
    {
        int farthest = 0;

        for (int ind = l; ind <= r; ind++)
        {
            farthest = max(ind + nums[ind], farthest);
        }

        l = r + 1;
        r = farthest;
        jumps++;
    }

    return jumps;
}

// main
int main()
{

    vector<int> nums = {2, 3, 1, 1, 4};

    cout << Jump(nums) << endl;

    return 0;
}