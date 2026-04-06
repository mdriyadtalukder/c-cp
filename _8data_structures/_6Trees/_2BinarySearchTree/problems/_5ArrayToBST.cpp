// sorted array k vag krbo then left part left e and right part right e..so on..left part age divide hy
//  mid ba jeta vag kora hyse oi node ta ans e dite thkbo..so preorder hote thkbe...preorder e ans dite hbe..
#include <bits/stdc++.h>
using namespace std;

void ArrayToBST(vector<int> &arr, int start, int end, vector<int> &ans)
{
    if (start > end)
        return;

    int mid = start + (end - start) / 2;

    // root
    ans.push_back(arr[mid]);

    // left subtree
    ArrayToBST(arr, start, mid - 1, ans);

    // right subtree
    ArrayToBST(arr, mid + 1, end, ans);
}

vector<int> sortedArrayToBST(vector<int> &nums)
{
    vector<int> ans;
    ArrayToBST(nums, 0, nums.size() - 1, ans);
    return ans;
}

// Driver code (for testing)
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};

    vector<int> result = sortedArrayToBST(nums);

    for (int x : result)
        cout << x << " ";

    return 0;
}