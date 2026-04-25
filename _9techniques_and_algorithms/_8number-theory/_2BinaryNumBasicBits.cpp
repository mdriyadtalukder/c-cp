// odd binary num er last e 1 hoy and even e 0 hy
//  _ _ _ 3 bit e amader 2 ta choice ase 0 or 1 rakhte pari like 0 0 0 or 1 1 1..so 2 choice ase..so2*2*2=(2^3)-1 ti number amara banate parbo
// 2^n==1LL<<n;
#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << pow(2, 3) << endl;
    cout << (1LL << 3) << endl;
    cout << INT_MAX << endl;
    int a = (1LL << 31) - 1; // int 32 bit er..-x theke +x obdi print kre signed int ta
    cout << a << endl;
    unsigned int b = (1LL << 32) - 1;//overflow hbe in signed // eita just positive num printe kre..0 theke 2*x print kre..signed theke 2 gun print kre positive num;
    cout << b << endl;
}