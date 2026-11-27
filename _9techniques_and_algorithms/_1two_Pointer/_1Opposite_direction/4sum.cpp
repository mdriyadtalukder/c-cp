#include <bits/stdc++.h>
using namespace std;

// brute force
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> v;
    set<vector<int>> s;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                for (int l = k + 1; l < nums.size(); l++)
                {
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                    if (sum == target)
                    {
                        vector<int> temp = {
                            nums[i], nums[j], nums[k], nums[l]};

                        sort(temp.begin(), temp.end());

                        if (s.find(temp) == s.end())
                        {
                            v.push_back(temp);
                            s.insert(temp);
                        }
                    }
                }
            }
        }
    }

    return v;
}

// optimal
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> result;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 3; i++)
    {
        // Skip duplicate values for the first element
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < n - 2; j++)
        {
            // Skip duplicate values for the second element
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int left = j + 1;
            int right = n - 1;

            while (left < right)
            {
                // Use long long to avoid integer overflow
                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                if (sum == target)
                {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});

                    // Skip duplicates on the left pointer
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    // Skip duplicates on the right pointer
                    while (left < right && nums[right] == nums[right - 1])
                        right--;

                    left++;
                    right--;
                }
                else if (sum < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
    }

    return result;
}