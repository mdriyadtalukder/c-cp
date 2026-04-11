// array k sort kra.
//  1st maxheap krbo then oi top ta k print krbo then last elem k top a add krbo and top ta last a as swap
//  then heapify krbo like parent er shthe compare krbo child k and child boro hole swap krbo
//  after that abr top ta print krbo and last ta top e dibo and top ta last a as swap and bar compare and so on this process.
// TC=O(nlogn)

#include <bits/stdc++.h>
using namespace std;

// maxheap to sorted array

void Heapify(int arr[], int index, int n)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < n && arr[left] > arr[largest]) // for minHeap <
        largest = left;

    if (right < n && arr[right] > arr[largest]) // for minHeap <
        largest = right;

    if (largest != index)
    {
        swap(arr[largest], arr[index]);
        Heapify(arr, largest, n);
    }
}

void BuildMaxHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        Heapify(arr, i, n);
    }
}
void printHeap(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void heapSortArray(int arr[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[i], arr[0]);
        Heapify(arr, 0, i);
    }
}
int main()
{
    int arr[] = {10, 3, 8, 9, 5, 13, 18, 14, 11, 70};
    BuildMaxHeap(arr, 10);
    printHeap(arr, 10);
    heapSortArray(arr, 10);
    printHeap(arr, 10);
}