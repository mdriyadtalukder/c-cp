// sorted krbo then odd hole midian hbe majhkhaner ta r even hole majkhaner 2 tar jogfol vag 2..
// maxheap e thakbe left side gula r minheap e right side er gula..
// 2 ta heap er size soman hole 2tar top er jogfol vag 2 hbe median
// left side boro hole left side theke -1 krbo and er top result
// right side boro hole er ekta elem left side e dibo
// left side>right side+1..hole left side er ekta right side e dibo
//TC=O(nlogn)
//very importannt

#include <bits/stdc++.h>
using namespace std;
// max heap (left side)
priority_queue<int> LeftMaxHeap;

// min heap (right side)
priority_queue<int, vector<int>, greater<int>> RightMinHeap;

// Function to insert heap
void insertHeap(int &x)
{
    // base case
    if (LeftMaxHeap.empty())
    {
        LeftMaxHeap.push(x);
        return;
    }

    if (x > LeftMaxHeap.top())
        RightMinHeap.push(x);
    else
        LeftMaxHeap.push(x);

    balanceHeaps();
}

// Function to balance heaps
void balanceHeaps()
{
    // Right heap should not be bigger than left
    if (RightMinHeap.size() > LeftMaxHeap.size())
    {
        LeftMaxHeap.push(RightMinHeap.top());
        RightMinHeap.pop();
    }
    else
    {
        // left should not exceed right by more than 1
        if (LeftMaxHeap.size() > RightMinHeap.size() + 1)
        {
            RightMinHeap.push(LeftMaxHeap.top());
            LeftMaxHeap.pop();
        }
    }
}

// Function to return median
double getMedianValue()
{
    // left has more elements
    if (LeftMaxHeap.size() > RightMinHeap.size())
        return LeftMaxHeap.top();

    // equal size
    double ans = LeftMaxHeap.top() + RightMinHeap.top();
    ans /= 2;

    return ans;
}

// main function
vector<double> getMedian(vector<int> &arr)
{
    vector<double> ans;

    for (int i = 0; i < arr.size(); i++)
    {
        insertHeap(arr[i]);
        ans.push_back(getMedianValue());
    }

    return ans;
}
int main()
{
}