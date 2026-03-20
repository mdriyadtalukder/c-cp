// x=1011001->set 2nd bit of x..so x|(1<<2);..set means 1 set kora..1<<2 means 100
// clear 3rd bit..x&(~(1<<3))..1<<3 means 1000..clear means 0 banano..
// flip means 0 re 1 o 1 re 0 banano..5th bit re flip kora..x^(1<<5)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x = 0b1101101;

    cout << (x | (1 << 2)) << endl;    // set 2nd bit
    cout << (x & (~(1 << 3))) << endl; // clear 3rd bit
    cout << (x ^ (1 << 5)) << endl;    // flip 5th bit
    cout << ((x >> 3) & 1) << endl;    // check 3rd bit set or not

    return 0;
}