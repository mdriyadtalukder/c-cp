#include <bits/stdc++.h>
using namespace std;

// sorted with two pointers for 0 and 1
void swapping(vector<int> &arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int main()
{
    vector<int> ar = {1, 0, 0, 1, 1, 0, 1, 0, 1, 0};

    int left = 0;
    int right = ar.size() - 1;

    while (left < right)
    {
        if (ar[left] == 1 && ar[right] == 0)
        {
            swapping(ar, left, right);
            left++;
            right--;
        }
        if (ar[left] == 0)
        {
            left++;
        }
        if (ar[right] == 1)
        {
            right--;
        }
    }

    for (int i : ar)
    {
        cout << i << " ";
    }

    return 0;
}