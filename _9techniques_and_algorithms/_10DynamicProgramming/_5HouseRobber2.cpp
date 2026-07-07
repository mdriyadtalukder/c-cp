// same just circle form e ase house.so 1st and last index adjancy hbe..
// 2ta array nibo.ektai 0-n-1 r ektai 1-n porjonto value nibo of main array
#include <bits/stdc++.h>
using namespace std;
// solution-1: --space optimizing
int Robbery(vector<int> &nums)
{
    int n = nums.size();

    if (n == 1)
        return nums[0];
    if (n == 2)
        return max(nums[0], nums[1]);

    int prev2 = nums[0];
    int prev1 = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++)
    {
        int curr = max(nums[i] + prev2, prev1);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}
int rob(vector<int> &nums)
{
    int n = nums.size();

    if (n == 1)
        return nums[0];

    vector<int> arr1(n - 1), arr2(n - 1);

    // exclude last
    for (int i = 0; i < n - 1; i++)
        arr1[i] = nums[i];

    // exclude first
    for (int i = 1; i < n; i++)
        arr2[i - 1] = nums[i];

    int curr1 = Robbery(arr1);
    int curr2 = Robbery(arr2);

    return max(curr1, curr2);
}

// soulution-2: most optimized solution--- space-O(1)
int rob2(vector<int> &nums)
{
    int n = nums.size();

    if (n == 1)
        return nums[0];
    if (n == 2)
        return max(nums[0], nums[1]);

    // Case 1: exclude last house (0 → n-2)
    int prev2 = nums[0];
    int prev1 = max(nums[0], nums[1]);
    int curr1 = prev1;

    for (int i = 2; i < n - 1; i++)
    {
        curr1 = max(nums[i] + prev2, prev1);
        prev2 = prev1;
        prev1 = curr1;
    }

    // Case 2: exclude first house (1 → n-1)
    prev2 = nums[1];
    prev1 = max(nums[1], nums[2]);
    int curr2 = prev1;

    for (int i = 3; i < n; i++)
    {
        curr2 = max(nums[i] + prev2, prev1);
        prev2 = prev1;
        prev1 = curr2;
    }

    return max(curr1, curr2);
}

/*
213. House Robber II

Problem Statement:

You are a professional robber planning to rob
houses along a street.

Unlike House Robber I,
the houses are arranged in a circle.

This means:

- The first house and the last house
  are adjacent.

You cannot rob two adjacent houses.

Return the maximum amount of money
you can rob without triggering the alarm.

------------------------------------------------

Example 1:

Input:

nums = [2,3,2]

Output:

3

Explanation:

You cannot rob both
house 1 and house 3.

Best choice:

Rob house 2.

Money = 3

------------------------------------------------

Example 2:

Input:

nums = [1,2,3,1]

Output:

4

Explanation:

Case 1:
Exclude last house.

[1,2,3]

Maximum = 4

Case 2:
Exclude first house.

[2,3,1]

Maximum = 3

Answer = max(4,3) = 4

------------------------------------------------

Example 3:

Input:

nums = [1,2,3]

Output:

3

Explanation:

Rob only house 3.

------------------------------------------------

Constraints:

1 <= nums.length <= 100

0 <= nums[i] <= 1000

------------------------------------------------

Approaches:

1. Top-Down DP
   Time  : O(N)
   Space : O(N)

2. Bottom-Up DP
   Time  : O(N)
   Space : O(N)

3. Space Optimized DP
   Time  : O(N)
   Space : O(1)

------------------------------------------------

Key Observation:

Since the first and last houses
are adjacent,

they cannot both be robbed.

So solve two separate problems:

Case 1:

Rob houses from

0 → n-2

(Exclude last house)

Case 2:

Rob houses from

1 → n-1

(Exclude first house)

Answer:

max(case1, case2)

------------------------------------------------

DP State:

dp[i] = Maximum money that can be robbed
up to house i.

Transition:

dp[i] = max(

nums[i] + dp[i-2],   // Pick

dp[i-1]              // Not Pick

)

Base Cases:

dp[0] = nums[0]

dp[1] = max(nums[0], nums[1])

Answer:

max(
HouseRobber(0...n-2),
HouseRobber(1...n-1)
)
*/
// int rob(vector<int> &nums)
