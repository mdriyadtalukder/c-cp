#include <bits/stdc++.h>
using namespace std;
void insertionSort(int arr[], int n)
// 1st elemnt sorted part hbe and baki gula unsorted hishebe dorbo..then unsorted part er ekta ekta elem check krbo and dekhbo sorted part er elem boro nki .boro hole oi unsorted part er elem k tar jaiga moto place krbo in sorted part
{ // 0(n^2)
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int prev = i - 1;
        while (prev >= 0 && arr[prev] > curr) // jotokkhn porjonto sothik place pacche choto elem ta jotokkhn porjonto cholbe and pre ta 1 kre minus hbe jdi sob boro hy..
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