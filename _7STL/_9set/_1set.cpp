#include <bits/stdc++.h>
using namespace std;
int main()
{
    set<int> s;

    s.insert(10);
    s.insert(15);

    cout << s.count(10); // if 10 is then it will show 1..does not matter how many 10 are in s..O(logN)

    s.erase(10); // if once erase 10 then count will show 0..does not matter how many 10 are after erase one 10..O(logN)

    cout << s.count(10);

    s.insert(10); // after insert 10 again it will show 1 if count(10)..O(logN)

    cout << s.count(10);

    cout << s.size(); // O(1)
    s.clear();        // O(n)
}