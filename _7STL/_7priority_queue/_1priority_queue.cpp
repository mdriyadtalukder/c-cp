#include <bits/stdc++.h>
using namespace std;
int main()
{
    // j value gula boro seigula upore thake sequencially..doesnot mttr when it is added.
    // priority_queue<int, vector<int>, greater<int>> pq; //choto theke boro

    priority_queue<int> pq; // boo theke choto
    pq.push(1);             // o(logn)
    pq.push(2);
    pq.emplace(3);
    pq.push(4);
    cout << pq.size() << endl;
    cout << pq.top() << endl;

    while (!pq.empty())
    {
        cout << pq.top() << " "; // o(1)
        pq.pop();                // o(logn)
    }
    cout << endl;
}