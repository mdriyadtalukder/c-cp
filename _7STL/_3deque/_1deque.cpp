#include <bits/stdc++.h>
using namespace std;
int main()
{
    // its similar to list and its created by double ended queue..

    // dequeue means pop element from normal queue..its not its part.

    deque<int> d;
    d.push_back(1);
    d.push_back(2);
    d.emplace_back(33);
    d.push_back(3);
    d.push_front(4);     // shamne theke element add kre;
    d.emplace_front(44); // shamne theke element add kre;
    d.push_front(5);

    d.pop_back();
    d.pop_front(); // shamne theke element delete hbe.

    for (int val : d)
    {
        cout << val << " ";
    }
    cout<<endl<<d[3];

    /* size, erase, clear, begin, end, rbegin, rend, insert, front, back.
    .these all implementation same as list..deque is same as list.
    .just it is created by double ended queue..or with dynamic array so we can access d[idex]..ja list e kora jai na..
     */
}