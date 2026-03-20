// 1,2,4,8,16,32,64....eigular binary just 1 ta zero..like 10,100,1000,10000 etc.x&(x-1)==0 hole its power of 2.ba n && ! (n & (n -1));
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x = 8;

    cout << ((x & x - 1) == 0) << endl;
    cout << (x & x - 1) << endl; //right most bit remove kora..mane right side er 1st 1 ta k remove clear kra ba 0 banano
    cout << (x && !(x & (x - 1))) << endl;

    return 0;
}

/*
n/2^k..n ta 2^k er divisible nki checking...

bool isDivisibleByPower0f2(int n, int k) {
int power0f2 = 1 << k;
return (n & (power0f2-1)) == 0;
*/