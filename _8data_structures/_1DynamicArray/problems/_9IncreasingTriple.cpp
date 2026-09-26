#include <bits/stdc++.h>
using namespace std;

// brute force
bool increasingTriplet(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                if (nums[i] < nums[j] && nums[j] < nums[k])
                {
                    return true;
                }
            }
        }
    }

    return false;
}
// optimal
bool increasingTriplet(vector<int> &nums)
{
    int first = INT_MAX;
    int second = INT_MAX;

    for (int num : nums)
    {
        if (num <= first)
        {
            first = num;
        }
        else if (num <= second)
        {
            second = num;
        }
        else
        {
            return true; // found third > second > first
        }
    }
    return false;
}

int main()
{

    vector<int> nums = {1, 2, 3, 4, 5};

    if (increasingTriplet(nums))
    {
        cout << "true\n";
    }
    else
    {
        cout << "false\n";
    }

    return 0;
}