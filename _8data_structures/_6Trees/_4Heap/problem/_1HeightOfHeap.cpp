// n ke 2 dara vag krbo utill n equal to 1..then count krbo koibar vag krte hyse.
//Time Complexity = O(log N)
#include <bits/stdc++.h>
using namespace std;
int heapHeight(int N, int arr[])
{

    // If only one node
    if (N == 1)
        return 1;

    int height = 0;

    while (N > 1)
    {
        height++;
        N = N / 2;
    }

    return height;
}
int main() {}