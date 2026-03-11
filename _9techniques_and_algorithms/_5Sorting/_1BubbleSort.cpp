#include <bits/stdc++.h>
using namespace std;
// adjacent element k ba 2 ta kre element swap krbo jdi condition true hy..
void bubbleSort(int arr[], int n)
{ // 0(n^2)
    for (int i = 0; i < n - 1; i++)
    {
        bool isSwap = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }
        if (!isSwap) // array is sorted AlreadyS
        {
            return;
        }
    }
};
int main()
{
    int n = 5;
    int arr[] = {4, 1, 5, 2, 3};
    bubbleSort(arr, n);
    for (auto k : arr)
    {
        cout << k << " ";
    }

    return 0;
}