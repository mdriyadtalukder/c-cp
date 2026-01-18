#include <bits/stdc++.h>
using namespace std;

bool comparison(pair<int, int> p, pair<int, int> p2)
{

    // sort by 2nd value
    if (p.second < p2.second)
        return true;
    if (p.second > p2.second)
        return false;

    // 2nd value equal hole 1st value er tahole 1st value wise sort hbe.
    if (p.first < p2.first)
        return true;
    else
        return false;
}
int main()
{

    vector<pair<int, string>> student;

    sort(student.begin(), student.end());
    sort(student.begin(), student.end(), greater<int>()); // 1st value onujayi sort hy pair er..
    sort(student.begin(), student.end(), comparison);     // 2nd value onujayi sort hy pair er..

    // iterator in vector
    vector<int> v = {10, 15, 12, 5, 20};

    // vector<int>::iterator it = v.begin();
    // OR
    auto it = v.begin(); // "auto" keyword is used to deduce datatype automatically
    cout << *it;
    cout << endl;
    // 10
    it++;
    cout << *it; // 15
    cout << endl;

    it--;
    cout << *it;
    cout << endl;      // 10
    cout << *(it + 3); // 5
    cout << endl;

    // iterator in fixed array
    int a[5] = {10, 15, 12, 5, 2};
    int *p = a;
    cout << *p; // 10
    cout << endl;

    p++;
    cout << *p; // 15
    cout << endl;

    p--;
    cout << *p; // 10
    cout << endl;

    cout << *(p + 3); // 5
    cout << endl;
}