#include <bits/stdc++.h>
using namespace std;
// heap
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

/*
Operation        | Time Complexity       | Space Complexity
----------------------------------------------------------
push(x)          | O(log n)             | O(1)
emplace(x)       | O(log n)             | O(1)
pop()            | O(log n)             | O(1)
top()            | O(1)                 | O(1)
empty()          | O(1)                 | O(1)
size()           | O(1)                 | O(1)
*/