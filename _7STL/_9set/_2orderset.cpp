#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// order_of_key(k) : number of items strictly smaller than k
// find_by_order(k): k-th element in the set (0-based)

#define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

int main()

{
    // all methods are same like set except those 2.
    //  oset os;
    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> os;

    os.insert(10);
    os.insert(6);
    os.insert(7);
    os.insert(1);

    // print elements
    for (int i = 0; i < os.size(); i++)
    {
        cout << *os.find_by_order(i) << " "; //O(logn)
    }
    cout << endl;

    // use order_of_key
    cout << os.order_of_key(6) << endl; //O(logn)
    cout << os.order_of_key(8) << endl;

    return 0;
}
