#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    int i = 0, j = numbers.size() - 1;
    while (i < j)
    {
        if (numbers[i] + numbers[j] == target)
        {
            return {i + 1, j + 1};
        }
        if (numbers[i] + numbers[j] < target)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return {};
}

int main()
{
    vector<int> nums1 = {2, 7, 11, 15};
    int target = 9;

    vector<int> nums2 = twoSum(nums1, target);

    for (int x : nums2)
    {
        cout << x << " ";
    }

    return 0;
}