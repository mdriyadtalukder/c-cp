#include <bits/stdc++.h>
using namespace std;

// brute force
int thirdMax(vector<int> &nums)
{
    vector<int> v;

    sort(nums.rbegin(), nums.rend());

    v.push_back(nums[0]);

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[i - 1])
        {
            v.push_back(nums[i]);
        }
    }

    if (v.size() < 3)
        return v[0];

    return v[2];
}

// optimal
int thirdMax2(vector<int> &nums)
{
    // Use long long to avoid sentinel collision with INT_MIN
    long long first = LLONG_MIN;
    long long second = LLONG_MIN;
    long long third = LLONG_MIN;

    for (int num : nums)
    {
        // Skip duplicates
        if (num == first || num == second || num == third)
        {
            continue;
        }
        if (num > first)
        {
            // New largest: shift everything down
            third = second;
            second = first;
            first = num;
        }
        else if (num > second)
        {
            // New second largest: shift third down
            third = second;
            second = num;
        }
        else if (num > third)
        {
            // New third largest
            third = num;
        }
    }

    // If third was never assigned, return the maximum
    return (int)(third == LLONG_MIN ? first : third);
}

int main()
{
    vector<int> nums = {2, 2, 3, 1};

    cout << thirdMax(nums) << endl;

    return 0;
}