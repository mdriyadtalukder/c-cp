#include <bits/stdc++.h>
using namespace std;
// 2 vag hbe array ta..sorted part and unsorted part ..unsorted part e small index khujbo and oitar shthe i k swap krbo..
void selectionSort(int arr[], int n)
{ // n^2)
    for (int i = 0; i < n - 1; i++)
    {
        int smallestIdx = i; // unsorted part starting
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[smallestIdx])
            {
                smallestIdx = j;
            }
        }
        swap(arr[i], arr[smallestIdx]);
    }
}
int main()
{
    int n = 5;
    int arr[] = {4, 1, 5, 2, 3};
    selectionSort(arr, n);
    for (auto k : arr)
    {
        cout << k << " ";
    }

    return 0;
}