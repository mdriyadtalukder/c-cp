#include <iostream>
#include <vector>
using namespace std;
// eta array  k small sub array te divide kre then sort kre all small sub array and merge kre..
// TC=O(logn)..every bar n/2 vag hy..so n/2^k=1 ,n=2^k,logn=k
//  divide and conquer..1st e divide krbo boro problm ta k choto choto problem e..then choto problem er ans diye oi boro problem er solution ber krbo..its conquer.
int merge(vector<int> &arr, int st, int mid, int end)
{
    vector<int> temp;
    int i = st, j = mid + 1, invCount = 0;
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j]) // for decending >=.
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
            invCount += (mid - i + 1);
        }
    }
    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }
    for (int idx = 0; idx < temp.size(); idx++)
    {
        arr[idx + st] = temp[idx];
    }
    return invCount;
}
int mergeSort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int mid = st + (end - st) / 2;
        int leftc = mergeSort(arr, st, mid);       // left half
        int rightc = mergeSort(arr, mid + 1, end); // right half
        int inv = merge(arr, st, mid, end);
        return leftc + rightc + inv;
    }
    return 0;
}
int main()
{
    vector<int> arr = {12, 31, 35, 8, 32, 17};
    int r = mergeSort(arr, 0, arr.size() - 1);
    cout << r;

    return 0;
}