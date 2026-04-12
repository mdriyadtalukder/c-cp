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
        freq[nums[i]]++;
        windowSum += nums[i];

        int outVal = nums[i - k]; // minus krbe sei value
        if (--freq[outVal] == 0)  // eita jdi 1 tai thke tahole remove krbe from freq
            freq.erase(outVal);
        windowSum -= outVal;

        if (freq.size() == k)
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