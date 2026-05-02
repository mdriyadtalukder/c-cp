/*We divide a problem into smaller subproblems → conquer (solve) them → then combine (merge) the results.
✅ Divide and Conquer

It has 3 steps:

1. Divide → split the problem into smaller parts
2. Conquer → solve each smaller part (usually recursively)
3. Combine → merge the solutions into the final answer
for example: Merge Sort, Quick Sort, Binary Search are under Divide and Conquer algorithm
*/


//Find Maximum Element in an Array
//Time: O(n)--Space: O(log n) (recursion stack)
#include <bits/stdc++.h>
using namespace std;

// Divide and Conquer function
int findMax(vector<int> &a, int left, int right)
{
    // Base case: only one element
    if (left == right)
        return a[left];

    // Divide
    int mid = left + (right - left) / 2;

    // Conquer
    int leftMax = findMax(a, left, mid);
    int rightMax = findMax(a, mid + 1, right);

    // Combine
    return max(leftMax, rightMax);
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << findMax(a, 0, n - 1) << endl;

    return 0;
}