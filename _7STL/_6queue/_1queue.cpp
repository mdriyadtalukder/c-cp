#include <bits/stdc++.h>
using namespace std;
int main()
{
    // its FIFO
    queue<int> q;
    q.push(1); // o(1)
    q.push(2);
    q.emplace(3);
    q.push(4);
    cout << q.size() << endl;
    cout << q.front() << endl;

    while (!q.empty())
    {
        cout << q.front() << " "; // o(1)
        q.pop();                  // o(1)
    }
    cout << endl;
    queue<int> q2;
    q2.swap(q); // s er sob value s2 te ashbe and s empty hoye jbe..
}