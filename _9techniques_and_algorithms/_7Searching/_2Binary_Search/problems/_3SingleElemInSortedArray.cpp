#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int> &A)
{
    int n = A.size();
    int st = 0, end = n - 1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        // check boundaries
        if (mid == 0 && A[0] != A[1])
            return A[mid];

        if (mid == n - 1 && A[n - 1] != A[n - 2])
            return A[mid];

        // unique element
        if (A[mid - 1] != A[mid] && A[mid] != A[mid + 1])
            return A[mid];

        if (mid % 2 == 0) // even index
        {
            if (A[mid] == A[mid + 1])
                st = mid + 1;
            else
                end = mid - 1;
        }
        else // odd index
        {
            if (A[mid] == A[mid - 1])
                st = mid + 1;
            else
                end = mid - 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> A = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};

    cout << singleNonDuplicate(A);

    return 0;
}