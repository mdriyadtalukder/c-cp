#include <bits/stdc++.h>
using namespace std;
void insertionSort(int arr[], int n)
{ // 0(n^2)
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int prev = i - 1;
        while (prev >= 0 && arr[prev] > curr)
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }

        arr[prev + 1] = curr; // placing the curr el in its correct position
    }
}
int main()
{
    int n = 5;
    int arr[] = {4, 1, 5, 2, 3};
    insertionSort(arr, n);
    for (auto k : arr)
    {
        cout << k << " ";
    }

    return 0;
}