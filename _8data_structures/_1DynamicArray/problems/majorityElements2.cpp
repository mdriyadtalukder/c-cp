#include <bits/stdc++.h>
using namespace std;
// brute force
vector<int> majorityElement(vector<int> &nums)
{

    unordered_map<int, int> m;
    vector<int> v;

    for (int i = 0; i < nums.size(); i++)
    {
        m[nums[i]]++;
    }

    for (auto j : m)
    {
        if (j.second > nums.size() / 3)
        {
            v.push_back(j.first);
        }
    }

    return v;
}

// optimal(Boyer-Moore Voting Algorithm)
vector<int> majorityElement(vector<int> &nums)
{
    int n = nums.size();
    int cand1 = 0, cand2 = 0;
    int count1 = 0, count2 = 0;

    // First pass: find candidates
    for (int num : nums)
    {
        if (num == cand1)
        {
            count1++;
        }
        else if (num == cand2)
        {
            count2++;
        }
        else if (count1 == 0)
        {
            cand1 = num;
            count1 = 1;
        }
        else if (count2 == 0)
        {
            cand2 = num;
            count2 = 1;
        }
        else
        {
            // Cancel: three distinct elements found
            count1--;
            count2--;
        }
    }

    // Second pass: verify candidates
    count1 = 0;
    count2 = 0;
    for (int num : nums)
    {
        if (num == cand1)
            count1++;
        else if (num == cand2)
            count2++;
    }

    vector<int> result;
    if (count1 > n / 3)
        result.push_back(cand1);
    if (count2 > n / 3)
        result.push_back(cand2);
    return result;
}
int main()
{
    vector<int> nums = {3, 2, 3};

    majorityElement(nums);

    return 0;
}