// odd number of 1 hole 1 hbe else 0 in binary numbers..like 1,0 hole 1 hbe and 0,1 hole 1 hbe..(1,0=1)(0,1=1)
// NOT means 0 ta 1 hbe o 1 ta 0 hbe.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a = 19, b = 26, c = 51;
    cout << (a ^ b ^ c) << endl; // XOR
    cout << (~a) << endl;        // NOT
}