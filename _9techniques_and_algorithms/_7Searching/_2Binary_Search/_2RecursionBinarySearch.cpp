
#include <bits/stdc++.h>
using namespace std;
int recBinarySearch(vector<int> arr, int tar, int st, int end)
{ // recursion
    if (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (tar > arr[mid])
        { // 2nd half
            return recBinarySearch(arr, tar, mid + 1, end);
        }
        else if (tar < arr[mid])
        { // 1st half
            return recBinarySearch(arr, tar, st, mid - 1);
        }
        else
        { // mid => ans
            return mid;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {12, 31, 35, 8, 32, 17};
    cout << recBinarySearch(arr, 35, 0, arr.size() - 1);
    return 0;
}