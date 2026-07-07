
#include <bits/stdc++.h>
using namespace std;
// top down--recursion with from top elem to dowm
int Robber(int index, vector<int> &nums, vector<int> &dp)
{
    if (index == 0)
        return nums[0];

    if (index == 1)
        return max(nums[0], nums[1]); // 2 ta thkle jeta boro oita return krbo

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
//1st e base case likte hy in bottom up
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

// house ase..tar vitorer value holo tar vitorer taka..ami j kono ghore churi krte pari
// but jdi adjancy(pasher ta) house e churi kri tahole alarm vajbe o police ashbe
// max koto tk churi krte parbo from all possible solution
//[1,2,3.4]--4 no ghor theke tk churi krle kon kon ghore churi krte parbo next r jdi na churi kri then kon kon ghore churi krte parbo next
// eivbe tree banabo for all.
/*
198. House Robber

Problem Statement:

You are a professional robber planning to rob
houses along a street.

Each house contains a certain amount of money.

The only constraint is:

You cannot rob two adjacent houses,
otherwise the alarm system will be triggered.

Return the maximum amount of money
you can rob without triggering the alarm.

------------------------------------------------

Example 1:

Input:

nums = [1,2,3,1]

Output:

4

Explanation:

Rob house 1 (1)

Skip house 2

Rob house 3 (3)

Total = 1 + 3 = 4

------------------------------------------------

Example 2:

Input:

nums = [2,7,9,3,1]

Output:

12

Explanation:

Rob house 1 (2)

Skip house 2

Rob house 3 (9)

Skip house 4

Rob house 5 (1)

Total = 2 + 9 + 1 = 12

------------------------------------------------

Example 3:

Input:

nums = [5]

Output:

5

Explanation:

Only one house exists.

------------------------------------------------

Constraints:

1 <= nums.length <= 100

0 <= nums[i] <= 400

------------------------------------------------

Approaches:

1. Simple Recursion
   Time  : O(2^N)
   Space : O(N)

2. Top-Down DP (Memoization)
   Time  : O(N)
   Space : O(N)

3. Bottom-Up DP (Tabulation)
   Time  : O(N)
   Space : O(N)

4. Space Optimized DP
   Time  : O(N)
   Space : O(1)

------------------------------------------------

DP State:

dp[i] = Maximum money that can be robbed
from houses 0 to i.

Transition:

dp[i] = max(

    nums[i] + dp[i-2],   // Pick current house

    dp[i-1]              // Skip current house

)

Base Cases:

dp[0] = nums[0]

dp[1] = max(nums[0], nums[1])

Answer:

dp[n-1]
*/
// int rob(vector<int> &nums)
