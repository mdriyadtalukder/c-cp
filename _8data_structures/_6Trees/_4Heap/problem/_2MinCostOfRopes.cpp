//ekta array thkbe eita k priority queue e add krbo min heap er jate choto gula age thke..
//then sob cheye choto 2 ta add krbo and sum p te add krbo and oi 2 ta elem pop krbo.
//eita krte thkbo until get single elem
//TC=O(n log n)
#include <bits/stdc++.h>
using namespace std;

long long minCost(long long arr[], long long n)
{
    // Min heap
    priority_queue<long long, vector<long long>, greater<long long>> p;

    // Push all elements into heap
    for (long long i = 0; i < n; i++)
    {
        p.push(arr[i]);
    }

    long long cost = 0;

    // Combine ropes
    while (p.size() > 1)
    {
        long long rope = p.top();
        p.pop();

        rope += p.top();
        p.pop();

        cost += rope;

        p.push(rope);
    }

    return cost;
}

int main()
{
    long long n;
    cin >> n;

    long long arr[n];
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << minCost(arr, n) << endl;

    return 0;
}