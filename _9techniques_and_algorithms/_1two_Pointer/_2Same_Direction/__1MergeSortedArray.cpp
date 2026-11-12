#include <bits/stdc++.h>
using namespace std;
//brute force
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
//optimal
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1;     // Pointer to end of valid nums1
    int j = n - 1;     // Pointer to end of nums2
    int k = m + n - 1; // Pointer to end of nums1 (write position)

    // Merge from the back, placing the larger element first
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // Copy remaining elements from nums2 (if any)
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
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