#include <bits/stdc++.h>
using namespace std;

int findMiddle(vector<int> &arr)
{
    int slow = 0;
    int fast = 0;

    while (fast < arr.size() && fast + 1 < arr.size())
    {
        slow++;    // move 1 step
        fast += 2; // move 2 steps
    }

    return arr[slow];
}

int main()
{
    vector<int> arr = {7, 2, 9, 4, 1};
    cout << findMiddle(arr);
}