#include <bits/stdc++.h>
using namespace std;
int main()
{

    // 11 methods
    set<int> s;

    s.insert(10); // O(logn)
    s.insert(15);
    s.insert(15);   // 15 add hbe na..coz duplicate value add hy na
    s.emplace(123); // O(logn)
    s.insert(229);

    cout << s.count(10); // if 10 is then it will show 1..does not matter how many 10 are in s..O(logN)

    s.erase(10); // if once erase 10 then count will show 0..does not matter how many 10 are after erase one 10..O(logN)

    cout << s.count(10);

    s.insert(10); // after insert 10 again it will show 1 if count(10)..O(logN)

    cout << s.count(10); // O(logn)

    if (s.find(10) != s.end())
    {
        cout << "Found";
    }
    else
    {
        cout << "Not Found";
    }

    cout << s.size() << endl; // O(1)

    cout << *(s.lower_bound(123)) << endl; /* 123 na thkle er theke boro ta dibe..
      jdi ekta boro na thke and 123 na thke tahole s.end() value dibe ja 0.
      should not be less than key..its not for unorderset */

    cout << *(s.upper_bound(123)); /* 123 er theke boro ta dibe..greater than key..its not for unorderset */

    s.clear(); // O(n)
    // s.empty();

    // multiset and unorderset are same as multiset and unordermap

    // set is unique so eita k multiset ba ununiqur krte pair use krb set e..ektai value r ektai index number thkbe.
    ////unorder_map is  implemented of hash table
}