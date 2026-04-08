#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    vector<int> ans;
    int j = 0, i = 0;
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
    for (int i = 0; i < m + n; i++)
    {
        nums1[i] = ans[i];
    }
}
int main()
{
    int m, n;
    cin >> m >> n;

    vector<int> nums1(m + n);
    vector<int> nums2(n);

    // input first array (only m valid elements)
    for (int i = 0; i < m; i++)
    {
        cin >> nums1[i];
    }

    // input second array
    for (int i = 0; i < n; i++)
    {
        cin >> nums2[i];
    }

    merge(nums1, m, nums2, n);

    // output merged array
    for (int i = 0; i < m + n; i++)
    {
        cout << nums1[i] << " ";
    }

    return 0;
}