// k=4 so 4 no lergest elem dite hbe..er jnno min heap use krbo..priority te 1st e k er soman mane 4 ta elem dkabo
// then next e p.top er cheye boro jegula oita dukabo and pop krbo choto ta/
// tc=o(nlogn)

#include <bits/stdc++.h>
using namespace std;

int kthLargest(int arr[], int l, int r, int k)
{

    // Min heap
    priority_queue<int, vector<int>, greater<int>> p;

    // push first k elements
    for (int i = 0; i < k; i++)
    {
        p.push(arr[i]);
    }

    // process remaining elements
    for (int i = k; i <= r; i++)
    {
        if (arr[i] > p.top())
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

    cout << kthLargest(arr, 0, n - 1, k) << endl;

    return 0;
}