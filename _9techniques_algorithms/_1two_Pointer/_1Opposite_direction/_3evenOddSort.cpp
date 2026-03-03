#include <bits/stdc++.h>
using namespace std;

// swap function
void swapping(vector<int> &ar, int i, int j)
{
    int temp = ar[i];
    ar[i] = ar[j];
    ar[j] = temp;
}

int main()
{

    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11};
    int left = 0;
    int right = a.size() - 1;

    while (left < right)
    {

        if (a[left] % 2 != 0 && a[right] % 2 == 0)
        {
            swapping(a, left, right);
            left++;
            right--;
        }

        if (a[left] % 2 == 0)
        {
            left++;
        }

        if (a[right] % 2 != 0)
        {
            right--;
        }
    }

    for (int i : a)
    {
        cout << i << " ";
    }

    return 0;
}