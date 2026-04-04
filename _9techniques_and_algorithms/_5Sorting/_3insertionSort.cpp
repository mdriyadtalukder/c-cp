#include <bits/stdc++.h>
using namespace std;
// 26min
void insertionSort(int arr[], int n)
// 1st elemnt sorted part hbe and baki gula unsorted hishebe dorbo..then unsorted part er ekta ekta elem check krbo and dekhbo sorted part er elem boro nki .boro hole oi unsorted part er elem k tar jaiga moto place krbo in sorted part
// choto hole sorted part er array k 2 ta banabo like 4 4 then 1st 4 e oi result insert krbo..like 2 4....145 2.. 1455..1445...1245
{ // 0(n^2)
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int prev = i - 1;
        while (prev >= 0 && arr[prev] > curr) // jotokkhn porjonto sothik place pacche choto elem ta totokkhn porjonto cholbe and pre ta 1 kre minus hbe jdi sob boro hy..
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