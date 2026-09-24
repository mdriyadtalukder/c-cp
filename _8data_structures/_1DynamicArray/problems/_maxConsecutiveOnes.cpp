#include <bits/stdc++.h>
using namespace std;

// brute force
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int maxCount = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        int count = 0;
        // Count consecutive 1's starting at i
        for (int j = i; j < nums.size(); j++)
        {
            if (nums[j] == 1)
            {
                count++;
            }
            else
            {
                break;
            }
        }
        maxCount = max(maxCount, count);
    }

    return maxCount;
}

// optimal
int findMaxConsecutiveOnes2(vector<int> &nums)
{
    int maxCount = 0;
    int count = 0;

    for (int num : nums)
    {
        if (num == 1)
            count++;
        else
            count = 0;

        maxCount = max(maxCount, count);
    }

    return maxCount;
}

int main()
{
    vector<int> nums = {1, 1, 0, 1, 1, 1};

    cout << findMaxConsecutiveOnes(nums) << endl;

    return 0;
}