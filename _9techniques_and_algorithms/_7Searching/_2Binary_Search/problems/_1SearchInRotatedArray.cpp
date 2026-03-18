#include <bits/stdc++.h>
using namespace std;
//1 side sorted hy..
int search(vector<int> &A, int tar)
{
    int st = 0;
    int end = A.size() - 1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (A[mid] == tar)
        {
            return mid;
        }

        // left part sorted
        if (A[st] <= A[mid])
        {
            if (A[st] <= tar && tar <= A[mid])
            {
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        // right part sorted
        else
        {
            if (A[mid] <= tar && tar <= A[end])
            {
                st = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{
    vector<int> A = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int ans = search(A, target);

    cout << ans;

    return 0;
}