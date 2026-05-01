// 2^2*2*3*3^2
// so GCD=2*3=6--lowest gula
// so LCM=2^2*3*2=36--highest gula....full theke GCD bad dilei LCM paoya jai
// a*b/GCD=LCM
// Euclidean Algorithm → only GCD
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

/*
ax+by=gcd(a,b)--find gcd(a,b)..and also find x,y...Extended Euclidean algo.. → GCD + coefficients (x, y)
#include <bits/stdc++.h>
using namespace std;

int extendedGCD(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int g = extendedGCD(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return g;
}

int main()
{
    int a = 12, b = 18;
    int x, y;

    int g = extendedGCD(a, b, x, y);

    cout << "GCD = " << g << endl;
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}

*/