// #include <bits/stdc++.h>
// using namespace std;

// vector<int> rotation(vector<int> &a, int k)
// {
//     int n = a.size();
//     vector<int> newArr(n);
//     int j = 0;

//     k = k % n; // handle cases where k > n

//     // last k elements
//     for (int i = n - k; i < n; i++)
//     {
//         newArr[j++] = a[i];
//     }

//     // remaining elements
//     for (int i = 0; i < n - k; i++)
//     {
//         newArr[j++] = a[i];
//     }

//     return newArr;
// }

// int main()
// {
//     vector<int> ar = {1, 2, 3, 4, 5};
//     int k = 2;

//     vector<int> br = rotation(ar, k);

//     for (int x : br)
//     {
//         cout << x << endl;
//     }

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

void swapping(vector<int> &a, int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void reverseArr(vector<int> &a, int i, int j)
{
    while (i < j)
    {
        swapping(a, i, j);
        i++;
        j--;
    }
}

int main()
{
    vector<int> ar = {1, 2, 3, 4, 5};
    int k = 101;

    int n = ar.size();
    k = k % n;

    reverseArr(ar, 0, n - k - 1);
    reverseArr(ar, n - k, n - 1);
    reverseArr(ar, 0, n - 1);

    for (int x : ar)
    {
        cout << x << " ";
    }

    return 0;
}