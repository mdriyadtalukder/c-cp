#include <bits/stdc++.h>
using namespace std;

bool hasCycle(vector<int> &arr)
{
    int slow = 0;
    int fast = 0;

    while (fast < arr.size() && arr[fast] < arr.size())
    {
        slow = arr[slow];      // move 1 step
        fast = arr[arr[fast]]; // move 2 steps

        if (slow == fast)
        {
            return true; // cycle detected
        }
    }

    return false; // no cycle
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 2}; //{3, 1, 3, 4, 2}

    if (hasCycle(arr))
        cout << "Cycle Found";
    else
        cout << "No Cycle";

    return 0;
}