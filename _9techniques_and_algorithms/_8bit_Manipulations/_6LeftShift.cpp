// x<<1 1 ghor left a jabe sobai..so shamne 1 ta 0 hbe..x<<2 2 ghor kre left e jbe sobai..so shamne 2 ta 0 hbe..x*2^a..a=1,2..koi ghor jbe.
// x>>1 1 ghor kre right a jbe..mane agabe..so last theke 1 ta bit remove hbe..x>>2 last theke 2 ta bit remove hbe..x/2^a..a=1,2..koi ghor jbe.

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a = 19;
    cout << (a << 2) << endl; // LEFT
    cout << (a >> 2) << endl; // RIGHT
}