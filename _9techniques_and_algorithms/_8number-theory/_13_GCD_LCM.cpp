// 2^2*2*3*3^2
// so GCD=2*3=6--lowest gula
// so LCM=2^2*3*2=36--highest gula....full theke GCD bad dilei LCM paoya jai
// a*b/GCD=LCM
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{

    cout << gcd(12, 18) << endl; // GCD

    cout << (12 * 18) / gcd(12, 18) << endl; // LCM

    cout << __gcd(12, 18) << endl; // correct STL function of GCD

    return 0;
}