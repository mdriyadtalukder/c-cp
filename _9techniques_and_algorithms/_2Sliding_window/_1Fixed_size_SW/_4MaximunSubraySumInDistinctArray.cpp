#include <bits/stdc++.h>
using namespace std;

long long maximumSubarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> freq;
    long long windowSum = 0;
    long long maxSum = 0;

    for (int i = 0; i < k; i++)
    {
        freq[nums[i]]++;
        windowSum += nums[i];
    }

    if (freq.size() == k) // sob alada value hole k obdi e hbe
        maxSum = windowSum;

    for (int i = k; i < nums.size(); i++)
    {
        freq[nums[i]]++;                    // add new element into window
        if (--freq[nums[i - k]] == 0) // remove old element frequency
            freq.erase(nums[i - k]);  // if count becomes 0, erase from map
        windowSum += nums[i] - nums[i - k]; // add new, remove old from sum


        if (freq.size() == k) // means all k elements are distinct
            maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << maximumSubarraySum(nums, k) << endl;

    return 0;
}