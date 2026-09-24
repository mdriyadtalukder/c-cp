#include <iostream>
#include <vector>
using namespace std;
// eta array  k small sub array te divide kre until single elem hy then sort kre all small sub array and merge kre..
// TC = O(n log n)..mergeSort() divides the array into 2 halves → log n levels..At every level, merge() processes all n elements → O(n)
// SC=O(n)..for vector<int> temp;
//  divide and conquer..1st e divide krbo boro problm ta k choto choto problem e..then choto problem er ans diye oi boro problem er solution ber krbo..its conquer.
void merge(vector<int> &arr, int st, int mid, int end)
{
    vector<int> temp;
    int i = st, j = mid + 1;
    while (i <= mid && j <= end) // 2 part k merge kora in sort way
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
        }
    }
    while (i <= mid) // i er element jdi beche thke
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= end) // j er element jdi beche thke
    {
        temp.push_back(arr[j]);
        j++;
    }
    for (int idx = 0; idx < temp.size(); idx++)
        // Put sorted temp elements back into arr
        // starting from index st.if st=2 then for idex 0,1,2...0+2=temp[0],0+1=temp[1],0+2=temp[2]...so on
        arr[idx + st] = temp[idx];
}

void mergeSort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int mid = st + (end - st) / 2;
        mergeSort(arr, st, mid);      // left half
        mergeSort(arr, mid + 1, end); // right half
        merge(arr, st, mid, end);
    }
}
int main()
{
    vector<int> arr = {12, 31, 35, 8, 32, 17};
    mergeSort(arr, 0, arr.size() - 1);
    for (auto k : arr)
    {
        cout << k << " ";
    }
    return 0;
}