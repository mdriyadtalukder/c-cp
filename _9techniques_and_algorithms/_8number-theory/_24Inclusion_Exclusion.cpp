/*
inclusion & exclusion:
A ∪ B ∪ C = A + B + C
            - (A ∩ B)
            - (B ∩ C)
            - (C ∩ A)
            + (A ∩ B ∩ C)

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B, C;
    int AB, BC, CA;
    int ABC;

    cin >> A >> B >> C;
    cin >> AB >> BC >> CA;
    cin >> ABC;

    /*
    Inclusion-Exclusion Principle:

    |A ∪ B ∪ C| = A + B + C
                  - (A ∩ B)
                  - (B ∩ C)
                  - (C ∩ A)
                  + (A ∩ B ∩ C)
    */

    int result = A + B + C - AB - BC - CA + ABC;

    cout << result << endl;

    return 0;
}