// it works only for sorted array.
#include <iostream>
#include <vector>
using namespace std;
//TC=O(logn)..every bar n/2 vag hy..so n/2^k=1 ,n=2^k,logn=k

int binarySearch(vector<int> arr, int tar)
{ // Iterative
    int st = 0, end = arr.size() - 1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (tar > arr[mid])
        {
            st = mid + 1;
        }
        else if (tar < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr1 = {-1, 0, 3, 4, 5, 9, 12}; // odd int tar1 = 12;
    vector<int> arr2 = {-1, 0, 3, 5, 9, 12};    // even int tar1 = 0;
    cout << binarySearch(arr1, 3);
    return 0;
}