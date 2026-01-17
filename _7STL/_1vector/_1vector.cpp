#include <bits/stdc++.h>
using namespace std;
int main()
{
    // total 27
    
    //   dynamic sized array
    vector<int> ar(50);     // vector size is 50 with all 0 element..like {0,0,0,0,....}
    vector<int> arr(44, 6); // vector size is 44 with all 6 element..like {6,6,6,6,...}
    vector<int> v;
    vector<int> v2 = {22, 33, 44, 55};
    vector<int> v3(v2);
    vector<int> v4 = {22, 1, 4, 3, 6, 7, 4, 31, 22};
    vector<int> vi = {10, 15, 12, 5, 20};

    v.push_back(1); // add element
    v.push_back(2);
    v.push_back(3);
    v.emplace_back(4); // emplace_back is same of push_back..they add elem in the last

    cout << v.size() << endl;     // length of vector
    cout << v.capacity() << endl; // capacity of vector

    // cout << v[0] << " " << v[1] << " " << v[2] << " " << endl;
    for (int val : v)
    {
        cout << val << " ";
    }
    cout << endl;

    v.pop_back(); // remove element from last elemt
    v.push_back(0);

    cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << " " << endl;

    cout << "val of index 2 is: " << v[2] << " or " << v.at(2) << endl;
    cout << "get 1st element of vector: " << v.front() << endl;
    cout << "get last element of vector: " << v.back() << endl;

    v3.erase(v3.begin());                     // 1st element delete hbe;
    v3.erase(v3.begin() + 2);                 // 2 index er element delete hbe
    v2.erase(v2.begin() + 1, v2.begin() + 3); //  index 1 to 2 er elements delete hbe..end elem e +1 besi dite hbe.

    v2.insert(v2.begin() + 3, 300); // 3 no index e 300 add hbe..expand hy..like total 4 elem thkle aro 1 jog hoye 3 no index e 300 add hy..so total elem 5 hbe.

    v2.clear(); // size 0 hbe but capacity same thkbe.
    if (v2.empty())
    {
        cout << "Vector is empty" << endl;
    } // yes v2 is empty..so it will print 1..if not so then it prints 0;

    cout << *(v4.begin()); // 1st value dibe
    cout << *(v4.end());   // last_index+1 index er value dibe ja 0.

    sort(v4.begin(), v4.end()); // sort vector;
                                // sort(arr,arr+5);//5 is length of arr..way of soring fixed array.

    cout << endl;

    // Iterator

    /*vector<int>::iterator it = vi.begin();
     OR
    auto it = vi.begin(); // "auto" keyword is used to deduce datatype automatically
    */

    // vector<int>::iterator it;// etar poriborte just auto likhleo hbe
    for (auto it = vi.begin(); it != vi.end(); it++)
    {
        cout << *(it) << " ";
    }

    cout << endl;

    // reverse iterator
    // vector<int>::reverse_iterator it; //etar poriborte just auto likhleo hbe
    for (auto it = vi.rbegin(); it != vi.rend(); it++)
    {
        cout << *(it) << " ";
    }
}

/*
Time & Space Complexity of std::vector<int> in C++

--------------------------------------------------------------------
Operation        | Time Complexity              | Space Complexity
--------------------------------------------------------------------
push_back(x)     | O(1) amortized, O(n) worst   | O(1)
emplace_back(x)  | O(1) amortized, O(n) worst   | O(1)
pop_back()       | O(1)                         | O(1)
at(i)            | O(1)                         | O(1)
operator[]       | O(1)                         | O(1)
front()          | O(1)                         | O(1)
back()           | O(1)                         | O(1)
insert(pos, x)   | O(n)                         | O(1)
erase(pos)       | O(n)                         | O(1)
clear()          | O(n)                         | O(1)
empty()          | O(1)                         | O(1)
--------------------------------------------------------------------

*/