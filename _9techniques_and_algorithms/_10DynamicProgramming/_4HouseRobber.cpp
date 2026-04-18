// house ase..tar vitorer value holo tar vitorer taka..ami j kono ghore churi krte pari
// but jdi adjancy(pasher ta) house e churi kri tahole alarm vajbe o police ashbe
// max koto tk churi krte parbo from all possible solution
//[1,2,3.4]--4 no ghor theke tk churi krle kon kon ghore churi krte parbo next r jdi na churi kri then kon kon ghore churi krte parbo next
// eivbe tree banabo for all.
#include <bits/stdc++.h>
using namespace std;
// top down--recursion with from top elem to dowm
int Robber(int index, vector<int> &nums, vector<int> &dp)
{
    if (index == 0)
        return nums[0];

    if (index < 0)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    return dp[index] = max(
               nums[index] + Robber(index - 2, nums, dp), // pick
               Robber(index - 1, nums, dp)                // not pick
           );
}
int rob(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    return Robber(n - 1, nums, dp);

    /*
    bootom up
    int rob(vector<int>& nums)
{
    int n = nums.size();

    if (n == 1)
        return nums[0];

    if (n == 2)
        return max(nums[0], nums[1]);

    vector<int> dp(n, -1);

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++)
    {
        dp[i] = max(
            nums[i] + dp[i - 2], // pick
            dp[i - 1]            // not pick
        );
    }

    return dp[n - 1];
}
*/

    /*
    space optimizing
    int n = nums.size();

        if (n == 1) return nums[0];
        if (n == 2)
        return max(nums[0], nums[1]);

        int prev2 = nums[0];
        int prev = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++)
        {
            int curr = max(nums[i] + prev2, prev);
            prev2 = prev;
            prev = curr;
        }

        return prev;
    */
}