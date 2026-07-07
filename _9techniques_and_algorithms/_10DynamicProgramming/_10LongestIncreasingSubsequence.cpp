// increase hocce number emn subsequnce length
//[10,9,2,5,3,7,101,18]--2,5,7,18 or 2,5,7,101..emn kre possible ans ber krbo and height length dibo..eikhne max size 4.
#include <bits/stdc++.h>
using namespace std;

int rec(int currIndex, int prevIndex, int n, vector<int> &nums, vector<vector<int>> &dp)
{
    // base case
    if (currIndex == n)
        return 0;

    if (dp[currIndex][prevIndex + 1] != -1)
    {
        return dp[currIndex][prevIndex + 1];
    }

    // not take
    int not_take = rec(currIndex + 1, prevIndex, n, nums, dp); // na nile cur ta cur+1 hbe

    // take
    int take = INT_MIN;
    if (prevIndex == -1 || nums[currIndex] > nums[prevIndex])
    {
        take = 1 + rec(currIndex + 1, currIndex, n, nums, dp); // nile 1+(cur ta cur+1 hbe and pre ta cur hbe)..
    }

    return dp[currIndex][prevIndex + 1] = max(not_take, take);
}

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();

    // dp[currIndex][prevIndex+1]
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    return rec(0, -1, n, nums, dp);
}

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    cout << lengthOfLIS(nums) << endl;

    return 0;
}
/*
space optimzed version
#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();

    vector<int> next(n + 1, 0), curr(n + 1, 0);

    for (int currIndex = n - 1; currIndex >= 0; currIndex--)
    {
        for (int prevIndex = currIndex - 1; prevIndex >= -1; prevIndex--)
        {
            int notTake = next[prevIndex + 1];

            int take = 0;
            if (prevIndex == -1 || nums[currIndex] > nums[prevIndex])
            {
                take = 1 + next[currIndex + 1];
            }

            curr[prevIndex + 1] = max(take, notTake);
        }

        next = curr;
    }

    return next[0];
}

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    cout << lengthOfLIS(nums) << endl;
}
*/