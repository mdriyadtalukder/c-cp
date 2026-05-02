// min heap and max heap use kre ei problem solve krte hoy..
// top k largest elem means top k largest elemnet dao..like
// k=3 so 1st or top 3 ta leagest element dao..like 4,5,3,2,1..array eita desending order a sort krbo like 5,4,3,2,1 then k=3 so 1st 3 ta boro elem dibo..result=[5,4,3]
// ei type er prblm minheap or maxheap dara kora hy ..ete tc kom hoy.. O(nlogk)..sc=O(k) for this prblm
#include <bits/stdc++.h>
using namespace std;

vector<int> topKElements(vector<int> &nums, int k)
{
    // Min heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int num : nums)
    {
        minHeap.push(num);

        // keep only k elements in heap
        if (minHeap.size() > k)
        {
            minHeap.pop();
        }
    }

    // extract result
    vector<int> result;
    while (!minHeap.empty())
    {
        result.push_back(minHeap.top());
        minHeap.pop();
    }

    return result;
}

int main()
{
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    vector<int> ans = topKElements(nums, k);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}