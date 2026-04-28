// pow(a,b) er algo eita..pow(a,b) double value rerurn kre..ja accurate na and optimized na.
// divide and conque use krbo ..1st e power k choto choto vag krbo then choto part solve kre ek shath krbo..like
//  2^16 -> 2^8 x 2^8
//  2^8  -> 2^4 x 2^4
//  2^4  -> 2^2 x 2^2
//  2^2  -> 2^1 x 2^1

#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
int binExpRecur(int a, int b)
{
    if (b == 0)
        return 1;
    int res = binExpRecur(a, b / 2);
    if (b & 1)
    {
        return (a * ((res * 1LL * res) % M)) % M;
    }
    else
    {
        return (res * 1LL * res) % M;
    }
}
int main()
{
    int a = 2, b = 13;
    cout << binExpRecur(a, b) << endl;
    cout << pow(a, b);
}