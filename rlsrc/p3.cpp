#include <iostream>
using namespace std;

void printArray(int arr[], int n, int index)
{
    if (index == n)
        return;

    cout << arr[index] << " ";

    printArray(arr, n, index + 1);
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, n, 0);
}