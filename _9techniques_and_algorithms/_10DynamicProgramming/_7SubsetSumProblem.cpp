// ekta array thkbe take 2 vag krbo..emn vabe krbo jate 2 part er sum same hy..sequence lagbe na..just take any elem from array and vag kro emn vabe j 2 tar sum soman hy
// total sum even hote hbe as we can divide into 2 vag..odd hole return false hbe

//Partition Equal Subset Sum
#include <bits/stdc++.h>
using namespace std;

bool rec(int i, int sum, int totalSum, vector<int> &nums, vector<vector<int>> &dp)
{
    // base case
    if (i == nums.size())
    {
        return sum == totalSum / 2;
    }

    if (dp[i][sum] != -1)
        return dp[i][sum];

    // not take
    bool not_take = rec(i + 1, sum, totalSum, nums, dp);

    // take
    bool take = false;
    if (sum + nums[i] <= totalSum / 2)
    {
        take = rec(i + 1, sum + nums[i], totalSum, nums, dp);
    }

    return dp[i][sum] = not_take || take;
}

bool canPartition(vector<int> &nums)
{
    int totalSum = 0;
    for (auto &it : nums)
    {
        totalSum += it;
    }

    if (totalSum % 2 == 1)
        return false;

    int target = totalSum / 2;

    vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));

    return rec(0, 0, totalSum, nums, dp);
}

int main()
{
    vector<int> nums = {1, 5, 11, 5};

    cout << canPartition(nums) << endl; // 1 (true)

    return 0;
}