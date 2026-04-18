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