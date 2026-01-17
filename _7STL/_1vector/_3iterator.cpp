#include <bits/stdc++.h>
using namespace std;
int main()
{

    vector<pair<int, string>> student;

    sort(student.begin(), student.end());

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
    cout << endl;// 10
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

    cout << *(p + 3); //5
    cout << endl;
}