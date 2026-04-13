// row wise sorte and column wise o sorted matrix..er k=6 th smallest elem konta?
// 1st e 1st column re minheap e dukabo..then sob cheye choto ta k pop krbo in minheap.so er position(i,j) store rakhte hbe.
// then jake pop krsi tar next take push krbo..so on..untill get kth smallest elem.
// tc=o(klogn+n)

#include <bits/stdc++.h>
using namespace std;

#define MAX 100

// create Min heap
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    // data(value), row, col
    vector<pair<int, pair<int, int>>> temp;

    for (int i = 0; i < n; i++)
    {
        temp.push_back(make_pair(mat[i][0], make_pair(i, 0))); //value,(i,j) index
    }

    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>>
        p(temp.begin(), temp.end()); //  p(temp.begin(), temp.end()) means we directly build heap in O(n)

    int ans;
    pair<int, pair<int, int>> Element;
    int i, j;

    while (k--)
    {
        Element = p.top();
        p.pop();

        ans = Element.first; // value

        i = Element.second.first;  // row number
        j = Element.second.second; // col number

        if (j + 1 < n)
        {
            p.push(make_pair(mat[i][j + 1], make_pair(i, j + 1)));
        }
    }

    return ans;
}