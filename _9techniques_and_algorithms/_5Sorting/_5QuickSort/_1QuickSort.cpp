// last index k pivot dorbo and er theke boro gula er right e rakhbo and choto gula left e..
// partition funtion ta pivat er shthe sob value compare kre and jete choto oita idx er value te rakhe swap kre,,
#include <iostream>
#include <vector>
using namespace std;
//average/practical Case TC=O(nlogn)
//worst case TC=O(n^2) //pivot repeatly small or large element hy..
int partition(vector<int> &arr, int st, int end)
{
    int idx = st - 1, pivot = arr[end];
    for (int j = st; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            idx++;
            swap(arr[j], arr[idx]);
        }
    }
    idx++;
    swap(arr[end], arr[idx]);
    return idx;
}
void quickSort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int pivIdx = partition(arr, st, end);
        quickSort(arr, st, pivIdx - 1);  // left half
        quickSort(arr, pivIdx + 1, end); // right half
    }
}
int main()
{
    vector<int> arr = {12, 31, 35, 8, 32, 17};
    quickSort(arr, 0, arr.size() - 1);
    for (auto k : arr)
    {
        cout << k << " ";
    }
    return 0;
}