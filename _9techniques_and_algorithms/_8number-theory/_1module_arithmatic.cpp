/*

1. (a+b) % M = ((a%M) +(b%M))%M
2. (a*b)%M = ((a%M) * (b%M))%M
3 (a−b) %M = ((a%M)-(b%M) +M)%M

*/
/*
given N..print factorial of N;
constraints
1 <= N <= 100
print answer modulo M
where M = 47
//M=10^9+7--eita very ideal choice..int data type er max value er close eita..and eita ekta prime number jar karone multiplicative inverse ber krte pari.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int M = 47; // missing semicolon fixed
    long long fact = 1;

    for (int i = 2; i <= n; ++i)
    {
        fact = (fact * i) % M; // take mod at every step (1*2*3*4*5)%47--its breaking-->((1*2*3*4)%47*5%47)%47..((1*2*3)%47*4%47)%47..so on
    }

    cout << fact << endl;

    return 0;
}