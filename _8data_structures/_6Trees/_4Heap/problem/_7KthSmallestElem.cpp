// k=4 so 4 no smallest elem dite hbe..er jnno max heap use krbo..priority te 1st e k er soman mane 4 ta elem dkabo
// then next e p.top er cheye choto jegula oita dukabo and pop krbo boro ta/
// tc=o(nlogn)

#include <bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[], int l, int r, int k)
{

    // Max heap (to keep k smallest elements)
    priority_queue<int> p;

    // push first k elements
    for (int i = 0; i < k; i++)
    {
        p.push(arr[i]);
    }

    // process remaining elements
    for (int i = k; i <= r; i++)
    {
        if (arr[i] < p.top())
        {
            p.pop();
            p.push(arr[i]);
        }
    }

    return p.top();
}

int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = 6;
    int k = 3;

    cout << kthSmallest(arr, 0, n - 1, k) << endl;

    return 0;
}