#include <bits/stdc++.h>
using namespace std;
// 2ta max heap merge kre max heap banate hbe..er jnno 2 ta array k eta ans array te vore oi ans array er upor setdown heapify apply dibo..
//TC=O(n)
void Heapify(vector<int> &ans, int index, int n)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < n && ans[left] > ans[largest])
        largest = left;

    if (right < n && ans[right] > ans[largest])
        largest = right;

    if (largest != index)
    {
        swap(ans[largest], ans[index]);
        Heapify(ans, largest, n);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b)
{
    vector<int> ans;

    // copy elements of first heap
    for (int i = 0; i < a.size(); i++)
        ans.push_back(a[i]);

    // copy elements of second heap
    for (int i = 0; i < b.size(); i++)
        ans.push_back(b[i]);

    // build max heap
    int n = ans.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(ans, i, n);

    return ans;
}

int main()
{
    // predefined heaps (already max heaps)
    vector<int> a = {10, 5, 6, 2};
    vector<int> b = {12, 7, 9};

    vector<int> result = mergeHeaps(a, b);

    cout << "Merged Max Heap: ";
    for (int x : result)
        cout << x << " ";

    cout << endl;

    return 0;
}