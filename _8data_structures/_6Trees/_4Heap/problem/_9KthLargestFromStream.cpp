#include <bits/stdc++.h>
using namespace std;
//4th largest ta array te dukabo..jdi k porjonto queue er size na hy tahole -1 dukabo array te..
vector<int> kthLargestStream(vector<int> &arr, int k)
{

    priority_queue<int, vector<int>, greater<int>> p; // min heap
    vector<int> ans;

    for (int i = 0; i < arr.size(); i++)
    {

        p.push(arr[i]);

        if (p.size() > k)
        {
            p.pop();
        }

        if (p.size() < k)
        {
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(p.top());
        }
    }

    return ans;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int k = 4;

    vector<int> res = kthLargestStream(arr, k);

    for (int x : res)
        cout << x << " ";

    return 0;
}