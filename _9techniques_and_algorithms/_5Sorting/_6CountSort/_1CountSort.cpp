/*1st e son element e count ber krbo j koita kre ase.
.like index 0-its means 0 koita ase..so on.
.then sob gular prefix sum krbo all index er jnno.
.then main array er last theke element pic krbo and oi num er prefix sum er index e jbo ..
then value 1 kre komabo then oi value er index e push krbo elem ta in main array..*/
#include <bits/stdc++.h>
using namespace std;
// TC=O(n+max)=O(n)
void countSort(vector<int> &arr)
{
    int n = arr.size();

    int k = arr[0];
    for (int i = 0; i < n; i++)
    {
        k = max(k, arr[i]);
    }

    // 1st: count array
    vector<int> count(k + 1, 0);
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    // 2nd: prefix sum
    for (int i = 1; i <= k; i++)
    {
        count[i] += count[i - 1];
    }

    // 3rd: output array
    vector<int> output(n);

    for (int i = n - 1; i >= 0; i--)
    {
        output[--count[arr[i]]] = arr[i];
    }

    // copy back
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

int main()
{
    vector<int> arr = {1, 3, 2, 3, 4, 1, 6, 4, 3};

    countSort(arr);

    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}