// ekta array thkbe take 2 vag krbo..emn vabe krbo jate 2 part er sum same hy..sequence lagbe na..just take any elem from array and vag kro emn vabe j 2 tar sum soman hy
// total sum even hote hbe as we can divide into 2 vag..odd hole return false hbe

// Partition Equal Subset Sum
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

/*space optimized

#include <bits/stdc++.h>
using namespace std;

bool canPartition(vector<int> &nums)
{
    int totalSum = 0;
    for (int x : nums)
        totalSum += x;

    if (totalSum % 2)
        return false;

    int target = totalSum / 2;

    vector<bool> dp(target + 1, false);

    dp[0] = true; // Sum 0 is always possible

    for (int num : nums)
    {
        // Traverse backwards (0/1 Knapsack)
        for (int j = target; j >= num; j--)
        {
            dp[j] = dp[j] || dp[j - num];
        }
    }

    return dp[target];
}

int main()
{
    vector<int> nums = {1, 5, 11, 5};

    cout << canPartition(nums) << endl; // 1

    return 0;
}*/

//bool canPartition(vector<int> &nums)
/*
416. Partition Equal Subset Sum

Problem Statement:

You are given an integer array nums.

Return true if the array can be
partitioned into two subsets such that
the sum of elements in both subsets
is equal.

Otherwise return false.

------------------------------------------------

Example 1:

Input:

nums = [1,5,11,5]

Output:

true

Explanation:

Subset 1:

[1,5,5]

Sum = 11

Subset 2:

[11]

Sum = 11

Both subsets have equal sum.

------------------------------------------------

Example 2:

Input:

nums = [1,2,3,5]

Output:

false

Explanation:

Total sum = 11

Since the total sum is odd,

it cannot be divided equally.

------------------------------------------------

Constraints:

1 <= nums.length <= 200

1 <= nums[i] <= 100

------------------------------------------------

Approaches:

1. Simple Recursion
   Time  : O(2^N)

2. Top-Down DP (Memoization)
   Time  : O(N × Target)
   Space : O(N × Target)

3. Bottom-Up DP (Tabulation)
   Time  : O(N × Target)
   Space : O(N × Target)

4. Space Optimized DP
   Time  : O(N × Target)
   Space : O(Target)

------------------------------------------------

Key Observation:

If total sum is odd,

answer is always false.

Otherwise,

target = totalSum / 2

Now the problem becomes:

Can we select some elements
whose sum equals target?

This is exactly the
Subset Sum (0/1 Knapsack)
problem.

------------------------------------------------

DP State:

dp[i][sum]

=

Can we make the current sum
using elements from index i onward?

------------------------------------------------

Transition:

Not Take:

dp[i+1][sum]

Take:

dp[i+1][sum + nums[i]]

Answer:

Take OR Not Take

------------------------------------------------

Base Case:

When all elements are processed:

Return

(sum == target)

------------------------------------------------

Answer:

true

if target sum is possible,

otherwise

false.
*/