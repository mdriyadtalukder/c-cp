#include <bits/stdc++.h>
using namespace std;

pair<int, int> h()
{
    return {1, 2};
}
main()
{
    // 2 method
    pair<int, string> p = {32, "Riyad"}; // O(1)

    p.first = 44;                               // change 1st value
    cout << p.first << " " << p.second << endl; // O(1)
    pair<int, int> k = h();
    cout << k.first << " " << k.second;

    // multiple
    pair<pair<pair<string, int>, int>, string> multplePair = {{{"tal", 23}, 45}, "riyad"};

    cout << multplePair.first.first.first;  // "tal"
    cout << multplePair.first.first.second; // 23
    cout << multplePair.first.second;       // 45
    cout << multplePair.second;             // "riyad"

    // vector with pair
    vector<pair<int, int>> v = {{1, 2}, {2, 3}, {4, 5}};

    v.push_back({5, 6});
    v.emplace_back(6, 7); // different from push..in push we need to write {} for pair but in emplace it does not need..it automatically does it.

    for (pair<int, int> pl : v) // we can use auto instead of pair<int, int>
    {
        cout << pl.first << " " << pl.second << endl;
    }
}