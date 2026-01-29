#include <bits/stdc++.h>
using namespace std;
// vector is C++’s built-in implementation of a doubly linked list.

int main()
{
    // implemented by doubly linkedlist..TC same as vector

    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.emplace_back(33);
    l.push_back(3);
    l.push_front(4);     // shamne theke element add kre;
    l.emplace_front(44); // shamne theke element add kre;
    l.push_front(5);

    l.pop_back();
    l.pop_front(); // shamne theke element delete hbe.

    for (int val : l)
    {
        cout << val << " ";
    }

    // cout << endl<< l[2]; // not possible in list..get error.

    /* size, erase, clear, begin, end, rbegin, rend, insert, front, back.
    .these all implementation same as vector..list is same as vector.
    .just it is created by doubly linkedlist
     */
}