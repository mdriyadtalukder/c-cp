#include <bits/stdc++.h>
using namespace std;

// brute force
int majorityElement(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
}

// optimal(Boyer-Moore Voting Algorithm)
int majorityElement2(vector<int> &nums)
{
    // Boyer-Moore Voting Algorithm
    int candidate = nums[0];
    int count = 1;

    // Find candidate
    for (int i = 1; i < nums.size(); i++)
    {
        if (count == 0)
        {
            // Pick a new candidate when count drops to zero
            candidate = nums[i];
            count = 1;
        }
        else if (nums[i] == candidate)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    // The candidate is the majority element
    return candidate;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int ans = majorityElement(nums);
    cout << ans << endl;

    return 0;
}