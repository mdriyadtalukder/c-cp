#include <bits/stdc++.h>
using namespace std;
int main()
{
    // non sequencial container it is.its LIFO like plates

    stack<int> s;
    s.push(1); // o(1)
    s.push(2);
    s.emplace(3);
    s.push(4);
    cout << s.size() << endl;
    cout << s.top() << endl;

    while (!s.empty())
    {
        cout << s.top() << " "; // o(1)
        s.pop();                // o(1)
    }
    cout << endl;
    stack<int> s2;
    s2.swap(s); // s er sob value s2 te ashbe and s empty hoye jbe..
}
