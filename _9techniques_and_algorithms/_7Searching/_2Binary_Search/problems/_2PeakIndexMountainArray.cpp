#include <bits/stdc++.h>
using namespace std;

int peakIndexInMountainArray(vector<int> &A)
{
    int st = 1;
    int end = A.size() - 2;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (A[mid - 1] < A[mid] && A[mid] > A[mid + 1])
        {
            return mid;
        }
        else if (A[mid - 1] < A[mid])
        { // right side
            st = mid + 1;
        }
        else
        { // left side
            end = mid - 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> A = {1, 3, 5, 7, 6, 4, 2};

    cout << peakIndexInMountainArray(A);

    return 0;
}