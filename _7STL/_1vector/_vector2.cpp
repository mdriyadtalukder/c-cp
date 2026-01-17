#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[5] = {5, 4, 3, 2, 1};
    // sort(arr,arr+5);//5 is length of arr..way of soring fixed array.
    vector<int> even, odd;

    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        if (arr[i] % 2 == 0)
        {
            even.push_back(arr[i]);
        }
        else
        {
            odd.push_back(arr[i]);
        }
    }

    sort(even.begin(), even.end()); // way of sorting vector

    for (int i = 0; i < even.size(); i++)
    {
        cout << even[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < odd.size(); i++)
    {
        cout << odd[i] << " ";
    }
}