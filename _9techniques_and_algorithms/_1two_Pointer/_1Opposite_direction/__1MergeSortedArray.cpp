#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    vector<int> ans;
    int i = 0, j = 0;

    while (i < m && j < n)
    {
        if (nums1[i] < nums2[j])
        {
            ans.push_back(nums1[i]);
            i++;
        }
        else
        {
            ans.push_back(nums2[j]);
            j++;
        }
    }

    while (i < m)
    {
        ans.push_back(nums1[i]);
        i++;
    }

    while (j < n)
    {
        ans.push_back(nums2[j]);
        j++;
    }

    for (int k = 0; k < m + n; k++)
    {
        nums1[k] = ans[k];
    }
}

int main()
{
    vector<int> nums1 = {1, 3, 5, 0, 0, 0}; // extra space for nums2
    int m = 3;

    vector<int> nums2 = {2, 4, 6};
    int n = 3;

    merge(nums1, m, nums2, n);

    for (int x : nums1)
    {
        cout << x << " ";
    }

    return 0;
}